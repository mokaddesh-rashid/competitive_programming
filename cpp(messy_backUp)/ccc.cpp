#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* Root = NULL;

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


void RemoveValue(int value)
{
	if(Root == NULL)
	{
		cout << "Link is empty" << endl;
	}
	else if(Root->data == value )
	{
		Root = Root->next;
		Root->prev = NULL;
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
			cout << "Not found to remove " << endl;
		}
		else
		{

			t->next = t->next->next;
			if(t->next != NULL)
			t->next->prev = t;
		}
	}
}
void print()
{
	cout << "Current List: ";
	Node* t = Root;
	while(t->next != NULL)
	{
		cout << t->data << "  ";
		t = t->next;
	}
	cout << t->data << "  ";
	cout << endl;

	cout << "Reverse of Current List: ";

	while(t->prev != NULL)
	{
		cout << t->data << "  ";
		t = t->prev;
	}
	cout << t->data << "  ";
	cout << endl;
}

int search_val( int x )
{
	Node* t = Root;
	while(t != NULL)
	{
		if( x == t->data)
            return 1;
		t = t->next;
	}
	return 0;
}
int main()
{
    string str;
    int x, i, y;

    for( i=0; i<1111; i++ )
    {

       cout << "what you want to do ?? \n";
       cin >> str;
       cout << "input the value ?? \n";
       cin >> x;

       if( str == "add" )
       {
           AddFirst(x);
           print();
       }
       else if( str == "remove" )
       {
          RemoveValue(x);
          print();
       }
       else if( str == "search" )
       {
           y = search_val(x);
	       if( y == 1 )
              cout << "\nValue is in the list\n";
         else
              cout << "\nValue is not in the list\n";
       }
       else
        break;

       cout << endl;

    }

	print();

	return 0;
}


