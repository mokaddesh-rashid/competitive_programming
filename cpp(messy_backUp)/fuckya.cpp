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


bool babu(string str)
{
    int i=0, j=str.size()-1;

   while(i<j)
    {
        if(str[i]!=str[j]) return false;
        i++; j--;
    }

    return true;
}

int cnt[100];
string  ans[100];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    ///outf;
    mem(cnt,-1);
    int i,j,n,m=1;
    string str;

    while(m<=10000)
    {
        str="";
        set<string>sot;
        int a=m;n=0;
        while(a>0)
        {
            ///cout<<a%2;
            str+=('0'+a%2);
            a/=2;
            n++;
        }
        reverse(str.begin(),str.end());
        FOR(i,0,n-1)
        {
            string chk="";
            FOR(j,i,n-1)
            {
                chk+=str[j];
                if(babu(chk)) sot.insert(chk);
            }
        }

        if(cnt[n]==-1||(int)sot.size()<cnt[n]) cnt[n]=(int)sot.size(), ans[n]=str;
        ///cout<<sol.size()<<NL;
        m++;
    }

    FOR(i,1,20) cout<<i<<' '<<cnt[i]<<' '<<ans[i]<<NL;
    return 0;
}



