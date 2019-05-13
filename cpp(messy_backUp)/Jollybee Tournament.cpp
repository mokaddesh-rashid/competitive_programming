#include<bits/stdc++.h>

using namespace std;

#define PF           prLLf
#define SF(n)        scanf("%d", &n)
#define SFF(a,b)     scanf("%d %d", &a, &b)
#define SFFF(a,b,c)  scanf("%d %d %d", &a, &b, &c)
#define INF_I        2147483647    //max limit
#define INF          1999999999
#define PB           push_back
#define MEM(n, val)  memset((n), val, sizeof(n))
#define F            first
#define S            second
#define FOR(i, a, b) for(LL i = a; i <= b; i++)
#define ROF(i, a, b) for(LL i = a; i >= b; i--)
#define ALL(c)       c.begin(), c.end()
#define BOOST        std::ios_base::sync_with_stdio(false);
#define INP          freopen("in.txt", "r", stdin);
#define OUT          freopen("out.txt", "w", stdout);
#define MP           make_pair
#define INIT_RAND    srand(time(NULL))
#define MOD          1000000007
#define MX           100010
#define PI           acos(-1.0)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<LL, LL> PII;
typedef pair<long long, long long> PLL;
typedef priority_queue<LL> P_Q;
typedef queue<LL> Q;
typedef stringstream SS;

/*dir array
//8 moves
LL fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
LL fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
LL fx[]={+1,-1,+0,+0};
LL fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/

struct node {
	LL endmark, mini;
	bool used[35];
    LL mn[35];
	node *next[35];
	node()  {
		endmark=0;
		for(LL i=0;i<35;i++) next[i]=NULL;
		for(LL i=0;i<35;i++) used[i]=0;
        for(LL i=0;i<35;i++) mn[i]=-1;
	}
}*root;

LL l, n;

LL m;
LL path[35];

void ins() {//insert
	node *curr = root;
	for(LL i = 1; i <= m; i++)  {
		LL id = path[i];
		if(curr->next[id] == NULL)    {
            curr->next[id] = new node();
		}
		curr = curr->next[id];

		FOR(j, 1, i)   {
            curr->used[ path[j] ] = 1;
		}
	}
	curr->endmark++;
}
void del(node *cur) {
    for(LL i = 1;i <= l; i++) {
        if(cur->next[i])  {
            del(cur->next[i]) ;
        }
    }
    delete(cur) ;
}

LL prz[35];

LL ghuro(node *cur, LL lev) {

    LL cost = cur->endmark * prz[lev];
    LL mn = 2000000000;
    LL ans = 0;
    ///cout << "foo : ";
    FOR(i, 1, l)   {
        if(cur->used[i] == 0)   {
            if(cur->next[i] != NULL)  {
                cur->mn[i] = ghuro(cur->next[i], lev + 1);
                mn = min(mn, cur->mn[i]);
            }
            else    {
                mn = 0;
                cur->mn[i] = 0;
            }
        }
        else    {
            cur->mn[i] = -1;
        }
    }
    if(mn == 2000000000)    {
        mn = 0;
    }
    cur->mini = mn;
    ///cout << mn + cost << " ";
    return mn + cost;
}

vector<LL> res;
void pr(node *cur) {
    ///cout << "foo : ";
    FOR(i, 1, l)   {
        if(cur->used[i] == 0)   {
            if(cur->mini == cur->mn[i]) {
                ///cout << i << " ";
                res.PB(i);
                if(cur->next[i])    {
                    pr(cur->next[i]);
                }
                return;
            }
        }
    }
}

int main()  {
    INP;
    OUT;
    BOOST;
    int tc;
    cin >> tc;
    //SF(tc);
    FOR(tt, 1, tc)   {

        res.clear();
        cin >> l >> n;
        FOR(i, 1, l)   {
            cin >> prz[i];
        }
        root = new node();
        FOR(kk, 1, n)   {
            cin >> m;
            FOR(i, 1, m)   {
                cin >> path[i];
            }
            ins();
        }
        ghuro(root, 0);
        pr(root);
        del(root);

        bool chk = 0;

        bool used[35];
        MEM(used, 0);
        FOR(i, 0, (LL)res.size() - 1)   {
            if(chk) {
                cout << " ";
            }
            chk = 1;
            cout << res[i];
            used[ res[i] ] = 1;
        }
        ///cout << "   ";
        FOR(i, 1, l)   {
            if(used[i] == 0) {
                if(chk) {
                    cout << " ";
                }
                chk = 1;
                cout << i;
            }
        }
        cout << "\n";
        if(tt==tc) cout<<"\n";
    }
    return 0;
}

