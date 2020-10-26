#include "Auto.h"

Auto::Auto() {
	setFirm("unknown");
	setModel("unknown");
	setNumber("unknown");
	setPrice(0);
	setYear(2000);
	setMileage(0);
}
Auto::Auto(std::string firm, std::string model, std::string number, int price, int year, int mileage) {
	setFirm(firm);
	setModel(model);
	setNumber(number);
	setPrice(price);
	setYear(year);
	setMileage(mileage);
}

void Auto::setFirm(std::string firm) {
	_firm = firm;
}
void Auto::setModel(std::string model) {
	_model = model;
}
void Auto::setNumber(std::string number) {
	_number = number;
}
void Auto::setPrice(int price) {
	_price = price;
}
void Auto::setYear(int year) {
	_year = year;
}
void Auto::setMileage(float mileage) {
	_mileage = mileage;
}


std::string Auto::getFirm() {
	return _firm;
}
std::string Auto::getModel() {
	return _model;
}
std::string Auto::getNumber() {
	return _number;
}
int Auto::getPrice() {
	return _price;
}
int Auto::getYear() {
	return _year;
}
float Auto::getMileage() {
	return _mileage;
}