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
Node* FindMin(Node* root)
{
  while(root->left != NULL)
    root = root->left;
  return root;
}
void Delete(struct Node *root, int data )
{
  if(root == NULL)
    return ;

  else if(data < root->data)
   Delete(root->left,data);

  else if(data > root->data)
    Delete(root->right, data);

  else
  {
    // Case 1: No Child
    if(root->left == NULL && root->right == NULL)
        {
         root = NULL;
    // Case 2: one child
       }
    else if(root->left == NULL)
    {
      struct Node *temp = root;
      root = root->right;

    }
    else if(root->right == NULL)
    {
      struct Node *temp = root;
      root = root->left;
    }
    else
    {
      struct Node *temp = FindMin(root->right);
      root->data = temp->data;
      Delete(root->right, temp->data);
    }
  }
}

void Print_In(Node* startNode)
{
	if(startNode != NULL)
	{
		Print_In(startNode->left);
		cout << startNode->data << "  ";
		Print_In(startNode->right);
	}
}

int main()
{
	Add(50);
	Add(42);
	Add(64);
	Add(34);
	Add(56);
	Print_In(Root);
	cout << endl;
	Delete(Root, 34 );
	Print_In(Root);

	return 0;
}
