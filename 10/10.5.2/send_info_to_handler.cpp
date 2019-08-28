#include <cmath>
#include <iostream>

class general_error {
public:
	char *message;
	general_error(char *message) {
		this->message = message;
	}
};

class out_of_range {
public:
	size_t i; 
	out_of_range(size_t i) {
		this->i = i;
	}
};

class overflow {};
class underflow {};

class array {
	size_t size; // реальный размер массива
	size_t capacity; // максимально-допустимый размер
	double *data;
public:
	array(size_t capacity);
	~array();

	double operator [] (size_t i); // получить значение i-го элемента
	void push(double v); // добавить элемент
	double pop(); // убрать последний добавленный элемент
};

array::array (size_t capacity) {
	if (capacity == 0)
		throw general_error ("массив нулевой вместимости");
	this->capacity = capacity;
	size = 0;
	data = new double [capacity];
}

array::~array() {
	delete [] data;
}

double array::operator [] (size_t i) {
	if (i < size) 
		return data [i];
	else 
		throw out_of_range (i);
}

void array::push(double v) {
	if (size < capacity) 
		data[size++] = v;
	else 
		throw overflow ();
}

double array::pop() {
	if (size > 0) 
		return data[--size];
	else 
		throw underflow ();
}

int main() {
	setlocale(LC_ALL, "Russian");

	char c;
	size_t i;
	double v;
	
	std::cout << "Введите ёмкость массива: ";
	std::cin >> v;
	
	array a(v);
	
	for ( ; ; ) {
		std::cout << "Введите:\n \"+\" для добавления элемента;\n \"-\" для извлечения;\n \"i\" для просмотра i-го элемента;\n \"a\" для выхода;\n: ";
		std::cin >> c;
		try {
			switch (c) {
			case '+':
				std::cout << "Введите добавляемое число: ";
				std::cin >> v;
				a.push(v);
			break;

			case '-':
				v = a.pop();
				std::cout << "Извлечено число " << v << std::endl;
			break;

			case 'i':
				std::cout << "Введите индекс: ";
				std::cin >> i;
				v = a[i];
				std::cout << "Искомый элемент равен " << v << std::endl;
			break;

			case 'a':
				system("pause");
				return 0;
			break;
			}
		}
		catch (const out_of_range& e) {
			std::cout << "Попытка доступа к элементу с недопустимым индексом "<< e.i << std::endl;
		}
		catch (overflow) {
			std::cout << "Операция не выполнена, так как массив переполнен." << '\n';
		}
		catch (underflow) {
			std::cout << "Операция не выполнена, так как массив пуст." << '\n';
		}
	}
	system("pause");
	return 0;
}
