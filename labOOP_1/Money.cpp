#include "Money.h"

std::ostream& operator<<(std::ostream& out, const Money& other)
{
	if (other.pennies < 10)
	{
		out << other.roubles << ',' <<  '0' << (int)other.pennies;
	}
	else
	{
		out << other.roubles << ',' << (int)other.pennies;
	}
	
	return out;
}

void Money::reduce()
{
	while (pennies > 99)
	{
		pennies -= 100;
		++roubles;
	}
	while (pennies < 0)
	{
		pennies += 100;
		--roubles;
	}
}

Money::Money() : roubles(0), pennies(0)
{

}

Money::Money(int r, int p) : roubles(r), pennies(p)
{
	reduce();
}

Money::Money(const Money& other) : roubles(other.roubles), pennies(other.pennies)
{

}

Money Money::operator+(const Money& other)
{
	return Money(roubles + other.roubles, pennies + other.pennies);
}

Money Money::operator-(const Money& other)
{
	return Money(roubles - other.roubles, pennies - other.pennies);
}

Money Money::operator*(const float& other)
{
	float money = roubles + pennies / 100.f;
	money *= other;
	if (money > 0)
	{
		return Money((int)money, (int)(money * 100) % 100);
	}
	else
	{
		return Money((int)money, -(int)(money * 100) % 100);
	}
}

//Money Money::operator*(const Money& other)
//{
//	float otherMoney = other.roubles + other.pennies / 100.f;
//	return *this * otherMoney;
//}

Money Money::operator/(const float& other)
{
	float money = roubles + pennies / 100.f;
	money /= other;
	if (money > 0)
	{
		return Money((int)money, (int)(money * 100) % 100);
	}
	else
	{
		return Money((int)money, -(int)(money * 100) % 100);
	}
}

//Money Money::operator/(const Money& other)
//{
//	float otherMoney = other.roubles + other.pennies / 100.f;
//	return *this / otherMoney;
//}

bool Money::operator<(const Money& other)
{
	return (roubles < other.roubles || roubles == other.roubles && pennies < other.pennies);
}

bool Money::operator<=(const Money& other)
{
	return !(*this > other);
}

bool Money::operator>(const Money& other)
{
	return (roubles > other.roubles || roubles == other.roubles && pennies > other.pennies);
}

bool Money::operator>=(const Money& other)
{
	return !(*this < other);
}

bool Money::operator==(const Money& other)
{
	return (pennies == other.pennies && roubles == other.roubles);
}

bool Money::operator!=(const Money& other)
{
	return !(*this == other);
}

bool Money::isPositive()
{
	return (roubles > 0);
}

