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
#define MAX 200010
#define MP make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

struct node
{
    double ar[23];

}info[MAX];

int att;
class Compare
{
public:
    bool operator()(node x,node y)
    {
        if(x.ar[21] == y.ar[21]) return x.ar[att] < y.ar[att];
        return x.ar[21] < y.ar[21];
    }
};

string dudes[] = {"ID", "Reason_for_absence", "Month_of_absence", "Day_of_the_week", "Seasons",
    "Transportation_expense", "Distance_from_Residence_to_Work", "Service_time", "Age",
    "Work_load_Average", "Hit_target", "Disciplinary_failure", "Education", "Son", "Social_drinker",
    "Social_smoker", "Pet", "Weight", "Height", "Body_mass_index", "Absenteeism_time_in_hours",
    "cluster"};
int n;
double avg[MAX], coco[MAX];
string str;

void seperate(int cur)
{
    int sz = str.size(), p = 0, val = 0, lel = 1, ok = 0;

    FOR(i,0,sz-1)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            int voo = str[i] - '0';
            val = val * 10 + voo;
            if(ok) lel *= 10;
        }
        if(str[i] == '.')
        {
            ok = 1;
        }
        if(str[i] == ',' || i == sz - 1)
        {
            info[cur].ar[p] = (double) val/lel;
            avg[p] += info[cur].ar[p];
            coco[p] += 1;

            lel = 1;
            ok = val = 0;
            p++;
        }
    }
}

int cnt[MAX];

int main()
{
    ios::sync_with_stdio(false);
    inf;
    outf;

    n = 740;
    FOR(i,0,n-1)
    {
        cin >> str;
        seperate( i );
    }

    FOR(i,0,n-1)
    {
        FOR(j,0,21)
        {
            if(j == 9)
            {
                double dd = info[i].ar[j] * (378884 - 205917) + 205917;
                int dodo = (int)dd;
                info[i].ar[j] = dodo;
            }
//            else cout << info[i].ar[j];
//            if(j != 21) cout << ',';
//            else cout << endl;
        }
        int po = (int)info[i].ar[21];
        cnt[ po ]++;
    }

    int toto = 0, clus = 1, loola = 17;
    int cocacola[1000];
    mem(cocacola, 0);

    FOR(clus,1, 10)
    {
        FOR(ok,loola,loola)
        {


            att = ok; toto = 0;
            double koko = 0;
            sort(info, info + n, Compare());

            cout << dudes[ok] << endl;
            FOR(i,0,n-1)
            {

                if((info[i].ar[att] != info[i + 1].ar[att] || info[i].ar[21] != info[i + 1].ar[21] )&& (int)info[i].ar[21] == clus)
                {
                    int popo = 0;
                    FOR(j,0,n-1)
                    {
                        if(info[i].ar[att] == info[j].ar[att] && (int)info[i].ar[21] == clus && (int)info[j].ar[21] == clus) popo++, toto++;
                    }
                    cout << info[i].ar[att] << '(' << popo << ')' << ", ";
                    cocacola[(int)info[i].ar[att]] += popo;

                    double lol = info[i].ar[att] * popo;
                    koko += lol;
                }

            }
            cout << endl << "Total " << toto << ' ' << koko / toto << endl << endl;
        }
    }
    FOR(i,0,1000-1) if(cocacola[i]) cout << i << ' ' << cocacola[i] << endl;


    return 0;
}

