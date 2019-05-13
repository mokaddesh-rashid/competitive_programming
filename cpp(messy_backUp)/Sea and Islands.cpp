#include<iostream>


using namespace std;

int main()
{
    int n,k;

    cin>>n>>k;

    int arr[n+2][n+2],i,j,a,b,c,x=0;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
          arr[i][j]=0;



      for(i=0;i<n;i++)
        for(j=0;j<n;j++)
          {
              if(x>=k)
                break;

              else if(i%2==0&&j%2==0)
                {
                    arr[i][j]=1;
                        x++;
                }

              if(x>=k)
                 break;
              else if(i%2==1&&j%2==1)
                {
                    arr[i][j]=1;
                        x++;
                }

          }



   if(x<k)
    cout<<"NO";

  else
  {
      cout<<"YES\n";
      for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
              {
                  if(arr[i][j]==1)
                    cout<<'L';
                  else
                    cout<<'S';
              }

            cout<<endl;
        }
  }


}

