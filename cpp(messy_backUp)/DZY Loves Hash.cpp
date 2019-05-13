#include<iostream>


using namespace std;

int main()
{
    long long int n,m,p;

    cin>>p>>n;


    int value[n+1],x,i,a,b,pos[p+1],arr_dis[n+1],ans=-1;

    fill_n(pos,p+1,0);

    for(i=0;i<n;i++)
    {
        cin>>value[i];

        pos[value[i]%p]++;

        if( pos[value[i]%p]>1&&ans==-1)
            ans=i+1;

    }

    cout<<ans;




}

