#include "StreetGen.h"

using namespace boost::geometry;

const float StreetGen::d2rFactor = 3.14159265f / 180.0f;
const float StreetGen::r2dFactor = 180.0f / 3.14159265f;

const int StreetGen::BRANCH1 = 0;
const int StreetGen::BRANCH2 = 1;
const int StreetGen::ROAD = 2;

const int StreetGen::NATURAL_PATTERN_INDEX = 0;
const int StreetGen::SF_PATTERN_INDEX = 1;
const int StreetGen::MANHATTAN_PATTERN_INDEX = 2;
const int StreetGen::RADIAL_PATTERN_INDEX = 3;

void StreetGen::setSeed(int seed) {
	rng.seed(seed);
}

void StreetGen::setSeed() {
	rng.seed(static_cast<unsigned int>(std::time(0)));
}

StreetGen::StreetGen(CityView2D *view, Point size) {
	ready = finished = false;
	setSize(size);

	parkCol = qRgb(100, 170, 100);
	landCol = qRgb(200, 200, 200);
	waterCol = qRgb(140, 140, 220);

	setDefaultValues();

	streets = StreetManager::StreetManager(size, view);
}

StreetGen::StreetGen() {
}

void StreetGen::setDefaultValues() {
	roadBranchProb = 0.7f;
	popDensityRadiusSearch = 500.0f;
	streetLength = 25;
	highwaylength = 50.0f;

	//Global constraints
	maxAngleSearch = 0.2f;
	manhattanBlockWidth = 30.0f;
	manhattanBlockHeight = 20.0f;

	minHighwayGrowthFactor = 0.5f;
	minStreetGrowthFactor = 0.25f;
	minHighwayGrowthScore = 10.0f;
	minStreetGrowthScore = 10.0f;

	//Geography Fitting
	maxRoadRotate = 0.7f;
	roadRotateInterval = 0.1f;
	roadSampleInterval = 2;
	maxWaterTraverse = 35.0f;
	maxPruneFactor = 0.75f;

	//Intersection fitting
	extendRadius = 20.0f;
	roadSnap = 25.0f;
	minDistanceSq = extendRadius * extendRadius;
	minLength = 10.0f;
	useWeightedVals = true;
}

