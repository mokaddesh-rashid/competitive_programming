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
    x = 32;
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
    x = 32;
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

    if( t->v == 0 )
    {
        while( root != t )
        {
            if( t->p->r == NULL && t->x == 0 )
            {
                t = t->p;
                t->l = NULL;
                t->r = NULL;
            }
            else if( t->p->l == NULL && t->x == 1 )
            {
                t = t->p;
                t->l = NULL;
                t->r = NULL;
            }
            else if( t->x == 0 )
            {
                t = t->p;
                t->l = NULL;
                break;
            }
            else if( t->x == 1 )
            {
                t = t->p;
                t->r = NULL;
                break;
            }

        }
    }
}

LL query( )
{
    LL i, x, j, y=0;
    x = 32;
    i = 0;
    j = 2147483648;
    node *t = root;

    while( x-- )
    {
        if( ar[i] == 0 && t->r != NULL )
        {
           // cout << 'k';
            y += j;
            t = t->r;
        }
        else if( ar[i] == 1 && t->l != NULL )
        {
           // cout << 'p';
            y += j;
            t = t->l;
        }
        else if( t->r != NULL)
        {
            //cout << 'r';
            t = t->r;
        }
        else if( t->l != NULL)
        {
            //cout << 'l';
            t = t->l;
        }

        i++;
        //cout << j << endl;
        j /= 2;
    }

    return y;



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
    double ck, wt;
    char ch;
    cin >> n;
    //x  = pow( 2, 31 );
    //cout << x << endl;
    add();
    for( i=0; i<n; i++ )
    {
        cin >> ch >> x;
        memset( ar, 0, sizeof(ar) );
        y = x;
        d = 31;
        while( x > 0 )
        {
          // cout << d << ''
            ar[d] = x%2;
            x /= 2;
            d--;
        }

        if( ch == '+' )
            add();
        else if( ch == '-' )
            del();
        else
            cout << max( query(), y ) << endl;


    }

    return 0;

}
