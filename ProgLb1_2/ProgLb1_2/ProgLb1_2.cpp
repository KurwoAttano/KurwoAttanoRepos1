// Чечёткин Артур ИВТ-8 Лаба 1 Вариант 6 Часть 2

#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>

using namespace std;

void initArray(float* arr, int len){
	for(int i = 0; i < 16; i++)
		arr[i] = i * exp(acos(-1.0) * i / 100);
}

void processArray(float* arr, float fArr[], int iLen, int jLen){
	for(int i = 0; i < iLen; i++) {
		for (int j = 0; j < jLen; j++) {
			fArr[i * iLen + j] = arr[i * jLen + j];
		}
	}
}

void showArray(float fArr[], int iLen, int jLen){
	for(int i = 0; i < iLen; i++) {
		for (int j = 0; j < jLen; j++) {
			cout <<setw(10)<< fArr[i * iLen + j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	float* primaryArray = new float[16];
	
	float** finalArray = new float*[4];
	for (int i = 0; i < 4; i++)
		finalArray[i] = new float[4];

	initArray(primaryArray, 16);
	processArray(primaryArray, &finalArray[0][0], 4, 4);
	showArray(&finalArray[0][0], 4, 4);

	delete [] primaryArray;
	for (int i = 0; i < 4; i++) 
		delete [] finalArray[i];
	delete [] finalArray;
}