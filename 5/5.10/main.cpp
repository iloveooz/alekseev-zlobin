#include <iostream>

int main (int argc, char **argv) {
	setlocale(LC_ALL, "Russian");

	float *x;
	int i, k, n, max, kgr, kon_max;

	std::cout << " n = "; 
	std::cin >> n; 

	x = new float[n]; 
	std::cout << "Введите массив X" << '\n';

	for (i  = 0; i < n; i++) {
		std::cout << i << " элемент: ";
		std::cin >> x[i];
	}

	for (kgr = i  = 0, k = 1; i < n - 1; i++)
		if (x[i] * x[i + 1] < 0) 
			k++;
		else
			if (k > 1) {
				kgr++;
				if (kgr == 1) {
					max = k;
					kon_max = i; 
				}
				else
					if (k > max) {
						max = k;
						kon_max = i;
					}
				k = 1;
			}

			if (k > 1) {
				kgr++;
				if (kgr == 1) {
					max = k;
					kon_max = n - 1;
				}
				else
					if (k > max) {
						max = k;
						kon_max = n - 1;
					}
			}
	
			if (kgr > 0) {
				std::cout << "В массиве " << kgr << " групп знакочередующихся элементов." << '\n';
				std::cout << "Группа максимальной длины начинается с элемента # " << kon_max - max + 1 << 
					", её длина " << max << ", номер последнего элемента группы - "  << kon_max << std::endl;

				for (i = kon_max - max + 1; i <= kon_max; i++)
					std::cout << x[i] << " ";
				std::cout << std::endl;
			}
			else
			std::cout << "В массиве нет групп знакочередующихся элементов" << '\n';
	system("pause");
	return 0;
}
