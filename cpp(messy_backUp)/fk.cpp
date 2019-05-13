#include<bits/stdc++.h>

using namespace std;

#define PF           printf
#define SF(n)        scanf("%d", &n)
#define SFF(a,b)     scanf("%d %d", &a, &b)
#define SFFF(a,b,c)  scanf("%d %d %d", &a, &b, &c)
#define INF_I        2147483647    //max limit
#define INF          1000000000
#define PB           push_back
#define MEM(n, val)  memset((n), val, sizeof(n))
#define F            first
#define S            second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define BOOST        std::ios_base::sync_with_stdio(false);
#define INP          freopen("in.txt", "r", stdin);
#define OUT          freopen("out.txt", "w", stdout);
#define MP           make_pair
#define INIT_RAND    srand(time(NULL))
#define MOD          1000000007
#define MX           (100010)
#define PI           acos(-1.0)
#define eps          .0000000001

#define cnd          tree[node]
#define lnd          tree[(node * 2)]
#define rnd          tree[((node * 2) + 1)]

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UI;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef priority_queue<int> PQ;
typedef queue<int> Q;
typedef stringstream SS;

//4 moves
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
#define valid(nx,ny) ((nx >= 0) && (nx < r) && (ny >= 0) && (ny < c))

vector<int> adjl[1010];
bool vis_ri[1010];
int left_of[1010];
int n;

bool bpm(int le)   {
    FOR(i, 0, (int)adjl[le].size() - 1)   {
        int ri = adjl[le][i];
        if((vis_ri[ri] == 0) && (left_of[ri] == -1))    {
            left_of[ri] = le;
            return true;
        }
    }
    FOR(i, 0, (int)adjl[le].size() - 1)   {
        int ri = adjl[le][i];
        if(vis_ri[ri] == 0)    {
            vis_ri[ri] = 1;
            if(bpm(left_of[ri]))    {
                left_of[ri] = le;
                //vis_ri[ri] = 0;
                return true;
            }
            ///vis_ri[ri] = 2;
        }
    }
    return false;
}

int maxbpm()    {
    MEM(left_of, -1);
    //MEM(vis_ri, 0);
    int ans = 0;
    FOR(i, 1, n)   {
        MEM(vis_ri, 0);
        if(bpm(i))  {
            ans++;
        }
    }
    return ans;
}

//vector<int> lst[1010];
vector<int> ult[1010];
vector<int> vv;

int m;
int outdeg[1010];



int main()  {
    //INP;
    //OUT;
    BOOST;
    int tc;
    cin >> tc;
    FOR(tt, 1, tc)   {
        FOR(i, 0, 1000)   {
            ult[i].clear();
        }
        MEM(outdeg, 0);
        cin >> n >> m;
        FOR(i, 1, m)   {
            int u, v;
            cin >> u >> v;
            //lst[u].PB(v);
            ult[v].PB(u);
            outdeg[u]++;
        }
        /**
        FOR(i, 1, n)   {
            cout << i << " : ";
            FOR(j, 0, (int)ult[i].size() - 1)   {
                cout << ult[i][j] << " ";
            }
            cout << "\n";
        }
        */
        int ans = 0;
        FOR(i, 1, n)   {
            if(outdeg[i] == 0)   {
                ans++;
                vv.PB(i);
            }
        }
        while(!vv.empty()) {
            /**
            FOR(i, 0, (int)vv.size() - 1)   {
                cout << vv[i] << " ";
            }
            cout << "\n";
            */
            FOR(i, 1, n)   {
                adjl[i].clear();
            }
            vector<int> tmp;
            FOR(i, 0, (int)vv.size() - 1)   {
                int v = vv[i];
                //cout << v << " : ";
                FOR(j, 0, (int)ult[v].size() - 1)   {
                    int u = ult[v][j];
                    outdeg[u]--;
                    //cout << u << " ";
                }
                //cout << "\n";
            }
            FOR(i, 0, (int)vv.size() - 1)   {
                int v = vv[i];
                FOR(j, 0, (int)ult[v].size() - 1)   {
                    int u = ult[v][j];
                    if(outdeg[u] == 0)  {
                        adjl[u].PB(v);
                        tmp.PB(u);
                    }
                }
            }
            sort(tmp.begin(), tmp.end());
            tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
            vv = tmp;

            ans += vv.size() - (maxbpm());
        }
        cout << "Case " << tt << ": ";
        cout << ans << "\n";
    }
    return 0;
}
/**
1
3 0

1
12 13
1 4
2 4
2 5
3 5
4 6
4 7
5 7
5 8
5 9
8 7
9 11
9 12
10 12
*/
