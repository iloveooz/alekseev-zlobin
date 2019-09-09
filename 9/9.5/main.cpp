#include <iostream>
#include <fstream>
#include <cmath>
#include <complex>

//Решение СЛАУ с комплексными коэффициентами
int SLAU(std::complex <float> **matrica_a, int n, std::complex <float> *massiv_b, std::complex <float> *x) {
	int i, j, k, r;
	std::complex <float> c, M, s;
	
	float max;
	std::complex <float> **a, *b;

	a = new std::complex <float> *[n];

	for (i = 0; i < n; i++)
		a[i] = new std::complex <float >[n];

	b = new std::complex <float>[n];
	
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = matrica_a[i][j];
	
	for (i = 0; i < n; i++)
		b[i] = massiv_b[i];
	
	for (k = 0; k < n; k++) {
		max = abs(a[k][k]);
		r = k;
		for (i=k+1; i < n; i++)
			if (abs(a[i][k])>max) {
				max = abs(a[i][k]);
				r = i;
			}
		for (j = 0; j < n; j++) {
			c = a[k][j];
			a[k][j] = a[r][j];
			a[r][j] = c;
		}

		c = b[k];
		b[k] = b[r];
		b[r] = c;

		for (i = k + 1; i < n; i++) {
			for (M = a[i][k] / a[k][k], j = k; j < n; j++)
				a[i][j] -= M * a[k][j];
			b[i] -= M * b[k];
		}
	}

	if (abs(a[n - 1][n - 1]) == 0)
		if (abs(b[n - 1]) == 0)
			return -1;
		else 
			return -2;
	else {
		for (i = n - 1; i >= 0; i--) {
			for (s = 0, j = i + 1; j < n; j++)
				s += a[i][j] * x[j];
		x[i] = (b[i] - s) / a[i][i];
		}
		return 0;
	}
	for (i = 0; i < n; i++)
		delete[] a[i];
		delete[] a;
		delete[] b;
}

//Вычисление обратной матрицы с комплексными коэффициентами
int INVERSE(std::complex <float> **a, int n, std::complex <float> **y) {
	int i, j, res;
	std::complex <float> *b, *x;

	b = new std::complex <float>[n];
	x = new std::complex <float>[n];

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			if (j==i)
				b[j] = 1;
			else 
				b[j] = 0;
		res = SLAU(a, n, b, x);
		if (res != 0)
			break;
		else
			for (j = 0; j < n; j++)
				y[j][i] = x[j];
	}

	delete[] x;
	delete[] b;

	if (res != 0)
		return -1;
	else
		return 0;
}

//Вычисление определителя матрицы с комплексными коэффициентами
std::complex <float> determinant (std::complex <float> **matrica_a, int n) {
	int i, j, k, r;
	std::complex <float> c, M, s, det = 1;
	std::complex <float> **a;
	float max;
	a = new std::complex <float> *[n];

	for (i = 0; i < n; i++)
		a[i] = new std::complex <float >[n];

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = matrica_a[i][j];
	
	for (k = 0; k < n; k++) {
		max = abs(a[k][k]);
		r = k;

		for (i = k + 1; i < n; i++)
			if (abs(a[i][k]) > max) {
				max = abs(a[i][k]);
				r = i;
			}
		if (r != k) 
			det =- det;
		for (j = 0; j < n; j++) {
			c = a[k][j];
			a[k][j] = a[r][j];
			a[r][j] = c;
		}
		for (i = k + 1; i < n; i++)
			for (M = a[i][k] / a[k][k], j = k; j < n; j++)
				a[i][j] -= M * a[k][j];
	}

	for (i = 0; i < n; i++)
		det *= a[i][i];
	
	return det;
	for (i = 0; i < n; i++)
		delete[] a[i];
	delete [] a;
}

//Умножение матриц с комплексными коэффициентами
void umn (std::complex <float> **a, std::complex <float> **b, std::complex <float> **c, int n, int m, int k) {
	int i, j, p;
	for (i = 0; i < n; i++)
		for (j = 0; j < k; j++)
			for (c[i][j] = p=0;p<m; p++)
				c[i][j]+=a[i][p] * b[p][j];
}

int main () {
	setlocale(LC_ALL, "Russian");
	int i, j, N;

	std::complex <float> **A, **B, **X, **Y;

	std::ifstream f;
	std::ofstream g;

	f.open("abc2.txt");
	f >> N;

	std::cout << " N =  " << N << std::endl;
	
	A = new std::complex <float> *[N];
	for (i = 0; i < N; i++)
		A[i] = new std::complex <float>[N];
	
	B = new std::complex <float> *[N];
	for (i = 0; i < N; i++)
		B[i] = new std::complex <float>[N];
	
	X = new std::complex <float> *[N];
	for (i = 0; i < N; i++)
		X[i] = new std::complex <float>[N];
	
	Y = new std::complex <float> *[N];
	for (i = 0; i < N; i++)
		Y[i] = new std::complex <float>[N];
	
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			f >> A[i][j];

	std::cout << "Матрица A"  <<  '\n';
	for (i = 0; i < N; std::cout << std::endl, i++)
		for (j = 0; j < N; j++)
			std::cout << A[i][j] << "\t";
	
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			f >> B[i][j];
	
	std::cout << "Матрица B"  <<  '\n';
	
	for (i = 0; i < N; std::cout << std::endl, i++)
		for (j = 0; j < N; j++)
			std::cout << B[i][j] << "\t";

	if (!INVERSE(A, N, X)) {
		std::cout << "Обратная матрица"  <<  '\n';
	
		for (i = 0; i < N; std::cout << std::endl, i++)
			for (j = 0; j < N; j++)
				std::cout << X[i][j] << "\t";

		umn(X, B,Y, N, N,N);
		std::cout << "\n Решение матричного уравнения " << '\n';
		for (i = 0; i < N; std::cout << std::endl, i++)
			for (j = 0; j < N; j++)
				std::cout << Y[i][j] << "\t";
	}
	else 
		std::cout << "Не существует обратной матрицы" << '\n';
	std::cout << "Определитель = " << determinant(A, N) << std::endl;
	system("pause");
	return 0;
}
