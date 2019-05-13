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
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> PR;

string str;
int a, b, n;

vector<int> four, seven;

int check(int p,char ch)
{
   /// cout << p << ' ' << ch << ' ' << a << ' ' << b << endl;
    if(ch < str[p]) return 0;

    if(str[p] < ch && ch == '4' && abs((a + 1) - b) <= (n - p - 1)) four.PB( p );
    if(str[p] < ch && ch == '7' && abs((b + 1) - a) <= (n - p - 1)) seven.PB( p );

    if(ch == str[p]) return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    int x, y;

    cin >> str; n = str.size();

    FOR(i,0,n-1)
    {

        x = check(i, '4');
        y = check(i, '7');
        if( !max(x, y) ) break;


        if(str[i] == '4') a++;
        else if(str[i] == '7') b++;
        if(i == n - 1 && a == b)
        {
            cout << str;
            return 0;
        }
    }

    x = y = -1;
    if(four.size()) x = four[four.size() - 1];
    if(seven.size()) y = seven[seven.size() - 1];


    if(n%2)
    {
        FOR(i,0,n)
        {
           if(i <= (n/2)) cout << 4;
           else cout << 7;
        }
    }
    else if(x == -1 && y == -1)
    {
        n += 1;
        FOR(i,0,n)
        {
           if(i <= (n/2)) cout << 4;
           else cout << 7;
        }
    }
    else
    {
        ///cout << x << ' ' << y << endl;
        int f, s;
        f = s = n/2;

        FOR(i,0,max(x, y) - 1)
        {
            cout << str[i];
            if(str[i] == '4') f--;
            else s--;
        }
//        cout << endl;
//        cout << f << ' ' << s << endl;

        if(x >= y) cout << '4', f--;
        else cout << '7', s--;

        while(f--)
        {
            cout << '4';
        }
        while(s--)
        {
            cout << '7';
        }
    }


    return 0;
}

