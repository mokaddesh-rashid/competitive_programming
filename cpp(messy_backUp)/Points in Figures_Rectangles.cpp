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
    double x, y, xx, yy, rd;
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
    while(true)
    {
        cin>>ch;
        if(ch=='*')break;
        ar[i].ty=ch;
        if(ch=='r')cin>>ar[i].x>>ar[i].y>>ar[i].xx>>ar[i].yy;
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


