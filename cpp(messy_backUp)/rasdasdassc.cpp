#include<bits/stdc++.h>

using namespace std;

#define PF           printf
#define SF(n)        scanf("%d", &n)
#define SFF(a,b)     scanf("%d %d", &a, &b)
#define SFFF(a,b,c)  scanf("%d %d %d", &a, &b, &c)
#define INF_I        2147483647    //max limit
#define INF          1999999999
#define PB           push_back
#define MEM(n, val)  memset((n), val, sizeof(n))
#define F            first
#define S            second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define ALL(c)       c.begin(), c.end()
#define BOOST        std::ios_base::sync_with_stdio(false);
#define INP          freopen("in.txt", "r", stdin);
#define OUT          freopen("out.txt", "w", stdout);
#define MP           make_pair
#define INIT_RAND    srand(time(NULL))
#define MOD          1000000007
#define MX           100010
#define SZ           100010
#define PI           acos(-1.0)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef priority_queue<int> PQ;
typedef queue<int> Q;
typedef stringstream SS;

/*dir array
//8 moves
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/

string str;

int main()  {
    //INP;
    //OUT;
    BOOST;
    int tc;
    cin >> tc;
    //SF(tc);
    cin.ignore();
    FOR(tt, 1, tc)   {
        ///cin >> str;
        getline(cin, str);

        int past = 1;
        int mn = 1;
        int mx = 1;
        //bool chk = 1;
        FOR(i, 0, (int)str.size() - 1)   {
            if(str[i] == '<')   {
                past++;
                //chk = 0;
            }
            else if(str[i] == '>')   {
                past--;
                //chk = 0;
            }
            else if(str[i] == '=')  {
                //chk = 0;
            }
            //cout << past << "\n";
            mn = min(mn, past);
            mx = max(mx, past);
        }

        cout << mx + (1 - mn) << "\n";
    }
    return 0;
}
