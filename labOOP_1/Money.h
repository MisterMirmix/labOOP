#pragma once
#include <iostream>
//24. Создать класс Money для работы с денежными суммами. 
// Число должно быть представлено двумя полями: 
// типа Tong для рублей и типа unsigned char - для копеек. 
// Дробная часть (копейки) при выводе на экран должна быть отделена от целой части запятой. 
// Реализовать сложение, вычитание, деление сумм, деление суммы на дробное число, 
// умножение на дробное число и операции сравнения.
class Money
{
	int roubles;
	int pennies; //это от 0 до 255
	void reduce();
	friend std::ostream& operator<<(std::ostream& out, const Money& other);
public:
	Money();
	Money(int r, int p);
	Money(const Money& other);
	Money operator+(const Money& other);
	Money operator-(const Money& other);
	/*Money operator*(const Money& other);*/
	Money operator*(const float& other);
	/*Money operator/(const Money& other);*/
	Money operator/(const float& other);
	bool operator<(const Money& other);
	bool operator<=(const Money& other);
	bool operator>(const Money& other);
	bool operator>=(const Money& other);
	bool operator==(const Money& other);
	bool operator!=(const Money& other);
	bool isPositive();
};

