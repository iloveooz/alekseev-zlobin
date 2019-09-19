#include <cmath>
#include <iostream>

unsigned int prostoe(unsigned int N) {
	int i, pr;
	for (pr = 1, i = 2; i <= N/ 2; i++)
		if (N % i == 0)	{
			pr = 0; 
			break;
		}
	return pr;
}

unsigned int soversh(unsigned int N) {
	unsigned int i, S;
	for (S = 0, i = 1; i <= N / 2; i++)
		if (N % i == 0) 
			S += i; // Сумма делителей.
	if (S == N) 
		return 1;
	else 
		return 0;
}

int main() {
	setlocale(LC_ALL, "Russian");
	unsigned int i, N, X, S, kp, ks;
	long int P;

	std::cout << " N = ";
	std::cin >> N;

	for (kp = ks = S = 0, P = 1, i = 1; i <= N; i++) {
		std::cout << " X = ";
		std::cin >> X;
		if (prostoe(X)) {
			kp++; // Счётчик простых чисел.
			P *= X; // Произведение простых чисел.
		}
		if (soversh(X)) {
			ks++; // Счётчик совершённых чисел.
			S += X; // Сумма совершённых чисел.
		}
	}
	if (kp > 0)	
		std::cout << "Среднее геометрическое = " << pow(P, (float) 1 / kp) <<	std::endl;

	else
		std::cout << "Нет простых чисел\n";

	if (ks > 0)	
		std::cout << "Среднее арифметическое = " << (float) S / ks << std::endl;
	else
		std::cout << "Нет совершённых чисел\n";
	system("pause");
	return 0;
}
