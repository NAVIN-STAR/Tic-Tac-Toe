import time as t
import os
board=[" "," "," "," "," "," "," "," "," "]
player=1
win=1
draw=-1
running=0
Game=running
mark="X"

def Board():
    print(" %c | %c |%c "%(board[0],board[1],board[2]))
    print(" __|___|__ ")
    print(" %c | %c |%c "%(board[3],board[4],board[5]))
    print(" __|___|__ ")
    print(" %c | %c |%c "%(board[6],board[7],board[8]))
    print("   |   |")
    
def checkwin():
    global Game
    if(board[0]==board[1] and board[1]==board[2] and board[1]!=" "):
        Game=win
    elif(board[3]==board[4] and board[4]==board[5] and board[4]!=" "):
        Game=win
    elif(board[6]==board[7] and board[7]==board[8] and board[8]!=" "):
        Game=win
    elif(board[0]==board[4] and board[4]==board[8] and board[4]!=" "):
        Game=win
    elif(board[2]==board[4] and board[4]==board[6] and board[4]!=" "):
        Game=win
    elif(board[0]==board[3] and board[3]==board[6] and board[6]!=" "):
        Game=win
    elif(board[1]==board[4] and board[4]==board[7] and board[4]!=" "):
        Game=win
    elif(board[2]==board[5] and board[5]==board[8] and board[2]!=" "):
        Game=win
    elif(board[0]!=" " and board[1]!=" "and board[2]!=" " and board[3]!=" " and board[4]!=" " and board[5]!=" " and board[6]!=" " and board[7]!=" " and board[8]!=" "):
        Game=draw
    else:
        Game=running
        
        
    
print("\tTicTacToe\n")
print("player 1 Mark is  'X'.")
print("player 2 Mark is  'O'.")
print()

print("Game Is Starting....")
t.sleep(1)

def checkposition(x):
    if(board[x]==" "):
        return 1
    else:
        return 0 
    
 
while(Game==running):
    t.sleep(1.5)
    os.system('cls')
    Board()
    if(player%2==0):
        print("player 2's chance to mark:\n")
        mark="O"
    else:
        print("Player 1's chance to mark:")
        mark="X"
    choice=int(input("Enter the position of Box you want to mark\n"))
    if(checkposition(choice-1)==1):
        board[choice-1]=mark
        player+=1
        checkwin()
    else:
        print("Error.... Already filled Box try again")
        
Board()

if(Game==win):
    if(player%2==0):
        print("Yeyyyyyyy...\nPlayer 1 Won.")
    else:
        print("Yeyyyyyyy...\nPlayer 2 Won.")
if(Game==draw):
    print("ohhhohhhh...\nThe game is tied")
