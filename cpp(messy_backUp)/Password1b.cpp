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


string str;
int i, j, x, y, n, m;



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

     cin >> str;

     n = str.size();

     int st = 0, en = n, maxx = mn, mid, a, b, c;


     while( st <= en )
     {
         mid = ( st + en ) / 2;

         a = 0;
         b = n-mid;
         c = 0;
         cout << st << ' ' << en << ' ' << mid << endl;
         while( str[a] == str[b] && a < mid && a <= b)
         {
             a++;
             b++;
             c++;
         }

         if( c == mid )
           {
                //cout << mid << endl;
                en = mid-1;

           }
         else
         {
             st = mid+1;
         }




     }



    return 0;

}


