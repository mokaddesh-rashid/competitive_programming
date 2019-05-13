#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int merge_it(long long int arr[],long long int xtra[],long long int start,long long int mid,long long int endd)
{
   long long int n1, n2;

    n1 = mid - start +1;
    n2 = endd - mid;

   long long int arr_1[n1+1], arr_2[n2+1], xtra_1[n1+1], xtra_2[n2+1], i, j, k, maxx;

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

  return 0;

}


int divide(long long int arr[],long long int xtra[],long long int start,long long int endd)
{
   long long int mid=(start+endd)/2;

    if(start<endd)
    {
        divide(arr,xtra,start,mid);
        divide(arr,xtra,mid+1,endd);

        merge_it(arr,xtra,start,mid,endd);
    }

    return 0;
}


int main()
{
   ios::sync_with_stdio(false);
   long long int n, i, j;

    cin >>n;


   long long int first[n+1], second[n+1], a, b=0, c, x=0, ff[n+1], ss[n+1], arr[ 2*n+2];

    for(i=0; i<n; i++)
    {
        cin >> a;

        first[i] = a;//x1*a+c;

        second[i] = i+1;//x2*a+c;



    }


    divide(first,second,0,n-1);

    for(i=0; i<n; i++, x)
    {
        if( first[i] == first[i+1])
        {
            ff[x] = second[i];
            ss[x] = second[i+1];
            x++;
        }

    }

    if( x == 0 )
      cout << -1;

    else
    {
        a = 0;
        b = -1;
        c = 0;
        divide(ff,ss,0,x-1);

        for( i= x-1; i >= 0; i--)
        {
            //cout << ff[i] <<' '<< ss[i]<<endl;
            if( b == -1 )
            {
                arr[a] = n;
                a++;
                arr[a] = ff[i];
                a++;
                b = ff[i];
                c++;
            }
            else if ( ss[i] < b )
            {
                arr[a] = b-1;
                a++;
                arr[a] = ff[i];
                a++;
                b = ff[i];
                c++;
            }
        }

        arr[a-1] = 1;

        cout << c <<endl;

        for( i= a-1; i>=0; i -= 2)
        {
            cout << arr[i] <<' '<<arr[i-1]<<endl;
        }

    }

    return 0;







}




//7

//9999999999999 9999999999999 3333333333333333 44444444444444 4444444444444444 9999999999999 3333333333333333

