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
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 2000010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

vector<int> Zalgo(string s) {
	vector<int> v(1,s.size());
	for(int i=1,l=-1,r=-1;i<s.size();i++) {
		if(i<=r && v[i-l]<r-i+1) v.push_back(v[i-l]);
		else {
			l=i; r=(i>r)?i:(r+1);
			while(r<s.size() && s[r-i]==s[r]) r++;
			v.push_back((r--)-l);
		}
	}
	v.push_back(0);
	v.clear();
	return v;
}

string str, lo, ro;
vector<int> low, up;
LL show[MAX];

int retLow(int i)
{
    int l = i + lo.size() - 1;
    int la = low[i + 1 + lo.size() ];

    if(l > str.size()) return -1;
    if(str[i + la] < lo[la]) l++;
    if(l > str.size()) return -1;
    return l;
}
int retHigh(int i)
{
    int r = i + ro.size() - 1;
    int la = up[i + 1 + ro.size()];

    if(r >= str.size()) return str.size();
    if(la != ro.size() && str[i + la] > ro[la]) r--;

    return r + 1;
}


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int n;

    cin >> str >> lo >> ro; n = str.size();

    up = Zalgo( ro + "@" + str );
    low = Zalgo( lo + "@" + str );

    LL add = 1; show[1] = -1;
    FOR(i,0,n)
    {
        add += (M + show[i]); add %= M;

        int l = retLow( i );
        int r = retHigh( i );

        if(str[i] == '0') r = i + 1;
        if(l == -1 || l >= r);
        else
        {
            show[l + 1] += add; show[r + 1] += (M - add);
            show[l + 1] %= M; show[r + 1] %= M;
        }

    }

    cout << add << endl;

    return 0;
}
