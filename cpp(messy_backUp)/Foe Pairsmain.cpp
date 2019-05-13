#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

void merge_it(int arr[], int xtra[], int start, int mid, int endd)
{
    int n1, n2;

    n1 = mid - start +1;
    n2 = endd - mid;

    int arr_1[n1+1], arr_2[n2+1], xtra_1[n1+1], xtra_2[n2+1], i, j, k, maxx;

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
        else if(arr_1[i]==arr_2[j]&&xtra_1[i] == xtra_2[j])
        {
            arr[k]=arr_1[i];
            xtra[k]=0;
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


int divide( int arr[], int xtra[], int start, int endd)
{
    int mid=(start+endd)/2;

    if(start<endd)
    {
        divide(arr,xtra,start,mid);
        divide(arr,xtra,mid+1,endd);

        merge_it(arr,xtra,start,mid,endd);
    }
}

int lower( int arr[], int st, int en, int val)
{
    int mid;

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

int upper( int arr[], int st, int en, int val)
{
    int mid;

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
    ios::sync_with_stdio(false);
    int n, i, j, m;

    cin >> n >> m ;

    int arr[n+1], can[n+1];

    memset(can, 0, sizeof(can));

    for( i=0; i<n; i++)
        cin >> arr[i];


    int ff[m+1], ss[m+1], a, b=0, c, x=0;

    for(i=0; i<m; i++)
    {
        cin >> a >> b ;

        ff[x] = a;

        ss[x] = b;
        x++;
        ff[x] = b;
        ss[x] = a;
        x++;//x2*a+c;



    }


    divide(ff,ss,0,x-1);
   cout << endl;
    for( i=0; i<x; i++)
       cout << ff[i] << ' ' << ss[i] << endl;
   cout << endl;
    i = 0;
    j = 0;
    int france = 0, k, low, up;
    while( i < n )
    {
        cout << endl << i << ' ' << j << endl;
        if( can[arr[j]] == 0 && j < n )
        {

            low = lower( ff, 0, x-1, arr[j] );
            up  = upper( ff, 0, x-1, arr[j] );
            j++;
            cout << arr[j-1] << ' ' << low << ' ' << up << " = = ";
            for( k=low; k<up; k++)
            {
                cout << ss[k] << ' ';
                can[ss[k]]++;
            }
            cout << endl;
        }
        else
        {
            low = lower( ff, 0, x-1, arr[i] );
            up  = upper( ff, 0, x-1, arr[i] );
            france = france + ( j - i );
            i++;
            cout << arr[i-1] << ' ' << low << ' ' << up << " = " << endl;
            for( k=low; k<up; k++)
            {
                if( can[ss[k]] != 0 )
                      can[ss[k]]--;
            }
        }
    }

    cout << france;









}
