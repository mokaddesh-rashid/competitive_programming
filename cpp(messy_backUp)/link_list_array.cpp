#include<iostream>

using namespace std;

int value[111],next[111],start=-1,last=-1,i,size_a=11;

void add_last(int x)
{
    again:
    cout<<"pos !\n";
    cin>>i;

    if(start==-1)
    {
        value[i]=x;
        next[i]=-1;
        start=i;
        last=i;
    }
    else if(next[i]!=-2)
        goto again;
    else
    {
       value[i]=x;
       next[i]=-1;
       next[last]=i;
       last=i;
    }
}

void display()
{
    int t=start;

    while(t>-1)
    {
        cout<<value[t]<<' ';
        t=next[t];
    }


}

int main()
{
    for(i=0;i<size_a;i++)
        next[i]=-2;
    add_last(1);
    display();
     add_last(2);
    display();
     add_last(3);
    display();
     add_last(4);
    display();
     add_last(5);
    display();
     add_last(6);
    display();


}
