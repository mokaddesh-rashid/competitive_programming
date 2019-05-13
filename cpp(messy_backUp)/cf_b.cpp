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

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)


//set<int>::iterator ii;

string str[1011];
int arr[10001],brr[10001];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, cnt = 0, a, b, c = 0;

    cin >> n >> m ;

    for( i=0; i<n; i++ )
    {
        cin >> str[i];
    }

    for( i=0; i<n; i++ )
        for( j=0; j<m; j++ )
    {
        if( str[i][j] == '*' )
            {
                cnt++;
                arr[i]++;
                brr[j]++;
            }
    }

    for( i=0; i<n; i++ )
        for( j=0; j<m; j++ )
    {

        if( arr[i]+brr[j]-1 == cnt && str[i][j] == '*' )
            {
               // cout << i << ' ' << j << ' ' << arr[i] << ' ' << brr[j] << ' ' << cnt << endl;
                a = i+1;
                b = j+1;
                c = 1;
            }
        else if( arr[i]+brr[j] == cnt && str[i][j] == '*' )
            {
               // cout << i << ' ' << j << ' ' << arr[i] << ' ' << brr[j] << ' ' << cnt << endl;
                a = i+1;
                b = j+1;
                c = 1;
            }


    }

    if( c == 0 )
        cout << "NO";
    else
        cout << "YES" << endl << a << ' ' << b;




    return 0;

}


