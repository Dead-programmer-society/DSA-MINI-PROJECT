#include "bits/stdc++.h"
using namespace std;


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

    for(int i=0;i<106;i++)cout<<" ";cout<<"BY-SATYAM JHA"<<endl;
    return;


}

string choose_word(int  Difficulty_Level)
{

    if ( Difficulty_Level == 1)
    {
        vector<string> words{"that","not","this","but","his","they","her","she","will","one","would",
                             "there","their","monkey","snow","time","person","year","thing","others",
                             "world","life","hand","part","child","woman","place","work","week","case",
                             "point","company","number","group","fact","Verb","have","make","know",
                             "take","come","think","look","want","give","use","find","work","seem",
                             "feel","try","good","new","first","last","long","great","little",
                             "other","old","right","big","high","small","large","next","early",
                             "young","few","bad","same","able","for","with","from",
                             "about","over","after"};


        srand((unsigned) time(0));
        int index =  rand()%77;

        return words[index];


    }
    else if( Difficulty_Level == 2)
    {
        vector<string> words{"rainbow","government","problem","different","important",
                             "prepositions","difficulty","determine","wikipedia","candidates","mathematics",
                             "admission","computer","alrady","public"};

        srand((unsigned) time(0));
        int index =  rand() %13;

        return words[index];
    }

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
      for(int i =0;i<45;i++)cout<<" ";  cout<<p1name<<" Your final score is "<<pp1<<"."<<endl;

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
    for(int i =0;i<45;i++)cout<<" "; cout<< "GUSSE THE  JUMBLLE WORDS: "<<endl;
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

        if(i == 0){for(int i =0;i<45;i++)cout<<" "; cout<< "*LEVEL-1"<<endl;}
        if(i==4) {for(int i =0;i<45;i++)cout<<" "; cout<<"*LEVEL-2"<<endl;}



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
            if(pp1> 6)
            {
               for(int i =0;i<45;i++)cout<<" "; cout <<"congratulations"<<p1name<<"YOU WIN"<<endl;
               for(int i =0;i<45;i++)cout<<" "; cout<<"YOUR SCORE "<<pp1<<endl;
                if(pp1!=8)
                {
                    for(int i =0;i<45;i++)cout<<" "; cout<<"CORRECT ANSWER ARE: ";
                    for(auto i:correct)cout<<i<<" ";

                }

            }
            else if(pp1<=6 &&  pp1 >3)
            {
                for(int i =0;i<45;i++)cout<<" "; cout<<"GOOD YOU PLAY WELL "<<"YOUR SCORE "<<pp1<<endl;
                for(int i =0;i<45;i++)cout<<" "; cout<<"CORRECT ANSWER ARE: ";for(auto i:correct)cout<<i<<" ";

            }
            else { for(int i =0;i<45;i++)cout<<" "; cout<<"YOUR SCORE  "<<pp1<<endl;
                   for(int i =0;i<45;i++)cout<<" "; cout<< "BETTER LUCK NEXT TIME........."<<endl;
            for(int i =0;i<45;i++)cout<<" ";cout<<"CORRECT ANSWER ARE: ";for(auto i:correct){cout<<i<<" ";}
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
        cin.ignore();
        getline(cin,p2name);
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

        if(i == 0) {for(int i =0;i<45;i++)cout<<" ";cout<< "*LEVEL-1"<<endl;}
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
    cout<<"|     To 'WIN' this game player have to gusse a number |"<<endl;
    for(int i =0;i<32;i++)cout<<" ";
    cout<<"|     which is random number[0-100] and alrady chossen.|"<<endl;
    for(int i =0;i<32;i++)cout<<" ";
    cout<<"|     Within seven try."; for(int i =0;i<32;i++)cout<<" ";cout<<"|"<<endl;
    for(int i =0;i<32;i++)cout<<" ";for(int i =0;i<55;i++)cout<<"-";cout<<endl;




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

    for(int i =0;i<45;i++)cout<<" "; cout<< "GUSSE THE NUMBER IN SEVEN CHANCE"<<endl;
    cout<<endl;
    for(int i = 1;i<=7;i++)
    {
        int ans;
        for(int i =0;i<45;i++)cout<<" "; cout<<i<<" TIME ENTER YOUR GUSE NUMBER: ";cin>>ans;

        if (ans > secret_number){for(int i =0;i<45;i++)cout<<" "; cout<< "THE NUMBER IS TOO HIGH"<<endl;}
        else if (ans < secret_number)  {for(int i =0;i<45;i++)cout<<" ";  cout<< "THE NUMBER IS TOO LOW"<<endl;}
        else {for(int i =0;i<45;i++)cout<<" "; cout<<"WINNER WINNER CHICKEN DINNER"<<endl;
        for(int i =0;i<45;i++)cout<<" "; cout<< "CONGURATs!! "<< name<<endl;
        break;}

    }
   for(int i =0;i<45;i++)cout<<" ";  cout<< "ANSWER IS "<<secret_number<<endl;

}

void end_()
{
    system("Color 0A");
    for(int i =0;i<45;i++)cout<<" "; cout<<"GAME OVER"<<endl;
    for(int i =0;i<40;i++)cout<<" ";cout<<"*******";



}

int main()
{
    bgin();

    for(int i =0;i<45;i++)cout<<" ";cout<< "1) GUSSING NUMBER. "<<endl;
    for(int i =0;i<45;i++)cout<<" ";cout<< "2) GUSSING WORD."<<endl;
    cout<<endl;
    for(int i =0;i<45;i++)cout<<" ";int p;cout<<"ENTER YOUR CHOICE: ";cin>>p;
    cout<<endl;
    if (p==1){gussing_number();}
    else if(p==2)


   {system("Color 0C");
    int x=0;

    for(int i =0;i<45;i++)cout<<" "; cout<< "select the number of play (1or2): ";cin>>x;

    if (x==1) {single_player();}

    else if(x==2) {double_player();}

    else {for(int i =0;i<45;i++)cout<<" ";cout<<"PLEASE ENTER A VALID CHOISE"<<endl;}}
    else {for(int i =0;i<45;i++)cout<<" ";cout<<"PLEASE ENTER A VALID CHOISE"<<endl;}
    cout<<endl;
    end_();

}