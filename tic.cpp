#include<iostream>
using namespace std;

char arr[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
int row, col;
bool draw = false;

void board (){
    system("cls");
    cout<<endl;
    cout<<"                                            TIC TAC TOE GAME    "<<endl;  
    cout<<endl;
    cout<< "  PRANALI  == X   "<<endl;
    cout<<endl;
    cout<< "  SNEHA  == O   "<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"\t\t          |          |          "<<endl;
    cout<<"\t\t    "<<arr[0][0]<<"     |    "<<arr[0][1]<<"     |    "<<arr[0][2]     <<endl;
    cout<<"\t\t          |          |          "<<endl;
    cout<<"\t\t----------|----------|----------"<<endl;
    cout<<"\t\t          |          |          "<<endl;
    cout<<"\t\t    "<<arr[1][0]<<"     |    "<<arr[1][1]<<"     |    "<<arr[1][2]     <<endl;
    cout<<"\t\t          |          |          "<<endl;
    cout<<"\t\t----------|----------|----------"<<endl;
    cout<<"\t\t          |          |          "<<endl;
    cout<<"\t\t    "<<arr[2][0]<<"     |    "<<arr[2][1]<<"     |    "<<arr[2][2]     <<endl;
    cout<<"\t\t          |          |          "<<endl;
    cout<<endl;
}
void player_turn(){
    int choice;
    if(turn == 'X'){
        cout<<"     PRANALI's  TURN :   ";
    }
    if(turn == 'O'){
        cout<<"     SNEHA's  TURN :   ";
    }
    cin>>choice;
    switch(choice){
        case 1 :row=0 , col=0;break;
        case 2 :row=0 , col=1;break;
        case 3 :row=0 , col=2;break;
        case 4 :row=1 , col=0;break;
        case 5 :row=1 , col=1;break;
        case 6 :row=1 , col=2;break;
        case 7 :row=2 , col=0;break;
        case 8 :row=2 , col=1;break;
        case 9 :row=2 , col=2;break;
        default:
            cout<<"INVALID CHOICE \n";break;
    }
    if(turn == 'X' && arr[row][col] != 'X' && arr[row][col] != 'O'){
        arr[row][col]= 'X';
        turn = 'O';
    }
    else if(turn == 'O' && arr[row][col] != 'X' && arr[row][col] != 'O'){
        arr[row][col] = 'O';
        turn= 'X';
    }
    else{
        //This is used when the user override value at any box.
        cout<<"Box already filled \n"<<"Please Try again!!!!!\n";
        player_turn();
    }
}
bool gameover(){
    //check who win
    for(int i=0; i<3; i++){
        if((arr[i][0]==arr[i][1] && arr[i][0]==arr[i][2]) || (arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i])){
            return false;
        }
    }
    if(arr[0][0]==arr[1][1] && arr[0][0]==arr[2][2] || arr[0][2]==arr[1][1] && arr[0][2]==arr[2][0]){
        return false;
    }
    //To check the game is playing or not
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(arr[i][j] != 'X' && arr[i][j] != 'O'){
                return true;
            }
        }
    }
    draw = true;
    return false;
}
    

int main(){
    board();
    while( gameover()){
        player_turn();
        board();
    }
    if(turn == 'O' && !draw ){
        cout<<" CONGRALAUTIONS PRANALI YOU WIN !!!"<<endl;
        cout<<"\n\n\n";
    }
    else if(turn == 'X' && !draw){
        cout<<" CONGRALAUTIONS SNEHA YOU WIN !!!"<<endl;
        cout<<"\n\n\n";
    }
    else{
        cout<<"GAME DRAW "<<endl;
    }
    return 0;
}

