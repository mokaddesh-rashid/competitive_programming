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

int ar[26][MAX], cnt[26];
string str;

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,a,b,c=1,x,y,z,p,q,r;

    cin>>str;
    FOR(i,0,(int)str.size()-1)
    {
        x=str[i]-'a';
        ar[x][cnt[x]]=i;
        cnt[x]++;
    }

    cin>>str;
    p=0;
    FOR(i,0,(int)str.size()-1)
    {
        x=str[i]-'a';
        a=lower_bound(ar[x],ar[x]+cnt[x],p)-ar[x];
        b=lower_bound(ar[x],ar[x]+cnt[x],0)-ar[x];
        cout<<a<<' '<<b<<' '<<cnt[x]<<NL;

        if(a!=cnt[x]) p=ar[x][a]+1;
        else if(b!=cnt[x]) p=ar[x][b]+1, c++;
        else
        {
            c=-1;
            break;
        }
    }

    cout<<c<<NL;
    return 0;
}


