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
typedef pair<string,int> p_i;


//set<int>::iterator ii;

string str[3001];
struct info
{
    string s;
    int v;
}pi[3001];

bool compare( info x, info y )
{
    return ( x.v < y.v );
}

void value( string x , int j)
{
   int a, b, c, d, i, n = x.size();
    for( i=0; i<n; i++ )
        {
            if( x[i] == '(' ) a = i;
            else if( x[i] == ')' ) b = i;
        }
   //cout << endl << x << ' ' << b-a << endl;
    pi[j].s = x, pi[j].v = b-a;
}

struct node
{
    int x, v;
    node *ne[27];
};

node *root;

void add( string st )
{
    node *t = root;
    int i = 0, n = st.size(), x;

    while( i < n )
    {
        x = st[i]-'a';

        if( t->ne[x] == NULL )
        {
            node *newnode = new node;
            newnode->v = 0;
            for(int i=0; i<26; i++ ) newnode->ne[i] = NULL;
            t->ne[x] = newnode;
        }
        t = t->ne[x];
        i++;
    }
    t->v = 1;

}

int src( string st )
{
    node *t = root;
    int i = 0, n = st.size(), x;

    while( i < n )
    {
        x = st[i]-'a';
        if( t->ne[x] == NULL )
            return 0;
        t = t->ne[x];
        i++;
    }
    return t->v;

}

void in()
{
    int j, i = 0;
    while( pi[i].v == 1 )
    {
        string st = "";
        j = 0;
        while( pi[i].s[j] != '=' )
        {
            st = st+pi[i].s[j];
            j++;
        }
        cout << st << endl;
        add(st);
        i++;
    }

}

int chk( int x )
{
    int i, j, a, b, c, n = pi[x].s.size();

    i = a = 0;
    b = 1;
    string st = "";

    while( pi[x].s[i] != ')' )
    {
        if( a == 1 )
        {
            if( pi[x].s[i] == ',' )
            {
                b = min( b , src(st) );
                //cout << st << ' ' << b << endl;
                st = "";
            }
            else st = st+pi[x].s[i];
        }
        if( pi[x].s[i] == '(' )
            a = 1;
        i++;
    }
    return b = min( b , src(st) );

}
void chk_add( int i )
{
   string st = "";
    int j = 0;
    while( pi[i].s[j] != '=' )
    {
        st = st+pi[i].s[j];
        j++;
    }
    add(st);
}

int ck[3001];

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int t, ca = 1;

        memset( ck, 0, sizeof(ck) );
        node *newnode = new node;
        newnode->v = 0;
        for(int i=0; i<26; i++ ) newnode->ne[i] = NULL;
        root = newnode;
        int i, j, x, y, n, m, a, b;

        cin >> n ;

        for( i=0; i<n; i++ )
            cin >> str[i], value(str[i], i);

        sort( pi, pi+n, compare );

        in();

        while( true )
        {
            a = 0;
            for( i=0; i<n; i++ )
        {
            if( pi[i].v != 1 && ck[i] == 0 )
            {
                x = chk(i);
                if( x != 0 ) chk_add(i), ck[i]++;
                a = max( x, a );
            }
            else if( pi[i].v == 1 ) ck[i]++;

        }
        if( a == 0 ) break;

        }

        b = 1;
        for( i=0; i<n; i++ )
            b = min( ck[i], b );

        if( b == 0 ) cout << "Case #" << ca++ << ": " << "BAD" << endl;
        else cout << "Case #" << ca++ << ": " << "GOOD" << endl;


    return 0;

}


