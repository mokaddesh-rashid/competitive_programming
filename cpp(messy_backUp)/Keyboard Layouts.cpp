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

string str,tr,sr;
int ar[sz], br[sz];

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m,x;
    char ch;

    cin>>str>>tr>>sr;
    n=sr.size();

    FOR(i,0,25)
    {
        ar[str[i]]=tr[i];
    }
    FOR(i,0,n-1)
    {
        if(sr[i]>='a'&&sr[i]<='z')
        {
            x=sr[i];
            x=ar[x];
            ch=x;
            cout<<ch;
        }
        else if(sr[i]>='A'&&sr[i]<='Z')
        {
            x=sr[i]-'A';
            x+='a';
            x=ar[x];
            ch=x-'a'+'A';
            cout<<ch;
        }
        else cout<<sr[i];
    }

    return 0;
}


