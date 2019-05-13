#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>

using namespace std;

#define INF          freopen("in.txt", "r", stdin);
#define OUTF          freopen("out.txt", "w", stdout);
#define PF           printf
#define SF(n)        scanf("%d", &n)
#define SFF(a,b)     scanf("%d %d", &a, &b)


//set<int>::iterator ii;

int main()
{
   // ios::sync_with_stdio(false);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int i, j, x = 0 , y = 0 , n, m , mx = 0, mn = 100000;

    cin >> n  ;

    int arr[n+1];

    for( i=0; i<n; i++)
        {
            cin >> arr[i];
            mx = max( arr[i], mx);
            mn = min( arr[i], mn);
        }

    sort( arr, arr+n);

    for( i=0; i<n; i++)
    {
        if( arr[i]*2 < mx )
            x++;
        else
            break;
    }

    for( i=n-1; i>=0; i--)
    {
        if( arr[i] > mn*2 )
            y++;
        else
            break;
    }

    cout << min(x,y);





    return 0;

}

