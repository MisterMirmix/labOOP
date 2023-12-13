#include "Fraction.h"
int Fraction::gcd(long int a, unsigned short int b)
{
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

void Fraction::reduce()
{
	int a;
	if (this->numerator < 0)
	{
		a = gcd(-1*this->numerator, this->denominator);
	}
	else
	{
		a = gcd(this->numerator, this->denominator);
	}
	this->denominator = this->denominator / a; 
	this->numerator = this->numerator / a;
}

Fraction::Fraction() : numerator(NULL), denominator(NULL)
{

}

Fraction::Fraction(long int n, unsigned short int d) : numerator(n), denominator(d)
{
	this->reduce();
}

long int Fraction::getNumerator() const
{
	return this->numerator;
}

unsigned short int Fraction::getDenominator() const
{
	return this->denominator;
}

void Fraction::setNumerator(long int newNumerator)
{
	this->numerator = newNumerator;
	this->reduce();
}

void Fraction::setDenominator(unsigned short int newDenominator)
{
	this->denominator = newDenominator;
	this->reduce();
}

std::string Fraction::toString() const
{
	std::string out = std::to_string(this->numerator) + "/" + std::to_string(this->denominator);
	return out;
	/*std::cout << this->numerator << "/" << this->denominator << '\n';*/
}

Fraction& Fraction::operator *= (const  Fraction& fracrght)
{
	this->numerator *= fracrght.numerator;
	this->denominator *= fracrght.denominator;
	this->reduce();
	return *this;
}

Fraction Fraction::operator * (const  Fraction& fracrght) const
{
	return Fraction(this->numerator * fracrght.numerator, this->denominator * fracrght.denominator);
}

Fraction& Fraction::operator += (const  Fraction& fracrght)
{
	this->numerator = this->numerator * fracrght.denominator + fracrght.numerator * this->denominator;
	this->denominator *= fracrght.denominator;
	this->reduce();
	return *this;
}

Fraction Fraction::operator + (const  Fraction& fracrght) const
{
	return Fraction(this->numerator * fracrght.denominator + fracrght.numerator * this->denominator, this->denominator*fracrght.denominator);
}

Fraction& Fraction::operator -= (const  Fraction& fracrght)
{
	this->numerator = this->numerator * fracrght.denominator - fracrght.numerator * denominator;
	this->denominator *= fracrght.denominator;
	this->reduce();
	return *this;
}

Fraction Fraction::operator - (const  Fraction& fracrght) const
{
	return Fraction(this->numerator * fracrght.denominator - fracrght.numerator * denominator, this->denominator * fracrght.denominator);
}


bool Fraction::operator == (const  Fraction& fracrght)
{
	return (this->numerator * fracrght.denominator - fracrght.numerator * this->denominator == 0);
}

bool Fraction::operator != (const  Fraction& fracrght)
{
	return !(this->numerator * fracrght.denominator - fracrght.numerator * this->denominator == 0);
}
	
bool Fraction::operator < (const  Fraction& fracrght)
{
	return (this->numerator * fracrght.denominator - fracrght.numerator * this->denominator < 0);
}

bool Fraction::operator > (const  Fraction& fracrght)
{
	return (this->numerator * fracrght.denominator - fracrght.numerator * this->denominator > 0);
}

bool Fraction::operator <= (const  Fraction& fracrght)
{
	return !(this->numerator * fracrght.denominator - fracrght.numerator * this->denominator > 0);
}

bool Fraction::operator >= (const  Fraction& fracrght)
{
	return !(this->numerator * fracrght.denominator - fracrght.numerator * this->denominator < 0);
}
