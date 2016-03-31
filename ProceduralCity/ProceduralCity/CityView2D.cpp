#include "CityView2D.h"

void CityView2D::addRegions(std::vector<BuildingRegion> *regions) {
	BOOST_FOREACH(BuildingRegion region, *regions) {
		QPolygonF poly = QPolygonF();
		BOOST_FOREACH(Point p, region.getPoints()) {
			poly.append(p);
		}

		//TODO
		
		auto polyItem = scene->addPolygon(poly, QPen(QBrush(QColor(100, 0, 0)), 2.0f), QBrush(QColor(std::fmodf((poly.at(0).x() * 100), 256), 0, std::fmodf((poly.at(0).y() * 100), 256))));
		regionRender->addToGroup(polyItem);
	}
}

void CityView2D::addLots(std::vector<BuildingLot> *lots) {
	BOOST_FOREACH(BuildingLot lot, *lots) {
		QPolygonF poly = QPolygonF();
		BOOST_FOREACH(Point p, lot.getPoints()) {
			poly.append(p);
		}

		//TODO 
		auto polyItem = scene->addPolygon(poly, QPen(QBrush(QColor(0, 0, 0)), 2.0f), QBrush(QColor(100, 0, 0)));
		lotsRender->addToGroup(polyItem);
	}
}

QPen CityView2D::getRoadPen(Road * road) {
	if (road->rType == roadType::STREET) return roadPen;
	else return mainRoadPen;
}

void CityView2D::setPop(QImage *pop) {
	this->pop = *pop;
	//Create the pixmap now for the scene
	pixPop.convertFromImage(*pop);
}

void CityView2D::setHeight(QImage *height) {
	this->height = *height;
	//Create the pixmap now for the scene
	pixHeight.convertFromImage(*height);
}

void CityView2D::setGeog(QImage *geog) {
	this->geog = *geog;
	//Create the pixmap now for the scene
	pixGeog.convertFromImage(*geog);
}

void CityView2D::setPattern(QImage * pattern) {
	this->pattern = *pattern;
	//Create the pixmap now for the scene
	pixPattern.convertFromImage(*pattern);
}

void CityView2D::renderPop() {
	if (bg != nullptr)
		scene->removeItem(bg);
	bg = scene->addPixmap(pixPop);
	bg->setZValue(-1.0f);
}

void CityView2D::renderHeight() {
	if (bg != nullptr)
		scene->removeItem(bg);
	bg = scene->addPixmap(pixHeight);
	bg->setZValue(-1.0f);
}

void CityView2D::renderGeog() {
	if (bg != nullptr)
		scene->removeItem(bg);
	bg = scene->addPixmap(pixGeog);
	bg->setZValue(-1.0f);
}

void CityView2D::renderPattern() {
	if (bg != nullptr)
		scene->removeItem(bg);
	bg = scene->addPixmap(pixPattern);
	bg->setZValue(-1.0f);
}

void CityView2D::renderNone() {
	if (bg != nullptr)
		scene->removeItem(bg);
	bg = nullptr;
}

void CityView2D::renderVertices(bool renderVerts) {
	this->renderVerts = renderVerts;
	intersectionsRender->setVisible(renderVerts);
}

void CityView2D::setDrawLots(bool drawLots) {
	this->drawLots = drawLots;
	lotsRender->setVisible(drawLots);
}

void CityView2D::setDrawRegions(bool drawRegions) {
	this->drawRegions = drawRegions;
	regionRender->setVisible(drawRegions);
}

QGraphicsScene * CityView2D::getScene() {
	return scene;
}

void CityView2D::Reset(Point size) {
	scene->clear();
	bg = nullptr;

	QList<QGraphicsItem*> emptyRoads = QList<QGraphicsItem*>();
	QList<QGraphicsItem*> emptyIntersections = QList<QGraphicsItem*>();
	intersectionsRender = scene->createItemGroup(emptyIntersections);
	intersectionsRender->setVisible(renderVerts);
	roadsRender = scene->createItemGroup(emptyRoads);
	lotsRender = scene->createItemGroup(QList<QGraphicsItem*>());
	lotsRender->setVisible(drawLots);
	regionRender = scene->createItemGroup(QList<QGraphicsItem*>());
	regionRender->setVisible(drawRegions);

	scene->setSceneRect(QRectF(-100, -100, size.x() + 100, size.y() + 100));

}

void CityView2D::Update() {
	scene->update();
}

void CityView2D::addRoad(Road * toAdd) {
	QGraphicsLineItem *road = scene->addLine(QLineF(toAdd->getStart(), toAdd->getEnd()), getRoadPen(toAdd));
	road->setZValue(toAdd->rType == roadType::MAINROAD ? 2.0f : 3.f);
	roadsRender->addToGroup(road);
}

void CityView2D::addIntersection(RoadIntersection * toAdd) {
	QGraphicsRectItem *vert = scene->addRect(toAdd->boundingRect());
	vert->setZValue(1.0f);
	intersectionsRender->addToGroup(vert);
	intersectionsRender->setZValue(1.0f);
}

CityView2D::CityView2D() {
	scene = new QGraphicsScene();

	scene->setBackgroundBrush(QBrush(QColor::fromRgb(100, 100, 100)));
	//Create pens
	roadPen = QPen(QBrush(QColor::fromRgb(50, 50, 50)), 2.0f);
	mainRoadPen = QPen(QBrush(QColor::fromRgb(0, 0, 0)), 4.0f);
}

CityView2D::~CityView2D() {
}
