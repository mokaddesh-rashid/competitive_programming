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

    long long int i, j, n, m, a=0, b=0, c=0, d=0, x=0, y=0, z=0,  st, en;
    string str;
    char ch;

    cin >> n;

    st=-1;
    en=1;
    i=0;

    while( i < 9 )
    {
        st *=10;
        en *=10;

        i++;
    }
    st*=2;
    en*=2;

    for( i=0; i<n; i++)
    {
        cin>>str;
        cin>>a;
        cin>>ch;

        if(str==">"&&ch=='Y')
        {
            st=max(st,a+1);
        }
        else if(str=="<"&&ch=='Y')
        {
            //en=a-1;
            en=min(en,a-1);
        }
        else if(str==">="&&ch=='Y')
        {
           // st=a;
            st=max(st,a);
        }
        else if(str=="<="&&ch=='Y')
        {
           // en=a;
            en=min(en,a);
        }
        else if(str==">"&&ch=='N')
        {
            //en=a;
             en=min(en,a);
        }
        else if(str=="<"&&ch=='N')
        {
            //st=a;
            st=max(st,a);
        }
        else if(str==">="&&ch=='N')
        {
            //en=a-1;
            en=min(en,a-1);
        }
        else if(str=="<="&&ch=='N')
        {
           // st=a+1;
            st=max(st,a);
        }

       // cout<<st<<' '<<en<<endl;

        if(st>en)
            c=1;


    }

    if(c==1)
        cout<<"Impossible";
    else if(st==en)
        cout<<st;
    else
        cout<<(st+en)/2;





}

