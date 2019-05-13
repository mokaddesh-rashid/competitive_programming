#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* Root = NULL;

void AddLast(int value)
{
	Node* tempnode = new Node;
	tempnode->data = value;
	tempnode->next = NULL;
	tempnode->prev = NULL;

	if(Root == NULL)
	{
		Root = tempnode;
	}
	else
	{
		Node* t = Root;
		while(t->next != NULL)
		{
			t = t->next;
		}
		t->next = tempnode;
		tempnode->prev = t;
	}
}
void AddFirst(int value)
{
	Node* tempnode = new Node;
	tempnode->data = value;
	tempnode->next = NULL;
	tempnode->prev = NULL;

	if(Root == NULL)
	{
		Root = tempnode;
	}
	else
	{
		tempnode->next = Root;
		Root->prev = tempnode;
		Root = tempnode;
	}
}
void AddSorted(int value)
{
	Node* tempnode = new Node;
	tempnode->data = value;
	tempnode->next = NULL;
	tempnode->prev = NULL;

	if(Root == NULL)
	{
		Root = tempnode;
	}
	else if(value < Root->data)
	{
		tempnode->next = Root;
		Root->prev = tempnode;
		Root = tempnode;
		//AddFirst(value);
	}
	else if(Root->next == NULL)
	{
		Root->next = tempnode;
		tempnode->prev = Root;
		//AddLast(value);
	}
	else
	{
		Node* t = Root;
		while(t->next != NULL && t->next->data < value)
		{
			t = t->next;
		}
		if(t->next == NULL)
		{
			t->next = tempnode;
			tempnode->prev = t;
			//AddLast(value);
		}
		else
		{
			tempnode->next = t->next;
			tempnode->prev = t;
			t->next->prev = tempnode;
			t->next = tempnode;
		}
	}
}
void print()
{
	cout << "Current List: ";
	Node* t = Root;
	while(t != NULL)
	{
		cout << t->data << " <-> ";
		t = t->next;
	}
	cout << endl;
}

int main()
{
	AddSorted(15);
	print();
	AddSorted(12);
	print();
	AddSorted(18);
	print();
	AddSorted(14);
	print();
	AddSorted(17);
	print();
	AddSorted(25);
	print();

	return 0;
}

