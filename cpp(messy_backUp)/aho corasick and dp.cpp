#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define PB push_back
#define MAX 55*25*26
#define LL long long

const int M = 1000003;

int nex[MAX][26], giveId, bk[MAX], fuck[MAX];
struct node
{
    int lev, id;
    char ch;
    node *next[26], *fail, *pa;

    node()
    {
        lev = 0;
        pa = fail = NULL;
        FOR(i,0,25) next[i] = NULL;
        id = giveId++;
    }
};
node *Root;


int ID(char ch)
{
    int v = ch - 'a';
    return v;
}

void in(string str)
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
        }

        nex[s->id][x] = s->next[x]->id;
        s = s->next[x];
    }

    fuck[ s->id ] = 1;
    return;
}

queue<node*> que;
void outputLink(node *go,node *p)
{
    bk[ p->id ] = go->id;
    if(fuck[ go->id ]) fuck[ p->id ] = 1;
}

void bfs(node* p)
{
    que.push( p );

    while(!que.empty())
    {
        p = que.front(); que.pop();
        int C = ID( p->ch );

        if(p->pa == Root)
        {
            p->fail = Root;
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
                    break;
                }

                s = s->fail;
            }
        }

        FOR(i,0,25)
        {
            if(p->next[i] != NULL)
            {
                p->next[i]->lev = p->lev + 1;
                que.push( p->next[i] );
            }
        }
    }
}


int jumpKore(int p,int c)
{
    if(!p && !nex[p][c]) return 0;
    return nex[p][c] ? nex[p][c] : jumpKore(bk[p], c);
}

int n, can[100];
string pattern;
LL dp[22][MAX][2][2][2];

void show(char ch) {can[ ID( ch ) ] = 1;}

LL rec(int len,int p,int l,int u,int d)
{
    if(fuck[p]) return 0;
    if(len == 0) return (l && u && d);

    LL &temp = dp[len][p][l][u][d];
    if(temp != -1) return temp;

    temp = rec(len - 1, 0, l, u, 1) * 5;
    temp %= M;

    FOR(i,0,25)
    {
        temp += rec(len - 1, nex[p][i], 1, u, d);
        temp %= M;

        temp += rec(len - 1, nex[p][i], l, 1, d);
        temp %= M;

        if(can[i])
        {
            temp += rec(len - 1, nex[p][i], l, u, 1);
            temp %= M;
        }

    }

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    show('o'); show('i'); show('e'); show('s'); show('t');

    Root = new node();
    Root->fail = Root;
    Root->pa = Root;
    int len;


    cin >> len;
    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> pattern;
        in(pattern);
    }
    bfs( Root );

    FOR(i,0,giveId-1)
        FOR(c,0,25) nex[i][c] = jumpKore(i, c);

    memset(dp, -1, sizeof(dp));

    LL prin = rec(len, 0, 0, 0, 0);
    cout << prin << endl;

    return 0;
}

