#include<iostream>


using namespace std;


int mat[111][111];

int main()
{

    int n, m, a, b, i, j, from, to;

    n = 6;

    while( true )
    {
        char ch;

        cout << "What to do\n";
        cin >> ch;
        cout << endl;
        if( ch == 'c' )
        {
            cout << "Input edges\n";
            cout << "From\n";
            cin >> from;
            cout << "To\n";
            cin >> to;
            cout << endl;
            mat[from][to]++;

        }

        else if( ch == 'p' )
        {
          cout << "NUmber of the node?\n";
          cin >> i;
          cout << i << " -> ";

        for( j=1; j<=n; j++ )
        {
            if( mat[i][j] != 0 )
                 cout << j << ' ';
        }
          cout << endl;
        }

         else if( ch == 'q' )
            break;

    }

    return 0;

}