StreetGen::VarList* StreetGen::applyGlobalConstraints(ruleAttr rules, roadAttr roads) {
	//Create 3 sets of new variables
	if (roads.connected) {
		//Parent street has connected to an intersection -> stops growing.
		VarList *result = new VarList();
		result->push_back(RoadVariable(variableType::ROAD, -1));
		return result;
	}

	//Initialise the new set of variables
	ruleAttr nrules[3];
	roadAttr nroads[3];
	int delay[3];
	boost::random::uniform_real_distribution<float> uniform = boost::random::uniform_real_distribution<float>();

	QPointF distance = roads.end - roads.start;

	for (int i = 0; i < 3; i++) {
		//The parent of all these branches is the generated road from roads variable
		nroads[i].parentRoad = roads.generated;
		nroads[i].branchSource = roads.generated->roadEndIntersection;
		nroads[i].targetRoad = nullptr;
		nroads[i].rootRoad = roads.rootRoad;
		nroads[i].connected = false;
		nrules[i] = rules;
		//Increment depth
		nrules[i].depth++;

		//Calculate new position (end, angle, length) for each road pattern. (Apart from if value = 0
		float endx[4];
		float endy[4];
		float angle[4];
		float length[4];

		//Apply road pattern
		float scale = uniform(rng);
		nroads[i].start = roads.end;
		nroads[i].end = roads.start;
		delay[i] = i;
		nroads[i].angle = roads.angle;
	}

	//Road branches become streets with a certain probability
	if (roads.rtype == roadType::MAINROAD) {
		nroads[ROAD].rtype = roadType::MAINROAD;

		float branchProb1 = uniform(rng);
		float branchProb2 = uniform(rng);

		if (branchProb1 < roadBranchProb)
			nroads[BRANCH1].rtype = roadType::MAINROAD;
		else nroads[BRANCH1].rtype = roadType::STREET;
		if (branchProb2 < roadBranchProb)
			nroads[BRANCH2].rtype = roadType::MAINROAD;
		else nroads[BRANCH2].rtype = roadType::STREET;
	}
	else {
		nroads[BRANCH2].rtype = roadType::STREET;
		nroads[BRANCH1].rtype = roadType::STREET;
		nroads[ROAD].rtype = roadType::STREET;
	}

	//Set branches to point at right angle
	nroads[BRANCH1].angle += math::half_pi<float>();
	nroads[BRANCH2].angle -= math::half_pi<float>();
	//Arbritrary delay at the moment - shouldn't have too much of an effect if it is much bigger
	delay[BRANCH1] = 10;
	delay[BRANCH2] = 10;
	delay[ROAD] = 1;

	//Set all roads to have some new length
	nroads[BRANCH1].length = streetLength;// +uniform(rng) * 20.0f;
	nroads[BRANCH2].length = streetLength;//  +uniform(rng) * 20.0f;
	nroads[ROAD].length = highwaylength;

	//Calculate new end positions
	for (int i = 0; i < 3; i++) {
		if (nroads[i].rtype == roadType::MAINROAD) nroads[i].length = highwaylength;

		//Create unit vector in direction
		//if (nroads[i].angle < 0.0f) nroads[i].angle += math::two_pi<float>();
		nroads[i].angle = math::mod<float>(nroads[i].angle, math::two_pi<float>());
		Point unit = Point(cosf(nroads[i].angle), sinf(nroads[i].angle));
		unit *= nroads[i].length;
		nroads[i].end = nroads[i].start + unit;

		//Apply street patterns

		//Get each weighting by sampling
		if (nroads[i].rtype == roadType::MAINROAD) {
			//Mainroads follow population peaks, do not follow street patterns
			nroads[i].end = naturalRule(&nroads[i], &nrules[i]);
		} else if (useWeightedVals) {

			float values[4];
			getPatternWeightings(roads.end.x(), roads.end.y(), values);
			Point ends[4];
			int patternCount = 0;
			float maxVal = 0.0f;
			int maxIndex;

			for (int x = 0; x < 4; x++) {
				if (values[x] > maxVal) {
					maxVal = values[x];
					maxIndex = x;
				}
			}
			roads.majorityPattern = static_cast<roadPattern>(maxIndex);
			roads.manhattanFactor = values[MANHATTAN_PATTERN_INDEX];
			roads.sfFactor = values[SF_PATTERN_INDEX];
			roads.naturalFactor = values[NATURAL_PATTERN_INDEX];
			roads.radialFactor = values[RADIAL_PATTERN_INDEX];

			if (values[NATURAL_PATTERN_INDEX] - 0.01f > 0) {
				ends[NATURAL_PATTERN_INDEX] = naturalRule(&nroads[i], &nrules[i]);
			}

			if (values[MANHATTAN_PATTERN_INDEX] - 0.01f > 0) {
				ends[MANHATTAN_PATTERN_INDEX] = manhattanRule(&nroads[i]);
			}

			if (values[SF_PATTERN_INDEX] - 0.01f > 0) {
				ends[SF_PATTERN_INDEX] = sanFransiscoRule(&nroads[i]);
			}

			if (values[RADIAL_PATTERN_INDEX] - 0.01f > 0) {
				ends[RADIAL_PATTERN_INDEX] = radialRule(&rules, &roads);
			}

			nroads[i].end = weighValues(values, ends, &roads.end);
		}
		else {
			//Find majority, apply it.
			float values[4];
			getPatternWeightings(roads.end.x(), roads.end.y(), values);
			float maxVal = 0.0f;
			int maxIndex = NATURAL_PATTERN_INDEX;

			for (int x = 0; x < 4; x++) {
				if (values[x] > maxVal) {
					maxVal = values[x];
					maxIndex = x;
				}
			}

			roads.majorityPattern = static_cast<roadPattern>(maxIndex);
			roads.manhattanFactor = roads.sfFactor = roads.naturalFactor = roads.radialFactor = 0;

			if (maxIndex == MANHATTAN_PATTERN_INDEX) {
				nroads[i].end = manhattanRule(&nroads[i]);
				roads.manhattanFactor = 1.0f;
			} else if (maxIndex == RADIAL_PATTERN_INDEX) {
				nroads[i].end = radialRule(&nrules[i], &nroads[i]);
				roads.radialFactor = 1.0f;
			} else if (maxIndex == SF_PATTERN_INDEX) {
				nroads[i].end = sanFransiscoRule(&nroads[i]);
				roads.sfFactor = 1.0f;
			} else {
				nroads[i].end = naturalRule(&nroads[i], &nrules[i]);
				roads.naturalFactor = 1.0f;
			}
		}
	}


	for (int i = 0; i < 3; i++) {
		if (nroads[i].hasFailed()) delay[i] = -1;
	}

	//Create the new variables, for the production
	RoadVariable branch1 = RoadVariable(variableType::BRANCH, delay[BRANCH1], nrules[BRANCH1], nroads[BRANCH1]);
	RoadVariable branch2 = RoadVariable(variableType::BRANCH, delay[BRANCH2], nrules[BRANCH2], nroads[BRANCH2]);
	RoadVariable road = RoadVariable(variableType::ROAD, delay[ROAD], nrules[ROAD], nroads[ROAD]);
	RoadVariable insertion = RoadVariable(variableType::INSERTION, delay[ROAD], nrules[ROAD], nroads[ROAD]);
	insertion.state = solutionState::UNASSIGNED;

	VarList* newList = new VarList();
	newList->push_back(branch1);
	newList->push_back(branch2);
	newList->push_back(road);
	newList->push_back(insertion);

	return newList;
}

