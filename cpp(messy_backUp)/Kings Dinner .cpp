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
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct node
{
    LL v, pa, l;
}bfa[100010];

vector<int> mat[100010];
int que[100010], h, r, shit;

void bfs( int p )
{
    h = r = 0;
    bfa[p].l = 0;
    bfa[p].pa = -1;
    bfa[p].v = 1;
    que[r] = p;
    r++;
    while( h != r )
    {
        //cout << p << " = ";
        for(int i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];
            if( bfa[x].v == 0 )
            {
                //cout << x << ' ';
                bfa[x].l = (bfa[p].l+1)%2;
                bfa[x].pa = p;
                bfa[x].v = 1;
                que[r] = x;
                r++;
            }
            else if(bfa[x].l==bfa[p].l) shit=1;
        }
        //cout << endl;
        h++;
        p = que[h];
    }

}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    int tc;

    cin>>tc;
    FOR(tt,1,tc)
    {
        clean(mat,MAX-1);shit=0;mem(bfa,0);
        int i,j,n,m,a,b,c;

        cin>>n;
        FOR(i,1,n)
        {
            cin>>m;
            FOR(j,1,m)
            {
                cin>>a;
                mat[a].PB(i);
                mat[i].PB(a);
            }
        }
        cout<<"Case "<<tt<<": ";

        FOR(i,1,n)
        {
            if(bfa[i].v==0)
            {
                bfs(i);
            }
        }
        shit++; shit%=2;
        a=b=0;
        if(shit==1)
        {
            FOR(i,1,n)
            {
                if(bfa[i].l==0)a++;
                else b++;
            }
            if(a>b) swap(a,b);
        }
        if(shit<2)a=b=shit=0;
        cout<<shit<<' '<<a<<' '<<b<<NL;
    }
    return 0;
}


