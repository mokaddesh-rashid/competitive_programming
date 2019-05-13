#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int ti=0,n_no=0;

class node
{
public:
    int x;
    node *next,*prev;
};

node *root=NULL;

void add(int pos,int x)
{
    node *newnode = new node;
    newnode -> x = x;
    newnode -> next = NULL;
    newnode -> prev = NULL;

    if(root==NULL)
    {
        root = newnode;
        n_no++;
    }
    else if(pos == 0)
    {
        newnode->next = root;
        root=newnode;
        n_no++;
    }
    else
    {
        int l=0;

        node *t=root;

        while(t->x != pos)
        {
            l++;
            t=t->next;
        }
        l++;
        newnode->next = t->next;
        t->next = newnode;
        //cout << min(l, n_no-l)<<endl;
        ti += min(l, n_no-l);
        n_no++;


    }
}


int main()
{
    ios::sync_with_stdio(false);

     int t;

     cin >> t;

     while (t--)
     {
         ti=0;
         n_no=0;
         int n, a, i;

          cin >> n;

         for(i=0 ;i<n ;i++)
    {
        cin >> a;
        add(a,i+1);
    }

        cout << ti <<endl;

     }






}
