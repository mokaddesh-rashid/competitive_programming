
#include<iostream>
using namespace std;

struct node{
    int data;
    node *l;
    node*r;
};
node *root = NULL;
node *t = NULL;

void add(node* t, node *n = root){

    if (n != NULL){
        if (t->data < n->data){
            if (n->l == NULL)
                n->l = t;
            else
                add(t, n->l);
        }
        else{
            if (n->r == NULL)
                n->r = t;
            else
                add(t, n->r);
        }
    }
}
void Preorder(node* startNode)
{
    if(startNode != NULL)
	{
	    cout << startNode->data << "  ";
		Preorder(startNode->l);
		Preorder(startNode->r);


	}
}

void inorder (node* startNode)
{
	if(startNode != NULL)
	{
	    inorder(startNode->l);
	    cout << startNode->data << "  ";
		inorder(startNode->r);


	}
}


void postorder(node* startNode)
{
	if(startNode != NULL)
	{
        postorder(startNode->l);
        postorder(startNode->r);
	    cout << startNode->data << "  ";

	}
}
int main(){
top:
    cout << "which value do you want to add?" << endl;
    int n;
    cin >> n;
    node*newnode = new node;
    newnode->data = n;
    newnode->l = NULL;
    newnode->r = NULL;
    if (root == NULL)
        root = newnode;
    else
        add(newnode, root);
    cout << "current tree preorder :";
    Preorder( root );
    cout << endl;
    cout << "current tree inorder :";
    inorder( root );
    cout << endl;
    cout << "current tree postorder :";
    postorder( root );
    cout << "\n";
    cout << "for not adding more enter 'n' otherwise enter others letters : ";
    char c;
    cin >> c;
    if (c != 'n')
        goto top;
    return 0;
}

