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
#define vlid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

class Compare
{
public:
    bool operator()(string x,string y)
    {
        if(x.size()==y.size())return x<y;
        else return x.size()>y.size();
    }

};
string str[MAX],ans;
int cnt[30], start[30];

int valid(string str)
{
    mem(cnt,0);

    FOR(i,0,(int)str.size()-1)
    {
        int a=str[i]-'a';
        if(cnt[a])return 1;
        cnt[a]++;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    inf;
    //outf;
    mem(start,-1);
    int i,j,n,m,x,p,a,b;

    cin>>n;

    FOR(i,0,n-1)cin>>str[i];
    FOR(i,0,n-1)
    {
        if(valid(str[i]))
        {
            cout<<"NO"<<NL;
            return 0;
        }
    }

    sort(str,str+n,Compare());
    FOR(i,0,n-1)cout<<str[i]<<NL;

    FOR(i,0,n-1)
    {
        x=ans.size(); m=str[i].size();
        p=str[i][0]-'a';

        if(start[p]==-1&&ans>str[i])
        {
            ans=str[i]+ans;
            FOR(j,0,m-1)
            {
                p=str[i][j]-'a';
                start[p]=j;
            }
        }
        else if(start[p]==-1)
        {
            ans=ans+str[i];
            FOR(j,0,m-1)
            {
                p=str[i][j]-'a';
                start[p]=x+j;
            }
        }
        else
        {
            int k=0;
            FOR(j,start[p],start[p]+m-1)
            {
                if(j<x&&str[i][k]!=ans[j])
                {
                    cout<<"NO";
                    return 0;
                }
                else if(j>=x)ans+=str[i][k];
                k++;
            }
        }

    }

    if(valid(ans))cout<<"NO";
    else cout<<ans<<NL;
    return 0;
}


