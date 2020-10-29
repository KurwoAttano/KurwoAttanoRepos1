#include <iostream>
#include <cmath>
#include <iomanip>
#include "Fraction.h"

using namespace std;

int Fraction::FractionCount = 0;

int main()
{
	cout << "FractionCount: " << Fraction::GetFractionCount() << endl << endl;

	Fraction fract1(12, 24);
	cout << "fract1(12, 24) = " << fract1 << endl;

	Fraction fract2(-3, -14, 5);
	cout << "fract2(3, 14, 5) = " << fract2 << endl;

	Fraction fractInt(5);
	cout << "fractInt(5) = " << fractInt << endl;

	Fraction fractFloat(float(-1.75));
	cout << "fractFloat(1.75) = " << fractFloat << endl;

	Fraction fractDouble(7.55);
	cout << "fractDouble(7.55) = " << fractDouble << endl << endl;

	cout << "fractDouble(7.55) + fract2(-3, -14, 5) = " << fractDouble + fract2 << endl;
	cout << "fractInt(5) + fractFloat(-1.75) = " << fractInt + fractFloat << endl << endl;

	cout << "fract1(12, 24) - fractDouble(7.55) = " << fract1 - fractDouble << endl;
	cout << "fractDouble(7.55) - fractInt(5) = " << fractDouble - fractInt << endl << endl;

	cout << "fractDouble(7.55) * fract2(-3, -14, 5) = " << fractDouble * fract2 << endl;
	cout << "fractFloat(-1.75) * fract1(12, 24) = " << fractFloat * fract1 << endl << endl;

	cout << "fractInt(5) / fract1(12, 24) = " << fractInt / fract1 << endl;
	cout << "fractFloat(-1.75) / fract2(-3, -14, 5) = " << fractFloat / fract2 << endl << endl;

	cout << "gcd(100, 25) = " << Fraction::gcd(100, 50) << endl;
	cout << "gcd(75, 5) = " << Fraction::gcd(75, 25) << endl;
	cout << "gcd(112, 56) = " << Fraction::gcd(112, 56) << endl << endl;

	cout << "PrintAsFraction(0.125) = ";
	Fraction::PrintAsFraction(0.125);
	cout << "PrintAsFraction(0.55) = ";
	Fraction::PrintAsFraction(0.55);
	cout << "PrintAsFraction(0.14) = ";
	Fraction::PrintAsFraction(0.14);

	cout << endl;

	cout << "FractionCount: " << Fraction::GetFractionCount() << endl << endl;

	system("pause");
	return 0;
}