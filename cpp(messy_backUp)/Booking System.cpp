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
        if(arr_1[i]>arr_2[j])
        {
            arr[k]=arr_1[i];
            xtra[k]=xtra_1[i];
            xtra2[k]=xtra2_1[i];
            i++;
            k++;
        }
        else if(arr_1[i]==arr_2[j]&&xtra_1[i]>xtra_2[j])
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

void merge_it2(int arr[], int xtra[], int start, int mid, int endd)
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


int divide2( int arr[], int xtra[], int start, int endd)
{
    int mid=(start+endd)/2;

    if(start<endd)
    {
        divide2(arr,xtra,start,mid);
        divide2(arr,xtra,mid+1,endd);

        merge_it2(arr,xtra,start,mid,endd);
    }
}



int main()
{
    int n, i, j;

    cin >>n;


    int f[n+1], s[n+1], a, b=0, c, t[n+1];

    for(i=0; i<n; i++)
    {
        cin >>a>>c;

        f[i] = a;//x1*a+c;

        s[i] = c;

        t[i]= i+1;//x2*a+c;



    }

    int ans[2*n+2], x = 0, y = 0 ;
    int m;
    cin >> m;

    int bal[m+1], arr[1111] ={0}, add[m+1];

    for( i=0; i<m; i++)
        {
            cin >> bal[i];
            add[i] = i+1;
        }

    divide2(bal,add,0,m-1);
    divide(s,f,t,0,n-1);

    //for(i=0;i<n;i++)
        //cout <<f[i]<<' '<<s[i] << ' ' <<t[i]<<endl;


   for( i=0; i<n; i++)
   {
       a =f[i];

       for( j=0; j<m; j++)
       {
           if( arr[j] == 0 && bal[j] >= a )
           {
               a = bal[j];
               y += s[i];
               arr[j]++;
               ans[x] = t[i];
               x++;
               ans[x] = add[j];//+1;
               x++;
               break;
           }
       }
   }
   cout << x/2 << ' ' << y << endl;
   for( i=0; i<x; i+=2)
    cout << ans[i] << ' ' << ans[i+1] << endl;





}










