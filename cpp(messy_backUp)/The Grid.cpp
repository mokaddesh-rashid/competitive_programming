#include<iostream>

using namespace std;

int main()
{
    int i,n,a,b,c,d;

    cin>>n;

    for(i=0;i<n;i++)
    {
        cin>>a>>c>>b>>d;

        cout<<"Case"<<' '<<i+1<<':'<<' '<<max(a-b,b-a)+max(c-d,d-c)<<endl;
    }
}
