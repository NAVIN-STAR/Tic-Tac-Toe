#include<iostream>
#include<windows.h>
#include<stdlib.h>
using namespace std;
int player=1;
int win=1;
int draw=-1;
int running=-1;
char mark='X';
int Game=running;
string board[9]={" "," "," "," "," "," "," "," "," "};
void Board()
{
    cout<<board[0]<<" |"<<board[1]<<" | "<<board[2]<<endl;
    cout<<"__|__|__"<<endl;
    cout<<board[3]<<" |"<<board[4]<<" | "<<board[5]<<endl;
    cout<<"__|__|__"<<endl;
    cout<<board[6]<<" |"<<board[7]<<" | "<<board[8]<<endl;

}
void checkwin()
{
    //horizontal win
    if(board[0]==board[1] && board[1]==board[2] && board[1]!=" ")
        Game=win;
    else if(board[3]==board[4] && board[4]==board[5] && board[6]!=" ")
        Game=win;
    else if(board[6]==board[7] && board[7]==board[8] && board[8]!=" ")
        Game=win;
    else if(board[0]==board[4] && board[4]==board[8] && board[4]!=" ")
        Game=win;
    else if (board[2]==board[4] && board[4]==board[6] && board[4]!=" ")
        Game=win;
    else if(board[0]==board[3] && board[3]==board[6] && board[6]!=" ")
        Game=win;
    else if(board[1]==board[4] && board[4]==board[7] && board[4]!=" ")
        Game=win;
    else if(board[2]==board[5] && board[5]==board[8] && board[2]!=" ")
        Game=win;
    else if(board[0]!=" " and board[1]!=" "&& board[2]!=" " && board[3]!=" " && board[4]!=" " && board[5]!=" " && board[6]!=" " && board[7]!=" " && board[8]!=" ")
        Game=draw;
    else
        Game=running;
}
int checkmark(int x)
{
    if(board[x]==" ")
        return 1;
    else
        return 0;
}
int main()
{
    
    cout<<"Game is Starting.....\n";
    cout<<"Player 1 mark is X.\n";
    cout<<"Player 2 mark is O.\n";
    Sleep(1000);
    while(Game==running)
    {
        Sleep(1500);
        system("cls");
        Board();
        if(player%2!=0)
        {
            cout<<"Player 1's turn to mark:\n";
            mark='X';
        }
        else
        {
            cout<<"Player 2's turn to mark:\n";
            mark='O';
        }
        int choice;
        cout<<"Enter the number form 1 - 9 of the  Box you want to mark:\n";
        cin>>choice;
        if(checkmark(choice-1)==1)
        {
            board[choice-1]=mark;
            player+=1;
            checkwin();
        }
    }
    Board();
    if(Game==draw)
        cout<<"ooppppssss..... \nThe game has tied both of you played well.";
    if(Game==win)
    {
        if(player%2!=1)
            cout<<"Yeyyyyyyyy.....\nPlayer 1 has won.";
        else
            cout<<"Yeyyyyyyyy.....\nPlayer 2 has won.";
    }
    

}