void StreetGen::applyLocalConstraints(RoadVariable *toCheck) {
	Road temp = Road(toCheck->road.start, toCheck->road.end);

	bool connectedToIntersection = false;
	bool connectedToNewIntersection = false;
	bool legalPlacement = tryMakeLegal(toCheck, &temp);

	if (toCheck->road.parentRoad != nullptr)
		assert(toCheck->road.start.x() - toCheck->road.parentRoad->getEnd().x() < 0.01f
			&& toCheck->road.start.y() - toCheck->road.parentRoad->getEnd().y() < 0.01f);

	if (toCheck->road.end.x() - 1627.4f < 1.0f && toCheck->road.end.y() == 1247.6f < 1.0f)
		qDebug() << "A";
	if (toCheck->road.end.x() - 1614.2f < 1.0f && toCheck->road.end.y() == 1267.6f < 1.0f)
		qDebug() << "A";
	if (toCheck->road.start.x() == 2045.0f && toCheck->road.start.y() == 1074.0f)
		qDebug() << "A";

	bool legalIntersection = tryConnectToExisting(toCheck, &temp, connectedToIntersection, connectedToNewIntersection);

	if (toCheck->road.end.x() == 2045.0f && toCheck->road.end.y() == 1074.0f)
		qDebug() << "A";
	if (toCheck->road.end.x() == 2041.0f && toCheck->road.end.y() == 1050.0f)
		qDebug() << "A";

	//Check close to intersection here?
	//Ensure unique ness here please
	bool isUniqueRoad = true;
	//If we are connecting to an intersection that already exists
	if (!connectedToNewIntersection && connectedToIntersection) isUniqueRoad = isUnique(toCheck, &temp);

	bool legalAngle = !overlapsConnected(toCheck, &temp);
	bool legalLength =  toCheck->road.length * toCheck->road.length > minLength;
	legalLength = temp.length() * temp.length() > minLength;
	if (legalPlacement && legalIntersection && legalAngle && legalLength && isUniqueRoad) toCheck->state = solutionState::SUCCEED;
	else toCheck->state = solutionState::FAILED;
	//Stop growing street
	if (connectedToIntersection) 
		toCheck->road.connected = true;
}

//Todo :: check angles
bool StreetGen::tryMakeLegal(RoadVariable * toCheck, Road * tempRoad) {
	//BUG angle change
	bool isLegal = false;
	bool withinBounds;
	bool legalSegment;
	bool endsLegal;
	//Others to check are pop density, gradient etc.
	float startAngle = (tempRoad->getAngle()) * d2rFactor;
	float angleChange = 0.0f;
	float angleToCheck = startAngle;
	QPointF newEnd = toCheck->road.end;
	float pruneFactor = 1.0f;

	withinBounds = tempRoad->isInBounds(size.x(), size.y());
	if (!withinBounds) endsLegal = false;
	else endsLegal = (sampleGeog(newEnd.x(), newEnd.y()) == geogType::LAND);

	getIllegalSegment(*tempRoad, legalSegment);
	
	isLegal = endsLegal && withinBounds && legalSegment;

	while (!isLegal) {
		//Update step
		if (angleChange > maxRoadRotate) return false;
		if (pruneFactor > maxPruneFactor) pruneFactor -= 0.04f;
		else {
			//Update angle once all prunes have been tried (yum)
			pruneFactor = 1.0f;
			if (angleChange > 0) angleChange = -angleChange;
			else angleChange = -angleChange + roadRotateInterval;
		}

		//Rotate line, set line length
		if (pruneFactor == 1.0f) {
			//Calculate new end position by rotating lines
			angleToCheck = startAngle + angleChange;				
			QLineF newLine = QLineF(tempRoad->getStart(), tempRoad->getEnd());
			newLine.setAngle(angleToCheck * r2dFactor);
			newEnd = newLine.p2();
		}
		else {
			//update position by shortening
			newEnd = tempRoad->lerp(pruneFactor);
		}

		Road segment = Road(tempRoad->getStart(), newEnd);
		//recalculate booleans
		withinBounds = tempRoad->isInBounds(size.x(), size.y());
		if (!withinBounds) endsLegal = false;
		else endsLegal = (sampleGeog(newEnd.x(), newEnd.y()) == geogType::LAND);

		getIllegalSegment(segment, legalSegment);

		isLegal = endsLegal && withinBounds && legalSegment;
	}

	tempRoad->setEnd(newEnd);
	toCheck->road.end = newEnd;
	toCheck->road.angle = angleToCheck * r2dFactor;
	toCheck->road.length *= pruneFactor;
	return true;
}

bool StreetGen::isUnique(RoadVariable * toCheck, Road * tempRoad) {
	RoadIntersection *s = toCheck->road.target;
	if (s == nullptr) return true;
	BOOST_FOREACH(Road *rItr, s->connected) {
		if (rItr == tempRoad) continue; 
		else {
			if ((rItr->getStart() == tempRoad->getEnd()) && (rItr->getEnd() == tempRoad->getStart())) 
				return false;
		}
	}

	return true;
}

