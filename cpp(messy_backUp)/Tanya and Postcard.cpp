#include<iostream>
#include<string>

using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);
    string s,t;

    cin>>s;


    long long int arr[200]={0},ooh[200]={0},i,a,b,c,d,w=0,y=0;

    for(i=0;i<s.size();i++)
    {
        arr[s[i]]++;
    }

    cin>>t;

     for(i=0;i<t.size();i++)
    {
       if(arr[t[i]]>0)
       {

          y++;
          arr[t[i]]--;


       }
       else  if(ooh[t[i]]>0)
       {

          y++;
          w--;
          ooh[t[i]]--;


       }
       else  if(arr[t[i]+32]>0)
       {
           w++;
           ooh[t[i]+32]++;
           arr[t[i]+32]--;
       }
       else  if(arr[t[i]-32]>0)
       {
           w++;
           ooh[t[i]-32]++;
           arr[t[i]-32]--;
       }
    }

    cout<<y<<' '<<w;
}
