#include<bits/stdc++.h>

using namespace std;


#define FOR(i,j,k) for(int i = j; i <= k; i++)
#define REV(i,j,k) for(int i = j; i >= k; i--)
#define F first
#define S second

typedef pair<int,int> pii;
const int MAX = 100010;

int ara[MAX], n, nex[MAX];
deque<pii> dq;

struct Node
{
    int p = 0;
    pii info[350];

}block[350];

int blockSz;

int which(int p) {return p/blockSz;}
int shuru(int bId) {return bId * blockSz;}
int sesh(int bId) {return (bId + 1) * blockSz - 1;}

void update(int bId)
{
    int l = shuru( bId ), r = sesh( bId ), &p = block[ bId ].p;

    p = 0;

    FOR(i,l,r)
        block[ bId ].info[p++] = {nex[i], ara[i]};

    sort(block[ bId ].info, block[ bId ].info + p);

    int c = 0;
    REV(i,p-1,0)
    {
        c = max(c, block[ bId ].info[i].S);
        block[ bId ].info[i].S = c;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    ///freopen("in.txt", "r", stdin);

    cin >> n; blockSz = sqrt( n );
    FOR(i,0,n-1) cin >> ara[i];

    dq.push_back( {n, -1} );
    REV(i,n-1,0)
    {
        while(!dq.empty())
        {
            int v = dq.back().S;

            if(v >= ara[i]) dq.pop_back();
            else break;
        }

        nex[i] = dq.back().F - i;
        dq.push_back( {i, ara[i]} );
    }

    FOR(i,0,n-1)
        if(!i || which(i) != which(i - 1)) update( which(i) );

    int q, l, r, v;
    cin >> q;
    FOR(i,0,q-1)
    {
        cin >> l >> r >> v; l--; r -= v;

        int prin = 0;

        for(int i = l; i <= r; i++)
        {
            int bId = which( i );
            int xx = shuru( bId ), yy = sesh( bId );

            if(l <= xx && yy <= r)
            {
                int st = 0, en = block[ bId ].p - 1, mid;

                while(st <= en)
                {
                    mid = (st + en)>>1;

                    if(block[ bId ].info[mid].F < v) st = mid + 1;
                    else en = mid - 1, prin = max(prin, block[ bId ].info[mid].S);
                }

                i = yy;
            }
            else if(nex[i] >= v) prin = max(prin, ara[i]);
        }

        cout << prin << endl;
    }

    return 0;
}
