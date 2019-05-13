#include <bits/stdc++.h>

using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
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
typedef pair<int,int> pr;

/*dir array
//8 moves
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/


//set<int>::iterator ii;
int n, m;
int ara[100010];
int coin[5] = {50, 20, 10, 5, 1};

int dp[100010];
int cnt[6];

bool func(int make)  {
    if(make < 0)    {
        return 0;
    }
    if(make == 0)   {
        return dp[make] = 1;
    }
    if(dp[make] != -1)    {
        return dp[make];
    }
    bool ans = 0;
    FOR(i, 0, 4)   {
        ans = (ans | func(make - coin[i]));
    }
    return dp[make] = ans;

}

int tmpcnt[6];

void bt(int make)  {
    if(make < 0)    {
        return;
    }
    if(make == 0)   {
        return;
    }
    bool ans = 0;
    FOR(i, 0, 4)   {
        if((make - coin[i] >= 0) && (dp[make - coin[i]]))    {
            tmpcnt[i]++;
            bt(make - coin[i]);
            break;
        }
        //ans = (ans | bt(make - coin[i]));
    }
    //return dp[make] = ans;

}
int main()
{
    ios::sync_with_stdio(false);
    int tc;
    cin >> tc;
    FOR(tt, 1, tc)  {
        cin >> n >> m;
        FOR(i, 1, m)   {
            cin >>  ara[i];
        }
        MEM(dp, -1);
        MEM(cnt, 0);
        sort(ara + 1, ara + m + 1);
        if(ara[m] != n)    {
            m++;
            ara[m] = n;
        }

        FOR(i, 1, m)   {

            MEM(tmpcnt, 0);
            func(ara[i]);
            //cout << func(ara[i]) << "\n";
            bt(ara[i]);
            FOR(i, 0, 4)    {
                cnt[i] = max(cnt[i], tmpcnt[i]);
            }
        }
        REV(i, 4, 0)   {
            if(i != 4)  {
                cout << " ";
            }
            cout << cnt[i];
        }
        cout << "\n";
    }

    return 0;

}
/*
2
150 4
150 123 70 20
212 3
1 200 61

1
212 3
1 200 61
*/

