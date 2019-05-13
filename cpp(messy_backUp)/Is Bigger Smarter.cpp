#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;


void merge_it(int arr[], int xtra[],int xtra2[], int start, int mid, int endd)
{
    int n1, n2;

    n1 = mid - start +1;
    n2 = endd - mid;

    int arr_1[n1+1], arr_2[n2+1], xtra_1[n1+1], xtra_2[n2+1], xtra2_1[n1+1], xtra2_2[n2+1], i, j, k, maxx;

    maxx = max( n1, n2);

    for( i=0; i < maxx; i++)
    {
        if( n1 > i)
        {
            arr_1[i] = arr[start+i];
            xtra_1[i] = xtra[start+i];
            xtra2_1[i] = xtra2[start+i];
        }

        if(n2 > i)
        {
            arr_2[i] = arr[mid+1+i];
            xtra_2[i] = xtra[mid+1+i];
            xtra2_2[i] = xtra2[mid+1+i];
        }
    }

    i=0;
    j=0;
    k=start;

    while(i<n1&&j<n2)
    {
        if(arr_1[i]<arr_2[j])
        {
            arr[k]=arr_1[i];
            xtra[k]=xtra_1[i];
            xtra2[k]=xtra2_1[i];
            i++;
            k++;
        }
        else if(arr_1[i]==arr_2[j]&&xtra_1[i]<xtra_2[j])
        {
            arr[k]=arr_1[i];
            xtra[k]=xtra_1[i];
            xtra2[k]=xtra2_1[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=arr_2[j];
            xtra[k]=xtra_2[j];
            xtra2[k]=xtra2_2[j];
            j++;
            k++;
        }
    }

    while(i<n1)
    {
            arr[k]=arr_1[i];
            xtra[k]=xtra_1[i];
            xtra2[k]=xtra2_1[i];
            i++;
            k++;
    }

  while(j<n2)
  {
            arr[k]=arr_2[j];
            xtra[k]=xtra_2[j];
            xtra2[k]=xtra2_2[j];
            j++;
            k++;
  }

}



int divide( int arr[], int xtra[], int xtra2[], int start, int endd)
{
    int mid=(start+endd)/2;

    if(start<endd)
    {
        divide(arr,xtra,xtra2,start,mid);
        divide(arr,xtra,xtra2,mid+1,endd);

        merge_it(arr,xtra,xtra2,start,mid,endd);
    }
}

int dp[1000+1][1000+10], dparr[1000+5], n, m=0, third[1100];

int rec( int x, int y , int z )
{
    if( x == n )
        return 0;
    if( dp[x][y] != -1 )
        return dp[x][y];

    else
    {
        if( dparr[x] < y  || z == -1 )
            {
                dp[x][y] = 1 + rec( x+1, dparr[x], dparr[x] );
                //m++;

            }

        dp[x][y] = max( dp[x][y] , rec( x+1, y, z ));

        return dp[x][y];
    }
}

void prin( int x, int y, int z )
{
    if( x == n )
        return ;

    else
    {
        if( ( dparr[x] < y  || z == -1 )  && 1 + rec( x+1, dparr[x], dparr[x] ) > rec(x+1, y, z) )
            {
                 cout << third[x] << ' ';
                 prin( x+1, dparr[x], dparr[x] );

            }

       else
            prin(x+1, y, z);

        return ;
    }
}


int main()
{
    int  i, j;

    cin >>n;

     memset( dp, -1, sizeof(dp));
    int first[n+1], second[n+1], a, b=0, c;

    for(i=0; i<n; i++)
    {
        cin >>a>>c;

        first[i] = a;//x1*a+c;

        dparr[i] = c;

        third[i]= i+1;//x2*a+c;



    }


    divide(first,dparr,third,0,n-1);

    //for(i=0;i<n;i++)
       // cout<<' '<<first[i]<<' '<<dparr[i] << ' ' <<third[i]<<endl;
    cout << rec( 0 , 0, -1) <<endl;

    prin( 0, 0, -1);

    cout << endl;




}









