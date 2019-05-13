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

int arr[10000001];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    int n = 0;
   // while( n < 100 )
    {
        LL i, j, x = 0, y = 2, m = 9, l = 0, p ,sp;

     cin >> n;

    while( x < n )
    {
        l += 2;
        if( x + m < n )
            x = x+m;
        else
        {
            break;
        }
        m = m*10;
    }
    sp = 0;
    while( x < n )
    {
        if( x + m < n )
            {
                x = x+m;
                arr[sp] =
            }
        else
        {
            x++;
            break;
        }
        if( m > 10 )
           m = m/10;
        else
          m = m/9;
    }
    //cout << x << endl << l << endl;

    p = l/2;
    sp = p+1;

    while( x < n )
    {
        //arr[sp]++;
        arr[p]++;
        x++;
        if( arr[p] == 10 )
        {
             while( arr[p] == 10 )
             {
                  arr[p] = 0;
                  arr[p-1]++;
                  p--;
             }
             for( i=p+1; i<=l/2; i++ )
                arr[i] = 0;
             p = l / 2;
        }
    }
    //cout << l << endl;
    for( i=1; i<=l/2; i++ )
        cout << arr[i];
    for( i=l/2; i>0; i-- )
        cout << arr[i];

        cout << endl;
    }



    return 0;

}


