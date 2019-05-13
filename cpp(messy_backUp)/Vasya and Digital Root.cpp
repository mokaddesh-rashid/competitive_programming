#include<iostream>

using namespace std;

int main()
{
    int k,d;

    cin>>k>>d;

    if(k>1&&d==0)
        cout<<"No solution";

    else
    {
     cout<<d;

    while(k>1)
    {
        cout<<0;
        k--;
    }

    }


}