void StreetGen::getIllegalSegment(Road segment, bool &legal) {
		//Linearly interpolate between start and end, sample for invalid positions
		float rLength = segment.length();

		float numSamples = rLength / roadSampleInterval;
		float xInc = cosf(segment.getAngle()) * roadSampleInterval;
		float yInc = sinf(segment.getAngle()) * roadSampleInterval;
		int begin = -1;
		int end = 0;
		int maxSamples = maxWaterTraverse / roadSampleInterval;

		//in bounds
		if (!segment.isInBounds(size.x(), size.y())) {
			legal = false;
			return;
		}

		Point curPos = segment.getStart();

		for (int i = 0; i < numSamples; i++) {
			curPos.setX(curPos.x() + xInc);
			curPos.setY(curPos.y() + yInc);
			geogType geog = sampleGeog(curPos.x(), curPos.y());

			if (geog != geogType::LAND) {
				//Illegal, update boundaries
				if (begin == -1) {
					begin = i;

				}
				else if (end == i - 1) end++;
				else {
					//We have found another piece of land / water, we should deal with this
					end++;
				}
			}

			if ((end - begin) > maxSamples) {
				legal = false;
				return;
			}
		}

		legal = true;
		return;
}

bool StreetGen::overlapsConnected(RoadVariable * toCheck, Road * tempRoad) {
	//Test connected roads for roads of similar angle (prevent this)
	//For roads at each intersection, test for angle / weird

	return false;
	if (toCheck->road.parentRoad == nullptr) return false;
	//test dot produce of connected roads
	const float dotThreshold = 0.2f;
	BOOST_FOREACH(Road *cRoad, toCheck->road.parentRoad->roadEndIntersection->connected) {
		//float angleVal = cRoad->angleTo(*tempRoad);
		//if (abs(angleVal - 180.0f) < 5.0f) return true;
		float dot = tempRoad->getDot(*cRoad);
		dot /= tempRoad->length();
		dot /= cRoad->length();
		if (dot >= dotThreshold) return true;
	}

	BOOST_FOREACH(Road *cRoad, tempRoad->roadEndIntersection->connected) {
		float dot = tempRoad->getDot(*cRoad);
		dot /= tempRoad->length();
		dot /= cRoad->length();
		if (dot >= dotThreshold) return true;
	}
	return false;
}

bool StreetGen::tryConnectToExisting(RoadVariable * toCheck, Road *tempRoad, bool &connectedToIntersection, bool &connectedToNewIntersection) {
	std::vector<StreetManager::intersectionRec> intersections;
	streets.getIntersectingEdges(*tempRoad, intersections);

	bool legalPlacement = false;

	//Road intersects with other roads in the system
	if (intersections.size() > 0) {
		auto minIntersect = streets.getClosest(toCheck->road.start, intersections);

		toCheck->road.end = minIntersect->first;
		//Add a crossing, leave target as null as we need to create this
		toCheck->road.targetRoad = minIntersect->second;
		toCheck->state = solutionState::SUCCEED;
		legalPlacement = true;
		connectedToIntersection = true;
		connectedToNewIntersection = true;
	}
	else { //Road does not intersect, so lets see if it is near to an existing crossing.
		std::vector<RoadIntersection *> possibleExistingIntersections;
		streets.getNearbyVertices(toCheck->road.end, extendRadius, possibleExistingIntersections);
		bool connectToIntersection = false;

		if (possibleExistingIntersections.size() > 0) {
			//we may be able to extend the road to join an intersection
			std::sort(possibleExistingIntersections.begin(), possibleExistingIntersections.end(),
				[&toCheck](RoadIntersection * a, RoadIntersection * b) { return a->location.getDistanceSq(toCheck->road.start) 
					< b->location.getDistanceSq(toCheck->road.start); });

			//sort by closest, then attach to the first intersection which doesn't intersect other lines
			BOOST_FOREACH(RoadIntersection *it, possibleExistingIntersections) {
				streets.getIntersectingEdges(Road(toCheck->road.start, it->location), intersections);
				//TODO :: Filter when intersections are part of the road we are joining to?
				bool legalIntersection = (intersections.size() == 0);

				if (legalIntersection && toCheck->road.start.getDistanceSq(it->location) > minDistanceSq) {
					toCheck->road.end = it->location;
					toCheck->road.targetRoad = it->connected.front();
					toCheck->road.target = it;
					connectedToNewIntersection = false;
					connectToIntersection = true; legalPlacement = true;
					break;
				}
			}
		}

		//Extend the road by a maximum radius, then see if it intersects.
		if (!connectToIntersection) {
			legalPlacement = true;
			float scale = (tempRoad->length() + extendRadius) / tempRoad->length();
			Point extended = Point(toCheck->road.start.x() + scale * (toCheck->road.end.x() - toCheck->road.start.x()), 
				toCheck->road.start.y() + scale * (toCheck->road.end.y() - toCheck->road.start.y()) );
			
			streets.getIntersectingEdges(Road(toCheck->road.start, extended), intersections);

			//TODO :: SEARCH FOR MINIMUM
			if (intersections.size() > 0 && toCheck->road.start.getDistanceSq(extended) > minDistanceSq) {
				//Allign road to first intersection
				auto minIntersect = streets.getClosest(toCheck->road.start, intersections);
				bool isSnapped = false;
				BOOST_FOREACH(RoadIntersection *intersection, *minIntersect->second->getIntersections()) {
					if (isSnapped) continue;
					//Try and snap to an intersection if it is arbritrarily close
					if (intersection->location.getDistanceSq(minIntersect->first) < 5.0f * 5.0f) {
						toCheck->road.end = intersection->location;
						toCheck->road.target = intersection;
						toCheck->road.targetRoad = minIntersect->second;
						connectedToIntersection = true;
						connectedToNewIntersection = false;
						isSnapped = true;
					}
				}

				if (!isSnapped) {
					toCheck->road.end = minIntersect->first;
					toCheck->road.targetRoad = minIntersect->second;
					connectToIntersection = true;
					connectedToNewIntersection = true;
				}
			}
		}
	}

	if (connectedToIntersection) assert(toCheck->road.targetRoad != nullptr);
	tempRoad->setEnd(toCheck->road.end);
	return legalPlacement;
}

