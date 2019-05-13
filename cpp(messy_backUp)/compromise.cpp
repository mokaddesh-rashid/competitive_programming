

#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>



using namespace std;


string str[100+1] ,ss[100+1];
int n,m,dp[5+1000][5+1000], t=0;


int rec(int x, int y)
{


    if( x == n )
    return 0;
    if (y == m)
    return 0;
    if( dp[x][y] != -1 )
       return dp[x][y];
    if( str[x] == ss[y] )
        {
            dp[x][y] = 1 + rec( x+1,y+1) ;
            return dp[x][y];
        }

    else
    {

          dp[x][y] = max( rec(x,y+1), rec(x+1,y) );
          return dp[x][y];

    }
}

void prin(int x, int y)
{
    if( x == n )
    return ;
    if (y == m)
    return ;
    if( str[x] == ss[y] )
    {
        cout << str[x];
        rec( x+1,y+1) ;
    }
    else
    {
        if( dp[x][y+1] > dp[x+1][y] )
            rec( x, y+1);
        else
            rec( x+1,y);
    }
}
string ans;
void printLCS(int i,int j)
{
    if(str[i]=="#" or ss[j]=="#"){
        return;
    }
    if(str[i]==ss[j]){
           if( t == 1 )
                cout <<' '<<str[i];
           else
                cout << str[i];
                 t = 1;
        printLCS(i+1,j+1);


    }
    else
    {
        if(dp[i+1][j]>dp[i][j+1]) printLCS(i+1,j);
        else printLCS(i,j+1);
    }
}



int main()
{

    int x;

    while( cin >> str[0] )
     {
         t = 0;
         n = 0;
         m = -1;
         while( true )
         {
             n++;
             cin >> str[n];
             if( str[n] == "#")
                break;
         }
         while( true )
         {
             m++;
             cin >> ss[m];
             if( ss[m] == "#")
                break;
         }



     memset( dp,-1,sizeof(dp));

     x = rec(0,0);

     //cout << x <<endl;
     printLCS( 0,0);
     cout << endl;
     }
}
