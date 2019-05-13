#include<iostream>
#include<ctime>

using namespace std;

int arr[100000], n;

void bubble( int arr[] )
{
    bool chk=false;
    for(int i=0;i<n-1;i++)
    {
        chk=0;
        for(int j=0;j<n-1;j++)
        {
          if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                chk=true;
            }
        }

        if(chk==false) break;
    }
    return;
}

int main()
{
    int i, j;

    cin >> n ;
    for( i=0; i<n; i++ ) cin >>arr[i];
    bubble(arr);
    for( i=0; i<n; i++ ) cout<<arr[i]<<' ';
    return 0;

}





