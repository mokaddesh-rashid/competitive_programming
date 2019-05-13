#include<iostream>

using namespace std;

int n, m, mat[20][20];

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
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j;

    make_list();
    n=7;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cout<<mat[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}


