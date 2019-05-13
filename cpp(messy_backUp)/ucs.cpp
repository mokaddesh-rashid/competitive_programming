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
#define MAX 100010
#define SZ 100010
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))

map<int,int>mopa;
map<string,int>value;
vector<int>mat[30],cost[30];

void hurestic()
{
    mopa[value["Arad"]]=0;
    mopa[value["Zerind"]]=0;
    mopa[value["Oradea"]]=0;
    mopa[value["Sibiu"]]=0;
    mopa[value["Fagaras"]]=0;
    mopa[value["Rimnicu Vilcea"]]=0;
    mopa[value["Pitesti"]]=0;
    mopa[value["Timisoara"]]=0;
    mopa[value["Lugoj"]]=0;
    mopa[value["Mehadia"]]=0;
    mopa[value["Drobeta"]]=0;
    mopa[value["Craiova"]]=0;
    mopa[value["Bucharest"]]=0;
    mopa[value["Giurgiu"]]=0;
}

void id()
{
    int cnt=0;
    value["Arad"]=++cnt;
    value["Zerind"]=++cnt;
    value["Oradea"]=++cnt;
    value["Sibiu"]=++cnt;
    value["Fagaras"]=++cnt;
    value["Rimnicu Vilcea"]=++cnt;
    value["Pitesti"]=++cnt;
    value["Timisoara"]=++cnt;
    value["Lugoj"]=++cnt;
    value["Mehadia"]=++cnt;
    value["Drobeta"]=++cnt;
    value["Craiova"]=++cnt;
    value["Bucharest"]=++cnt;
    value["Giurgiu"]=++cnt;
}

void add_connection(string X,string Y,int v)
{
    int a=value[X], b=value[Y], c=v;
    mat[a].PB(b); cost[a].PB(c);
    mat[b].PB(a); cost[b].PB(c);
}

void connection()
{
    add_connection("Oradea","Sibiu",151);
    add_connection("Arad","Zerind",75);
    add_connection("Arad","Sibiu",140);
    add_connection("Arad","Timisoara",118);
    add_connection("Zerind","Oradea",71);
    add_connection("Rimnicu Vilcea","Sibiu",80);
    add_connection("Fagaras","Sibiu",99);
    add_connection("Rimnicu Vilcea","Pitesti",97);
    add_connection("Rimnicu Vilcea","Craiova",146);
    add_connection("Fagaras","Bucharest",211);
    add_connection("Pitesti","Bucharest",101);
    add_connection("Pitesti","Craiova",138);
    add_connection("Drobeta","Craiova",120);
    add_connection("Mehadia","Drobeta",75);
    add_connection("Lugoj","Mehadia",70);
    add_connection("Timisoara","Lugoj",111);

}


struct node
{
    int first,second,v;
} ;

class Compare
{
public:
    bool operator()(node x,node y)
    {
        return x.S>y.S;
    }
};

node MP(int x,int y,int z)
{
    node ret;
    ret.F=x; ret.S=y; ret.v=z;
    return ret;
}

int vis[40],lev[40];
priority_queue<node,vector<node>,Compare>que;

void bfs(string start,string destination)
{
    que.push(MP(value[start],mopa[value[start]],0));
    lev[value[start]]=0;

    while(!que.empty())
    {
        node vv=que.top();

        int p=vv.F;
        vis[p]=1; lev[p]=vv.v;
        que.pop();

        if(p==value[destination])return;

        FOR(i,0,(int)mat[p].size()-1)
        {
            int x=mat[p][i];
            if(vis[x]==0)
                que.push(MP(x,lev[p]+cost[p][i]+mopa[x],lev[p]+cost[p][i]));
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m;
    id(); hurestic();
    connection();

    FOR(i,0,22)lev[i]=10000000;
    bfs("Arad","Bucharest");

    int v=value["Bucharest"];
    cout<<lev[v]<<NL;
    return 0;
}