void StreetGen::addRoadToSystem(roadAttr &roads) {

	//Create first intersection if necessary
	std::vector<RoadIntersection*> nearby;

	if (roads.end.x() == 2045.0f && roads.end.y() == 1074.0f)
		qDebug() << "A";
	if (roads.end.x() == 2041.0f && roads.end.y() == 1050.0f)
		qDebug() << "B";

	//Case for initial road. We have to manually attach the start intersection before creating the road.
	if (roads.parentRoad == nullptr) {
		//First road was generated, so branch this road
		Road *road = new Road(roads.start, roads.end, roads.parentRoad, roads.rtype);
		RoadIntersection *start = new RoadIntersection(road->getStart());
		roads.generated = road;
		road->addStartIntersection(start);
		start->parent = road;
		start->attachRoad(road);
		streets.insertIntersection(start);
		streets.branchRoad(start, road);
		roads.parentRoad = road;
		return;
	}

	//Otherwise, we can get the intersection from the parent road
	RoadIntersection *start = roads.parentRoad->roadEndIntersection;

	assert(roads.start.getDistance(start->location) < 1.0f);

	Road *road = new Road(roads.start, roads.end, start, roads.parentRoad, roads.rtype);
	roads.generated = road;

	//Create second intersection if necessary
	if (roads.targetRoad != nullptr) {
		//Check to see if we need to connect to an intersection / use old
		streets.connectToRoad(start, road, roads.targetRoad);
		roads.connected = true;
	}
	else {
		//Create the new empty crossing
		streets.branchRoad(start, road);
	}

	assert(road->intersections.size() >= 2);
}

void StreetGen::insertProduction(VarIterator before, VarList after) {
	//toInsert.emplace_front(std::pair<VarIterator, VarList>(before, after));
}

StreetGen::VarList StreetGen::getInitialProduction() {
	VarList initial;
	ruleAttr emptyRule;
	roadAttr emptyRoad;
	initial.push_front(RoadVariable(variableType::INSERTION, 0, emptyRule, getInitialRoadAttr()));
	initial.push_front(RoadVariable(variableType::ROAD, 0, getInitialRuleAttr(), emptyRoad));

	return initial;
}

ruleAttr StreetGen::getInitialRuleAttr() {
	//eventually pass these as parameters
	ruleAttr rules;
	rules.depth = 0;

	return rules;
}

roadAttr StreetGen::getInitialRoadAttr() {
	//eventually pass these as paramters
	roadAttr road;
	road.angle = 0.0f;
	road.start = Point(800, 800);
	road.end = Point(900, 800);
	road.length = math::sqrt(road.start.getDistanceSq(road.end));
	road.rtype = roadType::MAINROAD;
	road.connected = false;
	road.parentRoad = nullptr;

	return road;
}

