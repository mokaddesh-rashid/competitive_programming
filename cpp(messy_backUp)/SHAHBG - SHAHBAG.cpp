#include<iostream>

using namespace std;

int main()
{
    int arr[42000]={0},line[42000]={0},i,j,a,b,x=0,n,maxx=-1,t=0;

    cin>>n;


    for(i=0;i<n;i++)
    {
        x=0;
        t=0;
        cin>>a;
        maxx=max(maxx,a);
        arr[a]++;

        for(j=0;j<=maxx+1;j++)
        {
            if(arr[j]!=0)
            {
                x++;
            }

            else if(x>0&&arr[j]==0)
            {
                x=0;
                t++;
            }
        }

        cout<<t<<endl;



    }

    cout<<"Justice";
}
