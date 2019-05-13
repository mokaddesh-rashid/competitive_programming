
#include<iostream>

using namespace std;

int value[111],next[111],start=-1,last=-1,i,size_a=111;

void add_first(int x)
{
    again:
    cout<<"\npos !\n";
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
       next[i]=start;
       start=i;
    }
}

void remove_first()
{
    if(start>-1)
       start=next[start];
}

void display()
{
    int t=start;

    while(t>-1)
    {
        cout<<value[t]<<' ';
        t=next[t];
    }
    cout<<endl;


}

int main()
{
    for(i=0;i<size_a;i++)
        next[i]=-2;
    add_first(1);
    display();
      add_first(2);
    display();
      add_first(3);
    display();
     add_first(4);
    display();
      add_first(5);
    display();
      add_first(6);
    display();

    cout<<endl;

      remove_first();
      display();

       cout<<endl;

       remove_first();
      display();
       cout<<endl;
      remove_first();
      display();
       cout<<endl;
       remove_first();
      display();
       cout<<endl;
      remove_first();
      display();
       cout<<endl;
       remove_first();
      display();
       cout<<endl;
      remove_first();
      display();
       cout<<endl;
       remove_first();
      display();
       remove_first();
      display();
       cout<<endl;
      remove_first();
      display();
       cout<<endl;
       remove_first();
      display();
       cout<<endl;
      remove_first();
      display();
       cout<<endl;
       remove_first();
      display();
       cout<<endl;
      remove_first();
      display();
       cout<<endl;
       remove_first();
      display();

}
