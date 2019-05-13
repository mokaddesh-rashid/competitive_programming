#include<iostream>
#include <algorithm>
#include <vector>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);

   unsigned int i,j,a,b,c;

   string str;

   cin>>str;

   if(str.size()>1)
   a=str[str.size()-1]-48+10*(str[str.size()-1]-48);

   else
   a=str[str.size()-1]-48;


   a%=4;

   b=pow(1,a)+pow(2,a)+pow(3,a)+pow(4,a);

   cout<<b%5;




}

