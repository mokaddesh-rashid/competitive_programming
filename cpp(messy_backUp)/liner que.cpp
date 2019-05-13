#include<iostream>

using namespace std;

int size_q=5,front0=0,rear0=0,i,x;
int *que=new int[size_q];

void resize_it()
{
    size_q*=2;
    int *newarr=new int[size_q];

    for(i=front0;i<rear0;i++)
    {
        newarr[i]=que[i];
    }

    delete [] que;

    que=newarr;
}

void enque_q(int x)
{
    if(rear0==size_q)
        resize_it();
    que[rear0]=x;
    rear0++;
}

void deque_q()
{
    front0++;
}

void display()
{
    cout<<"current que : ";
    for(i=front0;i<rear0;i++)
        cout<<que[i]<<' ';

    cout<<endl;
}


int main()
{
    for(i=0;i>=0;i++)
    {
        char ch;
        cout<<"what to do !!\n";
        cin>>ch;

        if(ch=='e')
        {
            cin>>x;
            enque_q(x);
        }

        if(ch=='d')
        {
           if(front0==rear0)
            cout<<"empty que\n";

           else
             deque_q();
        }

        display();
    }

}

