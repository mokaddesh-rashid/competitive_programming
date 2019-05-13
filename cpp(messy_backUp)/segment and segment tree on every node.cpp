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
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define PB push_back
#define F first
#define S second
#define MAX 100010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct node
{
    int v;
    node *next[2];
    node()
    {
        FOR(i,0,1) next[i]=NULL;
        v=0;
    }
};

node *Root[MAX];

void update(node *idx, int b, int e, int st,int v)
{
    if(st > e || st < b ) return ;
    if(st == b && st == e)
    {
        idx->v = max(idx->v, v);
        return ;
    }

    if(idx->next[0] == NULL)
    {
        idx->next[0] = new node();
        idx->next[1] = new node();
    }

    update(idx->next[0], b, (b+e)/2, st, v);
    update(idx->next[1], ((b+e)/2)+1, e, st, v);

    idx->v = max(idx->next[0]->v, idx->next[1]->v);
}

LL query(node *idx, int b, int e, int st, int en)
{
    if(st > e || en < b ) return 0;
    if(st <= b && en >= e) return idx->v;

    if(idx->next[0] == NULL)
    {
        idx->next[0] = new node();
        idx->next[1] = new node();
    }
    if(idx->next[0] == NULL)
    {
        idx->next[0] = new node();
        idx->next[1] = new node();
    }

    LL lft = query(idx->next[0], b, (b+e)/2, st, en);
    LL rgt = query(idx->next[1], ((b+e)/2)+1, e, st, en);

    return max(lft, rgt);
}


int main()
{
    ///ios::sync_with_stdio(false);
    ///inf;
    //outf;

    int prin = 0, x, y, z, n, m, a;

    scanf("%d %d", &n, &m);///cin >> n >> m;

    FOR(i,0,MAX-1) Root[i] = new node();

    FOR(i,1,m)
    {
        scanf("%d %d %d", &x, &y, &z);///cin >> x >> y >> z;
        a = query(Root[x], 0, MAX, 0, z - 1);
        update(Root[y], 0, MAX, z, a + 1);
        prin = max(prin, a + 1);
    }

    printf("%d", prin);


    return 0;
}
