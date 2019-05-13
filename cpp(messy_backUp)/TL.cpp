#include<iostream>

using namespace std;

int main()
{
    int n,m;

    cin>>n>>m;

    int right[n+1],wrong[m+1],minn,maxx,i,a=0,x,minn_w=1111;

    for(i=0;i<n;i++)
    {
        cin>>right[i];

        if(i==0)
        {
            minn=right[i];
            maxx=right[i];
        }

        else
        {
            maxx=max(right[i],maxx);
            minn=min(right[i],minn);
        }
    }

      for(i=0;i<m;i++)
      {
          cin>>wrong[i];

          minn_w=min(wrong[i],minn_w);

          if(wrong[i]<=maxx)
              a=1;
      }
    //  cout<<minn_w<<endl;

      if(a==0&&minn*2<=maxx)
        cout<<maxx;
      else if(a==0&&minn*2<minn_w)
        cout<<minn*2;
      else
        cout<<-1;
}
