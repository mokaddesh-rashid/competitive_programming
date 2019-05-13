#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("dataset11.txt", "r", stdin)
#define outf        freopen("myoutput11.txt", "w", stdout)
#define PB push_back



const int MAX = 1010, MAXO = MAX * MAX;

map<string,int> stu_name_map, clg_name_map;

int getStudentId(string name)
{
    if(stu_name_map[name] == 0) stu_name_map[name] = stu_name_map.size();
    return stu_name_map[name] - 1;
}
int getCollegeId(string name)
{
    if(clg_name_map[name] == 0) clg_name_map[name] = clg_name_map.size();
    return clg_name_map[name] - 1;
}

struct Student
{
    string student_name;
    int student_rank;
    vector<int> student_quota, student_choice; /// ki  ki quota amr jonno applicable and ami kon kon college choice korechi inder of preference
}student_info[MAX];

struct College
{
    string college_name;
    int merit_student, quota_student;
    vector<int> size_of_each_quota; // ith quota r koto jon nibo
    vector<int> quota_student_list, merit_student_list;
}college_info[MAX];

///dinic part
int node, edge;
int src, des;
vector<int> adjl[MAX];
vector<int> rc[MAX];
vector<int> rev_idx[MAX];

void add_edge(int u,int v,int w)
{
    ///cout << "add " << u << ' ' << v << ' ' << w << endl;
    adjl[u].PB(v);
    adjl[v].PB(u);
    rc[u].PB(w);
    rc[v].PB(0);
    rev_idx[u].PB( adjl[v].size() - 1 );
    rev_idx[v].PB( adjl[u].size() - 1 );
}

void init_flow()
{
    FOR(i, 0, node + 1)
    {
        adjl[i].clear();
        rc[i].clear();
        rev_idx[i].clear();
    }
}
int lev[MAX];
int vis[MAX];
bool dinic_bfs()  { //this finds level of all nodes from source
    mem(vis, 0);
    mem(lev, 0);
    lev[src] = 0;
    vis[src] = 1;
    queue<int> myq;
    myq.push(src);
    while(!myq.empty()) {
        int u = myq.front();
        myq.pop();
        int sz = adjl[u].size();
        FOR(i, 0, sz - 1)   {
            int v = adjl[u][i];
            if(rc[u][i] == 0)   {
                continue;
            }
            if(vis[v] == 0) {
                vis[v] = 1;
                lev[v] = lev[u] + 1;
                myq.push(v);
            }
        }
    }
    if(vis[des])    {
        return 1;
    }
    return 0;
}

int shuru[MAX];
int dinic_dfs(int u, int flow) {

    if(u == des)    {
        return flow;
    }
    FOR(i, shuru[u], (int)adjl[u].size() - 1)   {
        shuru[u] = i;
        int v = adjl[u][i];
        if((lev[v] == lev[u] + 1) && (rc[u][i]))    {
            int ff = dinic_dfs(v, min(flow, rc[u][i]));
            if(ff) {
                rc[u][i] -= ff;
                rc[v][ rev_idx[u][i] ] += ff;

                return ff;
            }
        }
    }
    shuru[u] = adjl[u].size();
    return 0;
}

int dinic()
{
    int ans = 0;
    while(dinic_bfs()) {
        mem(shuru, 0);
        while(1)  {
            int ff = dinic_dfs(src, MAXO);
            //cout << "\n";
            if(ff == 0)break;
            ans += ff;
        }
    }

    return ans;
}

/// dinic part
int n, m, q, sortId[MAX]; ///No. of student N, no. of quota, Q and no. of colleges M.

bool dhukao(int cid,int sid)
{
    college_info[cid].quota_student_list.push_back( sid ); /// age dhukai ditesi pore check korbo valid naki

    init_flow();
    src = 0; des = 1;

    int exQ = 2, exS = 2 + q + 1;
    for(auto x : college_info[cid].quota_student_list)
    {
        add_edge(src, exS, 1); /// source theke student r connection
        for(auto quota : student_info[x].student_quota) /// x student r kon kon quota ase
        {
            int qq = quota + exQ;
            add_edge(exS, qq, 1); /// student theke quota r connection
        }
        exS++; ///creating next student node id
    }

    for(auto x : college_info[cid].size_of_each_quota)
    {
        add_edge(exQ, des, x);
        exQ++; ///creating next quota node id
    }

    node = exS;
    if(dinic() == college_info[cid].quota_student_list.size()) return 1;
    else
    {
        college_info[cid].quota_student_list.pop_back( );
        return 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;
    string name;
    int rnk, id, can, capacity;

    cin >> n >> q >> m;
    FOR(i,0,n-1)
    {
        cin >> name >> rnk;

        id = getStudentId( name );
        student_info[id].student_name = name;
        student_info[id].student_rank = rnk;
    }
    FOR(i,0,n-1)
    {
        cin >> name;

        id = getStudentId( name );
        FOR(oo,0,q-1)
        {
            cin >> can;
            if(can) student_info[id].student_quota.push_back( oo ); /// pushing oo th quota to student with ID
        }
    }

    FOR(i,0,m-1)
    {
        cin >> name >> capacity;

        id = getCollegeId( name );
        college_info[id].college_name = name;
        college_info[id].merit_student = capacity; /// initially sobai merit student
    }

    FOR(i,0,m-1)
    {
        cin >> name;

        id = getCollegeId( name );
        FOR(oo,0,q-1)
        {
            cin >> capacity;
            college_info[id].size_of_each_quota.push_back( capacity );
            college_info[id].merit_student -= capacity; /// merit student komtese
            college_info[id].quota_student += capacity; /// quota student bartese
        }
    }

    int num_of_choice, college_id;
    string college_name;

    FOR(oke,0,n-1)
    {
        cin >> name;

        id = getStudentId( name );

        cin >> num_of_choice;
        FOR(i,0,num_of_choice - 1)
        {
            cin >> college_name;

            college_id = getCollegeId( college_name );
            student_info[id].student_choice.push_back( college_id );
        }
    }

    FOR(i,0,n-1) sortId[i] = i;
    sort(sortId, sortId + n, [](int x,int y)
         {
                return student_info[x].student_rank < student_info[y].student_rank;
         });

    FOR(i,0,n-1)
    {
        id = sortId[i];
        for(auto cid : student_info[id].student_choice)
        {
            if(dhukao(cid, id)) break;
            else if(college_info[cid].merit_student_list.size() < college_info[cid].merit_student)
            {
                college_info[cid].merit_student_list.push_back( id );
                break;
            }
        }
    }

    FOR(i,0,m-1)
    {
        int extra = college_info[i].quota_student - college_info[i].quota_student_list.size();
        college_info[i].merit_student += extra;
        college_info[i].quota_student_list.clear();
        college_info[i].merit_student_list.clear();
    }

    FOR(i,0,n-1)
    {
        id = sortId[i];
        for(auto cid : student_info[id].student_choice)
        {
            if(dhukao(cid, id)) break;
            else if(college_info[cid].merit_student_list.size() < college_info[cid].merit_student)
            {
                college_info[cid].merit_student_list.push_back( id );
                break;
            }
        }
    }

    FOR(i,0,m-1)
    {
        cout << college_info[i].college_name << " = ";
        for(auto x : college_info[i].merit_student_list) cout << student_info[x].student_name << ", ";
        for(auto x : college_info[i].quota_student_list) cout << student_info[x].student_name << ", ";
        cout << endl;
    }
    return 0;
}
