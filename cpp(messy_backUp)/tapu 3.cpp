#include<iostream>
#include<vector>

using namespace std;
#define sz 1000

int A[sz][sz], B[sz][sz], C[sz][sz];

int main()
{
    int n, m, x, y, a, b, c=0, i, j, mi, mx;
    double avg;

    n=2; m=3;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>A[i][j];
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>B[i][j];
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            C[i][j]=A[i][j]+B[i][j];
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<C[i][j]<<' ';
        }
        cout<<endl;
    }
}



