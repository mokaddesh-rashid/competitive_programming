#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    int n;

    cin>>n;

    char str[n+1][n+1],digonal[3*n],extra[n*n],ch;
    int i,a=0,b=n-1,c=0,d=0,x,y=0;

    for(i=0;i<n;i++,a++,b--)
    {
        for(x=0;x<n;x++)
        {
            cin>>ch;

            if(x==a||x==b)
            {
                digonal[c]=ch;
                c++;
            }

            else
            {
                extra[d]=ch;
                d++;
            }
        }
    }
    for(i=1;i<c;i++)
    {
        if(digonal[i]!=digonal[i-1])
            y=1;
    }

     for(i=1;i<d;i++)
    {
        if(extra[i]!=extra[i-1])
            y=1;
    }

    if(extra[0]==digonal[0])
        y=1;

    if(y==0)
        cout<<"YES";
    else
        cout<<"NO";



}
