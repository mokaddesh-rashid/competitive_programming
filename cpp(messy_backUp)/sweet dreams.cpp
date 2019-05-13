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
#define MAX (1<<16)
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int nodeId, n, m;
int mat[310][12];

struct node
{
    int val, lev, typ, mask;
    char ch;
    node *next[11], *fail, *pa;
    vector<int> output;

    node()
    {
        typ = mask = lev = 0;
        val = nodeId++;

        pa = fail = NULL;
        FOR(i,0,9) next[i] = NULL;

    }
};

node *Root;
node *revId[MAX];


int ID(char ch)
{
    int v = ch - 'a';
    return v;
}

void in(string str,int p)
{
    node *s = Root;
    int n = str.size();

    FOR(i,0,n-1)
    {
        int x = ID( str[i] );
        if(s->next[x] == NULL)
        {
            s->next[x] = new node();

            s->next[x]->ch = str[i];
            s->next[x]->pa = s;
            s->next[x]->lev = s->lev + 1;
        }
        s = s->next[x];
    }

    s->output.PB( p ); ///output link list create korar jonno
    return;
}

/// creating output link list
void outputLink(node *go,node *p)
{
    FOR(i,0,(int)go->output.size()-1)
    {
        int oto = go->output[i];
        p->output.PB( oto );
    }

    FOR(i,0,(int)p->output.size()-1)
    {
        int oto = p->output[i];
        p->mask |= (1<<oto);

        if(oto >= n) p->typ = 1;
    }
    ///cout << p->ch << ' ' << p->lev << ' ' << p->val << ' ' << p->typ << ' ' << p->mask << " " << endl;
    ///if(p->typ) cout << p->val << " corrupted " << endl;
}

void bfs(node* p)
{
    queue<node*> que;
    que.push( p );

    while(!que.empty())
    {
        p = que.front(); que.pop(); revId[ p->val ] = p;
        int C = ID( p->ch ); /// what is my character

        if(p->pa == Root)
        {
            p->fail = Root;
            outputLink(Root, p);
        }
        else
        {
            node *s = p->pa->fail;

            while(true)
            {
                if(s->next[C] != NULL)
                {
                    p->fail = s->next[C];
                    outputLink(s->next[C], p);
                    break;
                }
                else if(Root == s)
                {
                    p->fail = s;
                    outputLink(s, p);
                    break;
                }

                s = s->fail;
            }
        }

        FOR(i,0,9)
        {
            if(p->next[i] != NULL)
            {
                p->next[i]->lev = p->lev + 1;
                que.push( p->next[i] );
            }
        }
    }
}

string pattern[MAX];

int getNode(node *p,int ch)
{
    if(p == Root && p->next[ch] == NULL) return p->val;
    if(p->next[ch] != NULL) return p->next[ch]->val;
    return getNode(p->fail, ch);
}

int lev[310][MAX];
pair<PR,int> pa[310][MAX];

void bfsBabu(int p,int bit)
{
    mem(lev, -1);
    queue<PR> que;

    lev[p][bit] = 0;
    que.push( MP(p, bit) );

    while(!que.empty())
    {
        p = que.front().F; bit = que.front().S;
        que.pop();

        FOR(i,0,9)
        {
            int go = mat[p][i];
            int newBit = bit | revId[go]->mask;

            if(lev[go][newBit] == -1 && !revId[go]->typ && go != p)
            {
                lev[go][newBit] = lev[p][bit] + 1;
                pa[go][newBit] = MP(MP(p, bit), i);
                que.push( MP(go, newBit) );
            }
        }
    }
}

void prin(int p,int bit)
{
    if(!p && !bit) return;
    prin(pa[p][bit].F.F, pa[p][bit].F.S);

    if(p) cout << revId[p]->ch;
    else
    {
        char ch = 'a' + pa[p][bit].S;
        cout << ch;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);
    ///freopen("out.txt", "w", stdout);
    LL x = 60 * 50 * 5010;
    cout << x << endl;

    return 0;
}
