#include "queue.h"
int main()
{
	setlocale(LC_ALL, "rus");
	bool flag = true;
	string menu("Choose function:\n1:Constructor\n2:Assignment operators\n"
		"3:Number of elements of each priority\n4:Check for emptiness\n"
		"5:Push element\n6:Delete element\n"
		"7:Top element information");
	cout << menu << "\n";
	int z;
	cin >> z;
	switch (z)
	{
	case 1: {
		Queue q;
		cout << "Empty queue: " << q;
		q.push(1, Prt::High);
		q.push(3, Prt::Medium);
		q.push(5, Prt::Low);
		q.push(2, Prt::High);
		q.push(4, Prt::Medium);
		q.push(6, Prt::Low);
		cout << "Not empty queue: " << q << "\n\n\n";
		cout << "Original queue: " << q;
		Queue q1(q);
		cout << "Copy queue: " << q1;
		Queue q3(move(q));
		cout << "Moved queue: " << q3;
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
		cout << "Original queue " << q;
		q1 = q;
		cout << "Copy assignment operator: " << q1;
		q2 = move(q);
		cout << "Move assignment operator: " << q2;
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
		cout << "Not empty queue: " << q;
		cout << "Number of High Priority Items: " << q.high_size() << "\n";
		cout << "Number of Medium Priority Items: " << q.medium_size() << "\n";
		cout << "Number of Low Priority Items: " << q.low_size() << "\n";
		cout << "Number of elements: " << q.size() << "\n";
		break;
	}
	case 4:
	{
		Queue q;
		cout << "Queue: " << q;
		cout << "Check for emptiness: " << (q.is_empty() ? "Empty" : "Not empty") << "\n";
		q.push(1, Prt::High);
		cout << "Queue: " << q;
		cout << "Check for emptiness: " << (q.is_empty() ? "Empty" : "Not empty") << "\n";
		break;
	}
	case 5:
	{
		Queue q;
		cout << "Queue: " << q;
		cout << "Push (1, High)" << "\n";
		q.push(1, Prt::High);
		cout << "Queue: " << q;
		cout << "Push (2, Low)" << "\n";
		q.push(2, Prt::Low);
		cout << "Queue: " << q;
		cout << "Push (3, Medium)" << "\n";
		q.push(3, Prt::Medium);
		cout << "Queue: " << q;
		break;
	}
	case 6: {
		Queue q;
		q.push(1, Prt::High);
		q.push(2, Prt::Medium);
		q.push(7, Prt::Low);
		q.push(-1, Prt::High);
		cout << "Queue: " << q;
		q.pop();
		cout << "Queue: " << q;
		q.pop();
		cout << "Queue: " << q;
		q.pop();
		cout << "Queue: " << q;
		q.pop();
		cout << "Queue: " << q;
		break;
	}
	case 7:
	{
		Queue q;
		q.push(1, Prt::High);
		q.push(8, Prt::Medium);
		q.push(0, Prt::Low);
		q.push(-1, Prt::High);
		cout << "Queue: " << q;
		cout << "Top element information: ";
		cout << q.get_top(q) << "\n";
		q.pop();
		cout << "Top element information: ";
		cout << q.get_top(q) << "\n";
		q.pop();
		cout << "Top element information: ";
		cout << q.get_top(q) << "\n";
		q.pop();
		cout << "Top element information: ";
		cout << q.get_top(q) << "\n";
		q.pop();
		break;
	}
	}
}
