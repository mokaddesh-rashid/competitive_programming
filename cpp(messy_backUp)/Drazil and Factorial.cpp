#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

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

    string str;

    int i, j, x = 0, y, n, m, arr[100000];

    cin >> n ;

    cin >> str;

    for( i=0; i<n; i++)
    {
        if( str[i] == '0' || str[i] == '1' )
        {
            continue;
        }
        else if( str[i] == '4' )
        {
            arr[x] = 2;
            x++;
            arr[x] = 2;
            x++;
            arr[x] = 3;
            x++;

        }
        else if( str[i] == '6' )
        {
            arr[x] = 5;
            x++;
            arr[x] = 3;
            x++;

        }
        else if( str[i] == '8' )
        {
            arr[x] = 7;
            x++;
            arr[x] = 2;
            x++;
            arr[x] = 2;
            x++;
            arr[x] = 2;
            x++;

        }

            else if( str[i] == '9' )
        {
            arr[x] = 7;
            x++;
            arr[x] = 3;
            x++;
            arr[x] = 3;
            x++;
            arr[x] = 2;
            x++;

        }
        else
        {
            //cout << 'k';
            arr[x] = str[i] - 48;
            x++;
        }

    }

    sort( arr, arr+x, greater<int>());

    for( i=0; i<x; i++)
        cout << arr[i];

    return 0;

}


