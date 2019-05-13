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

    int n,mi,ma;

    cin>>n;

    string str[n+1],age,ans1,ans2,show[n+1];
    char ch;

    int i,j,a,b,c,d,st=0,pos,arr[99999]={0},len,x;


    for(i=0;i<n;i++)
       {
            cin>>str[i];
            x=str[i].size();
            if(i==0)
            {
                mi=x;
                ma=x;
            }
            else
            {
                mi=min(mi,x);
                ma=max(ma,x);
            }

       }
    len=mi+ma;
    cin>>ch;
    x=0;
    for(i=0;i<n;i++)
    {
        string out;

        for(j=0;j<n;j++)
        {
            if(out.size()==0&&arr[j]==0)
            {
                if(i%2&&str[j].size()+age.size()==len)
                {
                    out=str[j];
                    pos=j;
                }

                else if(i%2==0)
                {
                    out=str[j];
                    pos=j;
                }
            }


            else if(out>str[j]&&arr[j]==0)
            {
                if(i%2&&str[j].size()+age.size()==len)
                {
                    out=str[j];
                    pos=j;
                }

                else if(i%2==0)
                {
                    out=str[j];
                    pos=j;
                }
            }
        }

        arr[pos]++;

        if(i%2==0)
        {
            age=out;
        }

        else
        {
        ans1=age+ch+out;
        ans2=out+ch+age;

        if(ans1<ans2)
            show[x]=ans1;
        else
            show[x]=ans2;

        x++;
        }


    }

    for(i=0;i<x;i++)
    {

        string out;

        for(j=0;j<x;j++)
        {
            if(out.size()==0&&arr[j]==1)
            {
                out=show[j];
                pos=j;
            }
            else if(out>show[j]&&arr[j]==1)
            {
                out=show[j];
                pos=j;
            }
        }

        cout<<out;
        arr[pos]++;
        cout<<endl;
    }



}

