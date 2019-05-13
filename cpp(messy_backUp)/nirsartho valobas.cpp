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

    while( i < n1 && j < n2 )
    {
        if( arr_1[i] > arr_2[j] )
        {
            arr[k]=arr_1[i];
            xtra[k]=xtra_1[i];
            xtra2[k]=xtra2_1[i];
            i++;
            k++;
        }
        else if( arr_1[i] == arr_2[j] && xtra_1[i] > xtra_2[j])
        {
            arr[k]=arr_1[i];
            xtra[k]=xtra_1[i];
            xtra2[k]=xtra2_1[i];
            i++;
            k++;
        }
        else if( arr_1[i] == arr_2[j] && xtra_1[i] == xtra_2[j] && xtra2_1[i] < xtra2_2[j] )
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


int main()
{

    int t;

    cin >> t;

    while( t-- )
    {
        int n, i, j;

    cin >>n;

    int arr[111], brr[111];

    int ff[111], ss[111], a, b=0, c, th[111];

    for(i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    for(i=0; i<n; i++)
    {
        cin >> brr[i];
    }

    for(i=0; i<n; i++)
    {
        ff[i] = arr[i] * brr[i];
        ss[i] = brr[i];
        th[i] = i+1;
    }


    divide(ff,ss,th,0,n-1);

    cout << th[0] << endl;


    }


}










