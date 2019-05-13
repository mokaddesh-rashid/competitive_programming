#include<iostream>

using namespace std;

class stack_p
{
public:
    int top,i,a,b,c,size_st;
    int *st=new int [1];

    stack_p()
    {
        top=-1;
        size_st=1;
        int *temp= new int [1];
        st=temp;

    }

    void push(int x)
    {
        this->top++;

        if(top==size_st)
            this->resize_st();

        this->st[top]=x;
    }
     void pop()
    {
        if(top!=-1)
           this->top--;
    }

    void resize_st()
    {
        int *temp=new int [size_st*2];

        for(i=0;i<=top;i++)
            temp[i]=this->st[i];

        delete [] st;
        size_st*=2;
        this->st=temp;
    }

    void display()
    {
        cout<<"current stack : ";

        for(int i=0;i<=this->top;i++)
            cout<<this->st[i]<<' ';

        cout<<endl;
    }

};

int main()
{
   stack_p ob;
   ob.pop();
   ob.pop();
   ob.pop();
   ob.push(12);
   ob.push(1);
   ob.push(122);
   ob.push(12);
   ob.push(1);
   ob.push(122);
   ob.push(12);
   ob.push(1);
   ob.push(122);
   ob.pop();
   ob.display();



}
