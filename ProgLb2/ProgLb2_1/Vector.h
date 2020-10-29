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
		delete[] _array;
	}

	int getLength() {
		return _length;
	}

	float& operator [] (int index) {
		return _array[index];
	}

private:
	int _length;
	float* _array;
};