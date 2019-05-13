#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>
#include<map>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define ss(n)       scanf("%s", n)
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 100010
#define sz 550010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

char str[15];
int cnt[sz], c;

struct node
{
    int v,a,b;
    node *next[26];
    node()
    {
        FOR(i,0,25) next[i]=NULL;
        v=0;
    }
};
node *Root;

void in(int n)
{
    int x=0,y,a,b;
    node *t=Root;

    while(x<n)
    {
        a=str[x]-'a';
        if(t->next[a]==NULL) t->next[a]=new node();
        t=t->next[a];
        x++;
        if(x==n)
        {
            t->v=c;
            c++;
        }
    }
}

int chk(int n)
{
    int x=0,y,a,b;
    node *t=Root;

    while(x<n)
    {
        a=str[x]-'a';
        if(t->next[a]==NULL) return 0;
        t=t->next[a];
        x++;
        if(x==n)
        {
            return t->v;
        }
    }
    return 0;
}


vector<int> mat[sz];
int vis[sz];

void dfs(int p)
{
    vis[p]=1;
    FOR(i,0,(int)mat[p].size()-1)
    {
        int x=mat[p][i];
        if(vis[x]==0) dfs(x);
    }
}

int main()
{
    ///ios::sync_with_stdio(false);
    //inf;
    //outf;
    Root=new node();
    int i,j,n,m,a,b,x,y;
    c=1;

    while(ss(str)!=EOF)
    {
        n=strlen(str);
        if(chk(n)==0)
        {
            in(n);
        }
        x=chk(n);

        ss(str);
        n=strlen(str);
        if(chk(n)==0)
        {
            in(n);
        }
        y=chk(n);
        cout<<x<<' '<<y<<NL;
        mat[x].PB(y);
        mat[y].PB(x);
    }

    dfs(1);
    a=0;
    FOR(i,1,c-1) if(vis[i]==0) a=1;

    if(a==0) pf("Possible\n");
    else pf("Impossible\n");
    return 0;
}


