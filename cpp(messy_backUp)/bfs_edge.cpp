#include<iostream>

using  namespace std;

int mat[10][10], que[10], he, re, n, m, vis[10], ase[10];

void bfs(int root)
{
    int p,i;
    he=re=0;
    que[re]=root;
    re++;

    while(he!=re)
    {
        p=que[he];
        ase[p]=1;
        he++;
        vis[p]=1;

        for(i=1;i<=n;i++)
        {
          if(mat[p][i]!=0&&vis[i]==0)
          {
              cout<<"Tree edge "<<p<<' '<<i<<endl;
              que[re]=i;
              re++;
              vis[i]=1;
          }
          else if(mat[p][i]!=0&&ase[i]==0&&vis[i]==1) cout<<"Back edge "<<p<<' '<<i<<endl;
          else if(mat[p][i]!=0)cout<<"cross edge "<<p<<' '<<i<<endl;

        }
        ase[p]=0;
    }
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
   bfs(1);
}

