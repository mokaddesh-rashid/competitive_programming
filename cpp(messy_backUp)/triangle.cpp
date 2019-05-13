#include<iostream>

using namespace std;

int main()
{
    int a[4],b,c,d,e,i,n;
    for(i=0;i<4;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<4;i++)
        for(n=i;n<4;n++)
    {
        if(a[i]<a[n])
            swap(a[i],a[n]);
    }


    if(a[0]==a[1]&&a[1]==a[2]||a[1]==a[2]&&a[2]==a[3])
        cout<<"TRIANGLE";
    else if(a[0]<a[1]+a[2]||a[1]==a[2]+a[3])
        cout<<"TRIANGLE";
    else if(a[0]==a[1]+a[2]||a[1]==a[2]+a[3])
        cout<<"SEGMENT";
    else
       cout<<"IMPOSSIBLE";

}
