#pragma once
#include <iostream>

class Pair
{
	friend std::ostream& operator<< (std::ostream& out, const Pair& other);
protected:
	int left;
	int right;
public:
	Pair();
	Pair(int nLeft, int nRight);
	int getLeft() const;
	int getRight() const;
	Pair operator+(const Pair& other);
	Pair operator-(const Pair& other);
};

class Complex :
	public Pair
{
	friend std::ostream& operator<< (std::ostream& out, const Complex& other);
public:
	Complex();
	Complex(int nLeft, int nRight);
	Complex conjurate() const;
	Complex operator+(const Complex& other);	
	Complex operator-(const Complex& other);
	Complex operator* (const Complex& other);
	Complex operator/ (const Complex& other);	
};

