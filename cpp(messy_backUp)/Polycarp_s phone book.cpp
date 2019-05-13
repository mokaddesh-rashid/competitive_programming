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
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define Mo          1000000000
#define M1          1000000007
#define M2          100000007
#define B1          11
#define B2          11
#define M_PI           3.14159265358979323846  /* pi */
#define LL           unsigned long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 300010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

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
        a=str[x]-'0';
        if(t->next[a]==NULL) t->next[a]=new node();
        t=t->next[a];
        x++;
        t->v++;
    }
}

void del(string str)
{
    int x=0,y,a,b,n=str.size();
    node *t=Root;

    while(x<n)
    {
        a=str[x]-'0';
        if(t->next[a]==NULL) t->next[a]=new node();
        t=t->next[a];
        x++;
        t->v--;
    }
}

int ase(string str)
{
    int x=0,y,a,b,n=str.size();
    node *t=Root;

    while(x<n)
    {
        a=str[x]-'0';
        t=t->next[a];
        if(t->v==0) return 1;
        //t=t->next[a];
        x++;
    }
    return 0;
}
string inp[MAX];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    Root=new node();

    int i,j,n,m,c,p,d;
    LL a,b,x,y,z,l,o;

    cin>>n;
    FOR(i,0,n-1)
    {
        cin>>str;
        inp[i]=str;
        FOR(i,0,8)
        {
            string chk="";
            FOR(j,i,8)
            {
                chk+=str[j];
                in(chk);
                //cout<<chk<<NL;
            }
        }
    }

    FOR(i,0,n-1)
    {
        string ans;
        a=11;
        str=inp[i];
        FOR(i,0,8)
        {
            string chk="";
            FOR(j,i,8)
            {
                chk+=str[j];
                del(chk);
                //cout<<"r"<<chk<<NL;
            }
        }
        FOR(i,0,8)
        {
            string chk="";
            FOR(j,i,8)
            {
                chk+=str[j];
                //cout<<chk<<' '<<ase(chk)<<NL;
                if(ase(chk))
                {
                    b=(j-i)+1;
                    if(b<a)ans=chk,a=b;
                }
            }
        }
        FOR(i,0,8)
        {
            string chk="";
            FOR(j,i,8)
            {
                chk+=str[j];
                in(chk);
                //cout<<"a"<<chk<<NL;
            }
        }
        cout<<ans<<NL;
    }
    return 0;
}
