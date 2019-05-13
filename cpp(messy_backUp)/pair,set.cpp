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
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    set< pair<int,int> >::iterator ii;
    set< pair<int,int> > yoo;

    int i, j, x, y, n, m, frnc = 0;

    cin >> n >> m ;

    int bro[n+1];

    for( i=0; i<n; i++)
        cin >> bro[i];

    for( i=0; i<m; i++)
    {
        cin >> x >> y;
        yoo.insert( make_pair( x , y ) );
    }
    for( i=0; i<m; i++)
    {
       cin >> x >> y;
       ii = yoo.find( make_pair( x , y ) );

       if(ii != yoo.end()) {
       		pair<int,int>p = *ii;
       		cout << p.first << " " << p.second << endl;
       }

    }






    return 0;

}
