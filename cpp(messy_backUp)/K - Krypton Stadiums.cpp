#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
#define PB push_back
#define F first
#define S second
#define MK make_pair
typedef pair<int,int> pr;

int val(char ch)
{
    int i, j, a, b, c;
    if(ch>='0'&&ch<='9')
    {
        a=ch-'0';
    }
    if(ch>='A'&&ch<='Z')
    {
        a=ch-'A';
        a+=10;
    }
    if(ch>='a'&&ch<='z')
    {
        a=ch-'a';
        a+=36;
    }
    return a;
}

string str;
pr ar[200010];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int n;
    while(cin>>n)
    {
        int i, j, x, y, m, a, b, c, g=0, ba=0, mn=0;
        FOR(i,0,n-1)
        {
            cin>>str;
            a=val(str[2]);b=val(str[1]);c=val(str[0]);
            x=62*62*c; x+=(62*b); x+=a;
            a=val(str[5]);b=val(str[4]);c=val(str[3]);
            y=62*62*c; y+=(62*b); y+=a;
            //cout<<x<<' '<<y<<endl;
            ar[i].F=x; ar[i].S=y;
            if(x==0)mn=max(mn,y);
        }
        FOR(j,0,n-1)
        {
            a=ar[j].S;
            g=0;
            FOR(i,j,a)
            {
                if(ar[i].S>=n-1) g=1, b=i;
            }
            cout<<j<<' '<<g<<endl;
            if(g==0) break;
            if(g==1) j=b+1;
        }

        FOR(i,0,mn)
        {
            if(ar[i].S>=n-1) ba=1;
        }
        if(g==1) cout<<"Great\n";
        else if(b==1) cout<<"Acceptable\n";
        else cout<<"Bad\n";
    }
    return 0;
}


