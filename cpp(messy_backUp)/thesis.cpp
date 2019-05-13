#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)

const int MAX = 110;

map<string,int> stu_name_map, clg_name_map;

int getStudentId(string name)
{
    if(stu_name_map[name] == 0) stu_name_map[name] = stu_name_map.size();
    return stu_name_map[name];
}
int getCollegeId(string name)
{
    if(clg_name_map[name] == 0) clg_name_map[name] = clg_name_map.size();
    return clg_name_map[name];
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
    int total_student, enrolled_student_number;
    vector<int> quota_student_number; // ith quota r koto jon nibo
    vector<int> student_list;
}college_info[MAX];

int n, m, q; ///No. of student N, no. of quota, Q and no. of colleges M.

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;
    string name;
    int rnk, id, can, capacity;

    cin >> n >> q >> m;
    FOR(i,0,n-1)
    {
        cin >> name >> rnk

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
        college_info[id].total_student = capacity;
    }

    FOR(i,0,m-1)
    {
        cin >> name;

        id = getCollegeId( name );
        FOR(oo,0,q-1)
        {
            cin >> capacity;
            college_info[id].quota_student_number.push_back( capacity );
        }
    }

    return 0;
}
