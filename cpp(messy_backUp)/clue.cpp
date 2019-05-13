#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define PB push_back
#define MAX 510

int nodeId, n, m;
int mat[MAX][MAX];

struct node
{
    int val, lev;
    char ch;
    node *next[26], *fail, *pa;
    vector<int> output;

    node()
    {
        lev = 0;
        val = nodeId++;
        pa = fail = NULL;
        FOR(i,0,25) next[i] = NULL;

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
            s->next[x]->lev = i + 1;
        }
        s = s->next[x];
    }

    s->output.PB( p ); ///output link list create korar jonno
    return;
}

queue<node*> que;


/// creating output link list
void outputLink(node *go,node *p)
{
    FOR(i,0,(int)go->output.size()-1)
    {
        int oto = go->output[i];
        p->output.PB( oto );
    }
    sort(p->output.begin(), p->output.end());

}

void bfs(node* p)
{
    que.push( p );

    while(!que.empty())
    {
        p = que.front(); que.pop(); revId[ p->val ] = p;
        int C = ID( p->ch ); /// what is my character

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
                    ///cout << p->ch << '(' << p->lev << ')' << ' ' <<  s->next[C]->ch << '(' << s->next[C]->lev << ')' << endl;
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

string pattern[MAX];

int rec(node *p,int ch)
{
    if(p == Root && p->next[ch] == NULL) return p->val;
    if(p->next[ch] != NULL) return p->next[ch]->val;
    return rec(p->fail, ch);
}
int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);
    ///freopen("out.txt", "w", stdout);
    Root = new node();
    Root->fail = Root;
    Root->pa = Root;

    cin >> n >> m;
    FOR(i,0,n+m-1)
    {
        cin >> pattern[i];
        in(pattern[i], i);
    }
    bfs( Root );

    FOR(i,0,nodeId-1)
    {
        FOR(k,0,10)
        {
            mat[i][k] = rec(revId[i], k);
            cout << i << ' ' << k << ' ' << rec(revId[i], k) << endl;
        }
    }




    return 0;
}

/*
4
a
in
tin
sting

aastingstinga
*/


