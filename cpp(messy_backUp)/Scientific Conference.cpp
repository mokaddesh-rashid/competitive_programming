#include<bits/stdc++.h>
using namespace std;
struct ti
{
    int f,s;
}t[100010];
bool cmp(ti a,ti b)
{
    if(a.f<=b.f)return true;
    else return false;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        t[i].f=b;
        t[i].s=a;
    }
    sort(t,t+n,cmp);
    //for(int i=0;i<n;i++)cout<<t[i].f<<' '<<t[i].s<<endl;
    int cftime=t[0].f,cstime=t[0].s,cnt=1;
    for(int i=1;i<n;i++)
    {
       if(i<100001&&cftime<t[i].s)
       {
           cnt++;
           cftime=t[i].f;
       }
    }
    printf("%d\n",cnt);
    return 0;
}
