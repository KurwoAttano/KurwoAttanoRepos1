#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Fraction{
public:
	Fraction(int numerator, int denominator) {
		SetToZero();
		FractionCount++;
		_numerator = abs(numerator);
		_denominator = abs(denominator);
		if (numerator < 0) _positive = !_positive;
		if (denominator < 0) _positive = !_positive;
	}
	Fraction(int integer, int numerator, int denominator) {
		SetToZero();
		FractionCount++;
		_integer = abs(integer);
		_numerator = abs(numerator);
		_denominator = abs(denominator);
		if (integer < 0) _positive = !_positive;
		if (numerator < 0) _positive = !_positive;
		if (denominator < 0) _positive = !_positive;
	}
	Fraction(int fractional) {
		SetToZero();
		FractionCount++;
		_integer = abs(fractional);
		if (fractional < 0) _positive = false;
	}
	Fraction(double fractional) {
		SetToZero();
		FractionCount++;
		ConvertToFraction(abs(fractional));
		if (fractional < 0) _positive = false;
	}
	
	int GetInt() {
		if (_numerator > 0)
			return int((_integer + double(_numerator) / _denominator) * (_positive == false ? -1 : 1));
		else
			return _integer * (_positive == false ? -1 : 1);
	}
	double GetDouble() {
		if (_numerator > 0)
			return (_integer + double(_numerator) / _denominator) * (_positive == false ? -1 : 1);
		else
			return _integer * (_positive == false ? -1 : 1);
	}

	void Reduce() {
		Reduce(GetDouble());
	}

	static int gcd(int n, int m) {
		long nod = 1L;
		for (long i = n > m ? m : n; i > 0; i--)
			if (n % i == 0 && m % i == 0) {
				nod = i;
				break;
			}
		return nod;
	}

	static void PrintAsFraction(double decimal_fraction) {
		int value = abs(decimal_fraction);
		bool positive = true;
		int integer = 0;
		int numerator = 0;
		int denominator = 0;
		int fractLength = 0;
		int n_2 = 0;
		int n_5 = 0;
		int temp;

		if (decimal_fraction < 0) positive = false;
		integer = abs(decimal_fraction);

		do {
			fractLength++;
			long p = pow(10, fractLength);
			temp = abs(decimal_fraction) * p;
		} while (temp % 10 != 0);
		temp /= 10;
		fractLength--;
		numerator = temp - integer * pow(10, fractLength);

		if (fractLength > 0) {
			while (numerator % 2 == 0) {
				n_2++;
				numerator /= 2;
			}
			while (numerator % 5 == 0) {
				n_5++;
				numerator /= 5;
			}
			denominator = pow(10, fractLength) / (pow(2, n_2) * pow(5, n_5));
		}

		if (!positive)
			cout << '-';
		if (integer != 0) {
			cout << integer;
			if (numerator != 0)
				cout << " ";
		}
		if (numerator != 0)
			cout << numerator <<
			'/' << denominator << endl;
	}
	static void PrintAsFraction(char* decimal_fraction) {
		PrintAsFraction(atof(decimal_fraction));
	}

	static int FractionCount; //!
	static int GetFractionCount() {
		return FractionCount;
	}

	// Plus
	Fraction operator + (Fraction value) {
		return Fraction(GetDouble() + value.GetDouble());
	}
	template <typename T>
	Fraction operator + (T value) {
		return Fraction(GetDouble() + value);
	}

	// Minus
	Fraction operator - (Fraction value) {
		return Fraction(GetDouble() - value.GetDouble());
	}
	template <typename T>
	Fraction operator - (T value) {
		return Fraction(GetDouble() - value);
	}

	// Multiply
	Fraction operator * (Fraction value) {
		return Fraction(GetDouble() * value.GetDouble());
	}
	template <typename T>
	Fraction operator * (T value) {
		return Fraction(GetDouble() * value);
	}

	// Divide
	Fraction operator / (Fraction value) {
		return Fraction(GetDouble() / value.GetDouble());
	}
	template <typename T>
	Fraction operator / (T value) {
		return Fraction(GetDouble() / value);
	}

	friend ostream& operator << (ostream& os, const Fraction& value) {
		if (!value._positive) 
			cout << '-';
		if (value._integer != 0) {
			os << value._integer;
			if (value._numerator != 0)
				os << " ";
		}
		if (value._numerator != 0)
			os << value._numerator << 
			'/' << value._denominator;
		return os;
	}

private:
	bool _positive = true;
	int _integer = 0;
	int _numerator = 0;
	int _denominator = 0;

	/*
				 numenator
		integer -----------
				denominator
	*/

	void ConvertToFraction(double value) {
		Reduce(value);
	}

	void Reduce(double value) {
		int fractLength = 0;
		int n_2 = 0;
		int n_5 = 0;
		int temp;

		if (value < 0) _positive = false;
		_integer = abs(value);

		do {
			fractLength++;
			long p = pow(10, fractLength);
			temp = abs(value) * p;
		} while (temp % 10 != 0);
		temp /= 10;
		fractLength--;
		_numerator = temp - _integer * pow(10, fractLength);

		if (fractLength > 0) {
			while (_numerator % 2 == 0) {
				n_2++;
				_numerator /= 2;
			}
			while (_numerator % 5 == 0) {
				n_5++;
				_numerator /= 5;
			}
			_denominator = pow(10, fractLength) / (pow(2, n_2) * pow(5, n_5));
		}
	}

	void SetToZero() {
		_positive = true;
		_integer = 0;
		_numerator = 0;
		_denominator = 0;
	}
};