#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

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


//set<int>::iterator ii;

struct node
{
    LL v, co;
    node *lft, *rig;
};

node *root = NULL;

void add( LL x , LL y )
{
    node *newnode = new node;
    newnode->lft = NULL;
    newnode->rig = NULL;
    newnode->v = x;
    newnode->co = y;

    if( root == NULL )
    {
        //cout << x << endl;
        root = newnode;
    }
    else if( root->v == x )
    {
        root->co += y;
        return;
    }

    else
    {
      node *t = root;

      while( true )
      {

          if( t->v == x )
          {
              t->co += y;
              return;
          }
          else if( t->v >= x )
          {
              if( t->lft == NULL )
              {
                  t->lft = newnode;
                  return;
              }
              else
                t = t->lft;
          }
          else
            {
              if( t->rig == NULL )
              {
                  t->rig = newnode;
                  return;
              }
              else
                t = t->rig;

            }

       }
   }
}
LL ret( LL x )
{
    if( root == NULL )
        return 0;
    else if( root->v == x )
    {
        return root->co;
    }

    else
    {
      node *t = root;

      while( t != NULL )
      {
          if( t->v == x )
          {
              return t->co;
          }
          else if( t->v >= x )
          {
              if( t->lft == NULL )
              {
                  return 0;
              }
              else
                t = t->lft;
          }
          else
            {
              if( t->rig == NULL )
              {
                  return 0;
              }
              else
                t = t->rig;

            }

       }
   }
}

int main()
{
    ios::sync_with_stdio(false);

    //inf;
    //outf;

    int i, j, x, y, n, m;


    add( 3, 4 );
    add( 4 , 4 );
    add( 3, 5 );
    cout << ret( 4 );


    return 0;

}


