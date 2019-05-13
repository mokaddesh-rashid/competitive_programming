using System;
using System.Text;

public class Board
{
	public string[] str;
	public bool human;
	static int val;

	Board()
	{
		str=new string[4];
		str[0]=str[1]=str[2]="___";
		human=true;
	}
	public void setISHuman()
	{
		human=false;
	}
	public bool getIsHuman()
	{
	    if(human==false) Console.WriteLine("OKna");
	    return human;
	}
	public bool isWinner(char ch)
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
			   if(str[i][j]!=ch)break;
			   if(j==2)return  true;
			}
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
			   if(str[j][i]!=ch)break;
			   if(j==2)return  true;
			}
		if(str[0][0]==ch&&str[1][1]==ch&&str[2][2]==ch)return true;
		if(str[2][0]==ch&&str[1][1]==ch&&str[0][2]==ch)return true;

		return false;

	}

	public void submitMove(int i,int j,char newChar)
	{
		StringBuilder sb = new StringBuilder(str[i]);
		sb[j] = newChar;
		str[i] = sb.ToString();

	}

	public void printBoard()
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				Console.Write("{0} ",str[i][j]);
			}
			Console.WriteLine();
		}
	}

	public int miin(int x,int y)
	{
		if(x>y)return y;
		else return x;
	}
	public int maax(int x,int y)
	{
		if(x>y)return x;
		else return y;
	}
	int Move(int v)
	{
	    ///printBoard();
		if(isWinner('O'))return 2;
		if(isWinner('X'))return 0;
		if(v==9)return 1;

		int temp;
		if(v%2==0)
		{
			temp=2;
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(str[i][j]=='_')
					{
						submitMove(i,j,'X');//str[i][j]='X';
						temp=miin(temp,Move(v+1));
						submitMove(i,j,'_');//str[i][j]='_';
					}
				}
			}
		}
		else
		{
			temp=0;
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					if(str[i][j]=='_')
					{
						submitMove(i,j,'O');///str[i][j]='O';
						temp=maax(temp,Move(v+1));
						submitMove(i,j,'_');///str[i][j]='_';
					}
				}
			}
		}
		return temp;
	}

	public int valid(int x,int y)
	{
		if(x>=0&&x<3&&y>=0&&y<3)return 1;
		return 0;
	}
	public int play(int t)
	{
		Console.WriteLine(" ");
		printBoard();
		if(t==9)return 0;
		if(isWinner('X'))return 1;
		if(isWinner('O'))return 2;

		int x,y;

		if(t%2==0)
		{
			Console.WriteLine("player 1: ");
			string inp=Console.ReadLine();
			x=(int)inp[0]-'0';
			y=(int)inp[1]-'A';

			if(valid(x,y)==1&&str[x][y]=='_')
			{
				submitMove(x,y,'X');///str[x][y]='X';
				return play(t+1);
			}
			else
			{
				Console.WriteLine("Invalid position!");
				return play(t);
			}
		}
		else
		{
		    if(getIsHuman())
            {
                Console.WriteLine("player 2: ");
                string inp=Console.ReadLine();
                x=(int)inp[0]-'0';
                y=(int)inp[1]-'A';

                if(valid(x,y)==1&&str[x][y]=='_')
                {
                    submitMove(x,y,'O');///str[x][y]='X';
                    return play(t+1);
                }
                else
                {
                    Console.WriteLine("Invalid position!");
                    return play(t);
                }
            }
			else
            {
                Console.WriteLine("player Computer: ");
                int v=Move(t);
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        if(str[i][j]=='_')
                        {
                            submitMove(i,j,'O'); ///str[i][j]='O';
                            if(Move(t+1)==v)return play(t+1);
                            submitMove(i,j,'_'); ///str[i][j]='_';
                        }
                    }
                }
            }
		}
		return 0;

	}
	public static void Main()
	{

		int i,j,n,m;
		Board ob=new Board();
		//while(true)
		{
			Console.WriteLine("\n\npress 1 for single player \n2 for double player");
			m=int.Parse(Console.ReadLine());
			if(m==1)ob.setISHuman();


			Console.WriteLine("Row starts with 0 \ncol starts with A \nto choose position(1,1)  press 0A");

			n=ob.play(0);
			if(n!=0)Console.WriteLine("Player {0} wins",n);//<<NL;
			else if(n==0)Console.WriteLine("Draw");
		}
	}
}
