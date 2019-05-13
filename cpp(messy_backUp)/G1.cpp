#include <bits/stdc++.h>
using namespace std;

#define N 2020
#define M 4040

char s[N][M];
int n, m;
int id[N], rk[N];

bool cmp(int i, int j) {
	int k = 0;
	while (s[i][k] == s[j][k]) k ++;
	assert(k < m);
	return s[i][k] < s[j][k];
}

int calc_dif(int i, int j, int k = 0) {
	while (s[i][k] == s[j][k]) k ++;
	assert(k < m);
	return k;
}

int dif[N][N];

bool cmp_(int i, int j) {
	return rk[i] < rk[j];
}

int js[N];
int ans[N];

int main() {
	//freopen("r.in", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt ++) {
		int q;
		scanf("%d %d %d", &n, &m, &q);
		for (int i = 0; i < n; i ++) id[i] = i, scanf("%s", s[i]);
		sort(id, id + n, cmp);
		for (int j = 1; j < n; j ++) {
			int now = 0;
			for (int i = 0; i < j; i ++) {
				now = calc_dif(id[i], id[j], now);
				dif[id[i]][id[j]] = now;
			}
		}
		for (int i = 0; i < n; i ++) rk[id[i]] = i;
		printf("Case #%d:\n", tt);
		while (q --) {
			int k;
			scanf("%d", &k);
			for (int i = 0; i < k; i ++) scanf("%d", &js[i]);
			int e = 0;
			sort(js, js + k, cmp_);
			for (int i = 1; i < k; i ++) ans[++e] = dif[js[i-1]][js[i]];
			int ee = 0;
			sort(ans + 1, ans + e + 1);
			for (int i = 1; i <= e; i ++) if (i == 1 || ans[i] != ans[i-1]) ans[++ee] = ans[i];
			printf("%d", ee);
			for (int i = 1; i <= ee; i ++) printf(" %d", ans[i]);
			puts("");
		}
	}

	return 0;
}
