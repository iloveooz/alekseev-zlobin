#include <iostream>

unsigned long long int DecNC(unsigned long long int N, unsigned int b) {
	//Функция выполняет перевод числа N, заданного в b-ичной системе счисления, в десятичную систему счисления
	unsigned long long int S, P;
	for (S = 0, P = 1; N != 0; S += N % 10 * P, P *= b, N /= 10);
	return S;
}

int main() {
	unsigned long long int X, Y; 
	unsigned int bX, bY;

	std::cout << " X = "; 
	std::cin >> X;

	std::cout << " b = "; 
	std::cin >> bX;

	std::cout << " Y = "; 
	std::cin >> Y;

	std::cout << " b = "; 
	std::cin >> bY;

	//Вывод заданных чисел в десятичной с/с.
	std::cout << X << " (" << bX << ") = " << DecNC(X, bX) << " (10) " << std::endl;
	std::cout << Y << " (" << bY << ") = " << DecNC(Y, bY) << " (10) " << std::endl;
	//Вычисление суммы и вывод результата.
	std::cout << X << " (" << bX << ") + " << Y << " (" << bY << ") = ";
	std::cout << DecNC(X, bX) + DecNC(Y, bY) << " (10) " << std::endl;
	system("pause");
	return 0;
}
