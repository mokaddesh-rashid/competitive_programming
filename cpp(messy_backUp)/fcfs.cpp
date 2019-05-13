#include<iostream>

using namespace std;


int ar[10001], br[10001];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x = 0, y, n, m;

    cout << "Total Number of process?\n";
    cin >> n;

    for( i=0; i<n; i++ )
    {
        cout << "Burst time and arrival time of " << i+1 << "th command?\n";
        cin >> br[i] >> ar[i];
    }

    for( i=0; i<n; i++ )
    {
        cout << "Waiting time for " << i+1 << "th command " << max( 0,x-ar[i]) << endl;
        x += br[i];
    }





    return 0;

}


