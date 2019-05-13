#include<bits/stdc++.h>

using namespace std;

#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define MAX 20


bitset<MAX> bits[26], use, shit;
string str;

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    int n;

    cin >> n;
    FOR(i,0,n-1)
    {
        use[i] = 1;
    }

    int p, v;

    FOR(i,0,20)
    {
        int l, r;

        cin >> l >> r;

        v = (r - l) + 1;
        v = n - v;

        shit = use;
        shit >>= v;
        shit <<= l;
        cout << shit << endl;
    }

    return 0;
}

