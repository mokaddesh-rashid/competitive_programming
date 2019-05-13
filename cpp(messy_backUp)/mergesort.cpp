#include <bits/stdc++.h>

using namespace std;

#define mem(a,b) memset(a,b,sizeof(a))
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define REV(i,j,k) for(int i=j;i>=k;i--)
#define FORR(i,j,k,l) for(int i=j;i<=k;i+=l)
#define inf         freopen("in.txt", "r", stdin)
#define outf        freopen("out.txt", "w", stdout)
#define pf          printf
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c)    scanf("%d %d %d", &a, &b, &c)
#define minn          (long long)-1000000000000000000
#define maxx          (long long) 1000000000000000000
#define mod          1000000007
#define M_PI           3.14159265358979323846  /* pi */
#define LL           long long
#define NL '\n'
#define cnd tree[idx]
#define lnd (idx<<1)
#define rnd ((idx<<1)+1)
#define PB push_back
#define F first
#define S second
#define MAX 100010
#define sz 100010
#define MK make_pair
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
typedef pair<int,int> pr;

int ar[sz];

void merge_it(int arr[],int st,int mid, int en)
{
    int n,n2;

    n=(mid-st)+1;
    n2=en-mid;

    int f_half[n+1],s_half[n2+1],i,j,k;

    for(i=0;i<n;i++) f_half[i]=arr[st+i];
    for(i=0;i<n2;i++) s_half[i]=arr[mid+1+i];

    i=j=0;
    k=st;
    while(i<n&&j<n2)
    {
        if(f_half[i]>s_half[j]) arr[k]=f_half[i],i++,k++;
        else arr[k]=s_half[j],j++,k++;

    }
    while(i<n)
    {
        arr[k]=f_half[i];
        i++; k++;
    }

     while(j<n2)
    {
        arr[k]=s_half[j];
        j++; k++;
    }

}

void divide(int arr[], int st, int en)
{
    int mid;

    if(st<en)
    {
        mid = ( st + en )/2;
        divide(arr,st,mid);
        divide(arr,mid+1,en);

        merge_it(arr,st,mid,en);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //inf;
    //outf;

    int n,i,j,a,b,c,x,y,z;

    cin>>n;
    FOR(i,0,n-1) cin>>ar[i];

    divide(ar,0,n-1);
}
