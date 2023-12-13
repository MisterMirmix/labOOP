#pragma once
#include <iostream>
//24. ������� ����� Money ��� ������ � ��������� �������. 
// ����� ������ ���� ������������ ����� ������: 
// ���� Tong ��� ������ � ���� unsigned char - ��� ������. 
// ������� ����� (�������) ��� ������ �� ����� ������ ���� �������� �� ����� ����� �������. 
// ����������� ��������, ���������, ������� ����, ������� ����� �� ������� �����, 
// ��������� �� ������� ����� � �������� ���������.
class Money
{
	int roubles;
	int pennies; //��� �� 0 �� 255
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

