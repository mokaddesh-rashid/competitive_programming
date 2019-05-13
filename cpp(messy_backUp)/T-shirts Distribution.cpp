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
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<int,int> pr;

/*dir array
//8 moves
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/


//set<int>::iterator ii;

string str, ex;
int ar[100010], t, pre[100010][5], nd[10000], col[100010];

void up( )
{
    int x = pre[t][0];

    if( ex == "S" ) nd[1]++, pre[t][x] = 1;
    else if( ex == "M" ) nd[2]++, pre[t][x] = 2;
    else if( ex == "L" ) nd[3]++, pre[t][x] = 3;
    else if( ex == "XL" ) nd[4]++, pre[t][x] = 4;
    else if( ex == "XXL" ) nd[5]++, pre[t][x] = 5;
    else if( ex == "XXL" ) nd[6]++, pre[t][x] = 6;

    return;
}

void chk()
{
    ex = "";

    for( int i=0; i<str.size(); i++ )
    {
        if( str[i] == ',' ) pre[t][0]++, up(), ex = "";
        else ex = ex+str[i];
    }

    pre[t][0]++;
    up();
    return;
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m, a = 0;

    for( i=1; i<=6; i++ ) cin >> ar[i];

    cin >> n;

    for( i=0; i<n; i++, t++ )
    {
        cin >> str;
        chk();
    }

    for( i=0; i<n; i++ )
        {
            if( pre[i][0] == 1 )
            {
                x = pre[i][1];
                nd[x]--;
                ar[x]--;
                if( ar[x] < 0 ) a = 1;
                col[i] = x;
            }
        }

    for( i=0; i<n; i++ )
        {
            if( pre[i][0] == 2 )
            {
                x = pre[i][1];
                y = pre[i][2];

                if( nd[x] < ar[x] ) col[i] = x, nd[x]--, ar[x]--;
                else if( nd[y] < ar[y] ) col[i] = y, nd[y]--, ar[y]--;

            }
        }
    for( i=0; i<n; i++ )
        {
            if( col[i] == 0 )
            {
                x = pre[i][1];
                y = pre[i][2];

                if( ar[x] > 0 ) col[i] = x, nd[x]--, ar[x]--;
                else if( ar[y] > 0 ) col[i] = y, nd[y]--, ar[y]--;
                else a = 1;

            }
        }

    if( a == 1 ) cout << "NO";
    else
    {
        cout << "YES\n";
        for( i=0; i<n; i++ )
        {
            if( col[i] == 1 ) cout << "S" << endl;
            else if( col[i] == 2 ) cout << "M" << endl;
            else if( col[i] == 3 ) cout << "L" << endl;
            else if( col[i] == 4 ) cout << "XL" << endl;
            else if( col[i] == 5 ) cout << "XXL" << endl;
            else if( col[i] == 6 ) cout << "XXXL" << endl;

        }
    }

    return 0;

}


