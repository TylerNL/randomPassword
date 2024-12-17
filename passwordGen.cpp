#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

string passwordGen(int passLen, string charSet);
int RNG(string charSet);

int main()
{
    //Initializes random number with the current time.
    srand(time(0));
    //Created all possible characters for the password.
    string numSet = "0123456789";
    string lowerLetterSet = "abcdefghijklmnopqrstuvwxyz";
    string upperLetterSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string symbolSet = "!@#$%^&*()_-+=[]{}\;'.,<>/?";
    //Add them up to make a collection of all possible characters that could be in the password.
    string allSet = numSet + lowerLetterSet + upperLetterSet + symbolSet;

    //Gets user input on how long they want their password to be.
    int passwordLength;
    cout << "Enter your desired password length\n";
    cin >> passwordLength;
    string newPass = passwordGen(passwordLength, allSet);
    //Prints out randomized password.
    cout << "Your randomized password: " << newPass << endl;

    return 0;
}
//Gets a random number based on the length of the character set.
int RNG(string charSet)
{
    //Gets a random index for the character set.
    int randomNum = rand() % charSet.length();

    return randomNum;
}
//Takes in the password length and the character set.
//Will return the randomized password.
string passwordGen(int passLen, string charSet)
{
    string randomPass = "";
    int random;
    //Goes through the loop for however long the password length is.
    for(int i = 0; i < passLen; i++)
    {
        //Gets a random index number for the char set and adds it to the password.
        random = RNG(charSet);
        randomPass += charSet[random];
    }
    return randomPass;
}

