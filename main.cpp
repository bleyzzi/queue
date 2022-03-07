#include "queue.h"
int main()
{
	setlocale(LC_ALL, "rus");
	bool flag = true;
	string menu("�������� �������:\n1:�����������\n2:��������� ������������\n"
		"3:����� ��������� ��� ������� ����������\n4:�������� �� �������\n"
		"5:������� ��������\n6:�������� �������� �� �������\n"
		"7:���������� � ������� ��������");
	cout << menu << "\n";
	while (flag) {
		int z;
		cin >> z;
		switch (z)
		{
		case 1: {
			Queue q;
			cout << "������ �������: " << q;
			q.push(1, Prt::High);
			q.push(3, Prt::Medium);
			q.push(5, Prt::Low);
			q.push(2, Prt::High);
			q.push(4, Prt::Medium);
			q.push(6, Prt::Low);
			cout << "����������� �������: " << q << "\n\n\n";
			cout << "������������ �������: " << q;
			Queue q1(q);
			cout << "����� �������: " << q1;
			Queue q3(move(q));
			cout << "������������ �������: " << q3;
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
			cout << "������������ �������: " << q;
			q1 = q;
			cout << "���������� �������� ������������: " << q1;
			q2 = move(q);
			cout << "������������ �������� ������������: " << q2;
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
			cout << "����������� �������: " << q;
			cout << "����� ��������� � ������� �����������: " << q.high_size() << "\n";
			cout << "����� ��������� �� ������� �����������: " << q.medium_size() << "\n";
			cout << "����� ��������� � ������ �����������: " << q.low_size() << "\n";
			cout << "����� ���������: " << q.size() << "\n";
			break;
		}
		case 4:
		{
			Queue q;
			cout << "�������: " << q;
			cout << "�������� �� �������: " << (q.is_empty() ? "������" : "���� ��������") << "\n";
			q.push(1, Prt::High);
			cout << "�������: " << q;
			cout << "�������� �� �������: " << (q.is_empty() ? "������" : "���� ��������") << "\n";
			break;
		}
		case 5:
		{
			Queue q;
			cout << "�������: " << q;
			cout << "������� ������� (1, High)" << "\n";
			q.push(1, Prt::High);
			cout << "�������: " << q;
			cout << "������� ������� (2, Low)" << "\n";
			q.push(2, Prt::Low);
			cout << "�������: " << q;
			cout << "������� ������� (3, Medium)" << "\n";
			q.push(3, Prt::Medium);
			cout << "�������: " << q;
			break;
		}
		case 6: {
			Queue q;
			q.push(1, Prt::High);
			q.push(2, Prt::Medium);
			q.push(7, Prt::Low);
			q.push(-1, Prt::High);
			cout << "�������: " << q;
			q.pop();
			cout << "�������: " << q;
			q.pop();
			cout << "�������: " << q;
			q.pop();
			cout << "�������: " << q;
			q.pop();
			cout << "�������: " << q;
			break;
		}
		case 7:
		{
			Queue q;
			q.push(1, Prt::High);
			q.push(8, Prt::Medium);
			q.push(0, Prt::Low);
			q.push(-1, Prt::High);
			cout << "�������: " << q;
			cout << "���������� � ������� ��������: ";
			cout << q.get_top(q) << "\n";
			q.pop();
			cout << "���������� � ������� ��������: ";
			cout << q.get_top(q) << "\n";
			q.pop();
			cout << "���������� � ������� ��������: ";
			cout << q.get_top(q) << "\n";
			q.pop();
			cout << "���������� � ������� ��������: ";
			cout << q.get_top(q) << "\n";
			q.pop();
			break;
		}
		}
		cout << "���� ������ ���������� - ������� true" << "\n";
		cin >> flag;
	}
}