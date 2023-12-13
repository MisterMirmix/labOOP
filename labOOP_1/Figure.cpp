#include "Figure.h"

const double PI = 3.14;
const double E = 0.00001;

///Point

Point::Point() : x(0.), y(0.)
{
}
Point::Point(double nx, double ny) : x(nx), y(ny)
{
}
double Point::getX() const
{
	return x;
}
double Point::getY() const
{
	return y;
}
double Point::getDistance(const Point& other) const
{
	return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
}

///Line
Line::Line() : p1(), p2()
{

}

Line::Line(Point np1, Point np2) : p1(np1), p2(np2)
{

}

Point Line::getP1() const
{
	return p1;
}

Point Line::getP2() const
{
	return p2;
}

double Line::getLength() const
{
	return p1.getDistance(p2);
}

bool Line::isParallel(const Line& other)
{
	Point vec1 = Point(p1.getX() - p2.getX(), p1.getY() - p2.getY());
	Point vec2 = Point(other.p1.getX() - other.p2.getX(), other.p1.getY() - other.p2.getY());

	return abs(vec1.getX() * vec2.getY() - vec2.getX() * vec1.getY()) <= E;
}

///Figure
Figure::Figure() : p(nullptr), size(0)
{

}

Figure::Figure(Point* np, int nsize) : p(new Point[nsize]), size(nsize)
{
	for (int i = 0; i < nsize; ++i)
	{
		p[i] = np[i];
	}
}

Figure::Figure(const Figure& other)
{
	size = other.size;
	for (int i = 0; i < size; ++i)
	{
		p[i] = other.p[i];
	}
}

Figure& Figure::operator=(const Figure& other)
{
	for (int i = 0; i < size; ++i)
	{
		p[i] = other.p[i];
	}
	return *this;
}

Figure::~Figure()
{
	delete[] p;
}


///Circle
Circle::Circle() : Figure(), r(0.)
{

}

Circle::Circle(double nR, Point* np) : Figure(np, 1), r(nR)
{

}

double Circle::getP() const
{
	return 2*PI*r;
}

double Circle::getS() const
{
	return PI*r*r;
}

std::string Circle::getType() const
{
	return "CIRCLE";
}


///Triangle
Triangle::Triangle() :
distance12(0),
distance23(0),
distance31(0)
{
}

Triangle::Triangle(Point* np) : Figure(np, 3),
distance12(np[0].getDistance(np[1])),
distance23(np[1].getDistance(np[2])),
distance31(np[2].getDistance(np[0]))
{
}

double Triangle::getP() const
{
	return distance12 + distance23 + distance31;
}

double Triangle::getS() const
{
	double P = getP() / 2.;
	return sqrt(P * (P-distance12) * (P - distance23) * (P - distance31));
} 

std::string Triangle::getType() const
{
	return "TRIANGLE";
}

///Trapezium
Trapezium::Trapezium()
{

}

Trapezium::Trapezium(Point* np) : Figure(np, 4)
{

}

double Trapezium::getP() const
{
	if (p != nullptr)
	{
		return p[0].getDistance(p[1]) + p[1].getDistance(p[2]) + p[2].getDistance(p[3]) + p[0].getDistance(p[3]);
	}
	return 0;
}

double Trapezium::getS() const
{
	if (p != nullptr)
	{
		try {
			Line* l = getParallelLines();
			double result;
			Point p01 = l[0].getP1();
			Point p02 = l[0].getP2();
			Point p11 = l[1].getP1();
			Point p12 = l[1].getP2();
			if (p01.getDistance(p11) >= p01.getDistance(p12))
			{
				Point t1[3] = { p01, p02, p11 };
				Point t2[3] = { p01, p12, p11 };
				result = Triangle(t1).getS() + Triangle(t2).getS();
			}
			else
			{
				Point t1[3] = { p01, p02, p12 };
				Point t2[3] = { p01, p11, p12 };
				result = Triangle(t1).getS() + Triangle(t2).getS();
			}
			delete[] l;
			return result;
		}
		catch (const char* msg)
		{
			std::cerr << msg << '\n';
		}
	}
	return 0;
}

std::string Trapezium::getType() const
{
	return "TRAPEZIUM";
}

Line* Trapezium::getParallelLines() const
{
	Line* lines = new Line[2];
	Line l1{ p[0], p[1] };
	Line l2{ p[1], p[2] };
	Line l3{ p[2], p[3] };
	Line l4{ p[3], p[0] };

	if (l1.isParallel(l3))
	{
		lines[0] = l1;
		lines[1] = l3;
	}
	else
	{
		if (l2.isParallel(l4))
		{
			lines[0] = l2;
			lines[1] = l4;
		}
		else
		{
			throw "IT'S NOT TRAPEZIUM!!";
		}
	}
	return lines;
}

