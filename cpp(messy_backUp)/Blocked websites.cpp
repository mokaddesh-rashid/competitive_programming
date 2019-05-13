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
#define MAX 100010
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,string> pr;

struct node
{
    int v,a,b;
    node *next[30];
    node()
    {
        FOR(i,0,25) next[i]=NULL;
        v=0;
    }
};
node *Root;
pr ar[100010];
string str,blah;
char ch;


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
        if(x==n) t->v=1;
    }
}

int chk(string str)
{
    int x=0,y,a,b,n=str.size();
    node *t=Root;

    while(x<n)
    {
        a=str[x]-'a';
        if(t->next[a]==NULL) return x;
        t=t->next[a];
        x++;
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    map<string,int> mp;
    map<string,int>::iterator it;
    Root=new node();
    int i,j,x,y,n,m,c=0,a=-1,b;
    cin>>n;
    FOR(i,0,n-1)
    {
        cin>>ch>>ar[i].S;
        if(ch=='+') ar[i].F=1;
        else ar[i].F=2;
    }
    sort(ar,ar+n);
    FOR(i,0,n-1)
    {
        if(ar[i].F==1) in(ar[i].S);
        else
        {
            x=chk(ar[i].S);
            if(x==-1) a=0;
            else
            {
                blah.assign(ar[i].S,0,x+1);
                if(mp[blah]==0) c++;
                mp[blah]=1;
            }
        }
    }
    if(a==0) cout<<-1<<NL;
    else
    {
        cout<<c<<NL;
        for(it=mp.begin();it!=mp.end();it++) cout<<it->F<<NL;
    }
    return 0;
}


