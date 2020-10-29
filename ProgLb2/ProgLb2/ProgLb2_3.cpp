#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "Auto.h"

using namespace std;

void GoRide(Auto* myAuto, int index, int distance) {
	myAuto[index].setMileage(myAuto[index].getMileage() + distance);
	cout << "a trip to the " << distance << " km" << endl;
	cout << "Current mileage: " << myAuto[index].getMileage() << endl;
}
void GoRide(Auto* myAuto, int distance) {
	GoRide(myAuto, 0, distance);
}

int getRand(int min, int max) {
	return min + rand() % max;
}

void Sort(Auto* arr, int len) {
	int isFrom2014_Count = 0;
	for (int i = 0; i < len; i++)
		if (arr[i].getYear() >= 2014) 
			isFrom2014_Count++;

	Auto* from2014 = new Auto[isFrom2014_Count];
	Auto* before2014 = new Auto[len - isFrom2014_Count];

	int iter1 = 0;
	int iter2 = 0;
	for (int i = 0; i < len; i++)
		if (arr[i].getYear() >= 2014) {
			from2014[iter1] = arr[i];
			iter1++;
		} else {
			before2014[iter2] = arr[i];
			iter2++;
		}

	int j = 0;
	Auto* temp = new Auto;
	for (int i = 0; i < isFrom2014_Count; i++) {
		j = i;
		for (int k = i; k < isFrom2014_Count; k++)
			if (from2014[j].getMileage() > from2014[k].getMileage())
				j = k;
		*temp = from2014[i];
		from2014[i] = from2014[j];
		from2014[j] = *temp;
	}
	j = 0;
	for (int i = 0; i < len - isFrom2014_Count; i++) {
		j = i;
		for (int k = i; k < len - isFrom2014_Count; k++)
			if (before2014[j].getMileage() > before2014[k].getMileage())
				j = k;
		*temp = before2014[i];
		before2014[i] = before2014[j];
		before2014[j] = *temp;
	}

	Auto* newArr = new Auto[len];
	for (int i = 0; i < len; i++)
		if (i < isFrom2014_Count)
			newArr[i] = from2014[i];
		else
			newArr[i] = before2014[i - (len - isFrom2014_Count)];

	for (int i = 0; i < len; i++)
		arr[i] = newArr[i];

	delete[] from2014;
	delete[] before2014;
	delete[] newArr;
	delete temp;
}

int main()
{
	Auto mainAuto[3];
	
	mainAuto[0].setFirm("Audi");
	mainAuto[0].setModel("TT");
	mainAuto[0].setNumber("AP123P");
	mainAuto[0].setPrice(200000);
	mainAuto[0].setYear(2009);
	mainAuto[0].setMileage(110250);

	mainAuto[1].setFirm("VAZ");
	mainAuto[1].setModel("21051");
	mainAuto[1].setNumber("E079AK");
	mainAuto[1].setPrice(39000);
	mainAuto[1].setYear(1994);
	mainAuto[1].setMileage(279115);

	mainAuto[2].setFirm("Bugatti");
	mainAuto[2].setModel("Chiron");
	mainAuto[2].setNumber("AA001A");
	mainAuto[2].setPrice(999999999);
	mainAuto[2].setYear(2018);
	mainAuto[2].setMileage(150);

	Auto* anotherAuto = new Auto("BMW", "M5", "XX666X", 920000, 2016, 45034);

	Auto* autos = new Auto[4];
	for (int i = 0; i < 3; i++)
		autos[i] = mainAuto[i];
	autos[3] = *anotherAuto;

	srand(time(0));

	for (int i = 0; i < 4; i++) {
		cout << "Car: " << autos[i].getFirm() << " " << autos[i].getModel() << " " << autos[i].getNumber() << endl;
		cout << "Current mileage: " << autos[i].getMileage() << endl << endl;
		GoRide(autos, 0, getRand(100, 800));
		GoRide(autos, 0, getRand(100, 800));
		GoRide(autos, 0, getRand(100, 800));
		cout << endl;
	}

	cout << "Serialize example:" << endl;
	mainAuto[0].setFirm("Serizlized_Audi");
	cout << "Set firm: Serialized_Audi" << endl;
	mainAuto[0].Serialize();
	cout << "Serializing" << endl;
	mainAuto[0].setFirm("Standart_Audi");
	cout << "Set firm \"Standart_Audi\"" << endl;
	mainAuto[0].Deserialize();
	cout << "Deserializing" << endl;
	cout << "Current firm: " << mainAuto[0].getFirm() << endl << endl;

	cout << "Array before sort:" << endl;
	for (int i = 0; i < 4; i++) {
		cout << i << ") "; 
		cout << autos[i].getFirm() << " " << autos[i].getModel() << "   ";
		cout << autos[i].getYear() << "   ";
		cout << autos[i].getMileage() << endl;
	}
	Sort(autos, 4);
	cout << endl;
	cout << "Array after sort:" << endl;
	for (int i = 0; i < 4; i++) {
		cout << i << ") ";
		cout << autos[i].getFirm() << " " << autos[i].getModel() << "   ";
		cout << autos[i].getYear() << "   ";
		cout << autos[i].getMileage() << endl;
	}
	cout << endl;

	delete anotherAuto;

	system("pause");
	return 0;
}