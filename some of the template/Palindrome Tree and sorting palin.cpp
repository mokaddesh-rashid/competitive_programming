#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define MAX 150010
#define ba 100001
#define LL unsigned long long
typedef pair<LL,LL> PR;

string s;
int n;
LL bits[MAX], has[MAX], mul[MAX], bag[MAX];
LL M = 1000000007, MI = 943660570;

void dude()
{
    LL c = 0;
    mul[0] = bag[0] = 1;

    FOR(i,0,n-1)
    {
        if(i > 0)
        {
            mul[i] = (LL)mul[i - 1] * ba; mul[i] %= M;
            if(i == 1) bag[i] = MI;
            else  bag[i] = (bag[i-1] * bag[1]) % M;
        }

        c += (LL)bits[i] * mul[i]; c %= M;
        has[i] = c;
    }
}


LL ran(int l,int r)
{
    LL ret = has[r] + M;

    if(l) ret -= has[l - 1]; ret %= M;
    ret *= bag[l]; ret %= M;

    return ret;
}


bool isGreater(int l,int r,int x,int y)
{
    int len = min((r - l), (y - x));
    int st = 0, en = len, mid, mc = -1;

    while(st <= en)
    {
        mid = (st + en)>>1;

        if(ran(l, l + mid) == ran(x, x + mid)) st = mid + 1, mc = max(mc, mid);
        else en = mid - 1;
    }

    if(mc == len) return (r - l) < (y - x);
    return (s[l + mc + 1] < s[x + mc + 1]);
}


struct node
{
    int next[26], len, suffixLink, numOfTime, endPos;
};

node tree[MAX];
int suff, id;

void initTree()
{
    suff = 2; id = 2;
    tree[1].len = -1; tree[1].suffixLink = 1;
    tree[2].len = 0; tree[2].suffixLink = 1;
}

int addChar(int pos) ///return tree if new node/palin is created
{
    int cur = suff, curlen = 0;
    int go = s[pos] - 'a'; ///current character to add

    while(true)
    {
        curlen = tree[cur].len;
        if(pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
            break;
        cur = tree[cur].suffixLink;
    }

    if(tree[cur].next[go])
    {
        suff = tree[cur].next[go];
        tree[suff].numOfTime++;
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
        tree[id].numOfTime = 1;
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
    tree[suff].numOfTime = 1;

    return true;
}

pair<PR, int> ara[MAX];
LL osa[MAX];

int main()
{
    ios::sync_with_stdio(false);
    int l, r, x, y, nPal = 0, q;
    LL c = 0;

    cin >> n >> q;
    cin >> s;

    FOR(i,0,n-1) bits[i] = s[i];
    dude(); initTree();


    for(int i = 0; i < n; i++) addChar( i );
    for(int i = id; i >= 3; i--)
        tree[ tree[i].suffixLink ].numOfTime += tree[i].numOfTime;

    nPal = id - 2;
    for(int i = id, j = 0; i >= 3; i--, j++)
    {
        int l = tree[i].endPos - tree[i].len + 1;
        int r = tree[i].endPos;

        ara[j].S = tree[i].numOfTime;
        ara[j].F = make_pair(l, r);
    }

    sort(ara, ara + nPal, [](pair<PR, int> x, pair<PR, int> y)
         {
            PR u = x.F, v = y.F;
            return isGreater(u.F, u.S, v.F, v.S);
         });


    c = 0;
    FOR(i,0,nPal-1) { c += ara[i].S; osa[i] = c; }
    FOR(i,1,q)
    {
        cin >> c;
        int x = lower_bound(osa, osa + nPal, c) - osa;

        if(x == nPal) cout << -1 << endl;
        else cout << ran(ara[x].F.F, ara[x].F.S) << endl;
    }
    return 0;
}

