#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int n,m,p;

    cin>>n>>m>>p;

    int arr[n+1][m+1],i,x,a,b,maxi=0,c,point[n+1],max_at=-1,y;

    for(i=0;i<n;i++)
    {
        maxi=0;
        c=0;
        for(x=0;x<m;x++)
        {
               cin>>arr[i][x];

            if(arr[i][x]==1)
                c++;
            else if(arr[i][x]==0)
               {
                  maxi=max(c,maxi);
                  c=0;
               }
        }
        maxi=max(c,maxi);
        point[i]=maxi;
        cout<<point[i]<<endl;
    }

    for(y=0;y<p;y++)
    {
        cin>>a>>b;
        a--;
        b--;

        if(arr[a][b]==0)
        {
            arr[a][b]=1;


        }
        else if(arr[a][b]==1)
        {
            arr[a][b]=0;

        }
        maxi=0;
        c=0;
        for(i=0;i<m;i++)
        {
               if(arr[a][i]==1)
                c++;
            else if(arr[a][i]==0)
               {
                  maxi=max(c,maxi);
                  c=0;
               }
        }
        maxi=max(c,maxi);
        point[a]=maxi;
        c=0;
        for(i=0;i<n;i++)
            c=max(c,point[i]);

        cout<<c<<endl;
    }
}
