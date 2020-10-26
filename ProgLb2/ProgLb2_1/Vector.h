#pragma once
#include <stdio.h>
#include <iostream>
class Vector
{
public:
	Vector(int index = 0) {
		_array = new float[index];
		_length = index;
	}
	~Vector() {
		printf("%s", "DEL VECTOR: (length==");
		printf("%d", _length);
		printf("%s", ")\n");
		for (int i = 0; i < _length; i++) {
			printf("%f\n", (float)_array[i]);
		}
		printf("%s", "\n");

		//delete[] _array; //FUCKING STRANGE DELETER
	}

	int getLength() {
		return _length;
	}

	float& operator[](int index) {
		return _array[index];
	}

//private:
public:
	int _length;
	float* _array;
};