#include<iostream>
#include<string>


using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
   string str,comm;

   cin>>str;

   int x=0,i,j,a=0,b=0,position,arr[11111],brr[1111],y=0;

    position = str.find("metal");


    while(position != string::npos)
     {
        arr[x]=position;
        x++;
		position = str.find("metal",position+1);
     }

    position = str.find("heavy");


    while(position != string::npos)
     {
        brr[y]=position;
        y++;
		position = str.find("heavy",position+1);
     }

     for(i=0;i<y;i++)
     {
         for(j=x-1;j>=0;j--)
         {
             if(brr[i]<arr[j])
                a++;
             else
                break;
         }
     }

     cout<<a;




}
