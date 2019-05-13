#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          prLLf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-9223372036854775807
#define maxx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n'
#define MAX 100005
#define cnd tree[idx]
#define lnd (2*idx)
#define rnd ((2*idx)+1)
typedef pair<LL,LL> p_i;


//set<LL>::iterator ii;

struct node
{
    LL x, v;
    node *l, *r, *p;
};

node *root = NULL;
LL ar[40], ran;

void add( )
{
    LL i, x;
    x = 21;
    i = 0;
    node *t = root;

    while( x-- )
    {
        if( ar[i] == 0 )
        {

            if( t->l == NULL )
            {
                node *newnode = new node;
                newnode->p = t;
                newnode->l = NULL;
                newnode->r = NULL;
                newnode->x = 0;
                newnode->v = 0;

                t->l = newnode;
            }

            t = t->l;
        }
        else
        {
            if( t->r == NULL )
            {
               node *newnode = new node;
               newnode->p = t;
               newnode->l = NULL;
               newnode->r = NULL;
               newnode->x = 1;
               newnode->v = 0;

               t->r = newnode;
            }

            t = t->r;
        }
        i++;
    }
    t->v++;
}

void del( )
{
    LL i, x;
    x = 21;
    i = 0;
    node *t = root;

    while( x-- )
    {
        if( ar[i] == 0 )
        {
            t = t->l;
        }
        else
        {
            t = t->r;
        }
        i++;
    }
    t->v--;

}

LL query( )
{
    LL i, x, j, y=0;
    x = 21;
    i = 0;
    node *t = root;

    while( x-- )
    {
        if( ar[i] == 0 && t->l != NULL )
            t = t->l;
        else if( ar[i] == 1 && t->r != NULL )
            t = t->r;
        else
            return 0;
        i++;
    }

    return t->v;



}
int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    node *newnode = new node;
    newnode->l = NULL;
    newnode->r = NULL;
    root = newnode;

    LL i, j, x, y, n, m, a, b, c, d;
    string str;
    char ch;
    cin >> n;

    for( i=0; i<n; i++ )
    {
        cin >> ch;
        cin >> str;
        memset( ar, 0, sizeof(ar) );
        y = str.size()-1;
        d = 20;
        while(  y >= 0 && d >= 0 )
        {
            x = str[y]-48;
            ar[d] = x%2;
            x /= 2;
            d--;
            y--;
        }

        if( ch == '+' )
            add();
        else if( ch == '-' )
            del();
        else
            cout << query() << endl;


    }

    return 0;

}
