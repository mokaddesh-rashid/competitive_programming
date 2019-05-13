#include<bits/stdc++.h>

using namespace std;

const int MAX = 300010;

struct node
{
    int next[26], len, suffixLink, numOfTime, endPos;
};

///numOfTime store koto bar ai palin ta create kora req asche and
///aita use kore total number of palin ber kore pari
///and proti ta palin koto bar ase aita o

string s;
node tree[MAX];
int suff, id;

void initTree()
{
    memset(tree, 0, sizeof(tree));

    suff = 2; id = 2;
    tree[1].len = -1; tree[1].suffixLink = 1;
    tree[2].len = 0; tree[2].suffixLink = 1;
}

int addChar(int pos) ///return tree if new node/palin is created
{
    int cur = suff, curlen = 0;
    int go = s[pos] - 'a'; ///current character to add

    while(true)
    {
        //cout << 'H' << endl;
        curlen = tree[cur].len;
        if(pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
            break;
        cur = tree[cur].suffixLink;
    }

    if(tree[cur].next[go])
    {
        suff = tree[cur].next[go];
        tree[suff].numOfTime++;
        return false;
    }

    id++;
    suff = id;
    tree[id].len = tree[cur].len + 2;
    tree[id].endPos = pos;

    tree[cur].next[go] = id; ///pa theke amake link ditesi

    if(tree[id].len == 1)
    {
        tree[id].suffixLink = 2;
        tree[id].numOfTime = 1;
        return true;
    }

    while(true)
    {
        cur = tree[cur].suffixLink;
        curlen = tree[cur].len;
        if(pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
        {
            tree[id].suffixLink = tree[cur].next[go];
            break;
        }
    }
    tree[suff].numOfTime = 1;

    return true;
}


long long lft[300010], rgt[300010];

int main()
{
    ios::sync_with_stdio(false);

    cin >> s;
    int n = s.size();
    long long prin = 0;

    initTree();
    for(int i = 0; i < n; i++) lft[i] = addChar( i ); ///create hoise naki(1) or 0
    for(int i = 0; i < n; i++) prin += lft[i]; cout << prin << endl;

    prin = 0;
    for(int i = id; i >= 3; i--) tree[ tree[i].suffixLink ].numOfTime += tree[i].numOfTime;
    ///finding proti palin koto bar ase as jara amake suffix link diye visit korte pare odr create kora and amake create kora same
    ///ajonno odr count ami nibo

    for(int i = 3; i <= id; i++) prin += tree[i].numOfTime;
    cout << prin << endl; ///total number of palin substring

    return 0;
}
