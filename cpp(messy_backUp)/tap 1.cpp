#include<iostream>
#include<vector>

using namespace std;
#define sz 1000

int ar[sz];

int main()
{
    int n, m, x, y, a, b, c=0, i, j, sum;
    double avg;

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
        c += ar[i];
    }

    cout<<"The numbers are ";
    for(i=0;i<n;i++) cout<<ar[i]<<' ';
    cout<<endl;

    cout<<"Sum is "<<c<<endl;

    avg=c; avg/=n;
    cout<<"Average is "<<avg<<endl;

}

