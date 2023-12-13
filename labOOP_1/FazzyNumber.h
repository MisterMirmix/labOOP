#ifndef FAZZYNUMBER_H
#define FAZZYNUMBER_H
#include <iostream>
class FazzyNumber
{
	
	double* xleft; //x-el
	double* x;
	double* xright; //x+er
	void normilize();
	friend std::ostream& operator << (std::ostream& out, const FazzyNumber& other);
	friend std::istream& operator >> (std::istream& in, FazzyNumber& other);
public:
	FazzyNumber();
	~FazzyNumber();
	FazzyNumber(const double& xleft,const double& x,const double& xright);
	FazzyNumber (const FazzyNumber& other);
	FazzyNumber& operator = (const FazzyNumber& other);
	FazzyNumber& operator += (const FazzyNumber& other);
	FazzyNumber operator + (const FazzyNumber& other);
	FazzyNumber& operator -= (const FazzyNumber& other);
	FazzyNumber operator - (const FazzyNumber& other);
	FazzyNumber& operator *= (const FazzyNumber& other);
	FazzyNumber operator * (const FazzyNumber& other);
	FazzyNumber inverse() const;
	FazzyNumber& operator /= (const FazzyNumber& other);
	FazzyNumber operator / (const FazzyNumber& other);
	bool operator < (const FazzyNumber& other);
	bool operator > (const FazzyNumber& other);
	bool operator <= (const FazzyNumber& other);
	bool operator >= (const FazzyNumber& other);
	bool operator == (const FazzyNumber& other);
};
#endif