#include <bits/stdc++.h>


using namespace std;

int main()
{
    int i, k, t, n, a[] = {1, 2, 3, 4, 5},arr[7],maxx=0,x,y,mat[7][7];

    for(i=0;i<5;i++)
        arr[i]=i+1;

    for(i=1;i<=5;i++)
        for(n=1;n<=5;n++)
    {
        cin>>mat[i][n];
    }

    n = 5; // 4 elements

   {
              y=mat[arr[1-1]][arr[2-1]]+mat[arr[2-1]][arr[1-1]]+mat[arr[3-1]][arr[4-1]]+mat[arr[4-1]][arr[3-1]];
              y=y+mat[arr[3-1]][arr[2-1]]+mat[arr[2-1]][arr[3-1]]+mat[arr[5-1]][arr[4-1]]+mat[arr[4-1]][arr[5-1]];
              y=y+mat[arr[3-1]][arr[4-1]]+mat[arr[4-1]][arr[3-1]];
              y=y+mat[arr[4-1]][arr[5-1]]+mat[arr[5-1]][arr[4-1]];
            }
            maxx=max(maxx,y);


    while(next_permutation(arr,arr+n))
     {
        y=0;


            {
              y=mat[arr[1-1]][arr[2-1]]+mat[arr[2-1]][arr[1-1]]+mat[arr[3-1]][arr[4-1]]+mat[arr[4-1]][arr[3-1]];
              y=y+mat[arr[3-1]][arr[2-1]]+mat[arr[2-1]][arr[3-1]]+mat[arr[5-1]][arr[4-1]]+mat[arr[4-1]][arr[5-1]];
              y=y+mat[arr[3-1]][arr[4-1]]+mat[arr[4-1]][arr[3-1]];
              y=y+mat[arr[4-1]][arr[5-1]]+mat[arr[5-1]][arr[4-1]];
            }
            maxx=max(maxx,y);
     }


       // cout << "\n";


    cout<<maxx;

    return 0;
}
