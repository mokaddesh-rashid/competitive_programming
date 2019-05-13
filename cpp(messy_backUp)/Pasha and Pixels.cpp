#include<iostream>

using namespace std;

int main()
{
    int r,c,k;

    cin>>r>>c>>k;

    int arr[r+3][c+3];

    int i,n,a=0,b,d;

    for(i=0;i<k;i++)
    {
        cin>>r>>c;

        arr[r][c]=-1;

        if(arr[r-1][c-1]==-1&&arr[r-1][c]==-1&&arr[r][c-1]==-1&&arr[r][c]==-1)
        {
            a=1;
            break;
        }
        else if(arr[r-1][c]==-1&&arr[r-1][c+1]==-1&&arr[r][c]==-1&&arr[r][c+1]==-1)
        {
            a=1;
            break;
        }

        else if(arr[r][c-1]==-1&&arr[r][c]==-1&&arr[r+1][c-1]==-1&&arr[r+1][c]==-1)
        {
            a=1;
            break;
        }
        else if(arr[r][c]==-1&&arr[r][c+1]==-1&&arr[r+1][c]==-1&&arr[r+1][c+1]==-1)
        {
            a=1;
            break;
        }


    }

    if(a==1)
    {
        cout<<i+1;
    }

    else
        cout<<0;
}
