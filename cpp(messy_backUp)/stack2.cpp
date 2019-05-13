#include<iostream>

using namespace std;


class stack0
{
public:
     static int x;
    int top,i,a;
    int *card=new int [10];

    stack0(int y)
    {
        top=y-1;
        for(i=top;i>=0;i--)
            cin>>card[i];
    }

    void game(stack0 &p1,stack0 &p2)
    {
        int c;
        while(p1.top!=-1&&p2.top!=-1)
        {
            x++;
            int *newarr=new int[10];

            if(p1.card[p1.top]>p2.card[p2.top])
            {
                c=0;
                for(i=0;i<=p1.top+1;i++)
                {
                    if(i==0)
                        newarr[i]=p1.card[p1.top];
                    else if(i==1)
                        newarr[i]=p2.card[p2.top];
                    else
                    {
                        newarr[i]=p1.card[c];
                        c++;
                    }

                }



            p1.top++;
            p2.top--;
            delete p1.card;
            p1.card=newarr;

            }

            else if(p1.card[p1.top]<p2.card[p2.top])
            {
                c=0;
                for(i=0;i<=p2.top+1;i++)
                {

                    if(i==0)
                        newarr[i]=p2.card[p2.top];
                    else if(i==1)
                        newarr[i]=p1.card[p1.top];
                    else
                    {
                        newarr[i]=p2.card[c];
                        c++;
                    }
                }

                p1.top--;
                p2.top++;
                delete p2.card;

                p2.card=newarr;


            }

            if(x>10*10*10)
            {
                p1.top=-3;

                break;
            }

        }
    }


};

int stack0::x =0;



int main()
{
   int n,k;

   cin>>n>>k;

   stack0 p1(k);

   cin>>k;
   stack0 p2(k);

   p1.game(p1,p2);



   if(p1.top==-3)
       cout<<-1;
   else if(p2.top==-1)
   {
       cout<<stack0::x<<endl;
    cout<<1;
   }
   else
   {
       cout<<stack0::x<<endl;
      cout<<2;
   }

}
