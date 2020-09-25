// Чечёткин Артур ИВТ-8 Лаба 1 Вариант 6 Часть 1

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int processArray(float* arr, int len, int A, int B) {

	// кол-во подходящих элементов массива
	int amount = 0;

	// домножаем элементы массива на рандом
	srand(time(0));
	for (int i = 0; i < len; i++)
		if (i % 2 == 0) { // если четный индекс
			int R = (rand() % (abs(A) + B + 1)) - A;
			arr[i] *= R;
		}

	// определяем кол-во и позиции двузначн. чисел
	bool* suitable = new bool[len];
	for (int i = 0; i < len; i++) {
		if (abs(arr[i]) >= 10 && abs(arr[i]) < 100) { // если двузначное
			suitable[i] = true;
			amount++;
		}
		else {
			suitable[i] = false;
		}
	}
	
	// формируем выходной массив
	float* finalArray = new float[amount];
	int j = 0;
	for (int i = 0; i < len; i++) {
		if (suitable[i] == true) {
			finalArray[j] = arr[i];
			j++;
		}
	}

	// выводим выходной массив
	printf("%s", "Final Array: [");
	for (int i = 0; i < amount; i++) {
		printf("%.0f", finalArray[i]);
		if (i < amount - 1) 
			printf("%s", " ");
	}
	printf("%s", "]\n");

	delete [] finalArray;
	delete [] suitable;
	return amount;
}

int main()
{
	float primaryArray[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int A, B;
	
	printf("%s", "Enter two nums (A < 0, B > 0)\n");
	printf("%s", "A = -");
	scanf("%d", &A);
	fflush(stdin);
	printf("%s", "B = ");
	scanf("%d", &B);
	fflush(stdin);
	printf("%s", "\n");

	int amount = processArray(primaryArray, 15, A, B);

	printf("%s", "Array Length: ");
	printf("%d", amount);
	printf("%s", "\n\n");

	system("pause");
	return 0;
}