#include<iostream>
#include<vector>

using namespace std;
#define sz 1000

int ar[sz];

int main()
{
    int n, m, x, y, a, b, c=0, i, j, mi, mx;
    double avg;

    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];

        if(i==0)
        {
            mi=mx=ar[i];
        }
        else
        {
            mx=max(ar[i],mx);
            mi=min(ar[i],mi);
        }
    }
    cout<<mx<<' '<<mi<<endl;

}


