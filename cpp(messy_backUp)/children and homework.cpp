#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int value[2000]={0},a,b,i;

    b=n/2;

    if(n%2)
        b++;

    for(i=0;i<n;i++)
    {
        cin>>a;
        value[a]++;
    }
    a=0;
    for(i=0;i<=1000;i++)
    {
        a=max(a,value[i]);
    }

    //cout<<a<<' '<<b<<' ';

    if(a<=b)
        cout<<"YES";
    else
        cout<<"NO";


}
