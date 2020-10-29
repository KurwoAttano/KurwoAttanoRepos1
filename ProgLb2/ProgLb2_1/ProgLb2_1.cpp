#include <iostream>
#include <cmath>
#include <iomanip>
#include "Vector.h"
#include "Matrix.h"

using namespace std;

void initArray(Vector& arr) {
	for (int i = 0; i < arr.getLength(); i++)
		arr[i] = i * exp(acos(-1.0) * i / 100);
}

void processArray(Vector& arr, Matrix& fArr) {
	for (int i = 0; i < fArr.getLengthX(); i++)
		for (int j = 0; j < fArr.getLengthY(); j++)
			fArr[i][j] = arr[i * fArr.getLengthX() + j];
}

void showArray1(Vector& arr) {
	cout << "[ ";
	for (int i = 0; i < arr.getLength(); i++)
		cout << setw(10) << arr[i] << " ";
	cout << " ]\n\n";
}

void showArray2(Matrix& fArr) {
	cout << "[ ";
	for (int i = 0; i < fArr.getLengthX(); i++) {
		for (int j = 0; j < fArr.getLengthY(); j++) {
			if (i > 0 && j == 0) cout << "  ";
			cout << setw(10) << fArr[i][j] << " ";
		}
		if (i == fArr.getLengthX() - 1) cout << "]\n\n";
		else cout << endl;
	}
}

int main()
{
	Vector primaryArray(16);
	Matrix finalArray(4, 4);

	initArray(primaryArray);
	processArray(primaryArray, finalArray);
	showArray1(primaryArray);
	showArray2(finalArray);

	system("pause");
	return 0;
}