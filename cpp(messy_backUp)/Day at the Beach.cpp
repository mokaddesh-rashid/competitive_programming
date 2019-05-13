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
            xtra[k]=xtra_2[j];
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
    int n, i, j, t=0;

    cin >>n;


    int value[n+1], pos[n+1], a, b=0, c, arr[n+1];

    for(i=0; i<n; i++)
    {
        cin >>a;

        arr[i] = a;
        value[i] = a;//x1*a+c;

        pos[i] = i;//x2*a+c;



    }


    divide(value,pos,0,n-1);

    for(i=0;i<n;i++)
        cout << value[i] <<' '<< pos[i]<<endl;



    i=0;

    while( i<n )
    {
         //cout << value[i]<<' '<<i<<endl;
       int  x = 0;

       for( j=i; j<pos[i]; j++)
       {
           if(arr[j]==value[i])
            x++;

           else
            break;
       }
      // cout << x<< endl;
       //cout << pos[i] <<endl;
       t+=(x+1);

       i=pos[i];



       i++;

    }

    cout << t;



}
