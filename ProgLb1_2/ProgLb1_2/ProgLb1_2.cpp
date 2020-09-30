// Чечёткин Артур ИВТ-8 Лаба 1 Вариант 6 Часть 2

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void initArray(float* arr, int len){
	for (int i = 0; i < len; i++)
		*(arr + i) = i * exp(acos(-1.0) * i / 100);
}

void processArray(float* arr, float** fArr, int iLen, int jLen){
	for (int i = 0; i<iLen; i++)
	    for (int j = 0; j < jLen; j++)
			*(*(fArr + i) + j) =  *(arr + i + j);
}

void showArray1(float* arr, int len){
	cout << "[ ";
	for (int i = 0; i < len; i++)
		cout << setw(10) << *(arr + i) << " ";
	cout << " ]\n\n";
}

void showArray2(float** fArr, int iLen, int jLen){
	cout << "[ ";
	for(int i = 0; i < iLen; i++) {
		for (int j = 0; j < jLen; j++) {
			if (i > 0 && j == 0) cout << "  ";
			cout << setw(10) << *(*(fArr + i)+j) << " ";
		}
		if (i == iLen - 1) cout << "]\n\n";
		else cout << endl;
	}
}

void DeleteArrays(float* arr,float** fArr, int size){
    delete[] arr;
	for (int i = 0; i < size; i++)
		delete[] fArr[i];
	delete[] fArr;
}

int main()
{
	float* primaryArray = new float[16];
	float** finalArray = new float*[4];
	for (int i = 0; i < 4; i++)
		finalArray[i] = new float[4];

	initArray(primaryArray, 16);
	processArray(primaryArray, finalArray, 4, 4);
	showArray1(primaryArray, 16);
	showArray2(finalArray, 4, 4);

	DeleteArrays(primaryArray, finalArray, 4);

	system("pause");
	return 0;
}