#include<iostream>

using namespace std;

int main()
{
    int n,k,score[1111],par=0,i,x;

    cin>>n>>k;

    for(i=0;i<n;i++)
    {
        cin>>score[i];

        if(i==k-1)
            x=score[i];
    }

     for(i=0;i<n;i++)
     {
         if(score[i]>=x&&score[i]>0)
            par++;
     }


     cout<<par;
}
