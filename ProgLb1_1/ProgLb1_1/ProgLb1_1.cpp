// Чечёткин Артур ИВТ-8 Лаба 1 Вариант 6 Часть 1

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
	cout << "Final Array: [";
	for (int i = 0; i < amount; i++) {
		cout << finalArray[i] << " ";
	}
	cout << "] \n";

	delete [] finalArray;
	delete [] suitable;
	return amount;
}

int main()
{
	float primaryArray[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	int A, B;
	
	cout << "Enter two nums (A < 0, B > 0)\n";
	cout << "A = -";
	cin >> A;
	cout << "B = ";
	cin >> B;
	cout << "\n";
	
	cout << "Array Length: " << processArray(primaryArray, 15, A, B) << "\n\n";
}