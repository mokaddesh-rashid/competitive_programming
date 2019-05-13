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
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

map<int,int>mopa;
map<string,int>value;
vector<int>mat[30],cost[30];

void id()///assigning an id to identify each city staring from id 1
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

void add_connection(string X,string Y,int v)///add edge between city X and Y
{
    int a=value[X], b=value[Y], c=v;///a is id of city X & b is id of city Y and c is edge size
    mat[a].PB(b); cost[a].PB(c);
    mat[b].PB(a); cost[b].PB(c);
}

void connection()///adding edges between cities
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


int vis[40],lev[40];
queue<int>que;

void bfs(string start,string destination)
{
    que.push(value[start]);

    while(!que.empty())
    {
        int p=que.front();  que.pop();
        vis[p]=1;
        if(p==value[destination])return;

        FOR(i,0,(int)mat[p].size()-1)
        {
            int x=mat[p][i];
            if(vis[x]==0)
            {
                vis[x]=1; lev[x]=lev[p]+cost[p][i];
                que.push(x);
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    int i,j,n,m;
    id(); connection();

    bfs("Arad","Bucharest");

    int v=value["Bucharest"];
    cout<<lev[v]<<NL;
    return 0;
}


