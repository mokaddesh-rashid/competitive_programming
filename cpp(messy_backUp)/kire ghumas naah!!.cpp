#include<iostream>

using namespace std;


int main()
{
    long long int n,m,k,i,j,a,b,c;


    cin>>n>>m>>k;

    a=max(n,m);
    b=min(n,m);




    if(a-1+b-1<k)
        cout<<-1;
    else if(k+1<=a)
    {
        k++;
        cout<<max(b*(a/k),a*(b/k));
    }

    else
    {
        k=k-(a-1);
         k++;
        //cout<<k<<endl;

        cout<<b/k;
    }


}
