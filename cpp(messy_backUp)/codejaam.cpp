#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define MAX 200010

int ar[MAX], va[MAX];

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);
    ///freopen("out.txt", "w", stdout);

    int tc;

    cin >> tc;

    FOR(tt,1,tc)
    {
        int n;

        cin >> n;
        vector<int> A, B, R;

        FOR(i,0,n-1)
        {
            cin >> ar[i];
            if(i%2) A.push_back( ar[i] );
            else B.push_back( ar[i] );
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int p, q, r;

        p = q = 0; r = -1;
        FOR(i,0,n-1)
        {
            if(i%2) va[i] = A[p], p++;
            else va[i] = B[q], q++;
        }

        FOR(i,1,n-1)
        {
            if(va[i] < va[i-1])
            {
                r = i - 1;
                break;
            }
        }

        if(r == -1) cout << "Case #" << tt << ": OK" << endl;
        else cout << "Case #" << tt << ": " << r << endl;

    }

    return 0;
}

/*
6
1 CS
2 CS
1 SS
6 SCCSSC
2 CC
3 CSCSS
*/
