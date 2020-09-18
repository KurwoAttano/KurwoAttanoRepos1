// Чечёткин Артур ИВТ-8 Лаба 1 Вариант 6 Часть 3

#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

int getLength(char text[]) {
	int arrayLength = 0;
	for (int i = 0; text[i]; i++)
		arrayLength++;
	return arrayLength;
}

void myStrncpy(char* finArr, char* arr, int len) {
	int cutLen = len;
	int finArrLen = getLength(finArr);
	int arrLen = getLength(arr);
	
	if (cutLen > finArrLen)
		cutLen = finArrLen;
	else if (cutLen > arrLen)
		cutLen = arrLen;

	for (int i = 0; i < finArrLen; i++)
		if (i < cutLen)
			finArr[i] = arr[i];
		else
			finArr[i] = ' ';
}

int main() {
	char word[64];
	int count;

	cout << "Enter text: ";
	cin.getline(word, 64);
	cout << "Enter copy lenght: ";
	cin >> count; 
	cout << endl;

	cout << "strncpy: ";
	char* finalWord1 = new char[count];
	strncpy(finalWord1, word, count);
	for (int i = 0; i < count; i++) cout << finalWord1[i];
	cout << "\n\n";

	cout << "myStrncpy: ";
	char* finalWord2 = new char[count];
	myStrncpy(finalWord2, word, count);
	for (int i = 0; i < count; i++) cout << finalWord2[i];
	cout << "\n\n";

	delete[] finalWord1, finalWord2;
	return 0;
}