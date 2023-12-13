#include "FazzyNumber.h"

void FazzyNumber::normilize()
{
	double arr[3] = { *xleft, *x, *xright };
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j+i < 3; ++j)
		{
			if (arr[i] > arr[i + j])
			{
				double a = arr[i];
				arr[i] = arr[i + j];
				arr[i + j] = a;
			}
		}
	}
	*xleft = arr[0];
	*x = arr[1];
	*xright = arr[2];
}

FazzyNumber::~FazzyNumber()
{
	delete xleft;
	delete x;
	delete xright;
}

FazzyNumber::FazzyNumber() : xleft(new double(0)), x(new double(0)), xright(new double(0))
{

}

FazzyNumber::FazzyNumber(const double& xleft = 0, const double& x = 0, const double& xright = 0) 
	: xleft(new double(xleft)), x(new double(x)), xright(new double(xright))
{
	normilize();
}

FazzyNumber::FazzyNumber(const FazzyNumber& other)
{
	xleft = new double;
	*xleft = *other.xleft;
	x = new double;
	*x = *other.x;
	xright = new double;
	*xright = *other.xright;
}

FazzyNumber& FazzyNumber::operator=(const FazzyNumber& other)
{
	*xleft = *other.xleft;
	*x = *other.x;
	*xright = *other.xright;
	return *this;
}

FazzyNumber& FazzyNumber::operator+=(const FazzyNumber& other)
{
	*xleft = *xleft + *other.xleft;
	*x = *x + *other.x;
	*xright = *xright + *other.xright;
	normilize();
	return *this;
}

FazzyNumber FazzyNumber::operator+(const FazzyNumber& other)
{
	return FazzyNumber(*xleft + *other.xleft, *x + *other.x, *xright + *other.xright);
}

FazzyNumber& FazzyNumber::operator-=(const FazzyNumber& other)
{
	*xleft = *xleft - *other.xleft - 2 * (*other.x - *other.xleft); // A-ar-(B-br)-2*(B-(B-br)) = A-ar-B+br-2br
	*xright = *xright - *other.xright - 2 * (*other.x - *other.xright); // A+ar-(B+br)-2*(B-(B+br)) = A+ar-B-br+2br
	*x = *x - *other.x;
	normilize();
	return *this;
}

FazzyNumber FazzyNumber::operator-(const FazzyNumber& other)
{
	return FazzyNumber(*xleft - *other.xleft - 2 * (*other.x - *other.xleft),
		*x - *other.x, *xright - *other.xright - 2 * (*other.x - *other.xright));
}

FazzyNumber& FazzyNumber::operator*=(const FazzyNumber& other)
{
	*xleft = (*xleft) * (*other.xleft);
	*xright = (*xright) * (*other.xright);
	*x = (*x) * (*other.x);
	normilize();
	return *this;
}

FazzyNumber FazzyNumber::operator*(const FazzyNumber& other)
{
	return FazzyNumber((*xleft) * (*other.xleft), (*x) * (*other.x), (*xright) * (*other.xright));
}

FazzyNumber FazzyNumber::inverse() const
{
	return FazzyNumber(1 / (*xright), 1 / (*x), 1 / (*xleft));
}

FazzyNumber& FazzyNumber::operator/=(const FazzyNumber& other)
{
	return (*this *= (other.inverse()));
}

FazzyNumber FazzyNumber::operator/(const FazzyNumber& other)
{
	return FazzyNumber((*xleft)/(*other.xright), (*x) / (*other.x), (*xright) / (*other.xleft));
}

bool FazzyNumber::operator<(const FazzyNumber& other)
{
	return (*xright - *xleft) < (*other.xright - *other.xleft);
}
bool FazzyNumber::operator > (const FazzyNumber& other)
{
	return (*xright - *xleft) > (*other.xright - *other.xleft);
}
bool FazzyNumber::operator <= (const FazzyNumber& other)
{
	return !(*this > other);
}
bool FazzyNumber::operator >= (const FazzyNumber& other)
{
	return !(*this < other);
}

bool FazzyNumber::operator==(const FazzyNumber& other)
{
	return (*xright - *xleft) == (*other.xright - *other.xleft);
}

std::ostream& operator<<(std::ostream& out, const FazzyNumber& other)
{
	out << '(' << *other.xleft << ',' << *other.x << ',' << *other.xright << ')';
	return out;
}

std::istream& operator>>(std::istream& in, FazzyNumber& other)
{
	in >> *other.xleft >> *other.x >> *other.xright;
	return in;
}



