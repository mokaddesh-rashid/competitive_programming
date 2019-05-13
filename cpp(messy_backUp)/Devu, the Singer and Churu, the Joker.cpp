#include<iostream>

using namespace std;

int main()
{
    int m,d;

    cin>>m>>d;

    int i,n,x=0,a,b,c=0,j=0,s=0;

    for(i=0;i<m;i++)
    {
        cin>>a;
        x=x+a;

        if(x>d)
        {
            c=1;
            break;

        }
        s++;
        if(x+10<=d)
        {
            x+=10;
            j+=2;
        }

    }

    j=j+((d-x)/5);
    if(s==m)
        cout<<j;
    else
        cout<<-1;

   // cout<<x;
}
