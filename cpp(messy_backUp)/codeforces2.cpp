#include<iostream>

using namespace std;

int main()
{
int n,m,i,c,d,e,f,g=0,h=0;
cin>>n>>m;
int a[n*m],b[m*n]; // edited
for(i=0;i<n;i++)
a[i]=0;
for(i=0;i<m;i++)
b[i]=0;
cin>>c;
for(i=0;i<c;i++)
{
cin>>d;
a[d]=1;
}
cin>>c;
for(i=0;i<c;i++)
{
cin>>d;
b[d]=1; // edited
}
for(int o=0;o<n*m;o++)
for(i=0;i<n*m;i++)
{
e=i%n;
f=i%m;
if(a[e]==1||b[f]==1)
{
a[e]=1;
b[f]=1;
}
}
for(i=0;i<n;i++)
{
  if(a[i]==0)
  g=1;
}
for(i=0;i<m;i++)
{
  if(b[i]==0)
  h=1;
}
if(g==0&&h==0)cout<<"yes";
else if(g==1||h==1)
cout<<"no";

return 0;



}
