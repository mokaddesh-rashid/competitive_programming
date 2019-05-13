#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define PB push_back
#define MAX 100010

struct node
{
    int val, lev;
    char ch;
    node *next[26], *fail, *pa;
    vector<int> output;

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
        }
        s = s->next[x];
    }

    s->output.PB( p ); ///output link list create korar jonno
    s->val = s->val + 1;

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

}

void bfs(node* p)
{
    que.push( p );

    while(!que.empty())
    {
        p = que.front(); que.pop();
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

string pattern[MAX], text;
int col[MAX];

void readText()
{
    int p = 0, n = text.size(), x;
    node *s = Root;

    while(p<n)
    {
        int x = ID( text[p] );///- 'a';
        if(s->next[x] != NULL)
        {
            s = s->next[x];
            FOR(i,0,(int)s->output.size()-1)
            {
                int go = s->output[i];
                col[go]++;
            }
            p++;
        }
        else if(s == Root) p++;
        else s = s->fail;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    ///freopen("out.txt", "w", stdout);

    Root = new node();
    Root->fail = Root;
    Root->pa = Root;

    int n;

    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> pattern[i];
        in( pattern[i] , i);
    }

    cin >> text;

    bfs( Root );
    readText();

    FOR(i,0,n-1) cout << pattern[i] << ' ' << col[i] << endl;

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


