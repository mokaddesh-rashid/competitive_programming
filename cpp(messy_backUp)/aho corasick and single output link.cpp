#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define PB push_back
#define MAX 100010

struct node
{
    int val, lev;
    char ch;
    node *next[26], *fail, *pa;
    node *output;
    vector<int> pat;

    node()
    {
        lev = val = 0;
        pa = fail = NULL;
        FOR(i,0,25) next[i] = NULL;
    }
};

node *Root;
int ID(char ch)
{
    int v;

    if(ch < 'a') v = ch - 'A';
    else v = ch - 'a';

    return v;
}

void in(string str,int oda)
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
        s = s->next[x];
    }

    s->val = s->val + 1;
    if(!s->pat.size()) s->pat.PB(oda);

    return;
}

queue<node*> que;


/// creating output link list
void outputLink(node *go,node *p)
{
    if(go->val) p->output = go;
    else p->output = go->output;
}

void bfs(node* p)
{
    que.push( p );

    while(!que.empty())
    {
        p = que.front(); que.pop();
        int C = ID( p->ch );; /// what is my character

        if(p->pa == Root)
        {
            p->fail = Root;
            p->output = Root;
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
                    p->output = Root;
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

string pattern[MAX], text;
node *show[MAX];

void readText()
{
    int p = 0, n = text.size(), x;
    node *s = Root;

    while(p < n)
    {
        int x = ID( text[p] );
        if(s->next[x] != NULL)
        {
            s = s->next[x];
            show[p] = s;
            p++;
        }
        else if(s == Root) p++;
        else s = s->fail;
    }
}

int papa[MAX], vis[MAX], chao, n, popo[MAX], coco;
queue<int> baby;

void prin(int p)
{
    if(p == n - 1) return;
    int go = chao;
    if(p != -1) go = papa[p];

    if(p == -1) cout << pattern[coco] << ' ';
    else cout << pattern[popo[p]] << ' ';
    prin(go);
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);

    Root = new node();
    Root->fail = Root;
    Root->pa = Root;
    Root->val = 1;
    Root->output = Root;

    int q;

    cin >> n;
    cin >> text;

    cin >> q;
    FOR(i,0,q-1)
    {
        cin >> pattern[i];
        reverse(pattern[i].begin(), pattern[i].end());
        in(pattern[i], i);
        reverse(pattern[i].begin(), pattern[i].end());
    }

    bfs( Root );
    readText();

    baby.push( n - 1 ); papa[n - 1] = n;
    while(!baby.empty())
    {
        int p = baby.front(); baby.pop();
        node *s = show[p];

        while(s != Root)
        {
            for(auto x : s->pat)
            {
                ///cout << x << endl;
                int lo = pattern[x].size();

                if(p - lo == -1)
                {
                    chao = p;
                    coco = x;
                    ///cout << -1 << ' ' << chao << endl;
                }
                else if(!vis[p - lo])
                {
                    baby.push(p - lo);
                    vis[p - lo] = 1;
                    papa[p - lo] = p;
                    popo[p - lo] = x;
                    ///cout << p << ' ' << p - lo << endl;
                }
            }
            s = s->output;
        }
    }

    prin( -1 );
    return 0;
}

/*
4
i
in
tin
baby
babyting
*/
