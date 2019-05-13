#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* Root = NULL;

void enque(int value)
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
void dequee()
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


void print()
{
	cout << "Current queue: ";
	Node* t = Root;
	while(t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}
	cout << endl;
}

int main()
{

	enque(4);
	dequee();
	enque(4);
	enque(5);
	enque(6);
	enque(7);
	print();
	dequee();
	print();

	return 0;
}

