#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string str,xtra;

    cin>>str;
    xtra=str;

    int m,n,i,a,b,c,x,y,k,j,t,p;

    cin>>m;

    for(i=0;i<m;i++)
    {
        cin>>a>>b>>c;

        a--;
        t=b-a;
        n=c%t;

        for(j=a;j<b;j++)
        {
            p=(j+n)%b;
            if((j+n)/b>0)
                p+=a;
            xtra[p]=str[j];
        }
        str=xtra;


    }
     cout<<str<<endl;



}

