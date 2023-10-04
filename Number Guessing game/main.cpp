#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void printing(string x, int num)
     {

          for (int i = 0; i<num; i++)
          {
               cout<<x;
          }
     }
 int guessing ()
 {
      int guess;
      cout<<endl;
     cout<<"Guess the number: ";
     cin>>guess;
     cout<<endl;
     return guess;
 }
 void screen_print()
 {
      printing("-", 40);
     cout<< "Welcome to the Number Guessing Game.";
     printing("-", 40);
     cout<<endl<<endl<<endl;
     printing("-", 20);
     cout<<"The Game's Rules: ";
     printing("-", 20);
     cout<<endl;
     cout<<"- You have to guess a number between 1 and 100."<<"\n";
     cout<<"- You choose difficulty of your game based on it a number of guesses is estimated."<<"\n";
     cout<<"- Feedback is given after every guess. "<<"\n";
     cout<<"- If your guess is correct you win. If you run out of guesses you lose."<<"\n";
     cout<<endl<<endl;
 }

int main()
{
     bool again = true;
     while(again)
     {
     screen_print();
     bool ready ;
     printing("-",20);
     cout<<"Are you ready to start? (Yes (type 1) / No (type 0))";
     printing("-", 20);
     cout<<endl;
     bool invalid = true;
     int response;
     int diff;
     while (invalid)
     {
     invalid = false;
     cin>> response;
     if (response == 1)
     {
          ready = true;
     }
     else if (response == 0)
     {
          ready = false;
          cout<<"-------->Whenever you are ready."<<endl;
          again = false;
     }
     else
     {
          cout<<"Invalid input. Please type 1 for yes and 0 for no."<<endl;
          invalid = true;
     }

     }
     if (response == 1)
     {cout<<endl<<endl;
     printing("-", 20);
     bool not_valid = true;
     while (not_valid)
     {
     cout << "Choose difficulty (Easy (type 0), Moderate (type 1), Hard (type 2)).";
     printing("-", 20);
     cout<<endl;
     cin>> diff;
     if (diff ==0 || diff==1 || diff ==2)
          {
               not_valid = false;
          }
     }
     int num_guesses;
     if (diff == 0)
     {
          num_guesses = 10;
     }
     else if (diff == 1)
     {
          num_guesses = 7;
     }
     else
     {
          num_guesses = 5;
     }
     printing("-", 10);
     cout<<"You have "<<num_guesses<<" guesses.";
     printing("-", 10);
     cout<<endl;
     int random;
     int guess;
     int num_guessed = 1;
     srand(time(NULL));
     random = 1+ (rand()% 100);
     int already_guessed[num_guesses] = {0};
     int index = 0;
     while (num_guessed <= num_guesses)
     {
     bool exists = false;
     guess = guessing();
     for(int i =0; i<sizeof(already_guessed)/sizeof(already_guessed[0]);i++)
     {
          if (already_guessed[i] == guess)
          {
               exists = true;

          }
     }
     if (exists == true)
     {
          cout<<"---> Already guessed that number. Enter another number."<<endl;
          continue;
     }
     else
     {
          already_guessed[index] = guess;
          index++;
     }

     if (guess == random)
     {
          cout<<"---> Correct. You win!"<<endl;
          break;
     }
     else if (num_guessed == num_guesses)
          {
               cout<<"---> Sorry ran out of guesses. You lost!"<<endl;
               cout <<"-----------> Correct answer is: "<<random<<endl;
               break;
          }
     else if (guess < random && random-guess <10)
     {
          cout<<"---> Low try a slightly higher number."<<endl;
     }
     else if (guess < random && random-guess >30)
     {
          cout<<"---> Too low try a higher number."<<endl;
     }
     else if (guess < random )
     {
          cout<<"---> Try a higher number."<<endl;
     }
     else if (guess > random && guess-random <10)
     {
          cout<<"---> High try a slightly lower number."<<endl;
     }
     else if (guess > random && guess-random >30)
     {
          cout<<"---> Too high try a lower number."<<endl;
     }
     else if( guess > random)
     {
          cout<<"---> Try a lower number."<<endl;
     }
     num_guessed += 1;
     }

     }
     int play_again;
     cout<<endl;
     cout<<"Do you want to play again? (Yes(type 1)/ No (Type 0))"<<"\t";
     cin>> play_again;
     if (play_again == 1)
     {
          system("cls");
     }
     else if (play_again == 0)
     {
          cout<<endl;
          printing("-", 50);
          cout<< ">Good bye!<";
          printing("-", 50);
          cout<<endl;
          again = false;
     }

}return 0;}
