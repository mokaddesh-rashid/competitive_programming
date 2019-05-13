#include<iostream>
#include<cstring>


using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    int n;

    cin>>n;

    char ch[n+1],c;

    int a,b,x=0,i,j,y=0;

    for(i=0;i<n;i++)
    {
        cin>>a>>b;

        if(x+a-y<=500)
        {
            x+=a;
            ch[i]='A';
        }
        else
        {
            y+=b;
            ch[i]='G';

        }
    }


    if(max(x-y,y-x)>500)
       cout<<-1;
    else
        for(i=0;i<n;i++)
           cout<<ch[i];


}
