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
typedef pair<LL,LL> pr;

LL tri_area(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3)
{
    return x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2);
}
LL val(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3)///chk if x2, y2 is on x1,y1 to x3,y3 segment
{
    LL re=0;
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

LL solve(LL ax, LL ay, LL bx, LL by, LL cx, LL cy, LL dx, LL dy)
{
    LL a, b, c, d, cnt=0, ck, re=0;
    LL x, y, z;

    a=tri_area(ax,ay,cx,cy,bx,by);
    b=tri_area(ax,ay,dx,dy,bx,by);

    c=tri_area(cx,cy,ax,ay,dx,dy);
    d=tri_area(cx,cy,bx,by,dx,dy);
    //cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
    if(a==b&&b==c&&c==d&&c==0)
    {
        ck=0;
        x=val(ax,ay,cx,cy,bx,by);
        y=val(ax,ay,dx,dy,bx,by);
        if(x==1||y==1) cnt++;
        else
        {
            //cout<<'k';
            x=val(cx,cy,ax,ay,dx,dy);
            y=val(cx,cy,bx,by,dx,dy);
            //cout<<x<<' '<<y<<endl;
            if(x==1||y==1) cnt++;
        }
    }
    else
    {
        LL f, s;
        f=s=0;
        if((a>=0&&b<=0)||(a<=0&&b>=0)) f=1;
        if((c>=0&&d<=0)||(c<=0&&d>=0)) s=1;
        if(s==1&&f==1) cnt++;
    }
    if(cnt!=0) re++;
    return re;
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
        LL i, j, x=0, y, ax, ay, bx, by, xx, yy, a=0;
        cin>>ax>>ay>>bx>>by>>x>>y>>xx>>yy;
        a=solve(ax, ay, bx, by, x, y, xx, y);
        a=max( a, solve(ax, ay, bx, by, x, y, x, yy));
        a=max( a, solve(ax, ay, bx, by, xx, yy, xx, y));
        a=max( a, solve(ax, ay, bx, by, xx, yy, x, yy));
        if(x<=ax&&ax<=xx && x<=bx&&bx<=xx && y>=ay&&ay>=yy&&y>=by&&by>=yy) a=1;///rectangle r bitore ase naki

        if(a==0) cout<<'F'<<endl;
        else cout<<'T'<<endl;
    }
    return 0;
}


