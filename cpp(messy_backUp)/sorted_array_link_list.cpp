#include<iostream>

using namespace std;

int value[111111],next[11111],start=-1,last=-1,i;


int sorted(int x)
{
    again:
    cout<<"\npos !\n";
    cin>>i;

    if(start==-1)
    {
        start=i;
        last=i;
        value[i]=x;
        next[i]=-1;
    }
    else if(next[i]!=-2)
        goto again;
    else if(x<=value[start])
    {
          value[i]=x;
          next[i]=start;
          start=i;

    }
     else if(x>=value[last])
    {
          value[i]=x;
          next[last]=i;
          last=i;
          next[last]=-1;

    }
    else
    {
        int t=start;
        int s=next[start];

        while(value[s]<x)
        {
            s=next[s];
            t=next[t];
        }

        value[i]=x;
        next[i]=next[t];
        next[t]=i;

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

    cout<<endl<<endl;
}


int main()
{
     for(int x=0;x<111;x++)
        next[x]=-2;


    for(int x=0;x>=0;x++)
    {
        int a;
        cout<<"value\n";
        cin>>a;
        sorted(a);
        display();
    }
}
