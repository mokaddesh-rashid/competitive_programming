#include<iostream>

using  namespace std;

int mat[10][10], que[10], he, re, n, m, vis[10];

void make_list()
{
   mat[1][2]=1;
   mat[1][4]=1;
   mat[2][4]=1;
   mat[2][5]=1;
   mat[3][1]=1;
   mat[3][4]=1;
   mat[3][6]=1;
   mat[4][3]=1;
   mat[4][6]=1;
   mat[4][7]=1;
   mat[4][5]=1;
   mat[5][7]=1;
   mat[6][3]=1;
   mat[6][7]=1;
   mat[7][6]=1;
   mat[7][4]=1;
}

void bfs(int root)
{
    int p,i;
    he=re=0;
    que[re]=root;
    re++;

    while(he!=re)
    {
        p=que[he];
        he++;
        vis[p]=1;
        ///cout<<p<<" = ";
        for(i=1;i<=n;i++)
        {
          if(mat[p][i]!=0&&vis[i]==0)
          {
             /// cout<<i<<' ';
              que[re]=i;
              re++;
              vis[i]=1;
          }
        }
        ///cout<<endl;
    }
}


int main()
{
   int i, j, a, b, c;

   n=7;
   make_list();
   bfs(2); ///starting node 2
   if(vis[3]==1) cout<<"V3 was present in this graph\n";
   else cout<<"V3 was not present in this graph\n";
}
