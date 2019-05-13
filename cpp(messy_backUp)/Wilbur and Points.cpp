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
        if(arr_1[i]<arr_2[j])
        {
            arr[k]=arr_1[i];
            xtra[k]=xtra_1[i];
            xtra2[k]=xtra2_1[i];
            i++;
            k++;
        }
        else if(arr_1[i]==arr_2[j]&&xtra_1[i]<xtra_2[j])
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


int main()
{
    int n, i, j;

    cin >>n;


    int first[n+1], second[n+1], a, b=0, c, third[n+1], x=0, ans[2*n+2], use[100000+1]={0}, st, la, mi,l=0,y,z;

    for(i=0; i<n; i++)
    {
        cin >>a>>c;

        first[i] = a;//x1*a+c;

        second[i] = c;

        third[i]= c-a;//x2*a+c;



    }


    divide(third,first,second,0,n-1);

    for(i=0;i<n;i++)
        cout<<third[i]<<' '<<first[i]<<' '<<second[i]<<endl;

     vector<int> v(third,third+n);

    for(i=0;i<n;i++)
    {
        cin>>a;

        std::vector<int>::iterator low,up;
        low=std::lower_bound (v.begin(), v.end(), a);

        if(low-v.begin()==n)
           {
                x=1;
                break;
           }

         for(j=low-v.begin();j<n;j++)
         {
             if(use[j]==0&&x==third[j]&&l==0)
             {
                 ans[l]=first[i];
                 l++;
                 ans[l]=second[i];
                 l++;
                 use[j]++;
                 y=first[i];
                 z=second[i];
                 break;
             }
             else if(use[j]==0&&x==third[j]&&((first[j]>y&&second[j]<z)||(first[j]<y&&second[j]>z)))
             {

                 ans[l]=first[i];
                 l++;
                 ans[l]=second[i];
                 l++;
                 use[j]++;
                 y=first[i];
                 z=second[i];
                 break;


             }
             else if(use[j]==0&&x==third[j]&&first[j]>y&&second[j]>z)
             {

                 ans[l]=first[i];
                 l++;
                 ans[l]=second[i];
                 l++;
                 use[j]++;
                 y=first[i];
                 z=second[i];
                 break;


             }
             else if(x<third[j])
             {
                 x=1;
                 break;
             }
         }

         if(x==1)
            break;

    }


    for(i=0;i<l;i+=2)
        cout<<ans[i]<<' '<<ans[i+1]<<endl;

}








