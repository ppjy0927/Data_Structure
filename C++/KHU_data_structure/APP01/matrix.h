#pragma once
using namespace std;  // ostream을 위해서 써야함


class Matrix {

public:

	Matrix() {

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				matrix[i][j] = 0;
			}
		}

	}

	Matrix(int ff, int fs, int sf, int ss) {

		matrix[0][0] = ff;
		matrix[0][1] = fs;
		matrix[1][0] = sf;
		matrix[1][1] = ss;
	}
	
	void set(int i, int j, int val) {
		matrix[i][j] = val;
	}

	int get(int i, int j) {
		return matrix[i][j];
	}

	int sum() {
		int result = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				result += matrix[i][j];
			}
		}
		return result;
	}

private:
	int matrix[2][2];

};