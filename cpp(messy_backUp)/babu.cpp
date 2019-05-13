#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

ll solve() {
	ll m, n; cin >> m >> n;
	vector<string> a(m);
	FOR(i,0,m) cin >> a[i];

	vvl dist(m,vl(n,oo));
	queue<pll> q;

	FOR(i,0,m) FOR(j,0,n) if (a[i][j] == '1') {
		dist[i][j] = 0, q.push({i,j});
	}

	while (sz(q)) {
		ll i, j;
		tie(i,j) = q.front();
		q.pop();

		FOR(di,-1,2) FOR(dj,-1,2) if (abs(di)+abs(dj) == 1) {
			ll ni = i+di, nj = j+dj;
			if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
			if (dist[ni][nj] < oo) continue;
			dist[ni][nj] = dist[i][j] + 1;
			q.push({ni,nj});
		}
	}

	ll rmin = -1, rmax = m+n;
	while (rmax-rmin > 1) {
		ll r = (rmin+rmax)/2;

		vvl total_furthest(m,vl(n,-oo));

		FOR(flipi,0,2) {
			FOR(flipj,0,2) {
				vvl furthest(m,vl(n,-oo));
				FOR(i,0,m) FOR(j,0,n) {
					if (dist[i][j] > r) furthest[i][j] = 0;
					if (i > 0) furthest[i][j] = max(furthest[i][j], furthest[i-1][j] + 1);
					if (j > 0) furthest[i][j] = max(furthest[i][j], furthest[i][j-1] + 1);
					total_furthest[i][j] = max(total_furthest[i][j], furthest[i][j]);
				}

				for (auto &v: dist) reverse(all(v));
				for (auto &v: total_furthest) reverse(all(v));
			}
			reverse(all(dist));
			reverse(all(total_furthest));
		}

		//FOR(i,0,m) FOR(j,0,n) cerr << total_furthest[i][j] << " \n"[j+1==n];

		bool ok = false;
		FOR(i,0,m) FOR(j,0,n) if (total_furthest[i][j] <= r) ok = true;

		if (ok) rmax = r; else rmin = r;
	}
	return rmax;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll TC; cin >> TC;
	FOR(tc,1,TC+1) cout << "Case #" << tc << ": " << solve() << endl;
}

