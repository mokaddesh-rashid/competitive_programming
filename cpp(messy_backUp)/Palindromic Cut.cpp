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
#define MAX 210
#define SZ 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

string str,chk;
char ck;
int ar[MAX],v,s,l,r;

void rec(int p)
{
    if(v==0||p>'z')return;

    if(ar[p]>=2)
    {
        v-=2;
        ar[p]-=2;
        ck=p;
        chk[l]=ck;l--;
        chk[r]=ck;r++;
        rec(p);
    }
    else rec(p+1);

}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,c=0,d;
    char ch;

    cin>>n;
    cin>>str;
    FOR(i,0,n-1)
    {
        m=str[i];
        ar[m]++;
    }
    FOR(i,0,'z') if(ar[i]%2)c++;
    chk=str;
    if(c==0)
    {
        cout<<1<<NL;
        d=v=n;
        l=d/2-1;r=d/2;
        rec(0);
        cout<<chk;
    }
    else
    {
        while(n%c!=0||(n/c)%2==0)
        {
            c++;
        }
        cout<<c<<NL;
        d=n/c;
        chk=str;
        FOR(i,0,'z')
        {
            if(ar[i]%2)
            {
                ch=i; ar[i]--;
                v=d-1;
                while(ar[s]==0&&s<'z')
                {
                    s++;
                }
                chk[d/2]=ch;
                l=d/2-1;r=d/2+1;
                rec(s);
                FOR(j,0,d-1)cout<<chk[j];
                cout<<' ';
                c--;
            }
        }
        FOR(i,0,'z')
        {
            if(ar[i]>0)
            {
                ch=i; ar[i]--;
                v=d-1;
                while(ar[s]==0&&s<'z')
                {
                    s++;
                }
                chk[d/2]=ch;
                l=d/2-1;r=d/2+1;
                rec(s);
                FOR(j,0,d-1)cout<<chk[j];
                cout<<' ';
                c--;
                i--;
            }
        }
    }
    return 0;
}


