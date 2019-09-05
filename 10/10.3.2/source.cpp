#include <iostream>

class matrix {
	double *m; // элементы матрицы
	size_t width, height; // число строк и столбцов в матрице
public:
	matrix(size_t w, size_t h);
	matrix(const matrix& m1); // конструктор копирования
	matrix& operator=(matrix & m1); // оператор присваивания
	double get_val(size_t i, size_t j);
	void set_val(size_t i, size_t j, double val);
	~matrix();
};

matrix::matrix(size_t w, size_t h) {
	m = new double [w * h];
	width = w;
	height = h;
}

matrix::matrix(const matrix& m1) {
	// устанавливаем размер матрицы и выделяем под неё память:
	width = m1.width;
	height = m1.height;
	int size = width * height;
	m = new double [size];
	// копируем элементы матрицы:
	for(int i = 0; i < size; i++)
	m[i] = m1.m[i];
}

matrix& matrix::operator=(matrix& m1) {
	int size = m1.width * m1.height;
	if (size > width * height)
		// защищаемся от переполнения буфера
		size = width * height;
	m = new double [size];
	
	// копируем элементы матрицы:
	for(int i = 0; i < size; i++)
		m[i] = m1.m[i];
	return *this;
}

matrix::~matrix() {
	delete [] m;
}

double matrix::get_val(size_t i, size_t j) {
	// получить значение элемента матрицы в позиции [i, j]
	return m[i * width + j];
}
void matrix::set_val(size_t i, size_t j, double val) {
	// устанавливаем значение элемента матрицы в позиции [i, j], если координаты не превышают размер матрицы
	if ((i < width) && (j < height))
		m[i * width + j] = val;
}

int main() {
	setlocale(LC_ALL, "Russian");

	matrix a(2, 2); // объявляем матрицу размерности 2 х 2
	a.set_val(0, 0, 100); // устанавливаем a[0,0] = 100

	matrix b = a; // присваиваем матрицу
	b.set_val(0, 0, 200); // устанавливаем b[0,0] = 200

	std::cout << " a[0, 0] = " << a.get_val(0, 0) << "; " << " b[0, 0] = " << a.get_val	(0, 0) << std::endl;
	system("pause");
	return 0;
}
