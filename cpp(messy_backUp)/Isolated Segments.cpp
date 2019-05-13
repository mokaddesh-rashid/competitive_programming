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

struct node
{
    int a, b, c, d;
}ar[1000];
int n;

int tri_area(int x1, int y1, int x2, int y2, int x3, int y3)
{
    return x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2);
}
int val(int x1, int y1, int x2, int y2, int x3, int y3)
{
    int re=0;
    if(x1==x2&&x3==x2)
    {
        //cout<<y1<<' '<<y2<<' '<<y3<<endl;
        if(y1<=y2&&y2<=y3) re=1;
        if(y1>=y2&&y2>=y3) re=1;
    }
    else if(y1==y2&&y3==y2)
    {
        if(x1<=x2&&x2<=x3) re=1;
        if(x1>=x2&&x2>=x3) re=1;
    }
    else
    {
        if(y1<=y2&&y2<=y3) re=1;
        if(y1>=y2&&y2>=y3) re=1;
        if(x1<=x2&&x2<=x3) re=1;
        if(x1>=x2&&x2>=x3) re=1;
    }
    //cout<<re<<endl;
    return re;
}

void solve()
{
    int a, b, c, d, cnt, ck, re=0;
    int x, y, z;
    FOR(i,0,n-1)
    {
        cnt=0;
        FOR(j,0,n-1)
        {
            if(i==j) continue;
            int x, y;
            a=tri_area(ar[i].a,ar[i].b,ar[j].a,ar[j].b,ar[i].c,ar[i].d);
            b=tri_area(ar[i].a,ar[i].b,ar[j].c,ar[j].d,ar[i].c,ar[i].d);

            c=tri_area(ar[j].a,ar[j].b,ar[i].a,ar[i].b,ar[j].c,ar[j].d);
            d=tri_area(ar[j].a,ar[j].b,ar[i].c,ar[i].d,ar[j].c,ar[j].d);
            //cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
            if(a==b&&b==c&&c==d&&c==0)
            {
                ck=0;
                x=val(ar[i].a,ar[i].b,ar[j].a,ar[j].b,ar[i].c,ar[i].d);
                y=val(ar[i].a,ar[i].b,ar[j].c,ar[j].d,ar[i].c,ar[i].d);
                if(x==1||y==1) cnt++;
                else
                {
                    //cout<<'k';
                    x=val(ar[j].a,ar[j].b,ar[i].a,ar[i].b,ar[j].c,ar[j].d);
                    y=val(ar[j].a,ar[j].b,ar[i].c,ar[i].d,ar[j].c,ar[j].d);
                    //cout<<x<<' '<<y<<endl;
                    if(x==1||y==1) cnt++;
                }
            }
            else
            {
                int f, s;
                f=s=0;
                if((a>=0&&b<=0)||(a<=0&&b>=0)) f=1;
                if((c>=0&&d<=0)||(c<=0&&d>=0)) s=1;
                if(s==1&&f==1) cnt++;
            }
        }
        if(cnt==0) re++;
    }
    cout<<re<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int tc;
    cin>>tc;
    FOR(t,1,tc)
    {
        int i, j, x, y, m;
        cin>>n;
        FOR(i,0,n-1) cin>>ar[i].a>>ar[i].b>>ar[i].c>>ar[i].d;
        solve();
    }
    return 0;
}


