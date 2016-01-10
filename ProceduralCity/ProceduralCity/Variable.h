#pragma once
#include <string>
#include "Road.h"

struct ruleAttr {
	//Do we end at a crossing? Did this crossing exist before or did we create it
	int depth;
};

struct roadAttr {
	float length, angle;
	Point start, end;
	//null => create an intersection at start
	RoadIntersection *branchSource;
	//null => create an intersection at end
	RoadIntersection *target;

	//The road that generated this.
	Road *parentRoad;
	//Incident road, if exists.
	Road *targetRoad;

	bool connected;

	void createFromIntersection(RoadIntersection *source) {
		branchSource = source;
		start = source->location;
	}

	void branchFromParent(Road *parent) {
		this->parentRoad = parent;
	}

	
};

enum Zone {
	RESIDENTIAL,
	COMMERTICAL,
	INDUSTRIAL
};

enum solutionState {
	UNASSIGNED,
	SUCCEED,
	FAILED
};

enum variableType {
	ROAD,
	INSERTION,
	BRANCH,
	EMPTY
};

//Represents the basic variable
class Variable {
public:
	int delay;
	ruleAttr rules;
	roadAttr road;
	variableType varType;
	solutionState state;

	Variable(variableType vType, int delay, ruleAttr rules, roadAttr road);
	Variable(variableType vType);
	Variable(variableType vType, int delay);
	Variable();
	~Variable();

	std::string toString();

};

