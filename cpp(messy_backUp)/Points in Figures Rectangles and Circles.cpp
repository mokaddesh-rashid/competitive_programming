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
#define LL           double
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

LL tri_area(LL x1, LL y1, LL x2, LL y2, LL x3, LL y3)
{
    return (x1*(y2-y3)-x2*(y1-y3)+x3*(y1-y2))*.5;
}
struct node
{
    double x, y, xx, yy, rd;
    double x1, y1, x2, y2, x3, y3;
    char ty;
};
double ax, bx, ay, by, f, s, dis;
node ar[100], br[100];
int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    char ch;
    int i=0, j, x, y, n=0, m;
    LL a, b, c;
    while(true)
    {
        cin>>ch;
        if(ch=='*')break;
        ar[i].ty=ch;
        if(ch=='r')cin>>ar[i].x>>ar[i].y>>ar[i].xx>>ar[i].yy;
        else if(ch=='t')cin>>ar[i].x1>>ar[i].y1>>ar[i].x2>>ar[i].y2>>ar[i].x3>>ar[i].y3;
        else cin>>ar[i].x>>ar[i].y>>ar[i].rd;
        i++;n++;
    }
    m=1;
    while(true)
    {
        x=-1;
        cin>>ax>>ay;
        if(ax==ay&&ax==9999.9) break;
        bx=ax; by=ay;
        FOR(i,0,n-1)
        {
          if(ar[i].ty=='t')
          {
             dis=tri_area(ar[i].x1,ar[i].y1,ar[i].x2,ar[i].y2,ar[i].x3,ar[i].y3);
             a=tri_area(ar[i].x1,ar[i].y1,ax,ay,ar[i].x2,ar[i].y2);
             b=tri_area(ar[i].x2,ar[i].y2,ax,ay,ar[i].x3,ar[i].y3);
             c=tri_area(ar[i].x3,ar[i].y3,ax,ay,ar[i].x1,ar[i].y1);
             //cout<<m<<' '<<a<<' '<<b<<' '<<c<<endl;
             if(a>=0&&b>=0&&c>=0)
                cout<<"Point "<<m<<" is contained in figure "<<i+1<<endl, x=i;
             else if(a<=0&&b<=0&&c<=0)
                cout<<"Point "<<m<<" is contained in figure "<<i+1<<endl, x=i;
          }
          if(ar[i].ty=='c')
          {
              dis = (ax-ar[i].x)*(ax-ar[i].x);
              dis += ((ay-ar[i].y)*(ay-ar[i].y));
              dis = sqrt(dis);
              if(dis<=ar[i].rd)cout<<"Point "<<m<<" is contained in figure "<<i+1<<endl, x=i;
              continue;
          }
          if(ar[i].x<ax&&ax<ar[i].xx && ar[i].x<bx&&bx<ar[i].xx && ar[i].y>ay&&ay>ar[i].yy&&ar[i].y>by&&by>ar[i].yy)
            cout<<"Point "<<m<<" is contained in figure "<<i+1<<endl, x=i;
        }
        if(x!=-1) x=x;
        else cout<<"Point "<<m<<" is not contained in any figure"<<endl;
        m++;
    }
    return 0;
}



