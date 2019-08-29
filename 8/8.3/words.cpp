#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>

int main() {
	setlocale(LC_ALL, "Russian");
	std::ifstream f;
	int p, j, i, kol, m, n = 0;
	std::string S[10];

	f.open("text.txt");
	if (f) {
		while (!f.eof()) {
			getline(f, S[n]);
			std::cout << S[n] << "\n";
			n++;
		}
		f.close();
		std::cout << std::endl;

		std::cout << "Количество строк в тексте - " << n << std::endl;

		for (kol = 0, i = 0; i < n; i++) {
			m = S[i].length();
			S[i] += ' ';
			for (p = 0; p < m; ) {
				j = S[i].find(' ', p);
				if (j != 0) {
					kol++; 
					p = j + 1;
				}
				else
					break;
			}
		}
		std::cout << "Количество слов в тексте - " << kol << std::endl;
	}
	else
		std::cout << "Файл не найден" << std::endl;
	system("pause");
	return 0;
}
