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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int b,g;

    cin>>b>>g;

    char ma,mi;

    int i,j,a,c,d,n,m;

    if(b>=g)
    {
        ma='B';
        mi='G';
        n=b;
        m=g;

        for(i=0;i<n+m;i++)
        {
            if(g==0)
            {
                cout<<ma;
            }
            else if(i%2==0)
            {
                cout<<ma;
                b--;
            }
            else
            {
                cout<<mi;
                g--;
            }

        }
    }

    else
    {
        ma='G';
        mi='B';
        n=b;
        m=g;

        for(i=0;i<n+m;i++)
        {
            if(b==0)
            {
                cout<<ma;
            }
            else if(i%2==0)
            {
                cout<<ma;
                g--;
            }
            else
            {
                cout<<mi;
                b--;
            }

        }
    }





}

