#include<iostream>

using namespace std;

class queuee
{
public:
    int frontt,rear,i,a,b,c,size_st;
    int *st=new int [1];

    queuee()
    {
        rear=0;
        frontt=0;
        size_st=1;
        int *temp= new int [1];
        st=temp;

    }

    void enque(int x)
    {
        int nxt=rear+1;

        if(nxt==size_st)
            this->resize_st();

        this->st[rear]=x;

        rear++;
    }
     void dequee()
    {
        if(frontt!=rear)
              frontt++;
    }

    void resize_st()
    {
        int *temp=new int [size_st*2];
        int a=0;

        for(i=frontt;i<rear;i++,a++)
            temp[a]=this->st[i];

        delete [] st;
        this->rear=a;
        this->frontt=0;
        size_st*=2;
        this->st=temp;
    }

    void display()
    {
        cout<<"current queue : ";

        for(int i=this->frontt;i<this->rear;i++)
            cout<<this->st[i]<<' ';

        cout<<endl;
    }

};

int main()
{
   queuee ob;

    ob.enque(1);
    ob.enque(2);
    ob.enque(3);
    ob.enque(4);
    ob.enque(5);
    ob.display();
    ob.dequee();
    ob.display();
    ob.dequee();
    ob.dequee();
    ob.dequee();
    ob.dequee();
    ob.dequee();
    ob.dequee();
    ob.dequee();
    ob.dequee();
    ob.dequee();
    ob.display();
    ob.enque(1);
    ob.enque(2);
    ob.enque(3);
    ob.enque(1);

    ob.display();


}
