#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

void merge_it( long long int  arr[],  long long int  xtra[],  long long int  start,  long long int  mid,  long long int  endd)
{
     long long int  n1, n2;

    n1 = mid - start +1;
    n2 = endd - mid;

     long long int  arr_1[n1+1], arr_2[n2+1], xtra_1[n1+1], xtra_2[n2+1], i, j, k, maxx;

    maxx = max( n1, n2);

    for( i=0; i < maxx; i++)
    {
        if( n1 > i)
        {
            arr_1[i] = arr[start+i];
            xtra_1[i] = xtra[start+i];
        }

        if(n2 > i)
        {
            arr_2[i] = arr[mid+1+i];
            xtra_2[i] = xtra[mid+1+i];
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
            i++;
            k++;
        }
        else if(arr_1[i]==arr_2[j]&&xtra_1[i]<xtra_2[j])
        {
            arr[k]=arr_1[i];
            xtra[k]=xtra_1[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=arr_2[j];
            xtra[k]=xtra_2[j];
            j++;
            k++;
        }
    }

    while(i<n1)
    {
            arr[k]=arr_1[i];
            xtra[k]=xtra_1[i];
            i++;
            k++;
    }

  while(j<n2)
  {
            arr[k]=arr_2[j];
            xtra[k]=xtra_2[j];
            j++;
            k++;
  }

}


 long long int  divide(  long long int  arr[],  long long int  xtra[],  long long int  start,  long long int  endd)
{
     long long int  mid=(start+endd)/2;

    if(start<endd)
    {
        divide(arr,xtra,start,mid);
        divide(arr,xtra,mid+1,endd);

        merge_it(arr,xtra,start,mid,endd);
    }
}


int main()
{
    ios::sync_with_stdio(false);
     long long int  n, i, j, k;

    cin >> n >> k;


     long long int  first[n+1], second[n+1], a, b=0, c, x=0, ff[n+1], ss[n+1], arr[n+1], maxx=0, y;

    for(i=0; i<n; i++)
    {
        cin >> a >> b ;

        first[i] = a;//x1*a+c;

        second[i] = b;//x2*a+c;



    }




    divide(first,second,0,n-1);

     a = 0;
      //cout << endl;
     for( i=0; i<n; i++)
     {
         //cout << first[i] << ' ' <<second[i] <<endl;
         a += second[i];
         arr[i] = a;
     }

    // cout << endl;
     arr[n] = arr[n-1];

    vector< long long int > v(first,first+n);
    vector< long long int >::iterator low,up;


   for( i=0; i<n ; i++ )
   {
       y = first[i] + k;

       up = upper_bound (v.begin(), v.end(), y-1);//upper_bound ( arr, arr+n, y-arr);
       x = up - v.begin();
       //cout << x-1 <<' ' << i-1 << endl;

       if( i == 0 )
        maxx = arr[x-1];
       else
        maxx = max( maxx, arr[x-1] - arr[i-1]);
   }


   cout << maxx << endl;









}
