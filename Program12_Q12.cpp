#include<iostream>
#include<cstring>//allows use of strlen function
#include<cctype>//allows use of isupper, islower, and isdigit functions
using namespace std;
//function prototypes
bool check_char_amount(char [], int);
bool check_uppercase(char [], int);
bool check_lowercase(char[], int);
bool check_digit(char[], int);
//main function
int main()
{
    const int MAX_CHAR = 20;//constant to set max length of user input cstring
    char password[MAX_CHAR];//cstring to hold user's input
    int length;//int variable to hold length of user's input
    //prompt for user input
    cout << "Please create a password that is at least ix characters long," << endl;
    cout << "contains at least one uppercase and one lowercase letter," << endl;
    cout << "and has at least one numeric digit. Your character limit is 20." << endl << endl;
    cout << "PASSWORD: ";
    cin.get(password, MAX_CHAR);//stores input in password cstring 
    length = strlen(password);//stores length of input in length variable
    cout << endl;
    //bool functions that return false if password doesnt match criteria and print message 
    //stating which criteria hasn't been met
    if (!check_char_amount(password, length))
    {
        cout << "-Your password is too short. Must be at least six characters." << endl;
    }
    if (!check_uppercase(password, length))
    {
        cout << "-Your password has no uppercase letters. Must have at least one" << endl;
        cout << "uppercase letter." << endl;
    }
    if (!check_lowercase(password, length))
    {
        cout << "-Your password has no lowercase letters. Must have at least one" << endl;
        cout << "lowercase letter." << endl;
    }
    if (!check_digit(password, length))
    {
        cout << "-Your password has no digits. Must have at least one digit" << endl;
    }
    //if no bool functions return false, tell user their password is valid
    else
    {
        cout << "Valid password!" << endl;
    }
    cout << endl;
    return 0;
}
//bool function to check if password is long enough
bool check_char_amount(char pass[], int len)
{
    const int MIN_CHAR = 6;//constant to store min length of user input
    if(len >= MIN_CHAR)
    {
        return true;
    }
    return false;
}
//bool function to check if password has any uppercase letters
bool check_uppercase(char pass[], int len)
{
    for(int i = 0; i < len; i++)
    {
        if(isupper(pass[i]))
        {
            return true;
        }
    }
    return false;
}
//bool function to check if password has any lowercase letters
bool check_lowercase(char pass[], int len)
{
    for(int i = 0; i < len; i++)
    {
        if(islower(pass[i]))
        {
            return true;
        }
    }
    return false;
}
//bool function to check if password has any digits
bool check_digit(char pass[], int len)
{
    for(int i = 0; i < len; i++)
    {
        if(isdigit(pass[i]))
        {
            return true;
        }
    }
    return false;
}