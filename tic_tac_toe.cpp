#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

//function to detect the tie in the game
int mcount=0;
int detect_tie(){
    mcount++;
    if(mcount==9){
        return 1;
    }
    return 0;
}

// 2D vector to represent the tic-tac-toe game board
vector<vector<string>> board(3,vector<string>(3," ")); 
vector<vector<int>> box(3,vector<int>(3));
//variable to keep track of whoes turn it is
int player_turn = 0;

int detect_win(){
    //iterate through the board to update the box matrix
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (board[i][j] == "X"){
                box[i][j] = 1;
            }
            else if (board[i][j] == "O") {
                box[i][j] = 0;
            }
        }
    }
    // Check rows and columns for a win
    for(int x=0;x<3;x++){
        if(((box[x][0]^box[x][1])==0 && (box[x][1]^box[x][2])==0)||((box[0][x]^box[1][x])==0 && (box[1][x]^box[2][x])==0)){
                return 1;
            
        }
    }
    // Check diagonals for a win
    for(int dia=0;dia<3;dia++){
        if(((box[0][0]^box[1][1])==0 && (box[1][1]^box[2][2])==0)||((box[0][2]^box[1][1])==0 && (box[1][1]^box[2][0])==0)){
            return 1;
        }
    }
    // Return 0 if no win is detected
    return 0;
}

//function to display the tic-tac-toe game board
void display_board(){
    //loop through each row of the board
    for(int row=0;row<3;row++){
        //loop through each column of the board
        for(int col=0;col<3;col++){
            cout<<"|"<<board[row][col]<<"| ";
        }
        cout<<endl<<endl;
    }
}

//function to handle the players input and update the board accordingly
void handle_inputs(){
    int player[2]={1,2};
    int pos,i,j;
    player_turn=0;
    while(true){
    (player_turn == 0) ? cout<<"\nPLAYER_1(X):-"<<endl : cout<<"\nPLAYER_2(O):-"<<endl; 
    cout<<"Enter the position[1-9]: ";
    cin>>pos;
    if(pos>=1 && pos<=9){
        i=(pos-1)/3;
        j=(pos-1)%3;
         //check if position is already occupied
        if(board[i][j]!=" "){
            cout<<"Wrong Input!! Try Again.."<<endl;
            continue;
        }
        else{
            (player_turn==0)?board[i][j]="X":board[i][j]="O";
        }
        display_board();
    }
    else{
        cout<<"\nSorry!! Invalid Position.Try Again"<<endl;
    }
    string symbol=(player_turn==1)?"O":"X";
    // Check for win
    if(detect_win()==1){
        cout<<"\n\nCongratulations player: PLAYER("<<symbol<<") "<<"YOU WON!!"<<endl;
        break;
    }
    // Check for tie
    else if(detect_tie()==1){
        cout<<"\n\nGood TRY!! The Game is tied ."<<endl;
        break;
    }
    player_turn==0?player_turn++:player_turn--;
    }
}

int main(){
    int choice,num=1;
    cout<<"*****TIC-TAC-TOE*****\n"<<endl;
    display_board();
    
    do{
        int c=2;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    box[i][j]=c;
                c++;
                }
            }
        cout<<"\n###**GAME "<<num<<":-**###"<<endl;
        cout<<"PLAYER_1(X) vs PLAYER_2(O)\n\n"<<endl;
        //function call to handle user inputs for the Tic-Tac-Toe game.
        handle_inputs();
        cout<<"\nDo you want to continue[1:yes/2:no]: ";
        cin>>choice;
        if(choice==2){
            exit(0);
        }
        else if(choice==1){
            //clearing the 2D vector so that it can be used again
            system("cls");
            
            mcount=0;
            
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    board[i][j] = " ";
                }
            }
            cout<<"*****TIC-TAC-TOE*****\n"<<endl;
            display_board();
            num++; //number of games played by the user
            continue;
        }
        else{
            break;
        }
    }while(true);
}