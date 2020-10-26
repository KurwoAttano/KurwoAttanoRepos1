#pragma once
#include "Vector.h"
class Matrix
{
public:
    Matrix(int rowSize, int colSize) {
        _rows = new Vector[rowSize];
        for (int i = 0; i < rowSize; i++)
            _rows[i] = Vector(colSize);
        _rowSize = rowSize;
        _colSize = colSize;
    }
    ~Matrix() {
        delete[] _rows;
    }

    int getTotalLength() {
        return _rowSize * _colSize;
    }
    int getLengthX() {
        return _rowSize;
    }
    int getLengthY() {
        return _colSize;
    }

    Vector& operator[](int index) {
        return _rows[index]; 
    }
    float operator=(float value) {
        return value;
    }

private:
    int _rowSize;
    int _colSize;
    Vector* _rows;
};

