#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int in[1000010], que[100010], hd, re;
LL xo[1000010];
vector<pr> mv;

int main()
{
    ios::sync_with_stdio(false);
    int i, j, x, y, n, m, p, q;

    cin >> n;

    FOR(i,0,n-1)
    {
        cin>>in[i]>>xo[i];
        if(in[i]==1)que[re++]=i;
    }

    while(hd<re)
    {
       p=que[hd];
       //cout << p << ' ' << xo[p] << ' ' << in[p] << endl;
       if( in[p] > 0 )
       {
           q=xo[p];
           in[q]--;
           xo[q]=xo[q]^p;
           if(in[q]==1)que[re++] = q;
           mv.PB( MK(p,q) );
       }
       hd++;
    }

    cout << mv.size() << endl;
    m = mv.size();
    FOR(i,0,m-1)
    {
        cout << mv[i].F << ' ' << mv[i].S << endl;
    }
    return 0;

}


