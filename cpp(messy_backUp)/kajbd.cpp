#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};

Node* Root = NULL;

void Add(int value)
{
	Node* temp = new Node;
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;

	if(Root == NULL)
	{
		Root = temp;
	}
	else
	{
		Node* t = Root;
		while(true)
		{
			if(value < t->data)
			{
				if(t->left == NULL)
				{
					t->left = temp;
					break;
				}
				else
				{
					t = t->left;
				}
			}
			else
			{
				if(t->right == NULL)
				{
					t->right = temp;
					break;
				}
				else
				{
					t = t->right;
				}
			}
		}
	}
}

void Preorder(Node* startNode)
{
	if(startNode != NULL)
	{
	    cout << startNode->data << "  ";
		Preorder(startNode->left);
		Preorder(startNode->right);


	}
}
void inorder_asending(Node* startNode)
{
	if(startNode != NULL)
	{
	    inorder_asending(startNode->left);
	    cout << startNode->data << "  ";
		inorder_asending(startNode->right);


	}
}
void inorder_desending(Node* startNode)
{
	if(startNode != NULL)
	{
	    inorder_desending(startNode->right);
	    cout << startNode->data << "  ";
	    inorder_desending(startNode->left);



	}
}

void postorder(Node* startNode)
{
	if(startNode != NULL)
	{
        postorder(startNode->left);
        postorder(startNode->right);
	    cout << startNode->data << "  ";

	}
}

int main()
{
	Add(50);
	Add(42);
	Add(64);
	Add(34);
	Add(56);
	cout << " Preorder : ";
	Preorder(Root);
	cout << endl;
	cout << " Inorder : ";
	inorder_asending(Root);
	cout << endl;
	cout << " Inorder : ";
	inorder_desending(Root);
	cout << endl;
	cout << " Postorder : ";
	postorder(Root);
	cout << endl;

	return 0;
}
