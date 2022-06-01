#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int data;
	int cost;
	Node* next;
};

struct AdjList
{
	Node* head;
};

class Queue
{
private:
	int front;
	int rear;
	int size;
	int* array;

public:
	Queue(int size)
	{
		this->size = size;
		front = -1;
		rear = -1;
		array = new int[size];
		for (int i = 0; i < size; i++)
		{
			array[i] = 0;
		}
	}

	void push_back(int val)
	{
		if (front == -1 && rear == -1)
			front = 0;

		rear = (rear + 1) % size;
		array[rear] = val;
	}

	int pop_front()
	{
		int val = array[front];
		if (front == rear)
			front = rear = -1;
		else
			front = (front + 1) % size;

		return val;
	}

	bool isEmpty()
	{
		if (front == -1 && rear == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int front_El()
	{
		return array[front];
	}
};

class Stack
{
private:
	int size;
	int top;
	int* array;

public:
	Stack(int size)
	{
		this->size = size;
		array = new int[size];
		top = -1;
	}
	void push(int val)
	{
		top++;
		array[top] = val;
	}
	void pop()
	{
		array[top] = 0;
		top--;
	}
	int topEl()
	{
		return array[top];
	}
	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};