// �������� ����� ���-8 ���� 1 ������� 6 ����� 1

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int processArray(float* arr, int len, int A, int B) {

	// ���-�� ���������� ��������� �������
	int amount = 0;

	// ��������� �������� ������� �� ������
	srand(time(0));
	for (int i = 0; i < len; i++)
		if (i % 2 == 0) { // ���� ������ ������
			int R = (rand() % (abs(A) + B + 1)) - A;
			arr[i] *= R;
		}

	// ���������� ���-�� � ������� ��������. �����
	bool* suitable = new bool[len];
	for (int i = 0; i < len; i++) {
		if (abs(arr[i]) >= 10 && abs(arr[i]) < 100) { // ���� ����������
			suitable[i] = true;
			amount++;
		}
		else {
			suitable[i] = false;
		}
	}
	
	// ��������� �������� ������
	float* finalArray = new float[amount];
	int j = 0;
	for (int i = 0; i < len; i++) {
		if (suitable[i] == true) {
			finalArray[j] = arr[i];
			j++;
		}
	}

	// ������� �������� ������
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