#include<iostream>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long int n,m;

    cin>>n>>m;
    m++;
    long long int arr[10000]={0},i,a,b,c=0,d=0,x=0,st[n+1],top=-1,ar[n+1],j;


    if(n>=m)
        {
          for(i=0;i<n;i++)
              cin>>a;
        cout<<"YES";
        }

    else
    {
        for(i=0;i<n;i++)
    {
        cin>>a;

        a=a%m;
        b=top;

        for(j=0;j<=b;j++)
        {
            c=a+st[j];
            c=c%m;

            if(arr[c]==0)
            {
                arr[c]=1;
                top++;
                st[top]=c;
            }
        }

        if(arr[a]==0)
        {
            arr[a]=1;
            top++;
            st[top]=a;
        }
    }


    if(arr[0]==1||x==1)
        cout<<"YES";
    else
        cout<<"NO";
    }



    for(i=0;i<=top;i++)
        cout<<st[i]<<' ';
}
