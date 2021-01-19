#include "bits/stdc++.h"
using namespace std;


void drawLine(int n, char symbol);
void rules();

void bgin()
{
    system("Color 0A");
    

    cout<<endl;
    for(int j=0;j<2;j++){for(int i=0;i<119;i++) cout<<"*";cout<<endl;}

    for(int j=0;j<4;j++)
    {
        if(j == 1)
        {
            for(int i=0;i<7;i++)cout<<"*";
            for(int i=0;i<46;i++)cout<<" ";cout<<"GUSSING GAME";

            for(int i=0;i<48;i++)cout<<" ";
            for(int i=0;i<6;i++)cout<<"*";cout<<endl;


        }
        else if(j==2)
        {
            for(int i=0;i<7;i++)cout<<"*";
            for(int i=0;i<40;i++)cout<<" ";cout<<"-------------------------";

            for(int i=0;i<41;i++)cout<<" ";
            for(int i=0;i<6;i++)cout<<"*";cout<<endl;


        }

      else{for(int i=0;i<119;i++){if (i<7 || i>112) cout<<"*";else cout<<" ";}cout<<endl;}



    }

    for(int j=0;j<2;j++){for(int i=0;i<119;i++) cout<<"*";cout<<endl;}

    for(int i=0;i<96;i++)cout<<" ";cout<<"BY-Theatrical Debuggers"<<endl;
    return;


}


string choose_word(int  Difficulty_Level)
{
     int index{};
    unordered_map<int,vector<string>> data;
    data[1] = {"that","not","this","but","his","they","her","she","will","one","would",
                             "there","their","monkey","snow","time","person","year","thing","others",
                             "world","life","hand","part","child","woman","place","work","week","case",
                             "point","company","number","group","fact","Verb","have","make","know",
                             "take","come","think","look","want","give","use","find","work","seem",
                             "feel","try","good","new","first","last","long","great","little",
                             "other","old","right","big","high","small","large","next","early",
                             "young","few","bad","same","able","for","with","from",
                             "about","over","after"};

    data[2] = {"rainbow","government","problem","different","important",
                             "prepositions","difficulty","determine","wikipedia","candidates","mathematics",
                             "admission","computer","already","public"};
    if (Difficulty_Level == 1)
    {
        srand((unsigned) time(0));
        index =  rand() %73;
 
          
    }
    else 
    {
        srand((unsigned) time(0));
         index =  rand() %13;

       

    }

    return data[Difficulty_Level][index];

      
    

}




string suffle_string( string s)
{
    while(1)
    {


        string temp="";

        vector<char> str(s.begin(),s.end());

        unsigned seed = chrono::system_clock::now().time_since_epoch().count();

        shuffle(str.begin(), str.end(),default_random_engine(seed));

        for (auto x: str) temp+=x;
        if (s!=temp) return temp;

    }

}

void thank(string p1name,int pp1)
    {
      for(int i =0;i<45;i++)cout<<" "; cout<<p1name<<endl;
      for(int i =0;i<45;i++)cout<<" ";cout<<" Your final score is "<<pp1<<"."<<endl;

      for(int i =0;i<45;i++)cout<<" ";  cout<<"Thanks for playing."<<endl;

    }

void instruction_gussing_word_single()
{
    for(int i =0;i<32;i++)cout<<" ";for(int i =0;i<56;i++)cout<<"-";cout<<endl;
    for(int i =0;i<32;i++)cout<<" ";
    cout<<"| *Instructions";for(int i =0;i<40;i++)cout<<" ";cout<<"|"<<endl;
    for(int i =0;i<32;i++)cout<<" ";cout<<"|     Total of EIGHT questions.   "; for(int i =0;i<21;i++)cout<<" ";cout<<"|"<<endl;
    for(int i =0;i<32;i++)cout<<" ";
    cout<<"|     +2 points for correct ans in LEVEL 1.            |"<<endl;
    for(int i =0;i<32;i++)cout<<" ";
    cout<<"|     +4 points for correct ans in LEVEL 2.            |"<<endl;
    for(int i =0;i<32;i++)cout<<" ";
    cout<<"|     -1 point for  wrong answers."; for(int i =0;i<21;i++)cout<<" ";cout<<"|"<<endl;
    for(int i =0;i<32;i++)cout<<" ";for(int i =0;i<56;i++)cout<<"-";cout<<endl;




}

