#include "Goods.h"

void Goods::normalise()
{
	if (amount < 0)
	{
		amount *= -1;
	}
	if (!cost.isPositive())
	{
		cost = cost *  (-1.f);
	}
}

Goods::Goods() : name("NONAME"), date("NODATA"), cost(Money()), amount(0), number("NONUMBER")
{
}

Goods::Goods(std::string _name, std::string _date, Money _cost, 
	int _amount, std::string _number) :
	name(_name), date(_date), cost(_cost), 
	amount(_amount), number(_number)
{
	normalise();
}

void Goods::increaseCostByValue(Money toChange)
{
	cost = cost + toChange;
}

void Goods::reduceCostByValue(Money toChange)
{
	if (cost > toChange)
	{
		cost = cost - toChange;
	}
	/*else
	{
		throw;
	}*/
}

void Goods::increaseAmountByValue(int toChange)
{
	amount = amount + toChange;
}

void Goods::reduceAmountByValue(int toChange)
{
	if (amount > toChange)
	{
		amount = amount - toChange;
	}
	/*else
	{
		throw;
	}*/
}

std::ostream& operator<<(std::ostream& out, const Goods& other)
{
	out << "Name: " << other.name << '\n'
		<< "Data: " << other.date << '\n'
		<< "Cost: " << other.cost << '\n'
		<< "Amount: " << other.amount << '\n'
		<< "Number: " << other.number;
	return out;
}

void Goods::discountByDate(int daysValue)
{
	if (daysValue > 0)
	{
		float totalDiscount = 0.99;
		for (int i = 1; i < daysValue; ++i)
		{
			totalDiscount *= 0.99;
		}
		cost = cost * totalDiscount;
	}
}