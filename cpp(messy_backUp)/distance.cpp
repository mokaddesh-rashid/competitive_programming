#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    long long int i,x,y,x1,y1,a,b,c,r,ans,re;
    double check;

    cin>>r>>x>>y>>x1>>y1;

    r*=2;

    ans=(x-x1)*(x-x1)+(y-y1)*(y-y1);
    check=sqrt(ans);
    re=check;
    if(double(re)!=check)
        re++;

     ans=re/r;
     if(re%r!=0)
          ans++;



  // if(check==ans)
      cout<<ans;

  //else
   // cout<<ans++;




}
