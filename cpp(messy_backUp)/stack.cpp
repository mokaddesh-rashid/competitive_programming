#include<iostream>
#include<cstring>

using namespace std;

class stack0
{
public:
    int *ar=new int[1];
    int siz,top,x,c,d,i;

    stack0()
    {
        top=-1;
        siz=1;
        int *r=new int[siz];
        ar=r;
    }

    void push()
    {
        cout<<"push value\n";
        cin>>c;
        if(top==siz-1)
            resizeit();
        top++;
        ar[top]=c;

    }

    void pop()
    {
        if(top<0)
            cout<<"nothing to pop\n";
        else
          top--;
    }

    void resizeit()
    {
        int *newarray= new int [siz*2];
        for(i=0;i<=top;i++)
        {
            newarray[i]=ar[i];
        }
        delete [] ar;
        siz=siz*2;
        ar=newarray;
    }

    void display()
    {
        cout<<"current stack : ";
        for(i=0;i<=top;i++)
            cout<<ar[i]<<' ';

        cout<<endl;
    }

};

int main()
{
    int i;
    char ch[11];
    stack0 ob;

  for(i=0;i>=0;i++)
  {
      cout<<"what to do\n";
      cin>>ch;

      if(strcmp(ch,"push")==0)
      {
          ob.push();
      }
      else if(strcmp(ch,"pop")==0)
      {
          ob.pop();
      }
      else
        break;

         ob.display();
  }
}


