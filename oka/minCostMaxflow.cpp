#include <stdio.h>
#include <bits/stdtr1c++.h>

#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl
#define ran(a, b) ((((rand() << 15) ^ rand()) % ((b) - (a) + 1)) + (a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define valid(nx,ny)  ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m))

using namespace std;

/// Min-cost Max-flow using SPFA (Shortest Path Faster Algorithm)
/// 0 Based indexed for directed weighted graphs (for undirected graphs, just add two directed edges)

namespace mcmf
{
    const int maxNode=80*80+7,maxEdge=maxNode*10,INF=INT_MAX/3;
    int L[maxNode],pre[maxEdge],to[maxEdge],C[maxEdge],numEdge=0,cost[maxEdge];

    inline void initGraph()
    {
        memset(L,-1,sizeof(L));
        numEdge=0;
    }

    inline void add(int u,int v,int c=1,int w=0)
    {
        to[numEdge]=v;
        pre[numEdge]=L[u];
        C[numEdge]=c;
        cost[numEdge]=w;
        L[u]=numEdge++;
    }

    inline void addEdge(int u,int v,int c=1,int w=0)
    {
        add(u,v,c,w);
        add(v,u,0,-w);
    }

    int D[maxNode],F[maxNode],mother[maxNode],path[maxNode];

    int djk(int s,int t)
    {
        priority_queue<pair<int,int> > Q;
        memset(F,0,sizeof(F));
        for(int i=0;i<maxNode;i++)D[i]=INF;

        F[s]=INF;D[s]=0;
        Q.push(make_pair(-D[s],s));

        while(!Q.empty())
        {
            int u=Q.top().second;
            int w=-Q.top().first;
            Q.pop();
            if(w>D[u])continue;
            if(u==t)break;
            for(int e=L[u];e!=-1;e=pre[e])
            {
                int v=to[e];
                if(C[e]>0 && D[v]>D[u]+cost[e])
                {
                    D[v]=D[u]+cost[e];
                    path[v]=e;
                    mother[v]=u;
                    F[v]=min(F[u],C[e]);
                    Q.push(make_pair(-D[v],v));
                }
            }
        }
        return F[t];
    }

    int nextFlow(int s,int t,int &_cost)
    {
        int f=djk(s,t);
        if(f==0)return 0;
        _cost=D[t];
        int g=t;
        while(g!=s)
        {
            C[path[g]]-=f;
            C[path[g]^1]+=f;
            g=mother[g];
        }
        return f;
    }

    int minCostFlow(int s,int t,int &_cost)
    {
        _cost=0;
        int f,flow=0,c;
        while((f=nextFlow(s,t,c))!=0)
        {
            flow=flow+f;
            _cost=_cost+c*f;
        }
        return flow;
    }

    void drawGraph(int n)
    {
        FOR(i,0,n)
        {
            cerr<<i;
            for(int e=L[i];e!=-1;e=pre[e])
            {
                cerr<<"->"<<to[e]<<","<<C[e]<<","<<cost[e];
            }
            cerr<<endl;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    //inf;

    src = pp++; des = pp++;
    mcmf::initGraph();
    mcmf::minCostFlow(src, des, prin);
    cout << prin << endl;
}



