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
#define valid(nx,ny)  ((nx >= 0) && (nx < 3) && (ny >= 0) && (ny < 3))
typedef pair<int,int> pr;


string str[4];
int chk(char ch)
{
    FOR(i,0,2)
        FOR(j,0,2)
        {
           if(str[i][j]!=ch)break;
           if(j==2)return  1;
        }
    FOR(i,0,2)
        FOR(j,0,2)
        {
           if(str[j][i]!=ch)break;
           if(j==2)return  1;
        }
    if(str[0][0]==ch&&str[1][1]==ch&&str[2][2]==ch)return 1;
    if(str[2][0]==ch&&str[1][1]==ch&&str[0][2]==ch)return 1;

    return 0;

}

void prin()
{
    FOR(i,0,2)
    {
        FOR(j,0,2)
        {
            cout<<str[i][j]<<' ';
        }
        cout<<NL;
    }
}

int Move(int v)
{
    if(chk('O'))return 2;
    if(chk('X'))return 0;
    if(v==9)return 1;

    int temp;
    if(v%2==0)
    {
        temp=2;
        FOR(i,0,2)
        {
            FOR(j,0,2)
            {
                if(str[i][j]=='_')
                {
                    str[i][j]='X';
                    temp=min(temp,Move(v+1));
                    str[i][j]='_';
                }
            }
        }
    }
    else
    {
        temp=0;
        FOR(i,0,2)
        {
            FOR(j,0,2)
            {
                if(str[i][j]=='_')
                {
                    str[i][j]='O';
                    temp=max(temp,Move(v+1));
                    str[i][j]='_';
                }
            }
        }
    }
    return temp;
}
int play(int t)
{
    prin();
    if(t==9)return 0;
    if(chk('X'))return 1;
    if(chk('O'))return 2;

    int x,y;

    if(t%2==0)
    {
        cout<<"player 1: "<<NL;
        cin>>x>>y;

        if(str[x][y]=='_'&&valid(x,y))
        {
            str[x][y]='X';
            return play(t+1);
        }
        else return play(t);
    }
    else
    {
        cout<<"player Computer: "<<NL;;
        int v=Move(t);
        FOR(i,0,2)
        {
            FOR(j,0,2)
            {
                if(str[i][j]=='_')
                {
                    str[i][j]='O';
                    if(Move(t+1)==v)return play(t+1);
                    str[i][j]='_';
                }
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

    while(true)
    {
        str[0]=str[1]=str[2]="___";
        n=play(0);
        if(n==1)cout<<"Player wins"<<NL;
        else if(n==0)cout<<"Draw"<<NL;
        else cout<<"Computer wins"<<NL;
    }
    return 0;
}


