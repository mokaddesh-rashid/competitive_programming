#include <bits/stdc++.h>

using namespace std;

int n, m, x[100005], ta;
long long ba;
priority_queue< pair< long long, int >, vector< pair< long long, int > >, greater< pair< long long, int > > > q;

int main() {
    freopen("in.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", x + i);
		if (x[i] < 0) {
			ba += x[i];
			x[i] = -x[i];
		}
	}
	sort(x, x + n);
	printf("%lld\n", ba);
	m--;
	q.push(make_pair(ba + x[0], 0));
	while (m--) {
		printf("%lld\n", q.top().first);
		ba = q.top().first;
		ta = q.top().second + 1;
		q.pop();
		// printf(" %d\n", ta);
		if (ta < n) {
			// printf(" %lld %lld\n", ba + x[ta], ba - x[ta - 1] + x[ta]);
			q.push(make_pair(ba + x[ta], ta));
			q.push(make_pair(ba - x[ta - 1] + x[ta], ta));
		}
	}
	return 0;
}
