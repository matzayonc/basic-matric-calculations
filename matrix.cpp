#ifndef MATRIX_CPP
#define MATRIX_CPP

Matrix add(Matrix A, Matrix B) {

	int n, m;
	if (A.n > B.n)
		n = A.n;
	else
		n = B.n;

	if (A.m > B.m)
		m = A.m;
	else
		m = B.m;


	Matrix C(m, n, "Output");
	C.zero();


	for (int i = 0; i < A.n; i++)
		for (int j = 0; j < A.m; j++)
			C.A[i][j] += A.A[i][j];

	for (int i = 0; i < B.n; i++)
		for (int j = 0; j < B.m; j++)
			C.A[i][j] += B.A[i][j];

	return C;
}


Matrix multiplyByNumber(Matrix A, int k) {

	Matrix C(A.m, A.n, "Output");
	C.zero();

	for (int i = 0; i < A.n; i++)
		for (int j = 0; j < A.m; j++)
			C.A[i][j] = A.A[i][j] * k;

	return C;
}

Matrix multiplyByInput(Matrix A) {

	Matrix C(A.m, A.n, "Output");
	C.zero();

	int k = 0;
	cout << "Podaj skalar:";
	cin >> k;
	cout << "\n";

	for (int i = 0; i < A.n; i++)
		for (int j = 0; j < A.m; j++)
			C.A[i][j] = A.A[i][j] * k;

	return C;
}

Matrix multiply(Matrix A, Matrix B) {

	if (A.n != B.m) {
		cout << "Mnozenie macierzy niemozliwe\n";
		Matrix C(0, 0, "empty");
		return C;
	}

	Matrix C(A.m, A.n, "Output");
	C.zero();

	for (int i = 0; i < A.n; i++)
		for (int j = 0; j < A.n; j++) {
			for (int p = 0; p < A.m; p++)
				C.A[i][j] += A.A[i][p] * B.A[p][j];
		}
	return C;
}

Matrix transpose(Matrix A) {

	Matrix C(A.m, A.n, "Output");
	C.zero();

	for (int i = 0; i < A.n; i++)
		for (int j = 0; j < A.m; j++)
			C.A[j][i] = A.A[i][j];


	int tmp = C.n;
	C.n = C.m;
	C.m = tmp;

	return C;
}

#endif