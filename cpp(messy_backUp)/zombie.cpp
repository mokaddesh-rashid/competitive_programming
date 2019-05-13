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
#define M          998244353
#define M_PI           3.14159265358979323846  /* pi */
#define LL           unsigned long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 510
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

LL ara[MAX];
int n, can[MAX];
map<LL,int> mopa;
map<LL,int>::iterator it;

LL my_sqrt(LL x)
{
  if(x < 0) return -1;
  LL y = (LL) (sqrtl((long double) x) + 0.5);
  while (y * y < x) {
    y++;
  }
  while (y * y > x) {
    y--;
  }
  if (y * y == x) {
    return y;
  }
  return -1;
}

LL my_crt(LL x)
{

  assert(x > 0);
  LL y = (LL) (powl((long double) x, 1.0 / 3.0) + 0.5);
  while (y * y * y < x) {
    y++;
  }
  while (y * y * y > x) {
    y--;
  }
  if (y * y * y == x) {
    return y;
  }
  return -1;
}

LL gcd(LL a, LL b) {
  while (a > 0 && b > 0) {
    if (a > b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    LL prin = 1;

    cin >> n;
    FOR(i,0,n-1) cin >> ara[i];

    FOR(i,0,n-1)
    {
        LL v = my_sqrt( ara[i] );
        LL vv = -1;
        if(v != -1) vv = my_sqrt( v );
        LL p = my_crt( ara[i]);

        if(vv != -1)
        {
            can[i] = 1;
            mopa[ vv ] += 4;
        }
        else if(v != -1)
        {
            can[i] = 1;
            mopa[ v ] += 2;
        }
        else if(p != -1)
        {
            can[i] = 1;
            mopa[ p ] += 3;
        }
    }

    FOR(i,0,n-1)
    {
        LL cnt = 0, di = 1, x, y;
        if(!can[i])
        {
            FOR(j,0,n-1)
            {
                if(ara[i] == ara[j])
                {
                    cnt++; can[j] = 1;
                    continue;
                }

                LL v = gcd(ara[i], ara[j]);
                if(v == 1) continue;

                di = 0;
                x = v; y = ara[i] / x;
               /// cout << ara[i] << ' ' << v << ' ' << x << ' ' << y << endl;

            }

            if(di)
            {
                cnt++;
                prin *= cnt; prin %= M;
                prin *= cnt; prin %= M;
            }
            else
            {
                mopa[x] += cnt;
                mopa[y] += cnt;
            }
        }
    }

    for (it=mopa.begin(); it!=mopa.end(); ++it)
    {
        LL cnt = it->second  + 1;
        prin *= cnt; prin %= M;

    }
    cout << prin << endl;
    cout.flush();


    return 0;
}
