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
typedef pair<int,int> pr;

struct Node
{
    int v,p,t;///v is counter , t is 0/1 type binary bit, p is level/position of node`s bit
    Node *next[2];

    Node()
    {
        FOR(i,0,1) next[i]=NULL;
        p=v=0;
    }
};
int bin[40],val;
Node *Root;

void in()
{
   Node *t=Root;
   int x=28, a;

   while(x>=0)
   {
       a=bin[x];
       if(t->next[a]==NULL) t->next[a]=new Node();

       t=t->next[a]; t->v++;
       t->t=a; t->p=x;
       ///cout<<t->p<<' '<<t->t<<NL;
       x--;
   }
}

void out()
{
   Node *t=Root;
   int x=28, a;

   while(x>=0)
   {
       a=bin[x];
       t=t->next[a]; t->v--;
       //cout<<t->p<<' '<<t->t<<' '<<t->v<<NL;
       x--;
   }
}

int query(Node *cn,int v)
{
    ///cout<<v<<NL;
    int a,b,c=0;
    if(bin[cn->p]!=cn->t&&Root!=cn) a=v|(1<<cn->p);
    else a=v;

    if(a>=val&&cn!=Root) return cn->v;
    if(v+(1<<(cn->p+2))<val&&cn!=Root) return 0;
    if(cn->next[0]!=NULL&&cn->next[0]->v>0) c+=query(cn->next[0],a);
    if(cn->next[1]!=NULL&&cn->next[1]->v>0) c+=query(cn->next[1],a);
    return c;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    Root=new Node();
    int i,j,x,y,n,m, c=0;

    cin>>n;
    FOR(i,0,n-1)
    {
        cin>>y>>x;
        FOR(j,0,30)
        {
            if(x&(1<<j)) bin[j]=1;
            else bin[j]=0;
        }

        if(y==1) in(), c++; /// add
        else if(y==2) out(), c--; /// remove
        else
        {
            cin>>val;
            cout<<c-query(Root,0)<<NL; /// query gives total number with whose xor of x will be greater equal than val
        }
    }
    return 0;
}



