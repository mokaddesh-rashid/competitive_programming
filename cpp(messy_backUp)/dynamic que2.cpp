#include<iostream>

using namespace std;

int size_q=1,front0,rear=0,i;

int *que=new int [size_q];


void resize_it()
{
    int *newque=new int [size_q*2];
    int a=0;
    for(i=front0;i!=rear;i=(i+1)%size_q)
    {
        newque[a]=que[i];
        a++;
    }

    delete [] que;

    que=newque;
    front0=0;
    rear=a;
    size_q*=2;

}

void enquee(int x)
{
    int next_rear=(rear+1)%size_q;

    if(next_rear==front0)
        {
            resize_it();
            que[rear]=x;
            rear=(rear+1)%size_q;

        }
    else
    {
        que[rear]=x;
        rear=next_rear;
    }



}

void dequee()
{
    if(front0!=rear)
       front0++;
}

void display()
{
    cout<<"current que : ";
    for(i=front0;i!=rear;i=(i+1)%size_q)
    {
        cout<<que[i]<<' ';
    }
    cout<<endl;
}

int main()
{
    int i,a,b;
    char ch;

    for(i=0;i>=0;i++)
    {
        cin>>ch;

        if(ch=='e')
        {
            cin>>a;
            enquee(a);
        }
        else if(ch=='d')
            dequee();
        display();


    }
}
