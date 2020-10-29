#pragma once
#include <stdio.h>
#include <iostream>
class Vector
{
public:
	Vector(int length = 0) {
		_array = new float[length];
		_length = length;
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

    // prefix
    Vector& operator ++ () {
        for (int i = 0; i < _length; i++)
            _array[i]++;
        return *this;
    }
    Vector& operator -- () {
        for (int i = 0; i < _length; i++)
            _array[i]--;
        return *this;
    }

    // postfix
    Vector operator ++ (int) {
        Vector temp(_length);
        for (int i = 0; i < _length; i++)
            temp[i] = _array[i]++;
        return temp;
    }
    Vector operator -- (int) {
        Vector temp(_length);
        for (int i = 0; i < _length; i++)
            temp[i] = _array[i]--;
        return temp;
    }

private:
	int _length;
	float* _array;
};