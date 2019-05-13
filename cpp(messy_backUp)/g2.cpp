#include<bits/stdc++.h>
using namespace std;

#define N 2010
#define M 4010

char s[N][M];
int n, m, c[N][N], p[N][N], id[N], rnk[N], cnt[N];
vector <int> rlt;

bool cmp(int i, int j) {
    int k = 0;
    while(s[i][k] == s[j][k]) k ++;
    return s[i][k] < s[j][k];
}

void calc(int x, int l, int r) {
    if(x == m) {
        c[l][r] = -1;
        return;
    }
    if(s[id[l]][x] == '1' || s[id[r]][x] == '0') {
        calc(x + 1, l, r);
        return;
    }
    int mid = r;
    while(s[id[mid]][x] == '1') mid --;
    c[l][r] = mid;
    p[l][r] = x;
    calc(x + 1, l, mid);
    calc(x + 1, mid + 1, r);
}

int gas(int l, int r) {
    if(l == 0) return cnt[r];
    return cnt[r] - cnt[l-1];
}

void solve(int l, int r) {
    int mid = c[l][r];
    if(mid == -1) return;
    int tot = gas(l, r);
    if(tot < 2) return;
    int L = gas(l, mid);
    int R = tot - L;
    if(L && R) rlt.push_back(p[l][r]);
    if(L) solve(l, mid);
    if(R) solve(mid + 1, r);
}

int main() {
    int t, q, runs = 0;
    scanf("%d", &t);
    while(t --) {
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 0; i < n; i ++) scanf("%s", s[i]);
        for(int i = 0; i < n; i ++) id[i] = i;
        sort(id, id + n, cmp);
        for(int i = 0; i < n; i ++) rnk[id[i]] = i;
        calc(0, 0, n - 1);
        printf("Case #%d:\n", ++ runs);
        while(q --) {
            memset(cnt, 0, sizeof cnt);
            int k, x;
            scanf("%d", &k);
            while(k --) {
                scanf("%d", &x);
                cnt[rnk[x]] = 1;
            }
            for(int i = 1; i < n; i ++) cnt[i] += cnt[i-1];
            rlt.clear();
            solve(0, n - 1);
            sort(rlt.begin(), rlt.end());
            int sz = unique(rlt.begin(), rlt.end()) - rlt.begin();
            printf("%d", sz);
            for(int i = 0; i < sz; i ++) printf(" %d", rlt[i]);
            puts("");
        }
    }
}
