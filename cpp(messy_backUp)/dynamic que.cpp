#include<iostream>

using namespace std;

int size_s=5,front0=0,rear0=0,i,x;

int *que=new int[size_s];

void resize_it()
{
    int *newarr=new int[size_s*2],a=0;
    cout<<endl;
    for(i=front0;i!=rear0;i=(front0+a)%size_s)
    {
        newarr[a]=que[i]<<' ';
        a++;
    }
    delete [] que;

    que=newarr;
    size_s*=2;
    front0=0;
    rear0=a;

}

void enque(int x)
{
    int next_rear=(rear0+1)%size_s;

    if(next_rear==front0)
      {
            resize_it();
            next_rear=(rear0+1)%size_s;
      }

      que[rear0]=x;
      rear0=next_rear;
}

void dequee()
{
    front0++;
}

void display()
{
    int a=0;
    cout<<"current que : ";
   for(i=front0;i!=rear0;i=(front0+a)%size_s)
    {
        cout<<que[i]<<' ';
        a++;
    }

    cout<<endl;
}



int main()
{
    for(i=0;i>=0;i++)
    {
        char ch;
        cout<<"what to do !!!\n";
        cin>>ch;

        if(ch=='e')
        {
            cin>>x;
            enque(x);
        }

        else if(ch=='d')
        {
            if(front0==rear0)
                cout<<"noting to deque\n";
            else
                dequee();
        }

        display();
    }
}
