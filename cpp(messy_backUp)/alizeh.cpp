#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("inL.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define clean(mat,n)   FOR(i,0,n) mat[i].clear()
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define M          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 500010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

int A[MAX], B[MAX], C[MAX];
int n, block, st[720], en[720], id, q, blockId[MAX];
int up[4][720], shd[4][720];

struct Node
{
    int a, b, c, ab, ca, bc, abc;

}blockInfo[720];

int pending(int id)
{
///update pending operations
    int chao = 0;

    if(shd[1][id] || shd[2][id] || shd[3][id])
    FOR(p,st[id],en[id])
    {
        if(shd[1][id]) A[p] = up[1][id], chao = 1;
        if(shd[2][id]) B[p] = up[2][id], chao = 1;
        if(shd[3][id]) C[p] = up[3][id], chao = 1;
    }
    shd[1][id] = shd[2][id] = shd[3][id] = 0;

    return chao;
///completed updating previous pending operations
}

void update(int id)
{
    blockInfo[id] = {M, -M, -M, -M, -M, -M, -M};

    FOR(p,st[id],en[id])
    {
        blockInfo[id].abc = max(blockInfo[id].abc, B[p] + C[p] - A[p]);

        blockInfo[id].ab = max(blockInfo[id].ab, B[p] - A[p]);
        blockInfo[id].bc = max(blockInfo[id].bc, B[p] + C[p]);
        blockInfo[id].ca = max(blockInfo[id].ca, C[p] - A[p]);

        blockInfo[id].a = min(blockInfo[id].a, A[p]);
        blockInfo[id].b = max(blockInfo[id].b, B[p]);
        blockInfo[id].c = max(blockInfo[id].c, C[p]);

    }
    return;
}

int query(int id)
{
    if(!shd[1][id] && !shd[2][id] && !shd[3][id]) return blockInfo[id].abc;

    if(!shd[1][id] && !shd[2][id] ) return blockInfo[id].ab + up[3][id];
    if(!shd[2][id] && !shd[3][id]) return blockInfo[id].bc - up[1][id];
    if(!shd[1][id] && !shd[3][id]) return blockInfo[id].ca + up[2][id];

    if(!shd[1][id]) return up[2][id] + up[3][id] - blockInfo[id].a;
    if(!shd[2][id]) return blockInfo[id].b + up[3][id] - up[1][id];
    if(!shd[3][id]) return blockInfo[id].c + up[2][id] - up[1][id];

    return up[2][id] + up[3][id] - up[1][id];

}

int main()
{
    ///ios::sync_with_stdio(false);
    inf;
    outf;

    int tc;

    sf(tc);

    FOR(tt,1,tc)
    {
        int op, l, r, type, val;

        sf(n);
        FOR(i,0,n-1) sfff(A[i], B[i], C[i]);

        block = sqrt(n); id = 0;

        mem(st, -1); mem(shd, 0); ///mem(up, 0); mem(blockId, 0);
        FOR(i,0,n-1)
        {
            if(i % block == 0) id++;
            if(st[id] == -1) st[id] = i; en[id] = i;
            blockId[i] = id;
        }

        FOR(i,1,id) update(i);
        sf(q);
        FOR(fuck,0,q-1)
        {
            sf(op);
            if(op == 1)
            {
                sff(l, r); sff(type, val);
                l--; r--;

                FOR(i,l,r)
                {
                    id = blockId[i];

                    if(st[id] == i && en[id] <= r)
                    {
                        up[type][id] = val;
                        shd[type][id] = 1;
                    }
                    else
                    {
                        pending( id );
                        FOR(p,i,min(en[id],r)) ///replace values
                        {
                            if(type == 1) A[p] = val;
                            if(type == 2) B[p] = val;
                            if(type == 3) C[p] = val;
                        }
                        update( id ); ///re calculate block`s answers
                    }
                    i = en[id];
                }
            }
            else
            {

                sff(l, r);
                l--; r--;

                int prin = M * -1;

                FOR(i,l,r)
                {
                    id = blockId[i];

                    if(st[id] == i && en[id] <= r)
                    {
                        prin = max(prin, query( id ));
                        i = en[id];
                    }
                    else
                    {
                        if(pending( id )) update( id ); /// to get actual ans
                        prin = max(prin, B[i] + C[i] - A[i]);
                    }

                }
                printf("%d\n", prin);
            }
        }
    }

    return 0;
}

