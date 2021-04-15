#include<iostream>
#include<string>
char array[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
int row,column;
char turn='x';
bool draw=false;

void box(){
    std::cout<<array[0][0]<<"|"<<array[0][1]<<"|"<<array[0][2]<<std::endl;
    std::cout<<"------------"<<std::endl;
    std::cout<<array[1][0]<<"|"<<array[1][1]<<"|"<<array[1][2]<<std::endl;
    std::cout<<"------------"<<std::endl;
    std::cout<<array[2][0]<<"|"<<array[2][1]<<"|"<<array[2][2]<<std::endl;
    std::cout<<"------------"<<std::endl;
}
void selection(){
    if(turn=='x'){
        std::cout<<"Player 1 turn\n";
    }
    else if (turn=='o')
    {
      std::cout<<"Player 2 turn\n";
    }
    std::cout<<"Enter the position:\n";
    std::cin>>choice;
    switch(choice)
    {
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            std::cout<<"Invalid Move";
    }
        if( (turn=='x')&&array[row][column] != 'x' && array[row][column] != 'o'){
            array[row][column]='x';
            turn='o';
        }
        else if((turn=='o')&&array[row][column] != 'x' && array[row][column] != 'o')
        {
            array[row][column]='o';
            turn='x';
        }
        else{
            std::cout<<"Already filled!";
            selection();
        }
        box();

}
bool gameover()
{
    for(int i=0; i<3; i++)
    if(array[i][0] == array[i][1] && array[i][0] == array[i][2] || array[0][i] == array[1][i] && array[0][i] == array[2][i])
    return false;
    
    
    if(array[0][0]==array[1][1]&&array[0][0]==array[2][2]||array[0][2]==array[1][1]&&array[0][2]==array[2][0])
    return false;
    
        for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        if(array[i][j] != 'X' && array[i][j] != 'O') 
         return true;

        draw = true;
        return false;
}            
int main(){
    while(gameover()){
    box();
    selection();
    gameover();
    }
    if(turn == 'x' && draw == false){
        std::cout<<"nnCongratulations!Player 'O' has won the game";
    }
    else if(turn == 'o' && draw == false){
        std::cout<<"nnCongratulations!Player 'X' has won the game";
    }
    else
    std::cout<<"nnGAME DRAW!!!nn";
}
    
        
            
            
        
    



   

        