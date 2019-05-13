#include<iostream>

using  namespace std;

int mat[10][10], n, m, vis[10], st[10], en[10], t;

void dfs(int p)
{
    int i;
    t++;
    st[p]=t;

    for(i=1;i<=n;i++)
    {
      if(mat[p][i]!=0&&st[i]==0)
      {
          cout<<"Tree edge "<<p<<' '<<i<<endl;
          dfs(i);
      }
      else if(mat[p][i]!=0&&st[i]!=0&&en[i]==0) cout<<"Back edge "<<p<<' '<<i<<endl;
      else if(mat[p][i]!=0&&st[i]!=0&&en[i]!=0&&st[i]>st[p]) cout<<"forward edge "<<p<<' '<<i<<endl;
      else if(mat[p][i]!=0)cout<<"Cross edge "<<p<<' '<<i<<endl;
    }
    t++;
    en[p]=t;
}

int main()
{
   int i, j, a, b, c;

   cin>>n>>m;
   for(i=0;i<m;i++)
   {
       cin>>a>>b;
       mat[a][b]=1;
   }
   dfs(1);
}


