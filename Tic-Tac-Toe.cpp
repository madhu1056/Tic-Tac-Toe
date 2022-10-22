#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> Tic_Tac{{'1','2','3'},{'4','5','6'},{'7','8','9'}};
bool Game = true;
bool Game_drawn = false;
int row,column;
char turn = 'X';

void Game_interface(){
    cout<<"-------------Tic_Tac_Toe-------------"<<endl;
    cout<<"Player1:- X"<<" "<<"Player2:- O"<<endl;
    for(int i=0;i<Tic_Tac.size();i++){
        for(int j=0;j<Tic_Tac[i].size();j++){
            cout<<"---"<<Tic_Tac[i][j];
        }
        cout<<"---"<<endl;
    }
}

void Play(){
        Game_interface();
        int choice;
        cout<<"enter your choice:"<<turn<<endl;
        cin>>choice;
        switch (choice){
            case 1: row=0; column =0;
                    break;
            case 2: row=0; column =1;
                    break;
            case 3: row=0; column =2;
                    break;
            case 4: row=1; column =0;
                    break;
            case 5: row=1; column =1;
                    break;
            case 6: row=1; column =2;
                    break;
            case 7: row=2; column =0;
                    break;
            case 8: row=2; column =1;
                    break;
            case 9: row=2; column =2;
                    break;
            
            default:"Not valid";
        }
        

        if(turn == 'X' && Tic_Tac[row][column]!='X' && Tic_Tac[row][column]!='O')
            {
                Tic_Tac[row][column] = 'X';
                turn = 'O';
            }

        else if(turn == 'O' && Tic_Tac[row][column]!='X' && Tic_Tac[row][column]!='O')
            {
                Tic_Tac[row][column] = 'O';
                turn = 'X';
            }

        else{
            cout<<"The selected box is already taken Please, choose another one"<<endl;
            Play();
        }
    Game_interface();
}


bool Game_over(){
    for(int i=0;i<3;i++){
        if(((Tic_Tac[i][0]==Tic_Tac[i][1])&&(Tic_Tac[i][1]==Tic_Tac[i][2]))||(Tic_Tac[0][i]==Tic_Tac[1][i])&&Tic_Tac[1][i]==Tic_Tac[2][i]){
            Game = false;
            return false;
        }
    }

    if((Tic_Tac[0][0]==Tic_Tac[1][1])&&(Tic_Tac[1][1]==Tic_Tac[2][2])||(Tic_Tac[0][2]==Tic_Tac[1][1])&&(Tic_Tac[1][1]==Tic_Tac[2][0]))
        {
            Game = false;
            return false;
        }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
        {
            if(Tic_Tac[i][j]!='X' || Tic_Tac[i][j]!='O')
                return true;
        }
    }
    Game_drawn = true;
    Game = false;
    return false;
}




int main(){
    string player1,player2;
    cout<<"enter the player1 name"<<endl;
    cin>>player1;
    cout<<"enter the player2 name"<<endl;
    cin>>player2;
    string X,O;
    X = player1;
    O = player2;
    while(Game_over()){
    Play();
    Game_over();
    }
    
    if(Game_drawn == false){
        if(turn =='X')
            cout<<"The winner is:"<<O<<endl;
        else
            cout<<"The winner is:"<<X<<endl;
    }
    else{
        cout<<"The game is drawn well tried both"<<endl;
    }
}

