#include<iostream>

using namespace std;

int mat[111][111];

int main()
{
    int n, m, a, b, i, j;

    cout << "Total number of nodes\n";
    cin >> n;

    cin >> m;

    cout << "Input edges\n";

    for( i=0; i<m; i++ )
    {
        cin >> a >> b;
        mat[a][b]++;
        mat[b][a]++;
    }
    cout << "Adjacency matrix for undirected graph \n";
    for( i=1; i<=n; i++ )
    {
        for( j=1; j<=n; j++ )
        {
            cout << mat[i][j] << ' ';
        }
        cout << endl;
    }


    return 0;

}


