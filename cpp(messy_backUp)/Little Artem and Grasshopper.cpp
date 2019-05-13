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
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long


//set<int>::iterator ii;

int arr[1000010];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = 0, y, n, m, a = 0, pos = 1 ;

    string str;

    cin >> n;

    cin >> str;

    for( i=0; i<n; i++ )
        cin >> arr[i];

    while( x < 10000000 )
    {
       // cout << pos << str[pos-1] << endl;
        if( pos < 1 || pos > n )
        {
            a = 1;
            break;
        }
        if( str[pos-1] == '>' )
        {
            pos += arr[pos-1];
        }
        else
        {
           pos -= arr[pos-1];
        }
        x++;
    }

    if( a == 0 )
        cout << "INFINITE";
    else
        cout << "FINITE";





    return 0;

}


