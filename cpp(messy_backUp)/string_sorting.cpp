#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

void merge_it(string arr[],   int start, int mid, int endd)
{
    int n1, n2;

    n1 = mid - start +1;
    n2 = endd - mid;

    string arr_1[n1+1], arr_2[n2+1];
    int i, j, k, maxx;

    maxx = max( n1, n2);

    for( i=0; i < maxx; i++)
    {
        if( n1 > i)
        {
            arr_1[i] = arr[start+i];
        }

        if(n2 > i)
        {
            arr_2[i] = arr[mid+1+i];
        }
    }

    i=0;
    j=0;
    k=start;

    while(i<n1&&j<n2)
    {

            int a, b, c, d = 0, al, sl;

            a = arr_1[i].size();
            b = arr_2[j].size();
            c = max( a, b );

            for( int x=0; x<c; x++ )
            {

                if( arr_1[i][x%a] < arr_2[j][x%b] )
                {
                    d = 1;
                    break;
                }
                else if( arr_1[i][x%a] > arr_2[j][x%b] )
                {
                    d = 2;
                    break;
                }

            }

        if( d == 0 )
        {
            if( arr_1[i]+arr_2[j] < arr_2[j]+arr_1[i] )
            {
               arr[k]=arr_1[i];
               i++;
               k++;
            }

            else
            {
                arr[k]=arr_2[j];
                j++;
                k++;
            }
        }


        else
        {

             if( d == 1)
        {
            arr[k]=arr_1[i];
            i++;
            k++;
        }

        else
        {
            arr[k]=arr_2[j];
            j++;
            k++;
        }


        }

    }




    while(i<n1)
    {
            arr[k]=arr_1[i];
            i++;
            k++;
    }

     while(j<n2)
     {
            arr[k]=arr_2[j];
            j++;
            k++;
     }

}


int divide( string arr[],   int start, int endd)
{
    int mid=(start+endd)/2;

    if(start<endd)
    {
        divide(arr,start,mid);
        divide(arr,mid+1,endd);

        merge_it(arr,start,mid,endd);
    }
}


int main()
{
    ios::sync_with_stdio(false);

   // while( true )
   // {
        int n, i, j;

    cin >>n;


    string first[n+1];

    int second[n+1], a, b=0, c, x=0, ff[n+1], ss[n+1];

    for(i=0; i<n; i++)
    {
        cin >> first[i];

    }


    divide(first,0,n-1);

    for(i=0; i<n; i++)
    {
        cout << first[i];


    }

   // cout << endl;
    //}








}


