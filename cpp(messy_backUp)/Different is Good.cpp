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



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x = 0, y, n, m, arr[99] = {0};

    string str;
    cin >> str;
    n = str.size();

    if( n > 26 )
        cout << -1;
    else
    {
       for( i=0; i<n; i++ )
       {
           y = str[i] - 97;
           arr[y]++;
       }
       for( i=0; i<26; i++ )
       {
           if( arr[i] > 1 )
           {
               x += ( arr[i] - 1 );
           }
       }

       cout << x;
    }





    return 0;

}


