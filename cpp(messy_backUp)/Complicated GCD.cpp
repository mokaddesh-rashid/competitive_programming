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


//set<int>::iterator ii;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    string str, ss;

    cin >> str;

    cin >> ss;

    if( str == ss )
         cout << str;
    else
         cout << 1;



    return 0;

}

