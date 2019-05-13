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
#define mod          998244353
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 1010*50 + 2100
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int giveId;
vector<int> lis[MAX];
string str;

struct Node
{
    int id;
    Node *next[30];
    Node()
    {
        FOR(i,0,25) next[i]=NULL;
        id = giveId++;
    }
};
Node *Root;

void in(string str,int p)
{
    int n = str.size();
    Node *t = Root;

    FOR(i,0,n-1)
    {
        int c = str[i] - 'A';
        if(t->next[c] == NULL) t->next[c] = new Node();
        //cout << c << endl;
        t = t->next[c];
        lis[t->id].PB( p );
        //cout << t->id << endl;
    }
    ///cout << "inserted " << endl;
}

int ase[MAX], prin;
void dfs(Node *t)
{
    FOR(i,0,25)
    {
        if(t->next[i] == NULL) continue;
        dfs(t->next[i]);
    }

    int p = t->id;
    int a = -1, b = -1;

    for(auto x : lis[p])
    {
        if(ase[x]) continue;
        else if(a == -1) a = x;
        else if(b == -1) b = x;
        else break;
    }

    if(a != -1 && b != -1)
        prin += 2, ase[a] = ase[b] = 1;// cout << a << ' ' << b << endl;
}



int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    int tc;

    cin >> tc;
    FOR(tt,1,tc)
    {
        giveId = 0;
        int n;
        Root = new Node();

        cin >> n;
        FOR(i,0,n-1)
        {
            cin >> str;
            reverse(str.begin(), str.end());
            in(str, i);
        }

        prin = 0; mem(ase, 0);
        dfs(Root);

        cout << "Case #" << tt << ": " << prin << endl;
        FOR(i,0,giveId + 1) lis[i].clear();
    }

    return 0;
}



