#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
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
#define MAX 1000010
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,string> pr;

struct node
{
    int v,ty;
    node *next[30];
    node()
    {
        FOR(i,0,25) next[i]=NULL;
        v=0;
        ty=1;
    }
};
node *Root;
string str[MAX];
char ch;
LL cnt=0,cnt2=0;


void in(string str)
{
    int x=0,y,a,b,n=str.size();
    node *t=Root;

    while(x<n)
    {
        a=str[x]-'a';
        if(t->next[a]==NULL) t->next[a]=new node();
        t=t->next[a];
        x++;
    }
}
void on(string str)
{
    int x=0,y,a,b,n=str.size();
    node *t=Root;

    x++;
    while(x<n)
    {
        a=str[x]-'a';
        if(t->next[a]==NULL) t->next[a]=new node();
        t=t->next[a];
        t->ty=0;
        x++;
    }
}


int chk(string str)
{
    int x=0,y,a,b=0,n=str.size();
    node *t=Root;

    while(x<n)
    {
        a=str[x]-'a';
        t=t->next[a];
        x++;
        b+=t->ty;
    }
    return b;
}


int ase(string str)
{
    int x=0,y,a,b,n=str.size();
    node *t=Root;

    while(x<n)
    {
        a=str[x]-'a';
        if(t->next[a]==NULL) return 1;
        t=t->next[a];
        x++;
    }
    return 0;
}

int up(node *t,int p)
{
    if(t->next[p]==NULL) return 0;
    else return 1+up(t->next[p],p);
}
int ole[MAX],dude[100];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;

    FOR(tt,1,tc)
    {
        mem(ole,0);mem(dude,0);
        int n;

        cin>>n;
        Root=new node();
        cnt2=cnt=0;
        FOR(i,0,n-1) cin>>str[i];
        sort(str,str+n,greater<string>());
        FOR(i,0,n-1)
        {
            if(ase(str[i]))
            {
                ole[i]=1;
                in(str[i]);
                on(str[i]);
            }
        }
        FOR(i,0,n-1)if(ole[i]==1)cnt+=chk(str[i]);
        FOR(i,0,25)
        {
            int a=up(Root,i);
            if(a>1)
            {
                a-=2;
                cnt+=(a/2);
            }
        }
        cout<<cnt<<NL;
    }


    return 0;
}

