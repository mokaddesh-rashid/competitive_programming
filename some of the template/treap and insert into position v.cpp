#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define read        freopen("in.txt", "r", stdin)
#define write       freopen("out.txt", "w", stdout)

typedef long long int64;

const int MAX = (1e5) + 10;

struct Node
{
    int key, prio, val, sum, idx;
    Node *l, *r;

    Node(int k,int p,int i)
    {
        key = k; prio = p; sum = val = 1; idx = i;
        l = r = NULL;
    }
};

void update(Node *X)
{
    if(X == NULL) return;

    X->sum = X->val;
    if(X->l != NULL) X->sum += X->l->sum;
    if(X->r != NULL) X->sum += X->r->sum;

    return;
}

Node* leftRotate(Node *up,Node *down)
{
    up->l = down->r; down->r = up;
    update(down); update(up);
    return down;
}

Node* rightRotate(Node *up,Node *down)
{
    up->r = down->l; down->l = up;
    update(down); update(up);
    return down;
}

Node* balance(Node *R)
{
    if(R->l != NULL && R->l->prio < R->prio) return leftRotate(R, R->l);
    else if(R->r != NULL && R->r->prio < R->prio) return rightRotate(R, R->r);
    return R;
}

///key should same for all the nodes
Node* add(Node* R,Node *org,int pos)///insert into position pos(0 based index)
{
    if(R == NULL) return org;

    int val = 0;
    if(R->l != NULL) val = R->l->sum;

    if(val >= pos) R->l = add(R->l, org, pos, fuka);
    else R->r = add(R->r, org, (pos - val - 1), fuka);

    R = balance(R);
    update(R);
    return R;
}

int main()
{
    ios::sync_with_stdio(false);
   // read;
    int tc;

    cin >> tc;
    FOR(tt,1,tc)
    {
    }
    return 0;
}


