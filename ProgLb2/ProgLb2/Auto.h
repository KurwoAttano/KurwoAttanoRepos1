#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

class Auto
{
public:
	Auto() {
		setFirm("unknown");
		setModel("unknown");
		setNumber("unknown");
		setPrice(0);
		setYear(2000);
		setMileage(0);
	}
	Auto(std::string firm, std::string model, std::string number, int price, int year, int mileage) {
		setFirm(firm);
		setModel(model);
		setNumber(number);
		setPrice(price);
		setYear(year);
		setMileage(mileage);
	}

	void setFirm(std::string firm) { _firm = firm; }
	void setModel(std::string model) { _model = model; }
	void setNumber(std::string number) { _number = number; }
	void setPrice(int price) { _price = price; }
	void setYear(int year) { _year = year; }
	void setMileage(float mileage) { _mileage = mileage; }

	std::string getFirm() { return _firm; }
	std::string getModel() { return _model; }
	std::string getNumber() { return _number; }
	int getPrice() { return _price; }
	int getYear() { return _year; }
	float getMileage() { return _mileage; }

	void Serialize() {
		Serialize("json_data.txt");
	}
	void Serialize(const std::string& filename) {
		string str = "{";
		str += SerialIizeParam("_firm", _firm);
		str += SerialIizeParam("_model", _model);
		str += SerialIizeParam("_number", _number);
		str += SerialIizeParam("_price", _price);
		str += SerialIizeParam("_year", _year);
		str += SerialIizeParam("_mileage", _mileage);
		str += "}";

		remove(filename.c_str());
		std::ofstream write;
		write.open(filename);
		if (write.is_open())
			write << str;
		write.close();
	}

	void Deserialize() {
		Deserialize("json_data.txt");
	}
	void Deserialize(const std::string& filename) {
		string str;
		ifstream read(filename);
		read >> str;
		read.close();

		str.erase(0, 1);
		bool lastIter = false;
		while (true) {
			string paramName;
			string paramValue;

			paramName.assign(str, 1, str.find('"', 1) - 1);
			paramValue.assign(str, str.find(':', 1) + 1, (str.find(',', 1) == UINT_MAX ? str.find('}', 1) : str.find(',', 1)) - str.find(':', 1) - 1);
			str.erase(0, str.find(',', 1) == UINT_MAX ? str.find('}') - 1 : str.find(',') + 1);
			if (lastIter) break;
			if (str.find(',', 1) == UINT_MAX)
				lastIter = true;

			//switch can't work with string
			if (paramName == "_firm") _firm = paramValue;
			else if (paramName == "_model") _model = paramValue;
			else if (paramName == "_number") _number = paramValue;
			else if (paramName == "_price") _price = atoi(paramValue.c_str());
			else if (paramName == "_year") _year = atoi(paramValue.c_str());
			else if (paramName == "_mileage") _mileage = atof(paramValue.c_str());
		}
	}

private:
	std::string _firm = "unknown";
	std::string _model = "unknown";
	std::string _number = "unknown";
	int _price = 0;
	int _year = 0;
	float _mileage = 0;

	template <typename T>
	string SerialIizeParam(string paramName, T paramValue) {
		string str = "";
		str += "\"" + paramName + "\":";
		str += paramValue;
		str += ",";
		return str;
	}
};