#pragma once
#include <string>

class Auto
{
public:
	Auto();
	Auto(std::string firm, std::string model, std::string number, int price, int year, int mileage);

	void setFirm(std::string firm);
	void setModel(std::string model);
	void setNumber(std::string number);
	void setPrice(int price);
	void setYear(int year);
	void setMileage(float mileage);

	std::string getFirm();
	std::string getModel();
	std::string getNumber();
	int getPrice();
	int getYear();
	float getMileage();

private:
	std::string _firm;
	std::string _model;
	std::string _number;
	int _price;
	int _year;
	float _mileage;
};