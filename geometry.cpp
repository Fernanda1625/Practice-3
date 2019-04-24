//Ejercicio 4.2

#include "geometry.h"

PointArray::PointArray(){
	size=0;
	points=new Point[0];
}

PointArray::PointArray(const Point ptsToCop[], const int toCopySize){
	size=toCopySize;
	points=new Point [toCopySize];
	for(int i=0; i<toCopySize;++i){
		point[i]=ptsToTopy[i];
	}
}

PointArray::PointArray(const PointArray &other){
	size=other.size;
	points=new Point [size];
	for(int i=0;i<size;i++){
		points[i]=other.points[i];
	}
}

PointArray::~PointArray(){
	delete[] points;
}

void PointArray::resize (int newSize){
	Point *pts = new Point [newSize];
	int minSize = (newSize>size ? size :newSize);
	for (int i=0;i<minSize;i++){
		pts[i]=points[i];
	}
	delete[] points;
	size=newSize;
	points=pts;
}

void PointArray::clear(){
	resize(0);
}

void PointArray::push_back(const Point &p){
	resize(size + 1);
	points[size-1]=p;
}

void PointArray::insert(const int pos, const Point &p){
	resize(size+1);
	for (int i=size-1; i>pos; i--){
		points[i]=points[i-1];
	}
	
	points[pos]=p;
}

void PointArray::remove(const int pos){
	if(pos>=0 && pos<size){
		for(int i=pos; i<size-2; i++){
			points[i] =points[i+1];
		}
		resize(size-1);
	}
}

Point *PointArray::get(const int pos){
	return pos>=0 && pos< size ? points + pos : NULL;
}

const Point *PointArray::get(const int pos) const {
	return pos>=0 && pos < size ? point + pos : NULL;
}
	}

//Ejercicio 5.1.2

int Polygon::n = 0;

Polygon::Polygon(const PointArray &pa) : points(pa){
	++numPolygons;
}

Polygon::Polygon(const Point pointArr[], const int numPoints): points (pointArr, numPoints){
	++numPolygons;
}

//Ejercicio 5.2.2

Point constructorPoints[4];

Point *updateConstructorPoints (const Point &p1, const Point &p2, const Point &p3, const Point &p4 = Point (0,0)){
	constructorPoints[0] = p1;
	constructorPoints[1] = p2;
	constructorPoints[2] = p3;
	constructorPoints[3] = p4;
	return constructorPoints;
}

Rectangle::Rectangle(const Point &11, const Point &ur):Polygon(updateConstructorPoints(11, Point(11.getX(),ur.getY())), ur, Point(ur.getX(), 11.getY()), 4){}

Rectangle::Rectangle(const int
