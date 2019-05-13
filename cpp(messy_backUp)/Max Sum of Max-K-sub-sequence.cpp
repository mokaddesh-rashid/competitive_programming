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
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define MIN          (long long)-1000000000000000000
#define MAX          (long long) 1000000000000000000
#define mod          1000000007
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int ar[200010], pos[200010];
int main()
{
    //ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    sf(tc);//cin>>tc;
    FOR(tt,1,tc)
    {
        int i, j=0, x=0, y, n, m, ms=mod*-1, l, r, z;
        sff(n,m);//cin>>n>>m;
        z=j=n;
        FOR(i,0,n-1)
        {
            sf(ar[i]);//cin>>ar[i];
            ar[j]=ar[i]; j++;
        }
        n*=2;
        i=j=0;
        while(i<n||j<n)
        {
            if(j==n) x-=ar[i],i++;
            else if(i==j) x+=ar[j],j++;
            else if(j-i>=m) x-=ar[i],i++;
            else if(x<=0) x-=ar[i],i++;
            else x+=ar[j],j++;
            cout<<x<<'('<<i<<' '<<j<<")"<<NL;
            if((x>ms||ms==mod*-1)&&i!=j&&j-i<=m)
            {
                l=i+1; r=j;
                if(j>z)
                {
                    r%=z;
                }
                ms=x;
                //cout<<l<<' '<<r<<NL;
            }
        }
        cout<<NL;
        pf("%d %d %d\n",ms,l,r);
        //cout<<ms<<' '<<l<<' '<<r<<NL;
    }
    return 0;
}
/*
1
8 8
604 221 706 10 -489 -164 619 -591
*/

