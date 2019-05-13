#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

void merge_it(double arr[], double xtra[], int start, int mid, int endd)
{
    int n1, n2;

    n1 = mid - start +1;
    n2 = endd - mid;

    double arr_1[n1+1], arr_2[n2+1], xtra_1[n1+1], xtra_2[n2+1];

    int i, j, k, maxx;

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


int divide( double arr[], double xtra[], int start, int endd)
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
    int n, i, j, t;

    cin >>n >>t;


    double first[n+1],second[n+1], l, m, d;

    long long int a, b=0, c, x, y, z;

    for(i=0; i<n; i++)
    {
        cin >> a >> c >> b;

        a *= a;
        c *= c;

        d = a + c;

        d = sqrt(d);

       // cout << d<<endl;

       first[i] = d;
       second[i] = b;



    }


    divide(first,second,0,n-1);

     i=0;
     while( t < 1000000 && i < n)
     {
        t += second[i];
        i++;
     }

     if(i==0)
        cout << 0;
     else if(t < 1000000)
        cout << -1;
     else
        printf("%.7lf",first[i-1]);




}
