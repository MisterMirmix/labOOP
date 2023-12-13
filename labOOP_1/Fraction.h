#include <string>
#ifndef FRACTION_H
#define FRACTION_H
class Fraction
{
private:
	long int numerator;
	unsigned short int denominator;
	int gcd(long int a, unsigned short int b);
	void reduce();
public:

	Fraction();
	Fraction(long int n, unsigned short int d);
	
	long int getNumerator() const;
	unsigned short int getDenominator() const;
	
	void setNumerator(long int newNumerator);
	void setDenominator(unsigned short int newDenominator);
	
	std::string toString() const;
	
	Fraction& operator *= (const  Fraction& fracrght);
	Fraction operator * (const  Fraction& fracrght) const;
	
	Fraction& operator += (const  Fraction& fracrght);
	Fraction operator + (const  Fraction& fracrght) const;

	Fraction& operator -= (const  Fraction& fracrght);
	Fraction operator - (const  Fraction& fracrght) const;

	bool operator == (const  Fraction& fracrght);
	bool operator != (const  Fraction& fracrght);
	bool operator < (const  Fraction& fracrght);
	bool operator > (const  Fraction& fracrght);
	bool operator <= (const  Fraction& fracrght);
	bool operator >= (const  Fraction& fracrght);

};

#endif