#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define PB push_back

struct node
{
    int val;
    node *next[26];
    node *fail;

    node()
    {
        val = 0;
        fail = NULL;
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
        if(s->next[x] == NULL) s->next[x] = new node();
        s = s->next[x];
    }

    s->val = s->val + 1;

    return;
}

int khujo(string str)
{
    node *s  = Root;
    int n = str.size();

    FOR(i,0,n-1)
    {
        int x = str[i] - 'a';
        if(s->next[x] == NULL) return 0;
        s = s->next[x];
    }

    return s->val;
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);///not checked
    Root = new node();

    int n;
    string str;

    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> str;
        in( str );
        cout << khujo( str ) << endl;
    }

    return 0;
}

