#include<iostream>
#include<string>

using namespace std;

int main()
{
    string home,away;

    cin>>home;
    cin>>away;

    int n;

    cin>>n;

    char team,card;
    int time,h_player[101]={0},a_player[101]={0},i,x,player;

    for(i=0;i<n;i++)
    {
        cin>>time>>team>>player>>card;

        if(team=='h')
        {
           if(h_player[player]!=-1)
                 h_player[player]++;

           if(h_player[player]==2)
           {
               cout<<home<<' '<<player<<' '<<time<<endl;
               h_player[player]=-1;
           }

           else if(card=='r'&&h_player[player]!=-1)
           {
                cout<<home<<' '<<player<<' '<<time<<endl;
               h_player[player]=-1;
           }


        }

       else  if(team=='a')
        {
           if(a_player[player]!=-1)
                 a_player[player]++;

           if(a_player[player]==2)
           {
               cout<<away<<' '<<player<<' '<<time<<endl;
               a_player[player]=-1;
           }

           else if(card=='r'&&a_player[player]!=-1)
           {
                cout<<away<<' '<<player<<' '<<time<<endl;
               a_player[player]=-1;
           }


        }
    }

}
