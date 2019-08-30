#include <iostream>
#include <cmath>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

struct complex1 {
	float Re;
	float Im;
};

struct complex2 {
	float Modul;
	float Argum;
};

// ввод числа в алгебраической форме
complex1 vvod1() {
	complex1 temp;
	std::cout << "Введите действительную часть числа" << '\n';
	std::cin >> temp.Re;

	std::cout << "Введите мнимую часть комплексного числа" << '\n';
	std::cin >> temp.Im;

	return temp;
}

// ввод числа в тригонометрической или показательной форме
complex2 vvod2() {
	complex2 temp;
	std::cout << "Введите модуль комплексного числа" << '\n';
	std::cin >> temp.Modul;
	std::cout << "Введите аргумент комплексного числа" << '\n';
	std::cin >> temp.Argum;
	return temp;
}

// вывод числа в алгебраической форме
void vivod(complex1 chislo) {
	std::cout << chislo.Re;
	if (chislo.Im >= 0)
		std::cout << " + " << chislo.Im << "i" << std::endl << std::endl;
	else
		std::cout << " " << chislo.Im << "i" << std::endl << std::endl;
}

// вывод числа в тригонометрической форме
void vivod(complex2 chislo) {
	std::cout << chislo.Modul << "(cos(" << chislo.Argum << ") + i * sin(" << chislo.Argum << "))" << std::endl;
}

// перевод числа из тригонометрической формы в алгебраическую, pr определяет, выводить или нет полученное число на экран.
complex1 perevod(complex2 chislo, bool pr = false ) {
	complex1 temp;
	temp.Re = chislo.Modul * cos(chislo.Argum);
	temp.Im = chislo.Modul * sin(chislo.Argum);
	if (pr) 
		vivod(temp);
	return temp;
}

// перевод числа из алгебраической формы в тригонометрическую, pr определяет, выводить или нет полученное число на экран.
complex2 perevod(complex1 chislo, bool pr = false) {
	complex2 temp;
	temp.Modul = sqrt(chislo.Re * chislo.Re + chislo.Im * chislo.Im);
	temp.Argum = atan(chislo.Im / chislo.Re);
	if (pr)
		vivod(temp);
	return temp;
}

// функция сложения двух чисел в алгебраической форме, pr определяет, выводить или нет число на экран.
complex1 plus1(complex1 chislo1, complex1 chislo2, bool pr = true) {
	complex1 temp;
	temp.Re = chislo1.Re + chislo2.Re;
	temp.Im = chislo1.Im + chislo2.Im;
	if (pr)
		vivod(temp);
	return temp;
}

// функция вычитания двух чисел в алгебраической форме, pr определяет, выводить или нет число на экран.
complex1 minus1(complex1 chislo1, complex1 chislo2, bool pr = true) {
	complex1 temp;
	temp.Re = chislo1.Re - chislo2.Re;
	temp.Im = chislo1.Im - chislo2.Im;
	if (pr)
		vivod(temp);
	return temp;
}

// функция умножения двух чисел в алгебраической форме, pr определяет, выводить или нет число на экран.
complex1 mult1(complex1 chislo1, complex1 chislo2, bool pr = true) {
	complex1 temp;
	temp.Re = chislo1.Re * chislo2.Re - chislo1.Im * chislo2.Im;
	temp.Im = chislo1.Im * chislo2.Re + chislo1.Re * chislo2.Im;
	if (pr)
		vivod(temp);
	return temp;
}

// функция деления двух чисел в алгебраической форме, pr определяет, выводить или нет число на экран.
complex1 divide1(complex1 chislo1, complex1 chislo2, bool pr = true) {
	complex1 temp;
	temp.Re = (chislo1.Re * chislo2.Re + chislo1.Im * chislo2.Im) / (chislo2.Re * chislo2.Re + chislo2.Im * chislo2.Im);
	temp.Im = (chislo1.Im * chislo2.Re - chislo1.Re * chislo2.Im) / (chislo2.Re * chislo2.Re + chislo2.Im * chislo2.Im);
	if (pr)
		vivod(temp);
	return temp;
}

// функция возведения комплексного числа в алгебраической форме в целую степень n, pr определяет, выводить или нет полученное число на экран.
complex1 pow1(complex1 chislo1, int n, bool pr = true) {
	complex1 temp;
	complex2 temp2;
	float p = 1;
	int i = 1;
	temp2 = perevod(chislo1, true); // перевод числа в тригонометрическую форму.
	for ( ; i <= n; p *= temp2.Modul, i++);
	temp.Re = p * cos(n * temp2.Argum);
	temp.Im = p * sin(n * temp2.Argum);
	if (pr)
		vivod(temp);
	return temp;
}

// функция извлечения корня степени n из комплексного числа в алгебраической форме, pr определяет, выводить или нет
// полученные значения на экран.Функция возвращает ro и fi.
void sqrtn1(complex1 chislo1, int n, float *ro, float *fi, bool pr = true) {
	complex1 temp;
	complex2 temp2;
	int i = 0;
	temp2 = perevod(chislo1, true); // перевод числа в тригонометрическую форму.
	*ro = pow(temp2.Modul,(float) 1 / n);
	*fi = temp2.Argum;
	if (pr) {
		for(i = 0; i < n; i++) {
			std::cout << i << "-е значение корня" << '\n';
			temp.Re = *ro * cos((*fi + 2 * M_PI * i) / n);
			temp.Im = *ro * sin((*fi + 2 * M_PI * i) / n);
			vivod(temp);
		}
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	complex1 chislo1, chislo2; // описание комплексных
	complex1 chislo5; // чисел в алгебраической форме.
	complex2 chislo3, chislo4; // описание комплексных чисел в тригонометрической форме.
	
	float ro1, fi1;

	chislo1 = vvod1(); // ввод исходных данных
	chislo2 = vvod1(); // в алгебраической форме.

	vivod(chislo1); // вывод исходных данных
	vivod(chislo2); // в алгебраической форме.

	chislo3 = perevod(chislo1, true); // перевод чисел
	chislo4 = perevod(chislo2, true); // в тригонометрическую форму и вывод их на экран.
	std::cout << "Сумма чисел ";
	chislo5 = plus1(chislo1, chislo2, true);
	std::cout << "Разность чисел ";
	chislo5 = minus1(chislo1, chislo2, true);
	std::cout << "Произведение чисел ";
	chislo5 = mult1(chislo1, chislo2, true);
	std::cout << "Частное чисел ";
	chislo5 = divide1(chislo1, chislo2, true);
	chislo5 = pow1(chislo1, 5, true); // возведение числа в пятую степень.
	sqrtn1(chislo1, 5, &ro1, &fi1, true); // извлечение корня пятой степени.
	system("pause");
	return 0;
}
