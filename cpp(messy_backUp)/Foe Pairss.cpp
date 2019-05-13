#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m;

    cin >> n >> m ;

    set < pair < int, int > > foe;
    set < pair < int, int > > :: iterator ii;

    int arr[n+1], f[2*m+1], s[2*m+1], can[n+1], france = 0;

    memset( can, 0, sizeof(can));

    for( i=0; i<n; i++)
    {
        cin >> arr[i];
    }


    for( i=0; i<m; i++)
    {
        cin >> x >> y;

        foe.insert( make_pair(x,y));
        foe.insert( make_pair(y,x));
    }

    //cout << endl;

    x = 0;

    for( ii= foe.begin(); ii != foe.end(); ii++)
    {
        pair< int, int> p = *ii ;
        f[x] = p.first;
        s[x] = p.second;
        x++;
        //cout << p.first << ' ' <<p.second << endl;
    }

    i = 0;
    j = 0;
    int low , up, k;
   // cout << endl << endl ;
    while(i < n || j < n )
    {
//        if( i == n-1 && j == n-1 )
//            break;
        if( can[arr[j]] == 0 && j < n )
        {
            low = lower_bound( f, f+x, arr[j] ) - f;
            up  = upper_bound( f, f+x, arr[j] ) - f;
            for( k=low; k<up; k++)
            {
                cout << s[k] << ' ';
                can[s[k]]++;
            }
            j++;
        }

        else
        {
            //if( j != n-1)
            france += ( j - 1 - i );
//            else
//            france += ( j - i );
            //cout << ( j - 1 - i ) <<endl;
            low = lower_bound( f, f+x, arr[i] ) - f;
            up  = upper_bound( f, f+x, arr[i] ) - f;
           // cout << low << ' ' << up << endl;
            for( k=low; k<up; k++)
            {
                     can[s[k]]--;
            }
            i++;

        }

    //cout << i << ' ' << j << endl;
    }

    cout << france+n ;

    return 0;

}


