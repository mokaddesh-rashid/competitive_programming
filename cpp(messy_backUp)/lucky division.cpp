#include<iostream>

using namespace std;

int main()
{
    int num,x=0,i,ar[111]={4,7,44,47,74,77,444,447,477,777,744,774,747,474};

    cin>>num;
    for(i=0;i<14;i++)
    {
        if(num%ar[i]==0)
            x=1;
    }
    if(x==1)
        cout<<"YES";
    else
        cout<<"NO";
}
