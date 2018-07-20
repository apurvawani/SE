/*
Write a C/CPP program for storing matrix. Write functions for :
1. Check whether matrix is upper triangular or not
2. Compute summation of diagonal elements
3. Compute transpose of given matrix
4. Add , Subtract & multiply two matrices
5. Check saddle point is present or not
*/

#include <iostream>
using namespace std;
class Matrix {
	int m , n;
	int mat[10][10];
public:
	Matrix() {
		m = 0;
		n = 0;
	}
	void getData(int , int);
	Matrix transpose();
	Matrix add(Matrix);
	Matrix subtract(Matrix);
	Matrix multiply(Matrix);
	bool upperTriangular();
	void saddlePoint();
	int sumOfDiagonalElements();
};
void Matrix :: getData(int r , int c) {
	m = r;
	n = c;
	cout << "Enter elements of the matrix : " << endl;
	for(int i = 0 ; i < m ; i++) {
		for(int j = 0 ; j < n ; j++) {
			cin >> mat[i][j];
		}
	}

}
Matrix Matrix :: transpose() {
	Matrix m3;
	for(int i = 0 ; i < m ; i++) {
		for(int j = 0 ; j < n ; j++) {
			m3.mat[j][i] = mat[i][j];
		}
	}
	cout << "Transpose Of The Matrix : " << endl;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			cout << m3.mat[i][j] << "\t";
		}
		cout << endl;
	}
	return m3;
}
Matrix Matrix :: add(Matrix m2) {
	Matrix m3;
	if(m==m2.m && n==m2.n) {
		for(int i = 0 ; i < m ; i++) {
			for(int j = 0 ; j < n ; j++) {
				m3.mat[i][j] = mat[i][j] + m2.mat[i][j];
			}
		}
		cout << "Sum of two matrices : ";
		for(int i = 0 ; i < m ; i++) {
			cout << endl;
			for(int j = 0 ; j < n ; j++) {
				cout << m3.mat[i][j] << "\t";
			}
		}

	}
	else {
		cout << "Addition operation cannot be performed!";
	}
	cout << endl;
	return m3;
}
Matrix Matrix :: subtract(Matrix m2) {
	Matrix m3;
	if(m==m2.m && n==m2.n) {
		for(int i = 0 ; i < m ; i++) {
			for(int j = 0 ; j < n ; j++) {
				m3.mat[i][j] = mat[i][j] - m2.mat[i][j];
			}
		}
		cout << "Difference of two matrices : ";
		for(int i = 0 ; i < m ; i++) {
			cout << endl;
			for(int j = 0 ; j < n ; j++) {
				cout << m3.mat[i][j] << "\t";
			}
		}
	}
	else {
		cout << "Subtraction operation cannot be performed!";
	}
	cout << endl;
	return m3;
}
Matrix Matrix :: multiply(Matrix m2) {
	Matrix m3;
	if(n==m2.m) {
		cout << "Multiplication of two matrices : " << endl;
		for(int i = 0 ; i < m ; i++) {
			for(int j = 0 ; j < n ; j++) {
				int r = 0;
				for(int k = 0 ; k < n ; k++) {
					 r += mat[i][k] * m2.mat[k][j];
				}
				cout << r << "\t";
				m3.mat[i][j] = r;
			}
			cout << endl;
		}
	}
	else {
		cout << "Multiplication operation not possible!";
	}
	cout << endl;
	return m3;
}
bool Matrix:: upperTriangular() {
	bool check = true;
	for(int i = 1 ; i < m ; i++) {
		for(int j = 0 ; j < i ; j++) {
			if(mat[i][j]!=0) {
				check = false;
				break;
			}
		}
	}
	return check;
}
void Matrix :: saddlePoint() {
	for(int i = 0 ; i < m ; i++) {
		int min_row = mat[i][0] , col_index = 0;
		for(int j = 1 ; j < n ; j++) {
			if(mat[i][j] < min_row) {
				min_row = mat[i][j];
				col_index = j;
			}
		}
		int k = 0;
		for(k = 0 ; k < m ; k++) {
			if(mat[k][col_index] > min_row) {
				break;
			}
		}
		if(k==m){
			cout << "Value Of The Saddle Point : " << min_row << endl;
		}
	}
}
int Matrix :: sumOfDiagonalElements() {
	int sum = 0;
	if(m==n) {
		for(int i = 0 ; i < m ; i++) {
			for(int j = 0 ; j < n ; j++) {
				if(i==j) {
					sum += mat[i][j];
				}
			}
		}
	}
	return sum;
}
int main() {
	int r1 , c1;
	cout << "Enter number of rows & columns : " << endl;
	cin >> r1 >> c1;
	Matrix m1 , m2 , m3 ,m4 , m5 , m6;
	m1.getData(r1 , c1);
	m3 = m1.transpose();
	int sum = m1.sumOfDiagonalElements();
	cout << "Sum Of Diagonal Elements : " << sum << endl;
	m1.saddlePoint();
	bool s = m1.upperTriangular();
	if(s==true) {
		cout << "Given matrix is UpperTriangular." << endl;
	}
	else {
		cout << "Given matrix is  not UpperTriangular." << endl;
	}
	int r2 , c2;
	cout << "Enter number of rows & columns for another matrix : " << endl;
	cin >> r2 >> c2;
	m2.getData(r2 , c2);
	m4 = m1.add(m2);
	m5 = m1.multiply(m2);
	m6 = m1.subtract(m2);
	return 0;
}
