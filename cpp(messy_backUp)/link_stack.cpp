#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* Root = NULL;

void push(int value)
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

void pop()
{
	if(Root == NULL)
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		Root = Root->next;
	}
}
void print()
{
	cout << "Current stack: ";
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
	for(int i=0; i<1111; i++)
    {
        cout << "what to do \n";
        string str;

        cin >> str;

        if( str == "push" )
        {
            int x;
            cout << "input the value \n";
            cin >> x;
            push(x);
        }
        else if( str == "pop" )
        {
            pop();
        }
        else
            break;
    }
	print();

	return 0;
}


