#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

void merge_it(long long int arr[], long long int xtra[], long long int start, long long int mid, long long int endd)
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

}


long long int divide( long long int arr[], long long int xtra[], long long int start, long long int endd)
{
    long long int mid=(start+endd)/2;

    if(start<endd)
    {
        divide(arr,xtra,start,mid);
        divide(arr,xtra,mid+1,endd);

        merge_it(arr,xtra,start,mid,endd);
    }
}

long long int lower( long long int arr[], long long int st, long long int en, long long int val)
{
    long long int mid;

    while( st <= en )
    {
        mid = ( st + en ) / 2;

        if( arr[mid] == val )
            en = mid - 1 ;

        else if( arr[mid] > val )
            en = mid - 1 ;

        else if( arr[mid] < val )
            st = mid + 1 ;
    }

    return st;
}

long long int upper( long long int arr[], long long int st, long long int en, long long int val)
{
    long long int mid;

    while( st <= en )
    {
        mid = ( st + en ) / 2;

        if( arr[mid] == val )
            st = mid + 1 ;

        else if( arr[mid] > val )
            en = mid - 1 ;

        else if( arr[mid] < val )
            st = mid + 1 ;
    }

    return st;
}



int main()
{
    //ios::sync_with_stdio(false);
    long long int n, i, j,  y;

    scanf( "%I64d" ,&n);//n;


    long long int first[n+1], second[n+1], a, b=0, c = 0, x=0, arr[n+1], brr[n+1], z, zz, d = 0;

    for(i=0; i<n; i++)
    {
        scanf( "%I64d %I64d" ,&arr[i], &brr[i]);
       //cin >> arr[i] >> brr[i];

       first[i] = arr[i];
       second[i] = brr[i];
    }


    divide(first,second,0,n-1);

    sort( arr, arr+n);
    sort( brr, brr+n);


    //cout << endl << endl;

    for( i=0; i<n ; i++)
    {
        a = first[i];
        b = second[i];
        //cout << a << ' ' << b << endl;
        x = lower( arr, 0, n-1, a);
        y = upper( arr, 0, n-1, a);
        //cout << x << ' ' << y << endl;
        z = lower( second, x, y-1, b);
        zz =  upper( second, x, y-1, b);
        //cout << z << ' ' << zz << endl;
        c = y -x - 1;
        z = zz - z - 1;
        c -= z;
        x = lower( brr, 0, n-1, b);
        y = upper( brr, 0, n-1, b);
        //cout << x << ' ' << y << endl ;
        c += (y - x - 1);
        //cout << c  << endl << endl ;
        d += c;

     //cout << x << ' ' << y << endl << endl;
    }

    printf("%I64d\n", d/2);// << endl;

}
