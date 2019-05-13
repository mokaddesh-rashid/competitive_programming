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

    int n,m;

    cin >> n >>m;

    int arr[n+1],a_t[100000+1]={0},pos[100000+1]={0},brr[n+1],b_t[100000+1]={0},i,j,a,x=0,ans[m+3],b=0,c=0;

    for(i=0;i<n;i++)
    {
        cin>> arr[i];

        a=arr[i];
        a_t[a]++;
        pos[a]=i;
    }

   for(i=0;i<m;i++)
    {
        cin>> brr[i];
        a=brr[i];
        b_t[a]++;
    }

    for(i=0;i<m;i++)
    {
       a=brr[i];

       if(a_t[a]<0)
            b=1;
       if(a_t[a]>1)
            c=1;

       if(a_t[a]>=1)
       {
           ans[x]=pos[a]+1;
           //a_t[a]--;
           x++;
           cout<<arr[x]<<' ';

       }
    }

    if(x<m)
        cout<<"Impossible";
    else if(c==1)
        cout<<"Ambiguity";
    else
    {

         cout<<"Possible"<<endl;

        for(i=0;i<m;i++)
    {
        //cout<<m<<endl;
        cout << ans[i]<<' ';
    }


    }





}
