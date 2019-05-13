#include<iostream>
#include<cstring>

using namespace std;

class matching
{
public:
     char A[111],B[111];
    int i,n,a,b,c=0,d,e=0,f=0,ar[11];
    matching()
    {
      cin>>A>>B;
      a=strlen(A);
      b=strlen(B);
    for(i=0;i<a;i++)
    {
        if(A[i]==B[0])
            { c=0;
              d=i;
                for(n=0;n<b;n++)
                {
                    if(B[n]==A[d])
                    {
                        c++;
                        d++;
                    }
                    else
                       {
                           c=0;
                            break;
                       }

                }
                if(c==b)
                    {
                        e++;
                        ar[f]=i;
                        f++;

                    }
            }
    }
    }

    void display()
    {


        if(e==0)
        cout<<"Not Found"<<endl;



    else
     {
         cout<<e<<"\n";

     for(i=0;i<e;i++)
        cout<<ar[i]+1<<"\t";
    }
    }
};

int main()
{
    int t,i;
    cin>>t;
    matching ob[t];
    for(i=0;i<t;i++)
        ob[i].display();

}
