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


//set<int>::iterator ii;

string str, ss;
int cnt[200010];
int i, j, y, n, m, a = -1, x = -1, b, e;


void adjust()
{

    int c = a-1;
    //cout << str[a+1] << endl;
    if( str[a+1] > '4' && m > 0 ) b++, e = 1;

    for( i=c; i>=0; i-- )
    {
        if( str[i] < '9' && b > 0 )
        {
            //cout << 'k';
            str[i] = str[i]+1;
            for( int k = i+1; k<n; k++ )
                str[k] = '0';
            b = 0;
            break;
        }
    }

    return;
}

void rev()
{
    while( m > 0 && x-1 > a )
    {
        if( str[x] > '4' )
        {
            str[x] = 0, cnt[x]++;
            if( str[x-1] != '9' )
            str[x-1] = str[x-1] + 1;
        }
        else
        {
            break;
        }
        x--;
        m--;
    }
    //cout << str << endl;
    adjust();

    return ;
}



int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;
    memset( cnt, 0, sizeof(cnt) );
    int ck = 0;
    a = x = -1;
    cin >> n >> m ;

    cin >> str;

    ss = str;

    for( i=0; i<n; i++ )
    {
        if( str[i] == '.' )
            a = i;
        if( str[i] > '4' && x == -1 && a > -1)
            x = i;
    }
     //cout << a << ' ' << x << endl;
    if( x == -1 )
    {
            n = str.size();
            for( i=n-1; i>=0; i-- )
            {
                if( str[i] == '.' ) ck = 1, n--;
                else if( str[i] == '0' ) n--;

                if( str[i] != '0' ) break;
            }
            if( ck == 0 )
            {
                cout << str;

            }
            else
            {
                for( i=0; i<n; i++ )
                cout << str[i];
            }
    }

    else
    {
        rev();
        if( b != 0 )
        {
            cout << 1;
            for( i=0; i<a; i++ )
                cout << 0;
        }
        else if( e != 0 )
        {
            for( i=0; i<a; i++ )
                cout << str[i];
        }
        else
        {
            for( i=0; i<n; i++ )
        {
            if( i > 0 && cnt[i] != 0 ) break;

            cout << str[i];
        }

        }

    }

    return 0;

}


