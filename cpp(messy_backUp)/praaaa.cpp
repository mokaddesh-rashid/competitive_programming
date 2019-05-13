#include <iostream>
using namespace std;

const int size = 1000; // queue te max 1000 ta value rakhte parba!!!
int arr[size];
int front = 0, rear = 0;
void enque(int value)
{
	if(rear < size)
	{
		arr[rear] = value;
		rear++;
	}
	else
	{
		cout << "Cannot add, Queue full" << endl;
	}
}
void deque()
{
	if(front == rear)
	{
		cout << "Cannot remove, Queue empty" << endl;
	}
	else
	{
		front++;
	}
}
void print()
{
	cout << "Current Queue: ";
	for(int i = front; i < rear; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

int main()
{
	enque(5);
	print();
	enque(6);
	print();
	enque(9);
	print();
	enque(1);
	print();
	enque(4);
	print();
	enque(7);
	print();
	deque();
	print();
	deque();
	print();
	deque();
	print();
	deque();
	print();
	deque();
	print();
	deque();
	print();
	return 0;
}
