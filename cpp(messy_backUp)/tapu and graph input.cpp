#include<iostream>
#include<vector>

using namespace std;
#define sz 1000

int mat[sz][sz];
vector<int> adjl[sz], cost[sz];


int main()
{
    int n, m, x, y, a, b, i, j;
    char ch, co;

    cin>>n>>m;
    for(i=0;i<m;i++)
    {
      cin>>ch>>co>>x;
      a=ch-'a'; b=co-'a';
      mat[a][b]=x;
      adjl[a].push_back(b);
      cost[a].push_back(x);
    }

    cout<<endl<<"  ";
    for(i=0;i<n;i++)
    {
        ch=i+'a';
        cout<<ch<<' ';
    }
    for(i=0;i<n;i++)
    {
        ch=i+'a';
        cout<<ch<<' '
        for(j=0;j<n;j++)
        {
            cout<<mat[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;

    for(i=0;i<n;i++)
    {
        x=adjl[i].size();
        ch=i+'a';
        cout<<ch<<" = ";
        for(j=0;j<x;j++)
        {
            ch=adjl[i][j]+'a'; b=cost[i][j];
            cout<<ch<<'('<<b<<')'<<' ';
        }
        cout<<endl;
    }

}
