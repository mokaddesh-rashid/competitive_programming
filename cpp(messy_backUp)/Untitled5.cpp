#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
#include <map>
#include <cstring>
#include <limits>
#include <limits.h>

using namespace std;

#define READ() freopen("in.txt","r",stdin)
#define WRITE() freopen("out.txt","w",stdout)
#define sf(n) scanf("%d",&n)
#define lsf(n) scanf("%lld", &n)
#define pb(n) push_back(n)

//#define debug(x,xString) cout << "value of " << xString<< "  : " << x << endl
//#define debug() cout << "working!!" << endl;
#define MAX 10000007
#define MOD 1000000007


int toMin(string s)
{
    int minits = 0;

    int fx = 0;
    for(int i=0;i<s.size();i++)
    {
        if(i < 2)
        {
            int x = s[i];
            x -= 48;
            fx *= 10;
            fx += x;
        }
        else if( i == 2)
        {
            minits = fx*60;
            fx = 0;
        }
        else if(i > 2)
        {
            int x = s[i];
            x -= 48;
            fx *= 10;
            fx += x;
        }

    }

    minits += fx;
    return minits;
}

void toDot(int x)
{
    int f = x/60;
    int s = x%60;

    if(f < 10)cout << 0;
    cout << f << ":";

    if(s < 10)cout << 0;
    cout << s;
}

int freq[3000];

int main()
{

//    cout << convertToBase10("67",8);
//    cout << convertToAnyBaseFrom10(522,16);

    int t;
    cin >> t;

    while(t--)
    {
        memset(freq,0,sizeof(freq));

        int n;
    cin >> n;
    int start,endd;

    while(n--)
    {
        string s,s1;
        cin >> s;
        cin >> s1;

        for(int i=toMin(s);i<=toMin(s1);i++)
        {
            freq[i]++;
        }

        int maxMin = 0;
//    int start;
    for(int i=0;i<2000;i++)
    {
        if(freq[i] > maxMin)
        {
            maxMin = freq[i];
            start = i;
        }
    }

//    int endd ;
    int i = start;
    while(1)
    {
        if(freq[i] != maxMin)
        {
            endd = i-1;
            break;
        }
        i++;
    }



    }

         toDot(start);
    cout << " ";
    toDot(endd);
    cout << endl;
    }


//    cout << toMin("10:15");







    return 0;
}



