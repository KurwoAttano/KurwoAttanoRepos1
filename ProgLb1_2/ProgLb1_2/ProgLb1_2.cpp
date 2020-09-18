// Чечёткин Артур ИВТ-8 Лаба 1 Вариант 6 Часть 2

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void initArray(float* arr, int len){
	float* pointer = arr;
	for (int i = 0; i < 16; i++) {
		*pointer = i * exp(acos(-1.0) * i / 100);
		pointer++;
	}
}

void processArray(float* arr, float fArr[], int iLen, int jLen){
	float* arrPointer = arr;
	float* fArrPointer = fArr;
	for (int j = 0; j < iLen * jLen; j++) {
		*fArrPointer = *arrPointer;
		fArrPointer++;
		arrPointer++;
	}
}

void showArray(float fArr[], int iLen, int jLen){
	float* fArrPointer = fArr;
	for(int i = 0; i < iLen; i++) {
		for (int j = 0; j < jLen; j++) {
			cout << setw(10) << *fArrPointer << " ";
			fArrPointer++;
		}
		cout << "\n";
	}
}

int main()
{
	float primaryArray[16];
	float finalArray[4][4];

	initArray(primaryArray, 16);
	processArray(primaryArray, &finalArray[0][0], 4, 4);
	showArray(&finalArray[0][0], 4, 4);

	return 0;
}