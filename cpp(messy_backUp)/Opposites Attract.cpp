#include<iostream>

using namespace std;

int main()
{
    long long int pos[12]={0},neg[12]={0},i,x=0,a,b,c=0,n;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a;

        if(a>0)
            pos[a]++;
        else if(a<0)
            neg[a*-1]++;
        else
            c++;

    }

    for(i=1;i<=10;i++)
    {
        if(pos[i]>0&&neg[i]>0)
        {
            a=pos[i]*neg[i];
            x+=a;
        }
    }

    if(c>1)
        x+=(c*(c-1))/2;

    cout<<x;




}
