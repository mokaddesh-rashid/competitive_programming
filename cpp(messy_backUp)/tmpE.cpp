#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define NL '\n'
#define xx first
#define yy second
#define PB push_back
#define mp make_pair
#define pii pair<int,int>
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%I64d",&x)
#define sd(x) scanf("%lf",&x)
#define ss(x) scanf("%s",x)
#define MEM(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define READ(f) freopen(f,"r",stdin)
#define WRITE(f) freopen(f,"w",stdout)
#define cnd tree[idx]
#define lnd tree[idx*2]
#define rnd tree[(idx*2)+1]
#define lndp (idx*2),(b),((b+e)/2)
#define rndp (idx*2+1),((b+e)/2+1),(e)
#define pi 2.0*acos(0.0)
#define MOD 1000000007
#define MAX 100005

int n;
string str[60];
vector<int> vv[3000][30];

int dp[60][60];
bool vis[60][60];
bool hoise;


int func(int u1, int u2)  {
    if(u1 == u2)    {
        hoise = 1;
        vis[u1][u2] = 1;
        return dp[u1][u2] = 0;
    }
    if(vis[u1][u2])    {
        return dp[u1][u2];
    }
    int ans = -100000;
    FOR(k, 0, 25)   {
        FOR(i, 0, (int)vv[u1][k].size() - 1)   {
            int v1 = vv[u1][k][i];
            if(v1 <= u1)   {
                continue;
            }
            FOR(j, 0, (int)vv[u2][k].size() - 1)   {
                int v2 = vv[u2][k][j];
                if(v2 >= u2)   {
                    continue;
                }
                if(v1 > v2) {
                    continue;
                }
                /*
                if(v1 == v2)    {
                    ans = max(ans, 1 + func(v1, v2));
                }
                else    {
                    ans = max(ans, 2 + func(v1, v2));
                }
                */
                ans = max(ans, 2 + func(v1, v2));
            }
        }
    }
    if(str[u1][u2] != '*')  {
        hoise = 1;
        ans = max(ans, 1);///u1, u2 er majher ta niye
    }

    /*
    if(u1 != u2)  {

    }
    */
    vis[u1][u2] = 1;
    return dp[u1][u2] = ans;
}

string bt(int u1, int u2)  {
    if(u1 == u2)    {
        return "";
    }
    FOR(k, 0, 25)   {
        FOR(i, 0, (int)vv[u1][k].size() - 1)   {
            int v1 = vv[u1][k][i];
            if(v1 <= u1)   {
                continue;
            }
            FOR(j, 0, (int)vv[u2][k].size() - 1)   {
                int v2 = vv[u2][k][j];
                if(v2 >= u2)   {
                    continue;
                }
                if(v1 > v2) {
                    continue;
                }
                if(dp[u1][u2] == (2 + dp[v1][v2]))    {
                    string tmp = "";
                    tmp += (k + 'A');
                    return tmp + bt(v1, v2) + tmp;
                }
                //ans = max(ans, 2 + bt(v1, v2));
            }
        }
    }
    //ans = max(ans, 1);///u1, u2 er majher ta niye
    if(str[u1][u2] != '*')  {
        if(dp[u1][u2] == 1) {
            string tmp = "";
            tmp += str[u1][u2];
            return tmp;
        }
    }
    /*
    if(u1 != u2)  {

    }
    */
    //return dp[u1][u2] = ans;
    return "";
}
/*
FOR(i, 'A', 'Z')   {
    FOR(i, u1 + 1, n - 1)   {
        ROF(j, u2 - 1, 0)   {
            if(str[u1][i] == )    {

            }
            func(i, j);
        }
    }
}
*/
int main()
{
    //int cases, caseno=0, n, i, j, k, sum=0, cnt=0;
    ios_base::sync_with_stdio(0);
    int tc;
    cin >> tc;
    FOR(tt, 1, tc)   {
        cin >> n;
        FOR(i, 0, n - 1)   {
            cin >> str[i];
        }
        FOR(i, 0, n - 1)   {
            FOR(j, 0, n - 1)   {
                if(str[i][j] == '*')   {
                    continue;
                }
                vv[i][str[i][j] - 'A'].PB(j);
            }
        }
        /*
        FOR(i, 0, vv[0][0].size() - 1)   {
            cout << vv[0][0][i] << " ";
        }
        cout << "\n";
        */
        MEM(vis, 0);
        //cout << func(0, n - 1) << "\n";
        hoise = 0;
        func(0, n - 1);
        if(hoise)   {
            cout << bt(0, n - 1) << "\n";
        }
        else    {
            cout << "NO PALINDROMIC PATH" << "\n";
        }

        ///clear
        FOR(i, 0, n - 1)   {
            FOR(j, 0, n - 1)   {
                if(str[i][j] == '*')   {
                    continue;
                }
                vv[i][str[i][j] - 'A'].clear();
            }
        }
    }


    //func()

    return 0;
}
/*
1
3
*A*
A*B
*B*


1
2
*A
A*



2
5
*ABAC
A*CBD
BC*CB
ABC*A
CDBA*

5
*AXYZ
A*BQR
XB*BT
YQB*A
ZRTA*
*/
