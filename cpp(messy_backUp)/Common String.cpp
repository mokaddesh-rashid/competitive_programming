#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    int i,n,a,b,c,len=0,x,time,y;
    string str1,str2,check;

    cin>>time;
   for(y=0;y<time;y++)
   {
        cin>>str1>>str2;

    for(i=0;i<str1.size();i++)
    {
        for(n=i;n<str1.size();n++)
        {
                  int pos=0;
                   check.assign(str1,i,n+1);
                   //cout<<check<<endl;
                   pos=str2.find(check);


                   for(x=0;x<str2.size();x++)
                   {
                       int k;
                       string check2;
                       check2.assign(str2,x,check.size());
                       if(check2==check)
                            k=check.size();
                        len=max(k,len);
                   }



        }
    }
     cout<<"Case"<<' '<<y+1<<':'<<' '<<len<<endl;


   }
}
