#include<iostream>

using namespace std;

class queuee
{
public:
    int frontt,rear,i,a,b,c,size_st;
    int *st=new int [5];

    queuee()
    {
        rear=0;
        frontt=0;
        size_st=5;
        int *temp= new int [5];
        st=temp;

    }

    void enque(int x)
    {
        int nxt=(this->rear+1)%size_st;

        if(nxt==frontt%size_st)
            this->resize_st();

        this->st[this->rear]=x;

        this->rear=(this->rear+1)%size_st;
    }
     void dequee()
    {
        if(frontt!=rear)
           this->frontt=(this->frontt+1)%size_st;
    }

    void resize_st()
    {
        int *temp=new int [size_st*2];
        int a=0;

        for(i=frontt;i!=rear;i=(i+1)%size_st,a++)
            temp[a]=this->st[i];

        delete [] st;
        size_st*=2;
        this->rear=a;
        this->frontt=0;
        this->st=temp;
    }

    void display()
    {
        cout<<"current queue : ";

        for(i=frontt;i!=rear;i=(i+1)%size_st)
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
    ob.dequee();
    ob.dequee();
    ob.display();
     ob.enque(1);
   ob.enque(2);
   ob.enque(3);
   ob.enque(4);
   ob.enque(5);
   ob.display();



}