//Applies the L System rules to the current variable. Returns the productions in VarList productions. Specific road creation behaviour
//is obtained by calls to LocalConstraints and GlobalConstraints
bool StreetGen::applyRule(VarIterator currentVar, VarList *productions) {
	//VarList productions;
	assert(productions->empty());
	VarIterator left;
	VarIterator right;
	switch (currentVar->varType) {
	case variableType::BRANCH : 
		//Production 6
		if (currentVar->delay < 0) return true;
		else if (currentVar->delay > 0) {
			//Production 4, reduce delay (but not for streets just yet
			if (currentVar->road.rtype != roadType::STREET || genStreets) {
				currentVar->delay--;
				delayChanged = true;
			}
			return false;
		}
		else {
			//Production 5. Create new Road and Insertion module
			if (currentVar->road.parentRoad != nullptr)
				assert(currentVar->road.start.getDistanceSq(currentVar->road.parentRoad->getEnd()) < 5.0f);

			productions->push_front(RoadVariable(variableType::INSERTION, 0, currentVar->rules, currentVar->road));
			productions->push_front(RoadVariable(variableType::ROAD, 0, currentVar->rules, currentVar->road));
			return true;
		}
		break;
	case variableType::INSERTION:
		//Production 7 - If a road with delay < 0 preceeds this, delete the variable.
		left = currentVar;
		left--;

		if (left->varType == variableType::ROAD && left->delay < 0) {
			return true;
		}
		else if (currentVar->state == solutionState::UNASSIGNED) {
			//Production 8. Unassigned insertion. Call local constraints to attempt to adjust the parameters.
			applyLocalConstraints(&(*currentVar));
			//Succeed => Safe to add to system
			if (currentVar->state == solutionState::SUCCEED)
				addRoadToSystem(currentVar->road);

		}
		else {
			//Production 9. If successful, the Road variable at production 2 will obtain the data needed from this variable to extend the system.
			return true;
		}
		break;
	case variableType::ROAD :
		right = currentVar;
		right++;

		//Production 1 - delete roads which have expired
		if (currentVar->delay < 0) {
			return true;
		}
		//Production 3, delete roads next to failed insertions.
		else if (right->state == solutionState::FAILED) {
			return true;
		} else {
			//Production 2 - right iterator is a succeeded insertion. Create new branches / road / insertion module with parameters set by
			//global goals. Add this road and vertices to the system.
			if (right->varType == variableType::INSERTION && right->state == solutionState::SUCCEED) {
				std::list<RoadVariable> it = *applyGlobalConstraints(currentVar->rules, right->road);

				BOOST_FOREACH(RoadVariable lol, it) {
					productions->push_back(lol);
				}

				return true;
			}
		}
			
		break;
	default: break;
	}
	return false;
}

float StreetGen::sampleHeight(int x, int y) {
	QColor val = QColor(hMap.pixel(x, y));
	return (val.red() % 256) / 256.0f;
}

geogType StreetGen::sampleGeog(int x, int y) {
	QRgb val = gMap.pixel(x, y);
	if (val == landCol) return geogType::LAND;
	else if (val == waterCol) return geogType::WATER;
	else if (val == parkCol) return geogType::PARK;
	else return geogType::LAND; 
}

float StreetGen::samplePop(int x, int y) {
	QRgb lol = pMap.pixel(x, y);
	return lol % 256;
	QColor val = QColor(pMap.pixel(x, y));
	return (val.red() % 256) / 256.0f;
}

QColor StreetGen::sampleStreet(int x, int y) {
	return QColor(sMap.pixel(x, y));
}

void StreetGen::getPatternWeightings(int x, int y, float weights[]) {
	//Sample pattern map
	QColor val = sampleStreet(x, y);
	
	weights[MANHATTAN_PATTERN_INDEX] = val.blueF();
	weights[NATURAL_PATTERN_INDEX] = val.blackF();
	weights[SF_PATTERN_INDEX] = val.redF();

	//TODO :: IMPLEMENT RADIAL
	weights[RADIAL_PATTERN_INDEX] = 0.0f;
	return;
}

float StreetGen::maxPopDensity(float startAngle, Point &start, Point &end, QPointF *peak) {
	//Sum weight of rays along center, return max sum
	int maxXVal = end.x();
	int maxYVal = end.y();
	float maxSum = 0.0f;
	
	float curAngle = startAngle - maxAngleSearch;
	curAngle = fmodf(curAngle, math::two_pi<float>());
	float endAngle = startAngle + maxAngleSearch;
	endAngle = fmodf(endAngle, math::two_pi<float>());
	float sectorSearched = 0;
	float roadLength = start.getDistance(end);
	float length = popDensityRadiusSearch;

	peak = &Point(maxXVal, maxYVal);

	Point curPoint = start;

	//Keep track of sector searched so we don't deal with wrap around issues.
	while (sectorSearched <= maxAngleSearch) {
		QLineF temp = QLineF::fromPolar(length, curAngle * r2dFactor);
		temp.translate(start);
		
		float sampleQuant = roadSampleInterval / length;
		float sampleInterval = sampleQuant;
		float xIncr = cosf(temp.dx()) * roadSampleInterval;
		float yIncr = sinf(temp.dy()) * roadSampleInterval;
		float sampleLength = roadSampleInterval;

		int xPos = temp.p1().x() + xIncr;
		int yPos = temp.p2().y() + yIncr;
		float cumulativeVal = 0;

		//Sum along the ray , sampling every roadSampleInterval untis
		while (sampleInterval < 1.0f) {
			if (xPos < 0 || xPos > size.x() || yPos < 0 || yPos > size.y()) 
				break;

			//Score += inverse distance * pop sample
			cumulativeVal += samplePop(xPos, yPos) / (float)(roadSampleInterval);
			xPos += xIncr;
			yPos += yIncr;
			sampleLength += sampleInterval;

			sampleInterval += sampleQuant;
		}

		//Scale by distance from desired (guess via angle dif)
		QPoint dif = QPoint(temp.x2() - end.x(), temp.y2() - end.y());
		//cumulativeVal /= abs(fmodf(startAngle - curAngle, math::two_pi<float>()));

		//Update current max
		//TODO :: Peak might be lower than length of road
		if (cumulativeVal > maxSum) {
			peak = &temp.p2();
			temp.setLength(roadLength);
			maxXVal = temp.x2();
			maxYVal = temp.y2();
			maxSum = cumulativeVal;
		}

		curAngle += roadRotateInterval;
		sectorSearched += roadRotateInterval;
	}

	//Now update road to point to new direction
	end = Point(maxXVal, maxYVal);
	return maxSum;
}

