#include<iostream>

using namespace std;

int main()
{
    int n,i;

    cin>>n;

    while(n>1)
    {
        cout<<n<<' ';

        for(i=2;i<n;i++)
        {
            if(n%i==0)
            {
                break;
            }
        }
         n/=i;
    }

    cout<<1<<endl;
}