void single_player()
{
    system("Color 0B");
    instruction_gussing_word_single();
    cout<<endl;
    vector<string> correct;
    string ans;
    for(int i =0;i<45;i++)cout<<" "; cout<< "GUESS THE  JUMBLED WORDS: "<<endl;
    vector<string> alrady_asked;
    string p1name ;
    for(int i =0;i<45;i++)cout<<" "; cout<<"Enter your name: ";
        cin.ignore();
        getline(cin,p1name);


    int pp1{};
    int i{};
    while(i<8)

    {

        string qn,picked_word;

        if(i<4) picked_word = choose_word(1);
        else picked_word = choose_word(2);


        if(count(alrady_asked.begin(),alrady_asked.end(),picked_word)>0)
        {
           continue;
           i = i-1;
        }
        alrady_asked.push_back(picked_word);

        qn = suffle_string(picked_word);

        if(i == 0){for(int i =0;i<45;i++)cout<<" "; cout<< "*LEVEL - 1"<<endl;}
        if(i==4) {for(int i =0;i<45;i++)cout<<" "; cout<<"*LEVEL - 2"<<endl;}



        for(int i =0;i<45;i++)cout<<" "; cout<<i+1<<" "<<qn<<": " ;

            cin >> ans;

            if (ans == picked_word)
            {
                if (i<4)pp1+=2;
                else pp1+=4;

            }
            else
            {
                pp1-=1;
                

                correct.push_back(picked_word);


            }
        
        
       
        

        if(i==7)
        {
        	cout << endl;
        	cout << endl;
            if(pp1> 6)
            {
               for(int i =0;i<45;i++)cout<<" "; cout <<"Congratulations "<<p1name<<" YOU WIN "<<endl;
               for(int i =0;i<45;i++)cout<<" "; cout<<"YOUR SCORE  : "<<pp1<<endl;
                if(pp1!=8)
                {
                    for(int i =0;i<45;i++)cout<<" "; cout<<"CORRECT ANSWER ARE: ";
                    for(auto i:correct)cout<<i<<" ";

                }

            }
            else if(pp1<=6 &&  pp1 >3)
            {
                for(int i =0;i<45;i++)cout<<" "; cout<<"GOOD YOU PLAYED WELL "<<"YOUR SCORE "<<pp1<<endl;
                for(int i =0;i<45;i++)cout<<" "; cout<<"CORRECT ANSWER ARE: ";for(auto i:correct)cout<<i<<", ";

            }
            else { for(int i =0;i<45;i++)cout<<" "; cout<<"YOUR SCORE : "<<pp1<<endl;
                   for(int i =0;i<45;i++)cout<<" "; cout<< "BETTER LUCK NEXT TIME........."<<endl;
            for(int i =0;i<45;i++)cout<<" ";cout<<"CORRECT ANSWER ARE: ";for(auto i:correct){cout<<i<<", ";}
        cout<<endl;

        }


        }
        i+=1;

        }
        thank(p1name,pp1);
        



}

 void thank_2(string p1name,string p2name,int pp1,int pp2)
    {
	    for(int i =0;i<45;i++)cout<<" ";cout<<p1name<<" your final score is "<<pp1<<endl;
        for(int i =0;i<45;i++)cout<<" ";cout<<p2name<<" your final score is "<<pp2<<endl;
        for(int i =0;i<45;i++)cout<<" ";cout<<"Thanks for playing"<<endl;

    }
