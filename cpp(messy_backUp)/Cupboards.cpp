#include<iostream>

using namespace std;

int main()
{
    long long int n,a=0,b=0,c=0,d=0,x,i;

    cin>>n;


    for(i=0;i<n;i++)
    {
        cin>>x;

        if(x==0)
            a++;
        else
            b++;
        cin>>x;

        if(x==0)
            c++;
        else
            d++;

    }

    cout<<min(a,b)+min(c,d);


}
