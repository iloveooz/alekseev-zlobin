#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	int k, i, j, N, a[20][20];
	std::cout << " N = ";
	std::cin >> N;
	std::cout << "Ввод матрицы A " << std::endl;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			std::cin >> a[i][j];

	for (i = k = 0; i < N; i++) {
		if (a[i][i] > 0) 
			k++;
		if (a[i][N - i - 1] > 0)
			k++;
	}
	for (i = 1; i < N - 1; i++) {
		if (a[0][i] > 0)
			k++;
		if (a[N - 1][i] > 0)
			k++;
		if (a[i][0] > 0) 
			k++;
		if (a[i][N - 1] > 0)
			k++;
	}

	if ((N%2!=0)&&(a [N/ 2] [N/2]>0))
		k--;
	std::cout << " k = " << k << std::endl;
	system("pause");
	return 0;
}
