#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* Root = NULL;

void AddLast(int value)
{
	Node* tempnode = new Node;
	tempnode->data = value;
	tempnode->next = NULL;

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
	}
}
void AddFirst(int value)
{
	Node* tempnode = new Node;
	tempnode->data = value;
	tempnode->next = NULL;

	if(Root == NULL)
	{
		Root = tempnode;
	}
	else
	{
		tempnode->next = Root;
		Root = tempnode;
	}
}
void AddSorted(int value)
{
	Node* tempnode = new Node;
	tempnode->data = value;
	tempnode->next = NULL;

	if(Root == NULL)
	{
		Root = tempnode;
	}
	else if(value < Root->data)
	{
		tempnode->next = Root;
		Root = tempnode;
		//AddFirst(value);
	}
	else if(Root->next == NULL)
	{
		Root->next = tempnode;
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
			//AddLast(value);
		}
		else
		{
			tempnode->next = t->next;
			t->next = tempnode;
		}
	}
}
void RemoveFirst()
{
	if(Root == NULL)
	{
		cout << "Link is empty" << endl;
	}
	else
	{
		Root = Root->next;
	}
}
void RemoveLast()
{
	if(Root == NULL)
	{
		cout << "Link is empty" << endl;
	}
	else if(Root->next == NULL)
	{
		Root = NULL;
	}
	else
	{
		Node* t = Root;
		while(t->next->next != NULL)
		{
			t = t->next;
		}
		t->next = NULL;
	}
}

void RemoveValue(int value)
{
	if(Root == NULL)
	{
		cout << "Link is empty" << endl;
	}
	else if(Root->data == value)
	{
		Root = Root->next;
		//RemoveFirst();
	}
	else
	{
		Node* t = Root;
		while(t->next != NULL && t->next->data != value)
		{
			t = t->next;
		}
		if(t->next == NULL)
		{
			cout << "Not found" << endl;
		}
		else
		{
			t->next = t->next->next;
		}
	}
}
void print()
{
	cout << "Current List: ";
	Node* t = Root;
	while(t != NULL)
	{
		cout << t->data << " -> ";
		t = t->next;
	}
	cout << endl;
}

int main()
{
	AddLast(14);
	print();
	AddFirst(19);
	print();
	AddFirst(12);
	print();
	AddLast(16);
	print();
	AddLast(17);
	print();
	AddFirst(11);
	print();
	AddFirst(13);
	print();
	AddFirst(15);
	print();

	RemoveFirst();
	print();
	RemoveLast();
	print();
	RemoveValue(16);
	print();
	RemoveValue(100);
	print();

	return 0;
}

