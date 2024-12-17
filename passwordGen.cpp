#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

string passwordGen(int passLen, string charSet);
int RNG(string charSet);

int main()
{
    ofstream outputFile;
    outputFile.open("passwords.txt");
    //Initializes random number with the current time.
    srand(time(0));
    //Created all possible characters for the password.
    string numSet = "0123456789";
    string lowerLetterSet = "abcdefghijklmnopqrstuvwxyz";
    string upperLetterSet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string symbolSet = "!@#$%^&*()_-+=[]{}\;'.,<>/?";
    //Add them up to make a collection of all possible characters that could be in the password.
    string allSet = numSet + lowerLetterSet + upperLetterSet + symbolSet;

    //Creates a password list.
    vector<string> passwordList;

    //Gets user input on how long they want their password to be.
    string newPass;
    int passwordLength, passOption;
    do{
        cout << "\n Menu: (Pick a corresponding number)\n";
        cout << "1. Generate new password\n" << "2. Show stored passwords\n" << "3.Exit \n";
        cin >> passOption;
        if(passOption == 1)
        {
            cout << "Enter your desired password length." << endl;
            cin >> passwordLength;
            newPass = passwordGen(passwordLength, allSet);
            cout << "\nYour randomized password: " << newPass << endl;
            passwordList.push_back(newPass);
        }
        else if(passOption == 2)
        {
            //Prints out all the passwords in the storage.
            outputFile << " Your Passwords: \n";
            for(int i = 0; i < passwordList.size(); i++)
            {
                outputFile << i+1 << ". " << passwordList[i] << endl;
            }
            cout << "\nSee output file for your passwords." << endl;
        }
        else if(passOption == 3)
        {
            exit(1);
        }
        else
        {
            cerr << "Not an option.";
            exit(1);
        }
    }while(passwordLength != -1);
    

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

