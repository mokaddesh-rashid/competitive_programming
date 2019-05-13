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
          dfs(i);
      }
    }
    t++;
    en[p]=t;
}

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

int main()
{
   int i, j, a, b, c;

   make_list();
   n=7;
   dfs(2);
   if(st[3]!=0) cout<<"V3 was present in this graph\n";
   else cout<<"V3 was present in this graph\n";
}




