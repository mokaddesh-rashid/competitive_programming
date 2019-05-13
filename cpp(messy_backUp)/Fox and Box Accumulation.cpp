#include<iostream>
#include<algorithm>


using namespace std;

int main()
{
    int n;

    cin>>n;

    int arr[n+1],use[111]={0},i,x=0,y=0,a,b,c,hmm[101]={0},j,k;

    for(i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

    while(y<n)
    {
        for(i=0;i<n;i++)
        {
            if(use[i]==0)
            {
              a=0;
              for(j=i;j<n;j++)
              {
                  if(arr[j]>=a&&use[j]==0)
                  {
                      use[j]=1;
                      a++;
                      y++;
                  }
              }
              x++;
            }
        }
    }

    cout<<x;


}
