#include<iostream>


using namespace std;

int main()
{
    int s,n;

    cin>>s>>n;

    long long int i,a=0,b,c,dra_stren[n+1],bonus[n+1],d,x;

    for(i=0;i<n;i++)
    {
        cin>>dra_stren[i]>>bonus[i];
    }

    d=n-1;

    for(i=0;i<=d;i++,d--)
        for(x=i;x<=d;x++)
    {
        if(dra_stren[i]>dra_stren[x])
        {
            swap(dra_stren[i],dra_stren[x]);
            swap(bonus[i],bonus[x]);
        }

        if(dra_stren[d]<dra_stren[x])
        {
            swap(dra_stren[d],dra_stren[x]);
            swap(bonus[d],bonus[x]);
        }
    }

     for(i=0;i<n;i++)
    {
        if(s>dra_stren[i])
            s+=bonus[i];
        else
        {
            a=1;
            break;
        }
    }

    if(a==0)
        cout<<"YES";
    else
        cout<<"NO";


}
