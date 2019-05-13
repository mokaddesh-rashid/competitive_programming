#include<iostream>

using namespace std;

int main()
{
    int k;
    string str;

    cin>>k;
    cin>>str;

    int ch,a,b,c,d,num[28]={0},i,x=1111,ok=0;

    for(i=0;i<str.size();i++)
    {
        ch=str[i]-96;

        num[ch]++;
       // cout<<ch<<' ';

    }

    //cout<<endl;

    for(i=0;i<27;i++)
    {
        if(num[i]!=0)
            x=min(num[i],x);
    }


    for(i=0;i<27;i++)//k and x check kr
    {
        if(num[i]!=0&&num[i]%k!=0)
            ok=1;

    }




    if(ok==0)
    {
      int hmm=k;

      while(hmm>0)
      {

          if(num[1]>0)
          {
              a=0;


              while(num[1]/k>a)
              {
                  cout<<'a';
                  a++;
              }
          }
          if(num[2]!=0)
          {
              a=0;

              while(num[2]/k>a)
              {
                  cout<<'b';
                  a++;
              }
          }
          if(num[3]!=0)
          {
              a=0;

              while(num[3]/k>a)
              {
                  cout<<'c';
                  a++;
              }
          }
          if(num[4]!=0)
          {
              a=0;

              while(num[4]/k>a)
              {
                  cout<<'d';
                  a++;
              }
          }
          if(num[5]!=0)
          {
              a=0;

              while(num[5]/k>a)
              {
                  cout<<'e';
                  a++;
              }
          }
          if(num[6]!=0)
          {
              a=0;

              while(num[6]/k>a)
              {
                  cout<<'f';
                  a++;
              }
          }
          if(num[7]!=0)
          {
              a=0;

              while(num[7]/k>a)
              {
                  cout<<'g';
                  a++;
              }
          }
          if(num[8]!=0)
          {
              a=0;

              while(num[8]/k>a)
              {
                  cout<<'h';
                  a++;
              }
          }
          if(num[9]!=0)
          {
              a=0;

              while(num[9]/k>a)
              {
                  cout<<'i';
                  a++;
              }
          }
          if(num[10]!=0)
          {
              a=0;

              while(num[10]/k>a)
              {
                  cout<<'j';
                  a++;
              }
          }
          if(num[11]!=0)
          {
              a=0;

              while(num[11]/k>a)
              {
                  cout<<'k';
                  a++;
              }
          }
          if(num[12]!=0)
          {
              a=0;

              while(num[12]/k>a)
              {
                  cout<<'l';
                  a++;
              }
          }
          if(num[13]!=0)
          {
              a=0;

              while(num[13]/k>a)
              {
                  cout<<'m';
                  a++;
              }
          }
           if(num[14]!=0)
          {
              a=0;

              while(num[14]/k>a)
              {
                  cout<<'n';
                  a++;
              }
          }
           if(num[15]!=0)
          {
              a=0;

              while(num[15]/k>a)
              {
                  cout<<'o';
                  a++;
              }
          }
           if(num[16]!=0)
          {
              a=0;

              while(num[16]/k>a)
              {
                  cout<<'p';
                  a++;
              }
          }
           if(num[17]!=0)
          {
              a=0;

              while(num[17]/k>a)
              {
                  cout<<'q';
                  a++;
              }
          }
           if(num[18]!=0)
          {
              a=0;

              while(num[18]/k>a)
              {
                  cout<<'r';
                  a++;
              }
          }
           if(num[19]!=0)
          {
              a=0;

              while(num[19]/k>a)
              {
                  cout<<'s';
                  a++;
              }
          }
           if(num[20]!=0)
          {
              a=0;

              while(num[20]/k>a)
              {
                  cout<<'t';
                  a++;
              }
          }
           if(num[21]!=0)
          {
              a=0;

              while(num[21]/k>a)
              {
                  cout<<'u';
                  a++;
              }
          }
          if(num[22]!=0)
          {
              a=0;

              while(num[22]/k>a)
              {
                  cout<<'v';
                  a++;
              }
          }
          if(num[23]!=0)
          {
              a=0;

              while(num[23]/k>a)
              {
                  cout<<'w';
                  a++;
              }
          }
          if(num[24]!=0)
          {
              a=0;

              while(num[24]/k>a)
              {
                  cout<<'x';
                  a++;
              }
          }
          if(num[25]!=0)
          {
              a=0;

              while(num[25]/k>a)
              {
                  cout<<'y';
                  a++;
              }
          }
          if(num[26]!=0)
          {
              a=0;

              while(num[26]/k>a)
              {
                  cout<<'z';
                  a++;
              }
          }
          hmm--;

      }
    }

    else
        cout<<-1;






}
