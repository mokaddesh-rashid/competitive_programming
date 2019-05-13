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
#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000007
#define LL           long long
#define NL '\n


//set<int>::iterator ii;


int arr[11111], chk[11111];

int func ( char ch )
{
    if( ch >= '0' && ch <= '9' )
        return ch-48;
    else if( ch >= 'a' && ch <= 'z' )
        return ch-97+36;
    else if( ch >= 'A' && ch <= 'Z' )
        return ch-65+10;
    else if( ch == '-' )
        return 62;
    else
        return 63;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    LL i, j, x = 0, y, n, m, a = 1;

    for( i=0; i<64; i++ )
        for( j=0; j<64; j++)
    {
        y = i & j;
        arr[y]++;

    }

     //for( i=0; i<64; i++ )
       // cout << i << ' ' << arr[i] << endl;


    string str;

    cin >> str;

    n = str.size();

    for( i=0; i<n; i++ )
   {

       x = func( str[i] );
       //cout << str[i] << ' ' << x << endl;
       chk[x]++;
   }

   for( i=0; i<64; i++ )
   {
       while( chk[i] > 0 )
       {
           //cout << a << ' ' << i << ' ' << arr[i] << endl;
           a = a * arr[i];
           a = a % mod;
           chk[i]--;
           //cout << a << ' ' << arr[i] << endl;
       }
   }

   cout << a;
    return 0;

}



