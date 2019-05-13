#include<iostream>
#include<string>
#include<sstream>
//#include<string.h>

using namespace std;

    //int x=4;
   char t='\n';

int main()
{

  string nm,n;
  int a,b;
  getline(cin,nm);
  stringstream(nm)>>a;
  a=1+a%2;

  cout<<"hello "<<a;


  return 0;
}


