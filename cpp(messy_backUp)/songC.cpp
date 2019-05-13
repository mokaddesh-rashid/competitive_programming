#include <bits/stdc++.h>

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
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

PR dir[4], cp;
int ty, ok[65][65];
string str;

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;

    dir[0] = MP(-1, 0); dir[1] = MP(0, 1);
    dir[2] = MP(1, 0); dir[3] = MP(0, -1);
    int tc;

    cin >> tc;

    FOR(tt,1, tc)
    {
        int prin = 0;
        ty = 0; mem(ok, 0);

        cin >> cp.F >> cp.S;
        cin >> str;

//        FOR(i,0,(int)str.size()-1)
//        {
//            if(str[i] == 'F')
//            {
//                cp.F += dir[ty].F;
//                cp.S += dir[ty].S;
//
//                ok[cp.F][cp.S]++;
//
//                if(ok[cp.F][cp.S] == 2) prin++;
//            }
//            else if(str[i] == 'R')
//            {
//                ty++;
//                if(ty == 4) ty = 0;
//            }
//            else
//            {
//                ty--;
//                if(ty == -1) ty = 3;
//            }
//        }

        cout << cp.F << ' ' << cp.S << ' ' << prin << endl;
    }

    return 0;
}
