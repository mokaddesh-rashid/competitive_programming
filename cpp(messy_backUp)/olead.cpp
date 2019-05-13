#include <bits/stdc++.h>
using namespace std;

#define NL '\n'
#define LL long long
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define pii pair<int,int>
#define FR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define MEM(a,b) memset(a,b,sizeof(a))
#define PII pair<int,int>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define ROF(i,j,k) for(int i=j;i>=k;i--)
#define pi 2.0*acos(0.0)
#define EPS 0.000000001
#define MOD 1000000007
#define MAX 200005

LL n,m, ar[MAX], lev[MAX], cnt[MAX], ase[MAX];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    std::ios_base::sync_with_stdio(0);

    LL a,b,x,y,z;

    cin>>n>>m;
    FOR(i,0,n-1)cin>>ar[i];
    FOR(i,0,m-1)cin>>lev[i];

    sort(ar,ar+n,greater<LL>());
    sort(lev,lev+m);

    b=a=x=y=0;
    cnt[0]=1;


    while(y<m)
    {
       if(ase[a]<cnt[a]&&a<=lev[y]) ase[a]++, y++;
       else if(a==0&&ase[a]==cnt[a]&&ar[y]==0) y++;
       else if(a>0&&ase[a]==cnt[a]&&lev[y]>=a&&cnt[a-1]>0&&x<n) cnt[a]+=ar[x],x++,cnt[a-1]--;
       else if(ase[a]==cnt[a]&&lev[y]>a)a++;
       else y++;
       //cout<<ase[a]<<' '<<cnt[a]<<' '<<lev[y]<<' '<<a<<NL;
    }
    //FOR(i,0,10)cout<<cnt[i]<<' ';
    //cout<<NL;
    LL c=0,d=0;
    a=0;
    FOR(i,0,m-1)
    {
        while(a<=lev[i])
        {
            ///cout<<cnt[a]<<NL;
            z=0;
            while(a <= lev[i] &&x<n&&c>0)
            {
                z+=ar[x]; x++; c--;
            }
            c+=z;
            c+=cnt[a];
            a++;
        }
        //cout<<lev[i]<<' '<<c<<NL;
        if(c>0) c--,d++;
    }
    if(m==0) d=1;
    cout<<d<<NL;

    return 0;
}