void instruction_gussing_word_double()
{
    for(int i =0;i<32;i++)cout<<" ";for(int i =0;i<56;i++)cout<<"-";cout<<endl;
    for(int i =0;i<32;i++)cout<<" ";
    cout<<"| *Instructions";for(int i =0;i<40;i++)cout<<" ";cout<<"|"<<endl;
    for(int i =0;i<32;i++)cout<<" ";cout<<"|     Game continue until one player makes two         |" <<endl;
    for(int i =0;i<32;i++)cout<<" ";cout<<"|     wrong sumit ";for(int i =0;i<37;i++)cout<<" ";cout<<"|"<<endl;
    for(int i =0;i<32;i++)cout<<" ";cout<<"|     +2 points for correct ans in LEVEL 1.            |"<<endl;
    for(int i =0;i<32;i++)cout<<" ";cout<<"|     +4 points for correct ans in LEVEL 2.            |"<<endl;
    for(int i =0;i<32;i++)cout<<" ";cout<<"|     -1 point for  wrong answers."; for(int i =0;i<21;i++)cout<<" ";cout<<"|"<<endl;
    for(int i =0;i<32;i++)cout<<" ";for(int i =0;i<56;i++)cout<<"-";cout<<endl;




}

void double_player()
{
    system("Color 0E");
    instruction_gussing_word_double();
    cout<<endl;

    vector<string> alrady_asked;
    string p1name ,p2name;

    for(int i =0;i<45;i++)cout<<" ";cout<<"Player 1 enter your name: ";
        cin.ignore();
        getline(cin,p1name);
    for(int i =0;i<45;i++)cout<<" ";cout<<"Player 2 enter your name: ";
        
        getline(cin,p2name);

    // cout<<p1name<<" "<<p2name<<endl;
    int pp1{},pp2{},turn{};

    int wa2=0,wa1=0;


    for(int i = 0;i<100;i++)
    {
        string qn,picked_word;

        if(i<4) picked_word = choose_word(1);
        else picked_word = choose_word(2);


        if(count(alrady_asked.begin(),alrady_asked.end(),picked_word)>0) continue;
        alrady_asked.push_back(picked_word);

        qn = suffle_string(picked_word);

        if(i == 0) {for(int i =0;i<45;i++)cout<<" ";cout<< "*LEVEL - 1"<<endl;}
        if(i==4) {for(int i =0;i<45;i++)cout<<" ";cout<<"*2LEVEL-2"<<endl;}

        for(int i =0;i<45;i++)cout<<" ";cout<< qn<<endl;

        if (turn%2==0)
        {
            for(int i =0;i<45;i++)cout<<" ";cout<<p1name<<" "<<"This is your turn: ";
            string ans;
            cin >> ans;

            if (ans == picked_word)
            {
                if (i<4)pp1+=2;
                else pp1+=4;
                for(int i =0;i<45;i++)cout<<" ";cout<<pp1<<" "<<"This is your score."<<endl;


            }
            else
            {
                pp1-=1;
                wa1+=1;
                for(int i =0;i<45;i++)cout<<" ";cout<< "Answer is "<<picked_word<<endl;
                for(int i =0;i<45;i++)cout<<" ";cout<<"Better luck next time...."<<endl;


            }

        if (wa1 == 2 || wa2 == 2)
        {
            for(int i =0;i<45;i++)cout<<" ";cout<<" "<<endl;
            for(int i =0;i<45;i++)cout<<" ";cout<< "Winner Winner Chicken Dinner"<<endl;
            thank_2(p1name,p2name,pp1,pp2);
            break;
        }
        }

        else
        {
            for(int i =0;i<45;i++)cout<<" ";cout<<p2name<<" "<<"This is your turn: ";
            string ans;
            cin >> ans;

            if (ans == picked_word)
            {
                if (i<4) pp2+=2;
                else pp2+=4;
                for(int i =0;i<45;i++)cout<<" ";cout<<pp2<<" "<<"This is your score"<<endl;


            }
            else
            {
                wa2+=1;
                pp2-=1;
                for(int i =0;i<45;i++)cout<<" ";cout<< "Answer is "<<picked_word<<endl;
                for(int i =0;i<45;i++)cout<<" ";cout<<"Better luck next time...."<<endl;


            }

        if (wa1 == 2 || wa2 == 2)
        {
           for(int i =0;i<45;i++)cout<<" "; cout<<" "<<endl;
            for(int i =0;i<45;i++)cout<<" ";cout<< "Winner Winner Chicken Dinner"<<endl;
            thank_2(p1name,p2name,pp1,pp2);
            break;
        }


        }

        turn=turn+1;

    }

}
void instruction_gussing_number()
{
    for(int i =0;i<32;i++)cout<<" ";for(int i =0;i<55;i++)cout<<"-";cout<<endl;
    for(int i =0;i<32;i++)cout<<" ";
    cout<<"| *Instructions";for(int i =0;i<40;i++)cout<<" ";cout<<"|"<<endl;
    for(int i =0;i<32;i++)cout<<" ";
    cout<<"|     To 'WIN' this game player have to guess a number |"<<endl;
    for(int i =0;i<32;i++)cout<<" ";
    cout<<"|     which is random number[0-100] and alrady chossen.|"<<endl;
    for(int i =0;i<32;i++)cout<<" ";
    cout<<"|     Within seven try."; for(int i =0;i<32;i++)cout<<" ";cout<<"|"<<endl;
    for(int i =0;i<32;i++)cout<<" ";for(int i =0;i<55;i++)cout<<"-";cout<<endl;
    
//    cout << endl;



}

