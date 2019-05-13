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
int cnt = 0;

void in(string str)
{
    node *s = Root;
    int n = str.size();

    FOR(i,0,n-1)
    {
        int x = str[i] - 'a';
        if(s->next[x] == NULL) s->next[x] = new node(), cnt++;
        s = s->next[x];
    }

    s->val = s->val + 1;

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in.txt", "r", stdin);///not checked
    Root = new node();

    int n, mo = 0;
    string str;

    cin >> n;
    FOR(i,0,n-1)
    {
        cin >> str;
        in( str );

        int lo = (int)str.size();
        mo = max(lo, mo);
    }

    if(cnt == mo) cout << mo << endl;
    else cout << "Impossible" << endl;

    return 0;
}


