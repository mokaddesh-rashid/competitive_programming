#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    long long int i,x=0,a,b=0,y=0,energy=0;

    for(i=0;i<n;i++)
    {
        cin>>a;

        energy=energy+(b-a);

        if(energy<0)
        {
            y=y-energy;
            energy=0;

        }
        b=a;
    }

    cout<<y;
}
