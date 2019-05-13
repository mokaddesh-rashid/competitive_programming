#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int bags[n+1],x=0,i,a,b,c,way=0;

    for(i=0;i<n;i++)
    {
        cin>>bags[i];
        x+=bags[i];
    }

    for(i=0;i<n;i++)
    {
        x=x-bags[i];

        if(x%2==0)
            way++;
        x+=bags[i];
    }

    cout<<way;
}
