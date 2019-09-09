#include <iostream>
#include <fstream>
#include <cmath>
#include <complex>
#include <iostream>

int main () {
	setlocale(LC_ALL, "Russian");
	int i, j, p, N, M, K;

	std::complex <float> **A, **B, **C;
	std::ifstream f;
	std::ofstream g;

	f.open("abc.txt");

	f >> N >> M >> K;
	std::cout << " N = " << N << "\tM = " << M << "\tK = " << K <<  std::endl;

	A = new std::complex <float> *[N];
	for (i = 0; i < N; A[i] = new std::complex <float> [M], i++);

	B = new std::complex <float> *[M];
	for (i = 0; i < M; B[i] = new std::complex <float> [K], i++);

	C = new std::complex <float> *[N];
	for (i = 0; i < N; C[i] = new std::complex <float> [K], i++);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; f>>A[i] [j], j++);
			std::cout << "Матрица A\ n";

	for (i = 0; i < N; std::cout << std::endl, i++)
		for (j = 0; j < M; std::cout << A[i][j] << "\t", j++);
	
	for (i = 0; i < M; i++)
		for (j = 0; j < K; f >> B[i][j], j++);
		std::cout << "Матрица B\n";

	for (i = 0; i < M; std::cout << std::endl, i++)
		for (j = 0; j < K; std::cout << B[i][j] << "\t", j++);

	for (i = 0; i < N; i++)
		for (j = 0; j < K; j++)
			for (C[i][j] = p = 0; p < M; p++)
				C[i][j] += A[i][p] * B[p][j];
	
	f.close ();
	std::cout << "Матрица C\n";
	for (i = 0; i < N; std::cout << std::endl, i++)
		for (j = 0; j < K; std::cout << C[i][j] << "\t", j++);
	
	g.open("result.txt");
	g << "Матрица C = A * B\n";
	for (i = 0; i < N; g << std::endl, i++)
		for (j = 0; j < K; g << C[i][j] << "\t", j++);
	g.close ();
	
	system("pause");
	return 0;
}
