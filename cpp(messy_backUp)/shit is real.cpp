#include<bits/stdc++.h>
using namespace std;
int TEST,CASE=1;
#define pf printf
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define clr(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define eb emplace_back
#define MAX 1000100
#define all(x) x.begin(),x.end()
#define mod7 1000000007
typedef long long int ll;
int arr[200100]={0};
int n,a,b,c;
string s;
int mx[1002][1002]={0};
int dp2[1002][1002]={0};
int dp5[1002][1002]={0};
bool check(int i,int j){
        if(i>n || j>n)return false;
        else return true;
}
int cnt2(int value){
        int ret=0;
        while(value>0){
                if(value%2==0)ret++;
                else break;
                value/=2;
        }
        return ret;
}
int cnt5(int value){
        int ret=0;
        while(value>0){
                if(value%5==0)ret++;
                else break;
                value/=5;
        }
        return ret;
}
int f2(int i,int j){
        if(i>n || j>n)return dp2[i][j]=999999;
        if(i==n && j==n){
                return cnt2(mx[i][j]);
        }
        if(dp2[i][j]!=-1)return dp2[i][j];
        int ret=999999;
        int cnt=cnt2(mx[i][j]);
        if(check(i+1,j))ret=min(ret,f2(i+1,j)+cnt);
        if(check(i,j+1))ret=min(ret,f2(i,j+1)+cnt);
        return dp2[i][j]=ret;
}
int f5(int i,int j){
        if(i>n || j>n)return dp5[i][j]=999999;
        if(i==n && j==n){
                return cnt5(mx[i][j]);
        }
        if(dp5[i][j]!=-1)return dp5[i][j];
        int ret=999999;
        int cnt=cnt5(mx[i][j]);
        if(check(i+1,j))ret=min(ret,f5(i+1,j)+cnt);
        if(check(i,j+1))ret=min(ret,f5(i,j+1)+cnt);
        return dp5[i][j]=ret;
}
void g2(int i,int j)
{
        if(i==n && j==n)return;
        ///cout << i << ' ' << j << endl;
        if(f2(i+1, j) <= f2(i, j + 1) && check(i + 1, j))
        {
                cout << "D";///pf("D");
                g2(i+1,j);
        }else
        {
                 cout << "R";///pf("R");
                g2(i,j+1);
        }
}
void g5(int i,int j){
        if(i==n && j==n)return;///cout << i << ' ' << j << endl;
        if(dp5[i+1][j] <= dp5[i][j+1] && check(i+1,j))
        {
                 cout << "D";///pf("D");
                g5(i+1,j);
        }else
        {
                 cout << "R";///pf("R");
                g5(i,j+1);
        }
}

int main(void)
{
        ios_base::sync_with_stdio(false);
        //cin.tie(0);
        //cout<<fixed<<setprecision(10);
        cin >> n;///si(n);
        for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                        cin >> mx[i][j];
        clr(dp2,-1);
        clr(dp5,-1);
        int tow=f2(1,1);
        int five=f5(1,1);
        if(tow<=five){
                cout<<tow<<endl;
                g2(1,1);
        }else{
                cout<<five<<endl;
                g5(1,1);
        }
        return 0;
}
