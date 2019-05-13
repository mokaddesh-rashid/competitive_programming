#include<iostream>

using namespace std;

int main()
{
    long long int n,x,i=0,y,t,m;

    cin>>t;

    for(m=0;m<t;m++)
    {
    	i=0;
        cin>>n>>x;

    y=x;
    while(x%n!=0)
    {
        x=(x*10)+y;
        i++;
    }

    cout<<"Case"<<' '<<m+1<<':'<<' '<<i+1<<"\n";
    }
}
