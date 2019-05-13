
#include<iostream>

using namespace std;

int main()
{
    int arr[111],a,y=1,i,x,b,c,start=0,end0=13,mid,d=0;


    for(i=0;i<=13;i++)
    {
        if(i<3)
        {
        arr[i]=y;
        y+=2;
        }
        else if(i>8)
        {
        arr[i]=y;
        y+=2;
        }

        else
            arr[i]=y;
    }

    for(i=0;i<=13;i++)
    {
       cout<<arr[i]<<' ';
    }

    cout<<endl;


    cin >> a;

     c=arr[start];
     b=arr[end0];

   while(start+1<end0)
   {
       mid=(end0+start)/2;
      // mid/=2;

       if(arr[mid]>=a)
       {
          end0=mid;
       }
       else if(arr[mid]<a)
       {
           start=mid;
       }
       x=arr[start];
       y=arr[end0];


   }



   cout<<start;//1st and last input count krta pare naaah


}
