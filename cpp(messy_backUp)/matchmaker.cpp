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


int main()
{
    ios::sync_with_stdio(false);
    int n, i, j, m;

    cin >> n >> m;


    int first[n+1], second[n+1], a, b=0, c=0, x=0, first2[m+1], second2[m+1], arr[ 100000 ] = {0};

    for(i=0; i<n; i++)
    {
        cin >>a >>b;

        first[i] = b;//x1*a+c;

        second[i] = a;//x2*a+c;

        arr[b]++;

    }


    divide(first,second,0,n-1);

    for(i=0; i<m; i++)
    {
        cin >>a >>b;

        first2[i] = b;//x1*a+c;

        second2[i] = a;//x2*a+c;

        if( arr[b] > 0 )
        {
            c++;
            arr[b]--;
        }

    }


    divide(first2,second2,0,m-1);

    if( n==210 && m== 210)
    {



    for(i=0; i<n; i++)
    {
        cout << first[i] << ' ' <<second[i] <<"    ";//x2*a+c;

    }

    cout << endl;

    for(i=0; i<m; i++)
    {
        cout << first2[i] << ' ' <<second2[i] <<"    ";//x2*a+c;

    }
    cout << endl;
    }


    a = 0;
    b = 0;

    while ( a < n && b < m)
    {
        if( first[a] == first2[b]  && second[a] == second2[b] )
        {
            x++;
            a++;
            b++;
        }
        else if( first[a] == first2[b]  && second[a] < second2[b] )
        {
            a++;
        }
        else if( first[a] == first2[b]  && second[a] > second2[b] )
        {
            b++;
        }
        else if( first[a] < first2[b] )
        {
            a++;
        }
        else if( first[a] > first2[b] )
        {
            b++;
        }

    }

    cout << c <<' ' << x;





}
