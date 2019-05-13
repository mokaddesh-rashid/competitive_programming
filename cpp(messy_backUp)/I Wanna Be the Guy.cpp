#include<iostream>

using namespace std;

int main()
{
    int n;

    cin>>n;

    int level[111]={0},x,i,a,oh=0;

    cin>>x;

    for(i=0;i<x;i++)
    {
        cin>>a;

        level[a-1]=1;
    }

    cin>>x;

    for(i=0;i<x;i++)
    {
        cin>>a;

        level[a-1]=1;
    }

    for(i=0;i<n;i++)
    {
        if(level[i]==0)
            oh=1;
    }

    if(oh==1)
        cout<<"Oh, my keyboard!";
    else
        cout<<"I become the guy.";


}
