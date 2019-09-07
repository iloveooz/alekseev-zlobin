#include <iostream>
#include <cmath>

class vector {
protected:
	double x, y;
public:
	vector(double x , double y) {
		this->x = x; 
		this->y = y;
	}
	double abs() {
		return sqrt(x * x + y * y);
	}
	void info() {
		std::cout << "Модуль вектора равен " << abs() << std::endl;
	}
};

class spatialvector : public vector	{
protected:
	double z;
public:
	spatialvector (double x, double y, double z);
	double abs() {
		return sqrt(x * x + y * y + z * z);
	}
};

spatialvector::spatialvector (double x , double y , double z) : vector (x, y) {
	this->z = z;
}

int main () {
	setlocale(LC_ALL, "Russian");
	std::cout << "Создаём вектор на плоскости с координатами 1, 2" << '\n';
	vector a(1, 2);
	a.info();
	std::cout << "Создаём пространственный вектор с координатами 1, 2, 3" << '\n';
	spatialvector b(1, 2, 3);
	b.info();
	system("pause");
	return 0;
}
