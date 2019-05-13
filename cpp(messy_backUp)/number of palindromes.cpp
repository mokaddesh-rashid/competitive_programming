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
#define MAX 400010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,int> PR;

#define ba 31

string s;
char olel[MAX];
struct node
{
    int next[26], len, suffixLink, numOfTime[2], endPos;
};

node tree[MAX];
int suff, id;

void initTree()
{
    FOR(i,0,id + 1)
    {
        memset(tree[i].next, 0, sizeof(tree[i].next));
        tree[i].len = tree[i].suffixLink = tree[i].numOfTime[0] = tree[i].numOfTime[1] = tree[i].endPos = 0;
    }

    suff = 2; id = 2;
    tree[1].len = -1; tree[1].suffixLink = 1;
    tree[2].len = 0; tree[2].suffixLink = 1;
}

int addChar(int pos,int lev) ///return tree if new node/palin is created
{
    int cur = suff, curlen = 0;
    int go = s[pos] - 'a'; ///current character to add

    while(true)
    {
        //cout << 'H' << endl;
        curlen = tree[cur].len;
        if(pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
            break;
        cur = tree[cur].suffixLink;
    }

    if(tree[cur].next[go])
    {
        suff = tree[cur].next[go];
        tree[suff].numOfTime[lev]++;
        return false;
    }

    id++;
    suff = id;
    tree[id].len = tree[cur].len + 2;
    tree[id].endPos = pos;

    tree[cur].next[go] = id;

    if(tree[id].len == 1)
    {
        tree[id].suffixLink = 2;
        tree[id].numOfTime[lev] = 1;
        return true;
    }

    while(true)
    {
        cur = tree[cur].suffixLink;
        curlen = tree[cur].len;
        if(pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
        {
            tree[id].suffixLink = tree[cur].next[go];
            break;
        }
    }
    tree[suff].numOfTime[lev] = 1;

    return true;
}


map<LL,int> mopa;
int cnt[MAX * 2][2];

int getId(LL v)
{
    if(mopa[v] == 0) mopa[v] = mopa.size();
    return mopa[v];
}

void getPalinOccurance(int lev)
{
    scanf("%s", olel);
    s = olel;
    int n = s.size();

    for(int i = 0; i < n; i++) addChar( i, lev);
    for(int i = id; i >= 3; i--)
        tree[ tree[i].suffixLink ].numOfTime[lev] += tree[i].numOfTime[lev];

}

int ara[4];

void solve()
{
    initTree();
    LL prin = 0;

    getPalinOccurance(0);
    suff = 2;
    getPalinOccurance(1);

    FOR(i,3,id)
    {
        prin += (LL)tree[i].numOfTime[0] * tree[i].numOfTime[1];
    }

    pf("%lld\n", prin);

}


int main() ///ekta palindrome kon string a beshi ase among 2 string
{
    int tc;

    sf(tc);
    FOR(tt,1,tc)
    {
        pf("Case #%d: ", tt);
        solve();
    }

    return 0;
}

