#pragma once
#include <iostream>
#include <utility>
#include <stdexcept>
#include <string>
using namespace std;

struct Node
{
	int val = 0;
	Node* next = nullptr;
	//Node(int _val) : val(_val), next(nullptr) {};
};

enum class Prt
{
	Low,
	Medium,
	High
};

class Queue
{
private:
	Node* front;
	Node* high_rear;
	Node* medium_rear;
	Node* low_rear;
	int r_high_size;
	int r_medium_size;
	int r_low_size;
	void cln();
	void erase();
	void copy_copy(const Queue&);
	void copy_move(Queue&&);
public:
	Queue();
	Queue(const Queue&);
	Queue(Queue&&);
	~Queue();
	Queue& operator=(const Queue&);
	Queue& operator=(Queue&&);
	bool is_empty() const;
	int size() const;
	int high_size() const;
	int medium_size() const;
	int low_size() const;
	void push(const int&, const Prt&);
	bool pop();
	string get_top(const Queue&);
	friend ostream& operator<<(ostream&, const Queue&);
};
