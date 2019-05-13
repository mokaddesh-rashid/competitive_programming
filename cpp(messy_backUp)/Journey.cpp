#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<LL,LL> pr;


//set<int>::iterator ii;

class Compare{
public:
    bool operator()(pr x, pr y){
        //return (x.first > y.first );
    }
};

vector <LL> mat[250011], cost[250011]; ///adjecency matrix

priority_queue< pr, vector< pr >, Compare > que;
LL cnt, k, n;

struct info0
{
    LL v, l, pa;
}lar[250001]; // array of info about input

int ar[250000];

void up()
{
    int ml = lar[n].l, a, b, c;
    a = n;
    b = 0;
    while( a != -1 )
    {
       ar[b] = a, b++;
       a = lar[a].pa;
    }
}

///**************dij*********
void dij( int p ) ///dij
{
    //cout << p << endl;
    lar[p].v = 0;
    lar[p].l = 1;
    lar[p].pa = -1;
    pair<LL,LL> mp;
    mp = make_pair( 0, p );
    que.push(mp);//que[re] = p;


    while( !que.empty() )
    {
        p = que.top().second;
        que.pop();
        //cout << p << " = ";
        for(LL i=0; i<mat[p].size(); i++ )
        {
            int x = mat[p][i];

            if( lar[p].v + cost[p][i] < lar[x].v || ( lar[p].l+1 > lar[x].l && lar[p].v + cost[p][i] < k && lar[p].l+1 <= n ) )
            {
                //cout << x << '(' << lar[p].v + cost[p][i] << ')' << ' ';
                lar[x].v = lar[p].v + cost[p][i];
                lar[x].l = lar[p].l+1;
                lar[x].pa = p;
                mp = make_pair( lar[x].v, x );
                que.push(mp);//que[re] = x;
                if( x == n ) up();

            }

        }
        //cout << endl;
        //hd++;
    }
    return;
}



void mess()
{
   for(int i=1; i<=201000; i++ )
         lar[i].v = mx;
}



int main()
{
    ios::sync_with_stdio(false);
    memset( lar, 0, sizeof(lar) );
    LL i, j, x, y, m, z, a, b, c, e, f, g;

    cin >> n >> m >> k;

    mess();
    for( i=0; i<m; i++ )
    {
        cin >> x >> y >> z;
        mat[x].push_back(y);
        cost[x].push_back(z);
    }

    dij( 1 );
    int ml = lar[n].l;

    cout << ml << endl;



    for( i=ml-1; i>=0; i-- )
        cout << ar[i] << ' ';

    return 0;

}
