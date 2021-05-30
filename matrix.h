#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
	int** A;
	int n, m;
	string name;


public:

	Matrix(int x, int y, string str);
	Matrix(void);

	void setName(string str);

	int getColumns(void);
	int getRows(void);
	string getName(void);
	int getValue(int x, int y);

	void fill(int limit = 100);
	void zero();
	void display(void);

	friend Matrix add(Matrix A, Matrix B);
	friend Matrix multiplyByNumber(Matrix A, int k);
	friend Matrix multiplyByInput(Matrix A);
	friend Matrix multiply(Matrix A, Matrix B);
	friend Matrix transpose(Matrix A);

	friend Matrix operator +(Matrix A, Matrix B);
	friend Matrix operator *(Matrix A, Matrix B);
	friend Matrix operator *(int k, Matrix A);
	friend Matrix operator *(Matrix A, int k);

	friend ostream& operator <<(ostream& out, Matrix& A);
	friend istream& operator >>(istream& in, Matrix& A);
};


Matrix::Matrix(int x, int y, string str) {
	m = x;
	n = y;
	name = str;

	A = new int* [n];
	for (int i = 0; i < n; i++)
		A[i] = new int[m];

	fill();
}

void Matrix::setName(string str) {
	name = str;
}

int Matrix::getColumns() {
	return n;
}

int Matrix::getRows() {
	return m;
}

string Matrix::getName() {
	return name;
}

int  Matrix::getValue(int x, int y) {
	return A[y - 1][x - 1];
}

void Matrix::fill(int limit) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = rand() % (limit - 1) + 1;
}

void Matrix::zero() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = 0;
}

void Matrix::display() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << A[j][i] << ", ";
		cout << "\n";
	}
	cout << "\n";
}

Matrix operator +(Matrix A, Matrix B) {
	return add(A, B);
}

Matrix operator *(Matrix A, Matrix B) {
	return multiply(A, B);
}

Matrix operator *(int k, Matrix A) {
	return multiplyByNumber(A, k);
}

Matrix operator *(Matrix A, int k) {
	return multiplyByNumber(A, k);
}

ostream& operator <<(ostream& out, Matrix& A) {

	for (int i = 0; i < A.m; i++) {
		for (int j = 0; j < A.n; j++)
			out << A.A[j][i] << ", ";
		out << "\n";
	}
	out << "\n\n";
	return out;
}

istream& operator >>(istream& in, Matrix& A) {
	for (int i = 0; i < A.n; i++)
		for (int j = 0; j < A.m; j++) {
			cout << "Podaj element z kolumny " << i + 1 << ", rzedu " << j + 1 << ":\n";
			in >> A.A[i][j];
		}
	return in;
}

#endif