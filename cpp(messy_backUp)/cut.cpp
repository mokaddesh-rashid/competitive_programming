#include <bits/stdc++.h>

#define FO(i,a,b) for (int i = (a); i < (b); i++)
#define sz(v) int(v.size())

using namespace std;

int n, k, s;
int f[151][151*151];
int q[155];

int main() {
    scanf("%d%d%d", &n, &k, &s);
    FO(i,0,n) scanf("%d", q+i);
    FO(i,0,k) s += i;
    int mx = 0;
    FO(i,0,n) mx += i;
    s = min(s,mx);
    FO(kk,0,k+1) FO(ss,0,s+1) {
        if (kk == 0) {
            f[kk][ss] = 0;
        } else {
            f[kk][ss] = 1e9;
        }
    }

    FO(i,0,n)
    {
        for (int kk = k; kk >= 1; kk--)
        FO(ss,i,s+1)
        {
            f[kk][ss] = min(f[kk][ss], f[kk-1][ss-i]+q[i]);
        }
    }
    printf("%d\n", f[k][s]);
}

int getMaxc(int x, int t) {
  return min(s, (x - t) * t);
}

void update(int &x, int val) {
  x = min(x, val);
}

void solve()
{
  d[0][0] = 0;
  for (int x = 0; x < n; ++x)
 {
    for (int t = 0; t <= x + 1 && t <= k; ++t)
    {
      int maxc = getMaxc(x + 1, t);
      for (int c = 0; c <= maxc; ++c)
      {
        nd[t][c] = INF;
      }
    }

    for (int t = 0; t <= x && t <= k; ++t)
    {
      int maxc = getMaxc(x, t);
      for (int c = 0; c <= maxc; ++c)
      {
        int &cur = d[t][c];
        if (cur == INF)
        {
          continue;
        }
        update(nd[t][c], cur);
        update(nd[t + 1][c + (x - t)], cur + a[x]);
      }
    }
    for (int t = 0; t <= x + 1 && t <= k; ++t)
    {
      int maxc = getMaxc(x + 1, t);
      for (int c = 0; c <= maxc; ++c)
      {
        d[t][c] = nd[t][c];
      }
    }
  }
  int maxc = getMaxc(n, k);
  int res = INF;
  for (int c = 0; c <= maxc; ++c) {
    res = min(res, d[k][c]);
  }
  printf("%d\n", res);
}
