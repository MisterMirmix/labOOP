#include "Pair.h"

//PAIR

Pair::Pair() : left(0), right(0)
{

}

Pair::Pair(int a, int b) : left(a), right(b)
{

}

int Pair::getLeft() const
{
    return left;
}

int Pair::getRight() const
{
    return right;
}

Pair Pair::operator+(const Pair& other)
{
    return Pair(left + other.left, right+other.right);
}

Pair Pair::operator-(const Pair& other)
{
    return Pair(left - other.left, right - other.right);
}

std::ostream& operator<<(std::ostream& out, const Pair& other) 
{
    out << '(' << other.left << ',' << ' ' << other.right << ')';
    return out;
}

//COMPLEX

std::ostream& operator<<(std::ostream& out, const Complex& other)
{
    out << '(' << other.left << " + " << other.right << 'i' << ')';
    return out;
}

Complex::Complex()
{

}

Complex::Complex(int nLeft, int nRight) : Pair(nLeft, nRight)
{

}

Complex Complex::conjurate() const
{
    return Complex(left, (-1)*right);
}

Complex Complex::operator+(const Complex& other)
{
    Pair x = Pair(*this) + other;
    return Complex(x.getLeft(), x.getRight());
}

Complex Complex::operator-(const Complex& other)
{
    Pair x = Pair(*this) - other;
    return Complex(x.getLeft(), x.getRight());
}

Complex Complex::operator*(const Complex& other)
{
    return Complex(left * other.left - right * other.right, left * other.right + other.left * right);
}

Complex Complex::operator/(const Complex& other)
{
    Complex a = (*this * other.conjurate());
    int div = other.left * other.left + other.right * other.right;
    return Complex(a.getLeft() / div, a.getRight() / div);
}