float StreetGen::getLowestGradient(float startAngle, Point start, float length) {
	float curAngle = startAngle - maxAngleSearch;
	curAngle = fmodf(curAngle, math::two_pi<float>());
	float endAngle = startAngle + maxAngleSearch;
	endAngle = fmodf(endAngle, math::two_pi<float>());

	float minAngle = startAngle;
	float minDensity = 100000.0f;
	float sectorSearched = 0;

	//get density at each sample point, compare to max
	while (sectorSearched <= maxAngleSearch) {
		float xAdd = cosf(curAngle) * length;
		float yAdd = sinf(curAngle) * length;
		float sampleDensity = sampleHeight(start.x() + xAdd, start.y() + yAdd);

		//Weigh more to keeping the same direction
		if (curAngle - startAngle < 0.01f) sampleDensity *= 0.7f;

		if (sampleDensity < minDensity) {
			minAngle = curAngle;
			minDensity = sampleDensity;
		}

		sectorSearched += roadRotateInterval;
	}

	return minAngle;
}

Point StreetGen::manhattanRule(const roadAttr* road) {
	//Ensure paths follow same angle - if branch, set length to block width. Otherwise set to block height.
	bool useHeight = useBlockHeight(0, road->angle);

	float lineLength = useHeight ? manhattanBlockHeight : manhattanBlockWidth;
	float xPos = road->start.x() + cosf(road->angle) * lineLength;
	float yPos = road->start.y() + sinf(road->angle) * lineLength;

	return Point(xPos, yPos);
}

bool StreetGen::useBlockHeight(float blockAngle, float curAngle) {
	float dif = fmodf(abs(curAngle - blockAngle), math::two_pi<float>());
	//Return true if angle is close to block angle
	return (dif < math::pi<float>() / 2.0f);
}

Point StreetGen::naturalRule(roadAttr* road, ruleAttr* rules ) {
	//Set path to point to maximum density 
	Point start = road->start;
	Point end = road->end;
	float angle = road->angle;
	QPointF peak;
	float score = maxPopDensity(angle, start, end, &peak);
	rules->peakTarget = peak;

	if (road->rtype == roadType::STREET) {
		if (score < minStreetGrowthScore) road->flagFail();
	}
	else {
		if (score < minHighwayGrowthScore) road->flagFail();
	}

	return end;
}

Point StreetGen::sanFransiscoRule(const roadAttr* road) {
	//Set path to point to minimum gradient of heightmap
	float angleToUse = getLowestGradient(road->angle, road->start, road->length);

	float xPos = road->start.x() + cosf(angleToUse) * road->length;
	float yPos = road->start.y() + sinf(angleToUse) * road->length;

	return Point(xPos, yPos);
}

Point StreetGen::radialRule(const ruleAttr * rules, const roadAttr * roads) {
	//Set path to rotate around centre point. (TODO)
	return Point();
}

//Linearly scale points based on weights
Point StreetGen::weighValues(float weights[], Point * vals, Point *start) {
	float weightSum = weights[0] + weights[1] + weights[2] + weights[3];
	Point cumulativeDistance = Point();

	//Add direction to cumulative
	for (int i = 0; i < 4; i++) {
		if (weights[i] - 0.01f < 0) continue;

		//Scale by weighting
		cumulativeDistance += QPointF(vals[i].rx() * weights[i], vals[i].ry() * weights[i]);
	}

	//Divide by total weighting
	cumulativeDistance /= weightSum;
	return cumulativeDistance;
}

//Not used
bool StreetGen::pointToTarget(roadAttr * road, ruleAttr * rules) {
	//Get point difference, see if it is valid.
	//If not, cull angle, then cull length.

	//Bounded by angle change
	Point dif = rules->peakTarget - road->start;
	if ((dif.x() * dif.x() + dif.y() * dif.y()) > highwaylength * highwaylength) {
		//Point is within bounds, so we can simply move it to there
		road->end = rules->peakTarget;
		return true;
	}
	else {
		//Point is further away, so lets point to as far as we can, capped by angle
		float angleDif = atan2f(road->start.x() - rules->peakTarget.x(), road->start.y() - rules->peakTarget.y());

	}

	return false;//for now, delete this
}

