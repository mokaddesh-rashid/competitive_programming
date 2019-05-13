#include<iostream>

using namespace std;

int main()
{
    long long int n,i,t,x=1,a,b;

    cin>>n>>t;

    for(i=0;i<n-1;i++)
    {
        cin>>a;
        x+=a;

        if(x==t)
            {
                cout<<"YES";
                break;
            }
        else if (x>t)
           {
                cout<<"NO";
                break;
           }
    }
}
