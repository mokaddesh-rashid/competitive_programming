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

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(i=j;i<=k;i++)
#define REV(i,j,k) for(i=j;i>=k;i--)
#define inf         freopen("in.txt", "r", stdin);
#define outf        freopen("out.txt", "w", stdout);
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define mn          (long long)-9223372036854775807
#define mx          (long long) 9223372036854775807
#define mod          1000000009
#define LL           long long
#define NL '\n


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

    int t, ca = 1;

    cin >> t;

    while( t-- )
    {
        int n, i, j, m;

    cin >> n >> m;
    n *= 2;


    int ff[n+1], ss[n+1], a, b=0, c, x=0, arr[n+1], y;

    for(i=0; i<n; i++)
    {
        cin >> a;

        ff[i] = a;//x1*a+c;

        if( i % 2 == 0 )
            ss[i] = 1;//x2*a+c;
        else
            {
                ss[i] = -1;
                ff[i]++;
            }
    }


    divide(ff,ss,0,n-1);

    cout << "Case " << ca++ <<':' << endl;
    for( i=0; i<m; i++ )
    {
        cin >> a;

        y = upper_bound( ff, ff+n, a ) - ff;

        if( ff[y] != a )
            y--;

        if( y < 0 || y == n )
        {
            cout << 0;
        }
        else
            cout << arr[y] << endl;
    }
    }




}
