#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main()
{
    char str[111][111];

    int n,i,m,x=0,leaf=0;

    cin>>n;

    for(i=0;i<n;i++)
    {
        char st[111];

        gets(st);

        if(i==0)
        {
            strcpy(str[x],st);
            x++;
            leaf++;
        }

        for(m=0;m<x;m++)
        {
            if(strcmp(str[m],st)==0)
                break;
            else if(m==x-1)
            {

            strcpy(str[x],st);
            x++;
            leaf++;

            }

        }

    }

    cout<<leaf;
}
