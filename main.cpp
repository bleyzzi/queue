#include "queue.h"
int main()
{
	setlocale(LC_ALL, "rus");
	bool flag = true;
	string menu("Выберите функцию:\n1:Конструктор\n2:Операторы присваивания\n"
		"3:Число элементов для каждого приоритета\n4:Проверка на пустоту\n"
		"5:Вставка элемента\n6:Удаление элемента из очереди\n"
		"7:Информация о верхнем элементе");
	cout << menu << "\n";
	while (flag) {
		int z;
		cin >> z;
		switch (z)
		{
		case 1: {
			Queue q;
			cout << "Пустая очередь: " << q;
			q.push(1, Prt::High);
			q.push(3, Prt::Medium);
			q.push(5, Prt::Low);
			q.push(2, Prt::High);
			q.push(4, Prt::Medium);
			q.push(6, Prt::Low);
			cout << "Заполненная очередь: " << q << "\n\n\n";
			cout << "Оригинальная очередь: " << q;
			Queue q1(q);
			cout << "Копия очереди: " << q1;
			Queue q3(move(q));
			cout << "Перемещенная очередь: " << q3;
			break;
		}
		case 2: {
			Queue q, q1, q2;
			q.push(5, Prt::High);
			q.push(7, Prt::Medium);
			q.push(0, Prt::Low);
			q.push(-1, Prt::High);
			q.push(-5, Prt::Medium);
			q.push(11, Prt::Low);
			cout << "Оригинальная очередь: " << q;
			q1 = q;
			cout << "Копирующий оператор присваивания: " << q1;
			q2 = move(q);
			cout << "Перемещающий оператор присваивания: " << q2;
			break;
		}
		case 3:
		{
			Queue q;
			q.push(1, Prt::High);
			q.push(2, Prt::Medium);
			q.push(7, Prt::Low);
			q.push(-1, Prt::High);
			q.push(-2, Prt::Medium);
			q.push(4, Prt::High);
			cout << "Заполненная очередь: " << q;
			cout << "Число элементов с высоким приоритетом: " << q.high_size() << "\n";
			cout << "Число элементов со средним приоритетом: " << q.medium_size() << "\n";
			cout << "Число элементов с низким приоритетом: " << q.low_size() << "\n";
			cout << "Число элементов: " << q.size() << "\n";
			break;
		}
		case 4:
		{
			Queue q;
			cout << "Очередь: " << q;
			cout << "Проверка на пустоту: " << (q.is_empty() ? "Пустая" : "Есть элементы") << "\n";
			q.push(1, Prt::High);
			cout << "Очередь: " << q;
			cout << "Проверка на пустоту: " << (q.is_empty() ? "Пустая" : "Есть элементы") << "\n";
			break;
		}
		case 5:
		{
			Queue q;
			cout << "Очередь: " << q;
			cout << "Вставим элемент (1, High)" << "\n";
			q.push(1, Prt::High);
			cout << "Очередь: " << q;
			cout << "Вставим элемент (2, Low)" << "\n";
			q.push(2, Prt::Low);
			cout << "Очередь: " << q;
			cout << "Вставим элемент (3, Medium)" << "\n";
			q.push(3, Prt::Medium);
			cout << "Очередь: " << q;
			break;
		}
		case 6: {
			Queue q;
			q.push(1, Prt::High);
			q.push(2, Prt::Medium);
			q.push(7, Prt::Low);
			q.push(-1, Prt::High);
			cout << "Очередь: " << q;
			q.pop();
			cout << "Очередь: " << q;
			q.pop();
			cout << "Очередь: " << q;
			q.pop();
			cout << "Очередь: " << q;
			q.pop();
			cout << "Очередь: " << q;
			break;
		}
		case 7:
		{
			Queue q;
			q.push(1, Prt::High);
			q.push(8, Prt::Medium);
			q.push(0, Prt::Low);
			q.push(-1, Prt::High);
			cout << "Очередь: " << q;
			cout << "Информация о верхнем элементе: ";
			cout << q.get_top(q) << "\n";
			q.pop();
			cout << "Информация о верхнем элементе: ";
			cout << q.get_top(q) << "\n";
			q.pop();
			cout << "Информация о верхнем элементе: ";
			cout << q.get_top(q) << "\n";
			q.pop();
			cout << "Информация о верхнем элементе: ";
			cout << q.get_top(q) << "\n";
			q.pop();
			break;
		}
		}
		cout << "Если хотите продолжить - введите true" << "\n";
		cin >> flag;
	}
}