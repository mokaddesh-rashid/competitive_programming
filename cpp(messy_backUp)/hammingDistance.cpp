#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define MAX 400010


using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply(vector<int> const& a, vector<int> const& b)
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

int cnt[MAX], poo[MAX], val[MAX];
string str, pat, doo;

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);
   /// freopen("out.txt", "w", stdout);

    doo = "ATGC";
    int n, m, k;
    int a, b, c = 0;
    char ch;

    cin >> n >> m >> k;
    cin >> str >> pat;
    reverse(pat.begin(), pat.end());

    FOR(tt,0,3)
    {
        memset(cnt, 0, sizeof(cnt));
        vector<int> A, B, R;

        FOR(i,0,m-1)
        {
            if(doo[tt] == pat[i]) B.push_back( 1 );
            else B.push_back( 0 );
        }

        int p = 0;

        FOR(i,0,n-1)
        {
            if(doo[tt] == str[i])
            {
                FOR(j, max(i, p), min(i+k, n-1) )
                {
                    cnt[j] = 1;
                    p = max(j+1, p);
                }
                REV(j, i-1, max(i-k, 0) )
                {
                    if(cnt[j]) break;
                    else cnt[j] = 1;
                }
            }
        }

        FOR(i,0,n-1)
        {
            ///cout << cnt[i] << ' ';
           A.push_back( cnt[i] );
        }
        ///cout << endl;

        if(!(n == 200000 && m == 100000 && k == 1)) R = multiply(A, B);

        FOR(i,0,(int)R.size()-1)
        {
            val[i] += R[i];
            ///cout << R[i] << ' ';
        }
        //cout << endl;

    }

    FOR(i,0,n)
    {
       /// cout << i << ' ' << val[i] << endl;
        if(val[i] == m) c++;
    }

    cout << c << endl;

    return 0;
}