void gussing_number()
{

    system("Color 0D");
    instruction_gussing_number();
    cout<<endl;
    for(int i =0;i<45;i++)cout<<" "; cout<< "ENTER YOUR NAME: ";
    cin.ignore();
    string name ;getline(cin,name);


    srand((unsigned) time(0));
    int secret_number =  rand() % 100;

    for(int i =0;i<45;i++)cout<<" "; cout<< "GUESS THE NUMBER IN SEVEN CHANCE"<<endl;
    cout<<endl;
    int j_{};
    int temp = 0;
    for(int j_ = 1;j_<=7;j_++)
    {
        int ans;
        for(int i =0;i<45;i++)cout<<" "; cout<<j_<<" TIME ENTER YOUR GUESS NUMBER: ";cin>>ans;

        if (ans > secret_number){for(int i =0;i<45;i++)cout<<" "; cout<< "THE NUMBER IS TOO HIGH"<<endl;}
        else if (ans < secret_number)  {for(int i =0;i<45;i++)cout<<" ";  cout<< "THE NUMBER IS TOO LOW"<<endl;}

        else { temp = 1; cout<<endl;for(int i =0;i<45;i++)cout<<" "; cout<<"WINNER WINNER CHICKEN DINNER"<<endl;
        for(int i =0;i<45;i++)cout<<" "; cout<< "CONGURATs!! "<< name<<endl;
        break;}

    }
    if (temp == 0){
        cout<<endl;
   for(int i =0;i<45;i++)cout<<" ";  cout<< "ANSWER IS "<<secret_number<<endl;
   for(int i =0;i<45;i++)cout<<" "; cout<<"You Lost!!"<<endl;}

}

void end_()
{
    system("Color 0A");
    for(int i =0;i<45;i++)cout<<" "; cout<<"GAME OVER"<<endl;
    for(int i =0;i<45;i++)cout<<" ";cout<<"***";



}

