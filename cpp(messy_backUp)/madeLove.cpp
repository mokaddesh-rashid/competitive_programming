#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define MAX 1000010


typedef complex<double> base;

void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();

	for (int i=1, j=0; i<n; ++i) {
		int bit = n >> 1;
		for (; j>=bit; bit>>=1)
			j -= bit;
		j += bit;
		if (i < j)
			swap (a[i], a[j]);
	}

	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen (cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w (1);
			for (int j=0; j<len/2; ++j) {
				base u = a[i+j],  v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] /= n;
}

vector<int> multiply(vector<int> a, vector<int> b)
{
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

vector<int> A, B, R;

void bm(int p)
{
    if(p == 0) return;

    int mid = p>>1;

    bm(mid);
    R = multiply(R, R);
    if(p%2) R = multiply(R, A);
////cout<<R.size()<<endl;

}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);
   /// freopen("out.txt", "w", stdout);

    int n, m, k, a;

    FOR(i,0,1000) A.push_back( 0 );
    FOR(i,0,1000) R.push_back( 0 );
    R[0] = 1;


    cin >> n >> k;
    FOR(i,1,n)
    {
        cin >> a;
        A[a] = 1;
    }

    bm(k);

    FOR(i,0,(int)R.size()-1)
    {
        if(R[i]) cout << i << ' ';
    }

    return 0;
}
