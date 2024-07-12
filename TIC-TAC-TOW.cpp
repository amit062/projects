#include<bits/stdc++.h>
using namespace std;

string position="123456789";

int x;

int digit;
char token='X';

string player1="";

string player2="";

int too=1;

void funx(){

    cout<<"        |       |    "<<endl;
    cout<<"     "<<position[0]<<"  |   "<<position[1]<<"   |  "<<position[2]<<"  "<<endl;
    cout<<"   _____|_______|_____ "<<endl;
    cout<<"        |       |    "<<endl;
    cout<<"     "<<position[3]<<"  |   "<<position[4]<<"   |  "<<position[5]<<"  "<<endl;
    cout<<"   _____|_______|_____ "<<endl;
    cout<<"        |       |    "<<endl;
    cout<<"     "<<position[6]<<"  |   "<<position[7]<<"   |  "<<position[8]<<"  "<<endl;
    cout<<"        |       |    "<<endl; 

}

void funx1(){
    if(token=='X'){
        cout<<player1<<" Please enter position: ";cin>>digit;
    }
    if(token=='O'){
        cout<<player2<<" Please enter position: ";cin>>digit;
    }
    

    if(digit<1 || digit>9){
        cout<<"Invalid request!!!"<<endl;
        funx1();
    }else{

        x=digit-1;
        

        if((token=='X')  && (position[x]!='X') && (position[x]!='O')){
            position[x]='X';
            token='O';
        }
        else if((token=='O')  && (position[x]!='X') && (position[x]!='O')){
            position[x]='O';
            token='X';
        }else{
            cout<<"NO empty space found!!!"<<endl;
            funx1();
        }

        
        
    }
    

}    

bool check(){
    

    if((position[0]==position[1] && position[0]==position[2]) || (position[3]==position[4] && position[3]==position[5]) || (position[6]==position[7] && position[6]==position[8])){
        return true;
        
    }else if((position[0]==position[3] && position[0]==position[6]) || (position[1]==position[4] && position[1]==position[7]) ||(position[2]==position[5] && position[2]==position[8]) ){
        return true;
        

    }else if((position[0]==position[4] && position[0]==position[8]) || (position[2]==position[4] && position[2]==position[6]) ){
        return true;
        
    }

        for(int i=0;i<position.size();i++){
            if(position[i]!='X' && position[i]!='O'){
                return false;
                    
            }
            

            
        }
        too=0;
        return true;

    
            
        
}



int main(){
    
    cout<<"Enter the 1st player name: ";cin>>player1;cout<<endl;
    cout<<"Enter the 2nd player name: ";cin>>player2;cout<<endl;

    while(!check()){

        funx();
        funx1();
        check();

    }

    if(token =='X' && too==1){
        cout<<"-----------------------"<<endl;
        cout<<player2<<" Wins!!"<<endl;
        cout<<endl;
        funx();
    }else if(token =='O' && too==1){
        cout<<"-----------------------"<<endl;
        cout<<player1<<" Wins!!"<<endl;
        cout<<endl;
        funx();
    }else{
         cout<<"-----------------------"<<endl;
        cout<<"Game Ends! Its a draw!!!"<<endl;
        cout<<endl;
        funx();
    }

    




}
