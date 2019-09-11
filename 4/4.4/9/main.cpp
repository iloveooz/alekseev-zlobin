#include <iostream>

unsigned long long int NC(unsigned long long int N, unsigned int b) {
	unsigned long long int S, P;
	for (S = 0, P = 1; N != 0; S += N % b * P, P *= 10, N /= b) {
		std::cout << " S = " << S << '\n';
		std::cout << " P = " << P << '\n';
		std::cout << " N = " << N << '\n';
		std::cout << " b = " << b << '\n';
		system("pause");
	}
	return S;
}

int main() {
	unsigned long long int X;
	std::cout << " X = ";
	std::cin >> X; //Ввод числа X.
	
	//Перевод числа X в заданные системы счисления.
	std::cout << X << " (10) = " << NC(X, 2) << " (2) " << std::endl;
	std::cout << X << " (10) = " << NC(X, 5) << " (5) " << std::endl;
	std::cout << X << " (10) = " << NC(X, 7) << " (7) " << std::endl;
	system("pause");
	return 0;
}
