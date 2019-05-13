#include<iostream>
#include<string>

using namespace std;

int main ()
{
    int arr[11],hmm[11],area[11],maxx=-1,a=0,b,c,d,x=0,i,pos=-1;
    string str="ABC";

    for(i=0;i<3;i++)
    {
        cin>>arr[i]>>hmm[i];
        area[i]=arr[i]*hmm[i];
        maxx=max(arr[i],maxx);
        maxx=max(hmm[i],maxx);
        x+=area[i];

    }
    for(i=0;i<3;i++)
    {
        if(area[i]>a)
        {
            pos=i;
            a=area[i];
        }
    }
    cout<<endl;

    swap(arr[pos],arr[0]);
    swap(hmm[pos],hmm[0]);
    swap(str[pos],str[0]);
    a=-1;

    for(i=1;i<3;i++)
    {
        if(area[i]>a)
        {
            pos=i;
            a=area[i];
        }
    }
    cout<<endl;

    swap(arr[pos],arr[1]);
    swap(hmm[pos],hmm[1]);
    swap(str[pos],str[1]);

    cout<<str<<endl;

    if(x!=maxx*maxx)
        cout<<-1;

    for(i=0;i<maxx;i++)
    {
       for(int j=0;j<maxx;j++)
       {
           if(i<arr[0]&&j<hmm[0])
            cout<<str[0];

           else if(i-arr[0]<arr[1]||j-hmm[0]<hmm[1])
             cout<<str[1];
           else
            cout<<str[2];

       }

       cout<<endl;
    }


}
