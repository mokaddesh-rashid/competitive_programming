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

node *Root[41];
vector<string> stringGroup[41];
string pattern, text;
int heads[41], id[41];

int ID(char ch)
{
    int v;

    if(ch < 'a') v = ch - 'A';
    else v = ch - 'a';

    return v;
}

void in(string str,int RootId)
{
    node *s = Root[RootId];
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
    return;
}

queue<node*> que;

/// creating output link list
void outputLink(node *go,node *p)
{
    p->val += go->val;
}

void bfs(node* p,int RootId)
{
    que.push( p );

    while(!que.empty())
    {
        p = que.front(); que.pop();
        int C = ID( p->ch );; /// what is my character

        if(p->pa == Root[RootId])
        {
            p->fail = Root[RootId];
            p->output = Root[RootId];
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
                else if(Root[RootId] == s)
                {
                    p->fail = s;
                    p->output = Root[RootId];
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


int readText(string text,int RootId)
{
    int p = 0, n = text.size(), x, ret = 0;
    node *s = Root[RootId];

    while(p < n)
    {
        int x = ID( text[p] );
        if(s->next[x] != NULL)
        {
            s = s->next[x];
            ret += s->val;
            ///cout << p << ' ' << s->val << endl;
            p++;
        }
        else if(s == Root[RootId]) p++;
        else s = s->fail;
    }
    return ret;
}

void make_aho(int RootId)
{
    Root[RootId] = new node();
    Root[RootId]->fail = Root[RootId];
    Root[RootId]->pa = Root[RootId];
    Root[RootId]->val = 0;///check
    Root[RootId]->output = Root[RootId];

    int q, n;
    ///cout << RootId << endl;
    for(auto x : stringGroup[RootId])
    {
        ///cout << x << endl;
        in(x, RootId);
    }

    bfs( Root[RootId], RootId);
}

int readAho(string text,int RootId)
{
    return readText(text, RootId);
}
///implementation part

void sortID(int l,int r)
{
    FOR(i,l,r) id[i] = i;
    sort(id + l, id + (r + 1), [](int a,int b)
         {
             return heads[a] < heads[b];
         });
//    cout << "SOorted ";
//    FOR(i,0,r) cout << id[i] << ' ';
//    cout << endl;
    return;
}

void mergeId(int a,int b)
{
    for(auto x : stringGroup[a])
    {
        stringGroup[b].PB( x );
    }

   /// cout << "merged " << a << ' ' << b << ' ' << heads[a] << ' ' << heads[b] << ' ' << endl;
    heads[b] += heads[a];
    heads[a] = 0;
    stringGroup[a].clear();

    make_aho( a );
    make_aho( b );
}

void addString(string str,int l,int r)///pos l = 0, r = 19
{
    sortID(l, r);
    int G = id[l];

    stringGroup[G].PB( pattern );
    heads[G]++; make_aho( G );

    int ok = 1;
    while(ok)
    {
        ok = 0; sortID(l, r);
        FOR(i,l,r)
        {
            if(heads[ id[i] ] == heads[ id[i + 1] ] && heads[ id[i] ])
                mergeId(id[i], id[i + 1]), ok = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    FOR(i,0,40) make_aho( i );
    int q, ty;

    cin >> q;
    FOR(i,1,q)
    {
        cin >> ty >> pattern;
        if(ty == 1) addString(pattern, 0, 19);
        else if(ty == 2) addString(pattern, 20, 39);
        else
        {
            int prin = 0;
            FOR(i,0,39)
            {
                if(i <= 19) prin += readText(pattern, i);
                else prin -= readText(pattern, i);
            }
            cout << prin << endl;
        }
    }

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
