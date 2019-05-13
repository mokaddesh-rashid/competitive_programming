#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int n,l,r,x;

    cin>>n>>l>>r>>x;

    long long int i, k, t, arr[n+1],a=0,b=0,c,ans=0,d;

    for(i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);

   // 4 elements

    t = pow(2, n);

    for(i = 1; i < t; i++) // start from 1
    {
        a=0;
        b=0;
        c=0;
        d=0;

        for(k = 0; k < n; k++)
        {
            if(i & (1 << k))
               {
                 // cout<<arr[]
                  if(a==0)
                    a=arr[k];
                  b=arr[k];
                  c+=arr[k];
               }

        }
        if(c>=l&&c<=r&&a+x<=b)
            ans++;

       // cout << "\n";
    }

    cout<<ans;

    return 0;
}
