#include <iostream>
#include <cmath>

float Pow(float a, int k, int m) { // 1
	std::cout << "func 1\t";

	if (a == 0)
		return 0;
	else if (k == 0)
		return 1;
	else if (a > 0)
		return exp(static_cast<float>(k) / m * log(a));
	else if (m % 2 != 0)
		return -exp(static_cast<float>(k) / m * log(-a));
}

float Pow(float a, int n) { // 2
	float p; 
	int i;
	std::cout << "func 2\t";

	if (a == 0)
		return 0;
	else if (n == 0)
		return 1;
	else if (n < 0)	{
		n = -n;
		p = 1;
		for (i = 1; i <= n; i++)
			p *= a;
		return static_cast<float>(1) / p;
	}
	else {
		p = 1;
		for (i = 1; i <= n; i++)
		 p *= a;
		return p;
	}
}

float Pow(int a, int n) { // 3
	int i, p;
	std::cout << "func 3\t";

	if (a == 0)
		return 0;
	else if (n == 0)
		return 1;
	else if (n < 0) {
		n = -n;
		p = 1;
		for (i = 1; i <= n; i++)
			p *= a;
		return static_cast<float>(1) / p;
	}
	else {
		p = 1;
		for (i = 1; i <= n; i++)
		 p *= a;
		return p;
	}
}

int main() {
	float a; 
	int k, m;

	std::cout << " a = ";
	std::cin >> a;

	std::cout << " k = "; 
	std::cin >> k;

	std::cout << " s = " << Pow(a, k) << '\n';
	std::cout << " s = " << Pow(static_cast<int>(a), k) << '\n';

	std::cout << " a = "; 
	std::cin >> a;

	std::cout << " k = "; 
	std::cin >> k;

	std::cout << " m = "; 
	std::cin >> m;

	std::cout << " s = " << Pow(a, k, m) << '\n';
	system("pause");
	return 0;
}
