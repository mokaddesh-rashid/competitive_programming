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
#define LL           unsigned long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 10000010
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int n,s,t;
int next[MAX],ase[2010],samne[MAX],cnt[MAX];
LL val[MAX];


LL up(int p)
{
    set<int>mosa;
    set<int>::iterator it;
    FOR(i,0,n-1)cnt[ase[i]]=0, mosa.insert(ase[i]);
    mosa.insert(s-1);
    LL a,b,c=0,d=0;
    while(d<n)
    {
        if(cnt[p]<next[p])
        {
            if(p!=s-1&&cnt[p]+1==next[p])mosa.erase(p);
            cnt[p]++;d++;
            p+=t;
            p%=s;
            c+=t;
        }
        else
        {
            a=p;
            a=*(mosa.lower_bound(p));
            if(p==s-1) p=0,c++;
            else
            {
                c+=(a-p);
                p=a;
            }

        }
    }
    return c;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    LL i,j,m,a=0,b,c,d=0,e,p;
    LL cost;

    cin>>n>>s>>t;
    FOR(i,0,n-1)
    {
        cin>>ase[i];next[ase[i]]++;
        cout<<i<<NL;
    }
    sort(ase,ase+n);

    a=s-1;
    REV(i,s-1,0)
    {
        if(next[i]!=0)a=i;
        samne[i]=a;
    }
    FOR(i,0,n-1)
    {
        a=up(ase[i]);
        val[ase[i]]=a;
    }
    val[s-1]=up(s-1);
    LL mx,mn;
    FOR(i,0,s-1)
    {
        cost=0;
        a=samne[i];p=i;
        cost+=((a-p)+val[a]);
        d+=cost;
        if(i==0)mx=mn=cost;
        else mx=max(mx,cost),mn=min(mn,cost);
    }
    e=__gcd((LL)s,d);
    cout<<mn<<NL;
    cout<<mx<<NL;
    if(s/e!=1) cout<<d/e<<'/'<<s/e<<NL;
    else cout<<s/e<<NL;
    return 0;
}
