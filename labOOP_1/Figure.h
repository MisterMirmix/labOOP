#pragma once
#include <string>
#include <cmath>
#include <exception>
#include <iostream>
class Point
{
	double x;
	double y;
public:
	Point();
	Point(double nx, double ny);
	double getX() const;
	double getY() const;
	double getDistance(const Point& other) const;
};

class Line
{
	Point p1;
	Point p2;
public:
	Line();
	Line(Point np1, Point np2);
	Point getP1() const;
	Point getP2() const;
	double getLength() const;
	bool isParallel(const Line& other);
};


class Figure
{
protected:
	Point* p;
	int size;
public:
	Figure();
	Figure(Point* np, int size);
	Figure(const Figure& other);
	Figure& operator = (const Figure& other);
	~Figure();
	virtual double getS() const = 0;
	virtual double getP() const = 0;
	virtual std::string getType() const = 0;

};

class Circle : public Figure
{
	double r;
public:
	Circle();
	Circle(double nR, Point* np);
	double getP() const override;
	double getS() const override;
	std::string getType() const override;

};

class Triangle : public Figure
{
	double distance12;
	double distance23;
	double distance31;
public:
	Triangle();
	Triangle(Point* np);
	double getP() const override;
	double getS() const override;
	std::string getType() const override;
};

class Trapezium : public Figure
{
	Line* getParallelLines() const;
public:
	Trapezium();
	Trapezium(Point* np);
	double getP() const override;
	double getS() const override;
	std::string getType() const override;
};