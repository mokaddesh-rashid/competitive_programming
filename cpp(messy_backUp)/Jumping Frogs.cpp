#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(LL i=j;i<=k;i++)
#define REV(i,j,k) for(LL i=j;i>=k;i--)
#define FORR(i,j,k,l) for(LL i=j;i<=k;i+=l)
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
#define sz 210
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<LL,LL> pr;

LL org[sz][sz], mat[sz][sz], n, m, maf, c_f, s, t, ar[sz], ty[sz];
LL que[sz], vis[sz],h, r, p, pa[sz], med[sz];

LL bfs(LL s)
{
    mem(vis,0);
    h=r=0;
    que[r]=s; r++;
    med[s]=mod; ///check max value

    while(h!=r)
    {
        p=que[h]; h++; vis[p]=1;
        ///cout<<p<<" = ";
        FOR(i,0,2*n)
        {
           if(mat[p][i]>0&&vis[i]==0)
           {
               ///cout<<i<<' ';
               med[i]=min(med[p],mat[p][i]);
               pa[i]=p; vis[i]=1; que[r]=i; r++;
           }

        }
        ///cout<<NL;
        ///if(p==t) break;
    }

    if(vis[t]==0) return 0;
    else
    {
        LL a,b,c;

        a=pa[t]; b=t; c=med[t];
        while(true)
        {
            mat[a][b]-=c;
            mat[b][a]+=c;
            if(a==s) break;

            a=pa[a]; b=pa[b];
        }

        return c;
    }
}

void solve()
{
    maf=0;
    while(true)
    {
        LL c=bfs(s);
        maf+=c;
        if(c==0) break;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL tc;
    cin>>tc;
    FOR(tt,1,tc)
    {
        LL i, j, a, b, c, d, x, y, z, m;
        LL st, mid, en;
        string str;

        cin>>n>>d; z=d;
        FOR(i,1,n)
        {
            cin>>str;
            m=str.size(); x=0;
            FOR(i,2,m-1)
            {
               y=str[i]-'0';
               x=x*10+y;
            }
            ar[i]=x;
            if(str[0]=='B') ty[i]=1;
            else ty[i]=0;
        }
        ar[0]=0; ty[0]=1;
        n++;
        ar[n]=d; ty[n]=1; m=n;

        st=1; en=d;
        while(st<=en)
        {
            mid=(st+en)>>1;
            mem(mat,0);
            ///cout<<mid<<NL;
            FOR(i,1,n-1)
            {
                ///cout<<i<<' '<<i+m<<' '<<ty[i]<<NL;
                if(ty[i]==1) mat[i][i+n]=5;
                else mat[i][i+n]=1;
            }
            FOR(i,0,n)
            {
                FOR(j,i+1,n)
                {
                    //cout<<
                    if(abs(ar[i]-ar[j])<=mid&&i!=j)
                    {
                       ///cout<<i<<' '<<j<<NL;
                       if(i==0) mat[i][j]=5;
                       else mat[i+n][j]=5;
                    }
                }
            }
            s=0; t=n;
            solve();

            if(maf>=2)
            {
                z=min(z,mid);
                en=mid-1;
            }
            else st=mid+1;
        }


        cout<<"Case "<<tt<<": "<<z<<NL;
    }

    return 0;
}


