/*
This was a really crappy program, the code is very
amateurly formatted, I am sorry.
Please bare with me I am still learning C++ and C
Anyways, this is battleships in C++! Its like some
random thing I decided to make
*/

#include <iostream>
using namespace std;


// DEVELOPER NOTE: compile using "gcc main.cpp -lstdc++ -o main.exe"
// DEVELOPER NOTE 2: for linux compile using "gcc main.cpp -lstdc++ -o main" and run using "./main"

/*
The human_ships array is the array the
player has for their ships.
They have 5 ships max, can change.
*/
string human_ships[6];

/*
The computer_ships array is the array the
computer has for their ships.
They have 5 ships max, can change.
Should be same as human_ships to be fair.
*/
string computer_ships[6];

/* human_ships_has is the ship choices the player has,
currently 0 before the game starts.
*/
int human_ships_has = 0;

/* computer_ships_has is the ship choices the computer has,
currently 0 before the game starts.
*/
int computer_ships_has = 0;

/*
StartsWith Implementation taken from: https://thispointer.com/c-check-if-a-string-starts-with-an-another-given-string/
*/
bool startsWith(std::string mainStr, std::string toMatch)
{
    // std::string::find returns 0 if toMatch is found at starting
    if(mainStr.find(toMatch) == 0)
        return true;
    else
        return false;
}

/*
endsWith taken and adapted from https://thispointer.com/c-how-to-check-if-a-string-ends-with-an-another-given-string/
*/
bool endsWith(const std::string &mainStr, const std::string &toMatch)
{
    if(mainStr.size() >= toMatch.size() && mainStr.compare(mainStr.size() - toMatch.size(), toMatch.size(), toMatch) == 0)
    {
        return true;
    } else {
        return false;
    }
}

bool computer_choose_ships()
{
    string happyPrompt;
    cout << "Your ships have been chosen! They are: ";
    for(int i = 0; i<5; i++) {
        cout << human_ships[i] << ", ";
    }
    cout << endl;
    cout << "Are you happy with this? [Y/n]: ";
    cin >> happyPrompt;
    cout << endl;
    if (happyPrompt == "n" || happyPrompt == "N")
    {
      cout << "Please restart the game." << endl;
      return 0;
    } else if (happyPrompt == "y" || happyPrompt == "Y") {
      cout << "That is great! Moving on..." << endl;
    } else {
      cout << "Unknown Answer '" << happyPrompt << "'." << endl;
      computer_choose_ships();
    }
    /*
        TODO TOMORROW: Make computer choose ships too.
    */
}

void human_choose_ships()
{
    cout << "Welcome to Battleships v0.0.1!" << endl;
    cout << "Choose your ships, player!" << endl;
    while (human_ships_has != 5)
    {
      ++human_ships_has;
      string coordinates;
      cout << "Choose ship co-ordinates for Ship " << human_ships_has << ": ";
      cin >> coordinates;
      cout << endl;
      if (coordinates.size() > 2)
      {
        cout << "Error! Co-ordinates must only be 2 digits long." << endl;
        --human_ships_has;
      } else {
          if (startsWith(coordinates, "a") || startsWith(coordinates, "b") || startsWith(coordinates, "c") || startsWith(coordinates, "d") || startsWith(coordinates, "e") || startsWith(coordinates, "A") || startsWith(coordinates, "B") || startsWith(coordinates, "C") || startsWith(coordinates, "D") || startsWith(coordinates, "E"))
          {
              if (endsWith(coordinates, "1") || endsWith(coordinates, "2") || endsWith(coordinates, "3") || endsWith(coordinates, "4") || endsWith(coordinates, "5"))
              {
                  // All good! Add it to the array!
                  // WAITING TO IMPLEMENT FUNCTION TO CHECK IF SHIP ALREADY EXISTS, NOT YET THO...
                  human_ships[human_ships_has] = coordinates;
                  cout << "Ship was successfully added to the array!" << endl;
              } else {
                  cout << "Error! Ship Co-Ordinates MUST end with any number between 1 and 5" << endl;
                  --human_ships_has; // RESET SHIPS HAS
              }
          } else {
              cout << "Error! Ship Co-Ordinates MUST start with any letter between A and Z, uppercase or lowercase" << endl;
              --human_ships_has; // RESET SHIPS HAS
          }
      }
    }
}

int main()
{
    human_choose_ships();
    computer_choose_ships();
    return 0;
}
