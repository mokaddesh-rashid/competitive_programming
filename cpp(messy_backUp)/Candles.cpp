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

int ar[110], p, n, ooh[100010], can[1100][101];
LL val[100000], num[12];

int num_chk(int b, int c)
{
    int a = 0;
    if(b<10&&c<10)
    {
      if(b!=c) a=1;
    }
    else if(b<10&&c>=10)
    {
       int e, f;
       e=c%10;
       f=c/10;
       if(b!=e&&b!=f&&e!=f) a=1;
    }
    else if(b>=10&&c<10)
    {
       int e, f;
       e=b%10;
       f=b/10;
       if(c!=e&&c!=f&&e!=f) a=1;
    }
    else
    {
       int e, f, g, h;
       e=b%10;
       f=b/10;
       g=c%10;
       h=c/10;
       if(e!=f&&e!=g&&e!=h&&f!=g&&f!=h&&g!=h) a=1;
    }
    return a;
}
void chk(int pos)
{
   int cnt, temp, lel, x, y, z, a, b, c;

   cnt = 0;
   FOR(i,0,p-1)
   {
       FOR(j,0,p-1)
          {
             if(i==j)continue;
             ooh[cnt] = num[i]*10+num[j];
             cnt++;
          }
       ooh[cnt] = num[i]; cnt++;
   }
   ooh[cnt] = 0; cnt++;
   FOR(i,0,cnt-1)
   {
       FOR(j,0,cnt-1)
       {
          a = num_chk(ooh[j],ooh[i]);
          b = ooh[j]+ooh[i];
          if(a==1&&b<=100) can[pos][b]++;
       }
       can[pos][ooh[i]]++;
   }

   sort(num,num+p,greater<int>());
   LL ret = 0;
   FOR(i,0,p-1)
   {
       ret = ret*10+num[i];
   }
   //if(p==10) cout<<ret<<endl;
   val[pos] = ret;
}

void create()
{
    int z = 1<<10;
    FOR(i,1,z-1)
    {
        p = 0;
        FOR(j,0,9)
        {
            if(i&(1<<j))
            {
               num[p]=j;
               p++;
            }
        }
        chk(i);

    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //inf;
    //outf;
    create();
    int ca=1;
    while(true)
    {
        int i, j, y, m, z, a, b, c, d;
        LL x, ans = maxx;
        sf(n);
        //cin >> n;
        if(n==0)break;
        FOR(i,0,n-1) sf(ar[i]);//cin>>ar[i];
        z = 1<<10;
        FOR(i,1,z-1)
        {
           a = 1;
           FOR(j,0,n-1)
           {
              x = ar[j];
              if(can[i][x]==0) a=0;
           }
           if(a==1)ans=min(ans,val[i]);
        }
        printf("Case %d: %lld\n",ca++,ans);
        //cout << "Case " << ca++ << ": " << ans << endl;
    }
    return 0;
}


