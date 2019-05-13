#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define PB push_back
#define MAX 100010

struct node
{
    char ch;

    node *next[26], *fail, *pa;
    vector<int> output;

    node()
    {
        pa = fail = NULL;
        FOR(i,0,25) next[i] = NULL;
    }
};

node *Root;

int ID(char ch)
{
    int ret = 0;

    if(ch < 'a') ret = ch - 'A';
    else ret = ch - 'a';

    return ret;
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

    if(!s->output.size())
    {
        s->output.PB( p );
    }
    return;
}

queue<node*> que;

void outputLink(node *go,node *p)
{
    if(go->output.size()) break;
    for(auto oto : go->output)
    {
        p->output.PB( oto );
        break;
    }
}

void bfs(node *p)
{
    que.push( p );

    while(!que.empty())
    {
        p = que.front(); que.pop();
        int C = ID( p->ch );
        //cout << p->ch << endl;

        if(p->pa == Root)
        {
            p->fail = Root;
        }
        else
        {
            node *s = p->pa->fail;

            while(true)
            {
                ///cout << s->lev << ' ' << s->ch << endl;
                if(s->next[C] != NULL)
                {
                    p->fail = s->next[C];
                    outputLink(s->next[C], p);
                    break;
                }
                else if(Root == s)
                {
                    p->fail = Root;
                    break;
                }

                s = s->fail;
            }
        }

        FOR(i,0,25)
        {
            if(p->next[i] != NULL)
            {
                que.push( p->next[i] );
            }
        }
    }

}


string pattern[MAX], text;
node *ocr[MAX];

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
            ocr[p] = s;
            p++;
        }
        else if(s == Root) p++;
        else s  = s->fail;
    }
}

int dp[MAX];
int rec(int p)
{
    if(p == -1) return 1;

    int &temp = dp[p];
    if(temp != -1) return temp;

    temp = 0;
    for(auto go : ocr[p]->output)
        temp = max(temp, rec(p - pattern[go].size()) );

    return temp;
}

void prin(int p)
{
    if(p == -1) return;

    for(auto go : ocr[p]->output)
    {
        if(rec(p - pattern[go].size()))
        {
            prin(p - pattern[go].size());
            cout << pattern[go] << ' ';
            return;
        }
    }

    return;
}
int main()
{
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);
   // freopen("out.txt", "w", stdout);

    Root = new node();
    Root->fail = Root;
    Root->pa = Root;

    int n, q;

    cin >> n;
    cin >> text;

    cin >> q;
    FOR(i,0,q-1)
    {
        cin >> pattern[i];

        string str = pattern[i];
        reverse(str.begin(), str.end());

        in(str, i);
    }

    bfs( Root );
    readText();

    memset(dp, -1, sizeof(dp));
    prin(n - 1);


    return 0;
}
