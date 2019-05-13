#include<iostream>


using namespace std;

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
    long long int n;
    cin>>n;

    long long int maxx=0,a,b,x,i,arr[n+1],y,c;


    for(i=0;i<n;i++)
    {
        cin>>arr[i];


      if(i>0)
      {
          if(i==1)
          {
              x=arr[i];
              y=arr[i-1];
          }
          else
            y=arr[i];

          while(true)
          {
              if(y%x==0)
                break;
              else
              {
                  c=x;
                  x=y%x;
                  y=c;
              }
          }
      }
    }
    if(n==1)
        cout<<arr[0]<<endl;
    else
        cout<<x*n<<endl;
    }

}
