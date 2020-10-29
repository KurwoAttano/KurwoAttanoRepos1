#pragma once
class Matrix {
public:
    Matrix(int rowSize, int colSize) {
        _array = new float*[rowSize];
        for (int i = 0; i < rowSize; i++)
            _array[i] = new float[colSize];
        _rowSize = rowSize;
        _colSize = colSize;
    }
    ~Matrix() {
        for (int i = 0; i < _rowSize; i++)
            delete[] _array[i];
        delete[] _array;
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

    float Get(int row, int col) { // at(){}
        return _array[row][col];
    }
    void Set(int row, int col, float value) { // setAt(){}
        _array[row][col] = value;
    }

    float* operator [] (int i) {
        return _array[i]; 
    }
    float operator = (float value) {
        return value;
    }

    // prefix
    Matrix& operator ++ () {
        for (int i = 0; i < _rowSize; i++)
            for (int j = 0; j < _colSize; j++)
                _array[i][j]++;
        return *this;
    }
    Matrix& operator -- () {
        for (int i = 0; i < _rowSize; i++)
            for (int j = 0; j < _colSize; j++)
                _array[i][j]--;
        return *this;
    }

    // postfix
    Matrix operator ++ (int) {
        Matrix temp(_rowSize, _colSize);
        for (int i = 0; i < _rowSize; i++)
            for (int j = 0; j < _colSize; j++)
                temp[i][j] = _array[i][j]++;
        return temp;
    }
    Matrix operator -- (int) {
        Matrix temp(_rowSize, _colSize);
        for (int i = 0; i < _rowSize; i++)
            for (int j = 0; j < _colSize; j++)
                temp[i][j] = _array[i][j]--;
        return temp;
    }

private:
    int _rowSize;
    int _colSize;
    float** _array;
};

