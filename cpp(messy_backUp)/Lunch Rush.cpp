#include<iostream>

using namespace std;

int main()
{
    int n,k;

    cin>>n>>k;

    int i,x,a,b,c,d,f,t,fun_arr[n+1],time_arr[n+1],max_fun;

    for(i=0;i<n;i++)
    {
        cin>>f>>t;

        if(t>k)
        {
            a=f-(t-k);
        }
        else
        {
            a=f;
        }

        if(i==0)
        {
           max_fun=a;
        }
        else
        {
            max_fun=max(max_fun,a);
        }
    }
    cout<<max_fun;


}
