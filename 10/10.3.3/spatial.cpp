#include <iostream>
#include <cmath>

class spatialvector {
	double x, y, z;
public:
	spatialvector(double x = 0, double y = 0, double z = 0);

	double abs() { return sqrt(x * x + y * y + z * z); }

	double get_x() { return x; }
	double get_y() { return y; }
	double get_z() { return z; }

	void set_x(double x) { this->x = x; }
	void set_y(double y) { this->y = y; }
	void set_z(double z) { this->z = z; }

	void info();

	spatialvector& operator ++ (); // префиксная форма
	spatialvector& operator -- ();

	spatialvector operator ++ (int); // постфиксная форма
	spatialvector operator -- (int);

	friend spatialvector operator + (spatialvector a, const spatialvector& b);
	friend spatialvector operator - (spatialvector a, const spatialvector& b);

	friend std::ostream& operator << (std::ostream& stream, const spatialvector& b);
	friend std::istream& operator >> (std::istream& stream, spatialvector& b);
};

spatialvector::spatialvector(double x1, double y1, double z1) {
	x = x1;
	y = y1;
	z = z1;
}

void spatialvector::info() {
	std::cout << "Координаты вектора: x = " << x << "; y = " << y << "; z = " << z << std::endl;
	std::cout << "Модуль вектора равен " << abs() << std::endl;
}

spatialvector& spatialvector::operator++() {
	x++; 
	y++; 
	z++;
	return *this;
}

spatialvector& spatialvector::operator--() {
	x--; 
	y--; 
	z--;
	return *this;
}

spatialvector spatialvector::operator++(int) {
	spatialvector temp = *this;
	++(*this);
	return temp;
}

spatialvector spatialvector::operator--(int) {
	spatialvector temp = *this;
	--(*this);
	return temp;
}

spatialvector operator+(spatialvector a, const spatialvector& b) {
	// передаём первый аргумент по значению,
	// поэтому можем изменять его, не влияя на исходный объект:
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	// возвращаем изменённую копию первого аргумента:
	return a;
}

spatialvector operator-(spatialvector a, const spatialvector& b) {
	a.x -= b.x;
	a.y -= b.y;
	a.z -= b.z;
	return a;
}

std::ostream& operator<<(std::ostream& stream, const spatialvector& b) {
	stream << " x = " << b.x << "; y = " << b.y << "; z = " << b.z << std::endl;

	return stream;
}

std::istream& operator>>(std::istream& stream, spatialvector& b) {
	stream >> b.x >> b.y >> b.z;
	return stream;
}

int main() {
	setlocale(LC_ALL, "Russian");
	spatialvector a, b(1, 2, 3);
	std::cout << " \n1. Заполнение вектора через стандартный ввод\n";
	std::cout << "Введите координаты вектора: ";
	std::cin >> a;
	a.info();
	std::cout << " \n2. Вычитание векторов\n";
	spatialvector c = a-b;
	std::cout << "Координаты вектора с=a-b(1,2,3): " << c;
	std::cout << " \n3. Изменение координаты вектора с помощью геттеров и сеттеров\n";
	c.set_x(c.get_x()+1);
	std::cout << "После инкремента координаты x, координаты вектора c: " << c;
	std::cout << " \n4. Инкремент:\nвывод с++: " << c++;
	std::cout << "Вывод ++с: " << ++c;
	system("pause");
	return 0;
}
