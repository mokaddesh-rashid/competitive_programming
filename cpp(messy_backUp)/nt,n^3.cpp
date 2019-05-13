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




long long int i, j, x, y, n, m, arr[4000100];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;


    for( i=0; i<=3000010; i++)
    {
        //x = bm( i+1,3);
        arr[i] = (i + 1) * (i + 1) * (i + 1);
    }
    while(1) {

        cin >> n;
        if(n == 0)
        {
            break;
        }
        i = 0;
        j = 0;
        bool chk = 0;
        while( i < 3000010 && j < 3000010)
        {
            if( arr[i] - arr[j] < n )
            {
                i++;
            }
            else if( arr[i] - arr[j] > n )
            {
                j++;
            }
            else    {
                chk = 1;
                break;
            }

        }

        if(chk == 0)
            cout << "No solution\n";
        else
           cout << i+1 << " " << j+1 << "\n";
    }


    return 0;

}
