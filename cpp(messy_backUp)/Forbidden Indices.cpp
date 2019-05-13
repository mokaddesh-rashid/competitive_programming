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
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct suff {
    int nr[2], p;
} L[MAX], TL[MAX];


string s,vld;
int N, stp, fr[MAX], freq[MAX], P[20][MAX];
/*
bool cmp(const suff &x, const suff &y) {
    if(x.nr[0] == y.nr[0]) return (x.nr[1] < y.nr[1]);
    return (x.nr[0] < y.nr[0]);
}


*/
// x - order of sorting for the pairs
void counting_sort(int x) {
    mem(freq,0);
    // counting frequency
    for(int i = 0; i < N; i++)
        freq[ L[i].nr[x] ]++;
    // cumulative sum of frequency
    fr[0] = 0;
    for(int i = 1; i < MAX; i++)
        fr[i] = fr[i-1] + freq[i-1];
    // sort the original array to temporary array
    for(int i = 0; i < N; i++)
        TL[ fr[ L[i].nr[x] ]++ ] = L[i];
    // assigning the original array
    for(int i = 0; i < N; i++)
        L[i] = TL[i];
}

void suffix() {
    int cnt;
    N = s.size();

    for(int i = 0; i < N; i++) P[0][i] = s[i]-'a';

    for(stp = 1, cnt = 1; (cnt>>1) < N; stp++, cnt<<=1) {
        for(int i = 0; i < N; i++) {
            L[i].nr[0] = P[stp-1][i];
            L[i].nr[1] = (i+cnt) < N ? P[stp-1][i+cnt]+1 : 0;
            L[i].p = i;
        }
        // sort by second element nr[1]
        counting_sort(1);
        // sort by first element nr[0]
        counting_sort(0);
        for(int i = 0; i < N; i++) {
            if(i > 0 && L[i].nr[0] == L[i-1].nr[0] && L[i].nr[1] == L[i-1].nr[1])
                P[stp][L[i].p] = P[stp][L[i-1].p];
            else
                P[stp][L[i].p] = i;
        }
    }
}
int lcp(int f,int s,int t)
{
    int n=N, x=1<<t;

    if(t==-1) return 0;
    else if(max(f+x,s+x)<=n&&P[t][f]==P[t][s])
         return (1<<t)+lcp(f+(1<<t), s+(1<<t), t);
    else return lcp(f,s,t-1);
}

int cnt[MAX],sum[MAX];
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    LL i,j,m,x,a,b,y,z,n;
    LL c=0,d;

    cin>>N;n=N;
    cin>>s; reverse(s.begin(),s.end());
    cin>>vld; reverse(vld.begin(),vld.end());

    suffix();
    FOR(i,0,n-1) if(vld[i]=='1')cnt[i]=1;

    c=0;
    FOR(i,0,n-1)
    {
        a=L[i].p;
        c+=cnt[a];
        sum[i]=c;
    }

    c=0;
    int e=0;
    REV(i,n-1,0)
    {
        ///cout<<L[i].p<<NL;
        a=L[i].p;
        j=i;
        x=0;
        if(i!=n-1)x=lcp(L[i].p,L[i+1].p,19);
        ///cout<<i<<' '<<x<<NL;
        while(j>=0)
        {
            e++;
            a=lcp(L[i].p,L[j].p,19);
            if(a<=x)break;
            else
            {
                //cout<<i<<' '<<j<<' '<<a<<NL;
                d=a*(i-j+1);
                y=sum[i];
                if(j!=0)y-=sum[j-1];
                //cout<<y<<NL;
                d-=(a*y);
                c=max(c,d);
            }
            j--;
        }
        ///cout<<NL;
    }
    cout<<c<<NL;

    return 0;
}