void casino_royale()
{
    string playerName;
    int amount; // hold player's balance amount
    int bettingAmount; 
    int guess;
    int dice; // hold computer generated number
    char choice;
 
    srand(time(0)); // "Seed" the random generator

    drawLine(60,'_');
    cout << "\n\n\n\t\tCASINO GAME\n\n\n\n";
    drawLine(60,'_');
 
    cout << "\n\nEnter Your Name : ";
    cin>>playerName;

    cout << "\n\n Enter Deposit amount to play game : $";
    cin >> amount;
    
    do
    {
        system("cls");
        rules();
        cout << "\n\nYour current balance is $ " << amount << "\n";
        
        // Get player's betting amount
        do
        {
        	
            cout <<playerName << " " <<"enter money to bet : $";
            cin >> bettingAmount;
            if(bettingAmount > amount)
                cout << "Your betting amount is more than your current balance\n"
                       <<"\nRe-enter data\n ";
        }while(bettingAmount > amount);
 
        // Get player's numbers
        do
        {
            cout << "Guess your number to bet between 1 to 10 :";
            cin >> guess;
            if(guess <= 0 || guess > 10)
                cout << "Please check the number!! should be between 1 to 10\n"
                    <<"\nRe-enter data\n ";
        }while(guess <= 0 || guess > 10);
 
        dice = rand()%10 + 1; // Will hold the randomly generated integer between 1 and 10
    
        if(dice == guess)
        {
            cout << "\n\nGood Luck!! You won Rs." << bettingAmount * 10;
            amount = amount + bettingAmount * 10;
        }
        else
        {
            cout << "Bad Luck this time !! You lost $ "<< bettingAmount <<"\n";
            amount = amount - bettingAmount;
        }
 
        cout << "\nThe winning number was : " << dice <<"\n";
        cout << "\n"<<playerName<<"You have $ " << amount << "\n";
        if(amount == 0)
        {
            cout << "You have no money to play ";
            break;
        }
        cout << "\n\n-->Do you want to play again (y/n)? ";     
        cin >> choice;
    }while(choice =='Y'|| choice=='y');
    
    cout << "\n\n\n";
    drawLine(70,'=');
    cout << "\n\nThanks for playing game. Your balance amount is $ " << amount << "\n\n";
    drawLine(70,'=');
 
}
void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        cout << symbol;
    cout << "\n" ;
}
 
void rules()
{
    system("cls");
    cout << "\n\n";
    drawLine(80,'-');
    cout << "\t\tRULES OF THE GAME\n";
    drawLine(80,'-');
    cout << "\t1. Choose any number between 1 to 10\n";
    cout << "\t2. If you win you will get 10 times of money you bet\n";
    cout << "\t3. If you bet on wrong number you will lose your betting amount\n\n";
    drawLine(80,'-');
}


int main()
{

    char cho;

    do
    {
    bgin();

    for(int i =0;i<45;i++)cout<<" ";cout<< "1) GUESSING NUMBER. "<<endl;
    for(int i =0;i<45;i++)cout<<" ";cout<< "2) GUESSING WORD."<<endl;
    for(int i =0;i<45;i++)cout<<" ";cout<< "3) CASINO ROYALE."<<endl;
    cout<<endl;
    for(int i =0;i<45;i++)cout<<" ";int p;cout<<"ENTER YOUR CHOICE: ";cin>>p;
    cout<<endl;
    if (p==1){gussing_number();}
    else if(p==2)
    {system("Color 0C");
    int x=0;

    for(int i =0;i<45;i++)cout<<" "; cout<< "Select the number of play (1or2): ";cin>>x;

    if (x==1) {single_player();}

    else if(x==2) {double_player();}
    
    else {for(int i =0;i<45;i++)cout<<" ";cout<<"PLEASE ENTER A VALID CHOISE"<<endl;}}
    else if(p==3){
        system("cls");
        casino_royale();
    }
    else {for(int i =0;i<45;i++)cout<<" ";cout<<"PLEASE ENTER A VALID CHOISE"<<endl;}
    cout<<endl;
    end_();

    cout<<endl;

    

    

    cout<<endl<<endl;

    for(int i =0;i<30;i++)cout<<" ";cout << "-->Do you want to play again (y/n)? ";cin >> cho;system("cls");



        
    }while(cho =='Y'|| cho=='y');

}
