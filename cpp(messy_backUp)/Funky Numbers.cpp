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
    ios::sync_with_stdio(false);

   // INP;
    //OUT;

    int i, j, x = 0, y, n = 1, m;

    cin >> m  ;

    int arr[100000];

    while( ( n * (n+1) / 2 ) <= m )
    {
        //cout << n * (n+1) / 2 << endl;
        arr[n-1] = n * (n+1) / 2;
        n++;

    }

    i = 0;
    j = n-2;

    while( i <= j )
    {
       //cout << arr[i] << ' ' << arr[j] << endl;
       if( arr[i]+arr[j] > m )
           j--;
       else if ( ( arr[i]+arr[j] < m ))
           i++;
       else
       {
           x = 1;
           break;
       }
    }

    if( x == 0 )
        cout << "NO";
    else
        cout << "YES";



    return 0;

}

