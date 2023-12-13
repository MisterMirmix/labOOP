#pragma once
#include "Money.h"
#include <string>
//#include <exception>
//Реализовать класс Goods (задание 36), используя для представления цены класс Money из задания 24. 
// Реализовать метод уценки товара, уменьшая цену на 1% за каждый день просрочки срока годности.

//36. Создать класс Goods (товар). 
// В классе должны быть представлены поля: наименование товара, 
// дата оформления, цена товара, количество единиц товара, номер накладной, 
// по которой товар поступил на склад. Реализовать методы изменения цены товара, 
// изменения количества товара (увеличения и уменьшения), вычисления стоимости товара. 
// Метод toString() должен выдавать в виде строки стоимость товара.

class Goods
{
	std::string name;
	std::string date;
	Money cost;
	int amount;
	std::string number;
	friend std::ostream& operator<<(std::ostream& out, const Goods& other);
	void normalise();
public:
	Goods();
	Goods(std::string _name, std::string _date, Money _cost,
		int _amount, std::string _number);
	void increaseCostByValue(Money toChange);
	void reduceCostByValue(Money toChange);
	void increaseAmountByValue(int toChange);
	void reduceAmountByValue(int toChange);
	void discountByDate(int daysValue);
};