void StreetGen::filterStreets() {
	if (haveStreetsBeenFiltered) return;
	
	BOOST_FOREACH(RoadIntersection *intersect, streets.getIntersections()) {
		assert(intersect->connected.size() > 0);
	}

	//Do some filtering

	//Intersections with one incident road?

	//Small Roads that don't go anywhere. We don't need ya
	//For region generation, we need to remove all dead end streets.

	//Q: Do we need to split roads so that one road for every two intersections? I.e. joining to a road splits that road in two?

	//A: Yes -> easy to create the geometry, then each road only has to track left and right. Easy to pad roads left.	
	//Connect.size() == 2 -> already simple
	//Otherwise, split every road into new ones simple roads, attach each intersection along

	//Assert all streets >= connected size 2

	haveStreetsBeenFiltered = true;
}

// L - System

void StreetGen::LSystemBeforeIterationBegin() {
	delayChanged = false;
}

void StreetGen::LSystemAfterIteration(bool changed) {
	finished = (!delayChanged && !changed);
	delayChanged = false;

	if (finished && !genStreets) {
		//We need to iterate again, this time flag that we can generate the streets
		finished = false;
		genStreets = true;
	}
}

bool StreetGen::isFinished() {
	return finished;
}

bool StreetGen::isLSystemFinished(bool changed) {
	return this->finished;
}

void StreetGen::printProductions() {

	std::string varString;

	qDebug() << "Iteration: " << iterationCount << ", nodes: " << current.size();

	for (VarIterator it = current.begin(); it != current.end(); it++) {
		varString += it->toString();
	};
	qDebug() << varString.data();

	if (current.size() == 0)
		qDebug() << "NO PRODUCTIONS";

	qDebug() << "";
	qDebug() << "Roads generated: " << streets.roadCount();
	qDebug() << "Verts generated: " << streets.vertCount();
}

//End L - System

//Initialise the system, add initial variable productions
void StreetGen::initialise() {
	streets.reset();
	genStreets = false;
	ready = true;
	finished = false;
	haveStreetsBeenFiltered = false;

	initialiseLSystem();

	//Set growth score
	minHighwayGrowthScore = popDensityRadiusSearch * minHighwayGrowthFactor;
	minStreetGrowthFactor = popDensityRadiusSearch * minStreetGrowthFactor;
}

bool StreetGen::isReady() {
	return ready;
}

StreetGen::~StreetGen()
{

}

void StreetGen::setExtendRadius(float val) {
	extendRadius = val;
}

void StreetGen::setRoadSnap(float val) {
	roadSnap = val;
}

void StreetGen::setMinLength(float val) {
	minLength = val;
}

void StreetGen::setRoadBranchProb(float val) {
	roadBranchProb = val;
}

void StreetGen::setMaxAngleSearch(float val) {
	maxAngleSearch = val;
}

void StreetGen::setManhattanBlockWidth(float val) {
	manhattanBlockWidth = val;
}

void StreetGen::setManhattanBlockHeight(float val) {
	manhattanBlockHeight = val;
}

void StreetGen::setMaxRoadRotate(float val) {
	maxRoadRotate = val;
}

void StreetGen::setRoadRotateInterval(float val) {
	roadRotateInterval = val;
}

void StreetGen::setMaxWaterTraverse(float val) {
	maxWaterTraverse = val;
}

void StreetGen::setMaxPruneFactor(float val) {
	maxPruneFactor = val;
}

void StreetGen::setRoadSampleInterval(float val) {
	roadSampleInterval = val;
}

void StreetGen::setUsePatternWeighting(bool useWeighting) {
	useWeightedVals = useWeighting;
}

void StreetGen::setRoadLength(float val) {
	streetLength = val;
}

void StreetGen::setHighwayLength(float val) {
	highwaylength = val;
}

void StreetGen::setPopRadiusSearch(float val) {
	popDensityRadiusSearch = val;
}

void StreetGen::setHighwayGrowthFactor(float factor) {
	minHighwayGrowthFactor = factor;
}

void StreetGen::setStreetGrowthFactor(float factor) {
	minStreetGrowthFactor = factor;
}

void StreetGen::setHeightMap(QImage & hMap, bool use) {

	this->hMap = QImage(hMap);
	useHeight = use;
}

void StreetGen::setPopMap(QImage & pMap, bool use) {
	this->pMap = QImage(pMap);
	usePop = use;
}

void StreetGen::setGeogMap(QImage & gMap, bool use) {
	this->gMap = QImage(gMap);
	useGeog = use;
}

void StreetGen::setPatternMap(QImage & sMap, bool use) {
	this->sMap = QImage(sMap);
	usePattern = use;
}

void StreetGen::setSize(Point newSize) {
	size = newSize;
	genX = boost::random::uniform_int_distribution<>(0, size.x());
	genY = boost::random::uniform_int_distribution<>(0, size.y());
}

std::list<Road*> StreetGen::getGeneratedRoads() {
	return streets.getRoads();
}

std::list<RoadIntersection*> StreetGen::getGeneratedIntersections() {
	return streets.getIntersections();
}

