#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define PB push_back

struct node
{
    int val;
    char ch;
    node *next[26], *fail, *pa;

    node()
    {
        val = 0;
        pa = fail = NULL;
        FOR(i,0,25) next[i] = NULL;
    }
};

node *Root;

void in(string str)
{
    node *s = Root;
    int n = str.size();

    FOR(i,0,n-1)
    {
        int x = str[i] - 'a';
        if(s->next[x] == NULL)
        {
            s->ch = str[i];
            s->next[x] = new node();
            s->next[x]->pa = s;
        }
        s = s->next[x];
    }

    s->val = s->val + 1;

    return;
}

queue<node*> que;

void bfs(node* p)
{
    que.push( p );

    while(!que.empty())
    {
        p = que.front(); que.pop();
        FOR(i,0,25)
        {
            if(p->next[i] != NULL)
            {
                char ch = 'a' + i;
                que.push( p->next[i] );
//                char boba = 'A';
//                if(p->pa != NULL) boba = p->pa->ch;
//                cout << ch << ' ' << boba  << endl;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    Root = new node();

    int n;
    string str;

    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> str;
        in( str );
    }

    bfs( Root );

    return 0;
}

