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

    long long int i, j, x, y, n, m, arr[100001] = {0} , maxx = mn, ans;

   // cout << maxx << endl;

    cin >> n ;

    for( i=0; i<n; i++)
    {
        cin >> x;

        arr[x]++;

        if( arr[x] > maxx )
        {
            //cout << 'k';
            maxx = arr[x];
            ans = x;
        }
    }

    cout << ans;

    return 0;

}


