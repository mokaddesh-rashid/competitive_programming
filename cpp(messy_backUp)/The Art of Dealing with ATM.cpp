#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<set>
#include <utility>

using namespace std;

#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          prlong long f
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-1000000000000000000
#define mx          (long long) 1000000000000000000


//set<long long >::iterator ii;

void merge_it(long long  arr[], long long  xtra[], long long  start, long long  mid, long long  endd)
{
    long long  n1, n2;

    n1 = mid - start +1;
    n2 = endd - mid;

    long long  arr_1[n1+1], arr_2[n2+1], xtra_1[n1+1], xtra_2[n2+1], i, j, k, maxx;

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


long long  divide( long long  arr[], long long  xtra[], long long  start, long long  endd)
{
    long long  mid=(start+endd)/2;

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

    //inf;
    //outf;

    long long i, j, x = 0, y, n, m, z=0, k, c, a, b, d;

    cin >> n >> k;//>> m ;

    long long arr[22*n+1], tim[22*n+1];

    for(i=0; i<n; i++)
        {
            cin >> a;

            b = a;
            c = 1;
            while( c <= k )
            {
                arr[x] = b;
                tim[x] = c;
                x++;
                c++;
                b += a;
            }
        }

  divide( arr, tim, 0, x-1);

   cin >> m;

   while( m-- )
   {
       long long ans = mx;
       cin >> a;

       for( i=0; i<x; i++)
       {
           b = a - arr[i];

           c = lower_bound( arr, arr+x, b) - arr;

           if( b == 0 )
           {
              d = tim[i];
              ans = min( ans, d);
           }
           else if( arr[c] == b )
           {
              d = tim[i]+tim[c];
              ans = min( ans, d);
           }
       }

       if( ans > k )
        cout << -1;
       else
        cout << ans;

       cout << endl;
   }

    return 0;

}


