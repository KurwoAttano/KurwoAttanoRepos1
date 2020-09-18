// Чечёткин Артур ИВТ-8 Лаба 1 Вариант 6 Часть 3

#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

void myStrncpy(char* finArr, char* arr, int len) {

	for (int i = 0; i < len; i++)
		finArr[i] = arr[i];
}

int main() {
	char word[11] = {'C','h','e','c','h','e','t','k','i','n'};
	char* wordLink = &(word[6]);
	cout << wordLink << "\n";
	int const count = 5;

	cout << "strncpy: ";
	char finalWord1[count];
	strncpy(finalWord1, word, count);
	for (int i = 0; i < count; i++) cout << finalWord1[i];
	cout << "\n\n";

	cout << "myStrncpy: ";
	char finalWord2[count];
	myStrncpy(finalWord2, word, count);
	for (int i = 0; i < count; i++) cout << finalWord2[i];
	cout << "\n\n";
}