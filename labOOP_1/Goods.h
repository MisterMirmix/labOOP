#pragma once
#include "Money.h"
#include <string>
//#include <exception>
//����������� ����� Goods (������� 36), ��������� ��� ������������� ���� ����� Money �� ������� 24. 
// ����������� ����� ������ ������, �������� ���� �� 1% �� ������ ���� ��������� ����� ��������.

//36. ������� ����� Goods (�����). 
// � ������ ������ ���� ������������ ����: ������������ ������, 
// ���� ����������, ���� ������, ���������� ������ ������, ����� ���������, 
// �� ������� ����� �������� �� �����. ����������� ������ ��������� ���� ������, 
// ��������� ���������� ������ (���������� � ����������), ���������� ��������� ������. 
// ����� toString() ������ �������� � ���� ������ ��������� ������.

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