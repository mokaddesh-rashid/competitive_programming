#include<iostream>
#include<string>

using namespace std;

int main()
{
   int k;

   cin>>k;

   string str;

   int i,n,j,x,arr[111]={0},maxx=0;

   for(i=0;i<4;i++)
   {
       cin>>str;

       for(j=0;j<str.size();j++)
       {
           char ch=str[j];
           x=ch-48;

          if(x>=0&&x<=9)
             arr[x]++;
       }
   }

   for(i=0;i<14;i++)
   {
       maxx=max(maxx,arr[i]);
   }

   if(maxx<=2*k)
      cout<<"YES";
   else
      cout<<"NO";
}
