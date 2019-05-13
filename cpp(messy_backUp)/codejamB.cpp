//Problem C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<bitset>
#include<queue>
#include<map>

using namespace std;

int get() {
	char c;
	while (c = getchar(), c != '-' && (c < '0' || c > '9'));
	bool flag = (c == '-');
	if (flag)
		c = getchar();
	int x = 0;
	while (c >= '0' && c <= '9') {
		x = x * 10 + c - '0';
		c = getchar();
	}
	return flag ? -x : x;
}

const int MAXN = 20;

bool flag[MAXN][MAXN];
int avail[MAXN][MAXN];
vector<pair<int, int> > g[MAXN][MAXN];
int px[MAXN * MAXN], py[MAXN * MAXN];
pair<int, int> ans[MAXN * MAXN];

bool dfs(int depth, int x, int y, int n, int m) {
	if (depth == n * m) {
		for (int i = 0; i < n * m; i++)
			ans[i] = make_pair(px[i] + 1, py[i] + 1);
		return true;
	}
	if (depth == 0) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				flag[i][j] = true;
				px[0] = i;
				py[0] = j;
				if (dfs(1, i, j, n, m))
					return true;
				flag[i][j] = false;
			}
	} else {
		int total = 0;
		pair<int, pair<int, int> > mov[MAXN * MAXN];
		for (int i = 0; i < g[x][y].size(); i++) {
			int u = g[x][y][i].first;
			int v = g[x][y][i].second;
			if (!flag[u][v])
				mov[total++] = make_pair(avail[u][v], make_pair(u, v));
		}
		sort(mov, mov + total);
		for (int i = 0; i < total; i++) {
			int u = mov[i].second.first;
			int v = mov[i].second.second;
			flag[u][v] = true;
			px[depth] = u;
			py[depth] = v;
			for (int j = 0; j < g[u][v].size(); j++)
				avail[g[u][v][j].first][g[u][v][j].second]--;
			if (dfs(depth + 1, u, v, n, m))
				return true;
			flag[u][v] = false;
			for (int j = 0; j < g[u][v].size(); j++)
				avail[g[u][v][j].first][g[u][v][j].second]--;
		}
	}
	return false;
}

int main() {
	int totaltest = get();
	for (int test = 1; test <= totaltest; test++) {
		int n = get(), m = get();
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				g[i][j].clear();
				for (int x = 0; x < n; x++)
					for (int y = 0; y < m; y++)
						if (i != x && j != y && i + j != x + y && i - j != x - y)
							g[i][j].push_back(make_pair(x, y));
			}
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				avail[i][j] = g[i][j].size();
		printf("Case #%d: ", test);
		if (!dfs(0, -1, -1, n, m))
			printf("IMPOSSIBLE\n");
		else {
			printf("POSSIBLE\n");
			for (int i = 0; i < n * m; i++)
				printf("%d %d\n", ans[i].first, ans[i].second);
		}
	}
	return 0;
}
