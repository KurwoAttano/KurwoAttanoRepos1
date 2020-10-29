#include <stdio.h>
#include <iostream>
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

	srand(time(0));

	cout << "Car: " << mainAuto[0].getFirm() << " " << mainAuto[0].getModel() << " " << mainAuto[0].getNumber() << endl;
	cout << "Current mileage: " << mainAuto[0].getMileage() << endl << endl;
	GoRide(mainAuto, 0, getRand(100, 800));
	GoRide(mainAuto, 0, getRand(100, 800));
	GoRide(mainAuto, 0, getRand(100, 800));
	cout << endl;

	cout << "Car: " << mainAuto[1].getFirm() << " " << mainAuto[1].getModel() << " " << mainAuto[1].getNumber() << endl;
	cout << "Current mileage: " << mainAuto[1].getMileage() << endl << endl;
	GoRide(mainAuto, 1, getRand(100, 800));
	GoRide(mainAuto, 1, getRand(100, 800));
	GoRide(mainAuto, 1, getRand(100, 800));
	cout << endl;

	cout << "Car: " << mainAuto[2].getFirm() << " " << mainAuto[2].getModel() << " " << mainAuto[2].getNumber() << endl;
	cout << "Current mileage: " << mainAuto[2].getMileage() << endl << endl;
	GoRide(mainAuto, 2, getRand(100, 800));
	GoRide(mainAuto, 2, getRand(100, 800));
	GoRide(mainAuto, 2, getRand(100, 800));
	cout << endl;

	cout << "Car: " << anotherAuto->getFirm() << " " << anotherAuto->getModel() << " " << anotherAuto->getNumber() << endl;
	cout << "Current mileage: " << anotherAuto->getMileage() << endl << endl;
	GoRide(anotherAuto, getRand(100, 800));
	GoRide(anotherAuto, getRand(100, 800));
	GoRide(anotherAuto, getRand(100, 800));
	cout << endl;

	cout << "Serialize example:" << endl;
	mainAuto[0].setFirm("Serizlized_Audi");
	cout << "Set firm: Serialized_Audi" << endl;
	mainAuto[0].Serialize();
	cout << "Serializing" << endl;
	mainAuto[0].setFirm("Standart_Audi");
	cout << "Set firm \"Standart_Audi\"" << endl;
	mainAuto[0].Deserialize();
	cout << "Deserializing" << endl;
	cout << "Current firm: " << mainAuto[0].getFirm() << endl;

	system("pause");
	return 0;
}