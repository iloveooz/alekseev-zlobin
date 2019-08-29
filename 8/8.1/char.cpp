#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");
	// описываем 3 строки, s3 указатель
	char s2[25], *s3, s4[30], s5[60]; 
	std::cout << "Введите строку:" << std::endl;
	std::cout << " s2 = ";
	// Ввод строки s2
	std::cin.getline(s2, 25);
	std::cout << "Была введена строка:" << std::endl;
	std::cout << " s2 = " << s2 << ", длина строки s2 = " << strlen(s2) << std::endl;
	// Запись в s3 адреса строки s4. Теперь в указателях s3 и s4 хранится один адрес
	s3 = s4; 
	std::cout << "Введите строку:" << std::endl;
	std::cout << " s3 = ";
	// Ввод строки s3
	std::cin >> s3; 
	std::cout << "Была введена строка:" << std::endl;
	// Вывод на экран s3 и s4
	std::cout << " s3 = " << s3 << std::endl; 
	std::cout << "Сформирована новая строка:" << std::endl;
	// s3 и s4  одно и тоже
	std::cout << " s4 = " << s4 << std::endl;
	std::cout << " Присоединяем строки s3 и s4 - " << strcat(s3, s4) << std::endl;
	strcpy_s(s5, s2);
	std::cout << "Строка s5 - " << s5 << std::endl;
	system("pause");
	return 0;
}
