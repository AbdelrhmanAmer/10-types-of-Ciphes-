/******************************************************************************

Author and ID and Group: Abdullah Mohammed Abdullah farg ID: 20210541
Author and ID and Group: Selsabeel Asim Ali Elbagir      ID: 20210714
Author and ID and Group: Abdelrhman Amer Ali,            ID:20211060
Author : Abdelrhman Amer
Course: CS112
Instructor: Doctor Mohamed_Elramly
Assignment: 2 
Taske : 6


this program the implements all the ten
algorithms in task 2. This program allow the user to choose 
the specific cipher


*******************************************************************************/
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <cstring>
#include <cctype>
#pragma warning (disable : 4996) // disables the warning from MVS for using strtok (tokenizer)
#include <map> // key, value order of 1 access time
#include <cmath>
#include <climits>
#include <stdio.h>
#include <ctype.h>
#include <algorithm> // used functions --> (transform() )
using namespace std;

// prototype
void railfence();
void baconian();
void morse();
void XOR();
char shiftChar (char character, int n_shift);
void encryptCaesar ();
void decryptCaesar ();
void Caesar();
void Atbash_cipher();
void simple_substitution_cipher();
void Affine_cipher();
void encrypt_Vignere ();
void Vignere ();
void decryption();

// declareing a constant variables because w'll gonna to use it any some functions.
const char arr1[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
const char arr2[26] = {'Z','Y','X','W','V','U','T','S','R','Q','P','O','N','M','L','K','J','I','H','G','F','E','D','C','B','A'};


int main()
{
int choose=0  ;
while ((choose>=0)&&(choose<10))
 {
     
    cout << "Welcome dear user. \n" << "What would you like to do today? \n";
    cout << "0.Affine .\n"<< "1.Caesar .\n"<< "2.Atbash .\n"<< "3.Vignere .\n"<< "4.baconian .\n"<<"5.simple_substitution .\n"<< "6.Polybius Square .\n"<<"7.morse.\n"<<"8.XOR.\n"<<"9.railfence.\n"<<"10.End .\n";
    cin  >> choose;
    if (choose== 1)
    	Caesar();
    else if (choose==9)
    	railfence();
    else if (choose== 4)
    	baconian();
    else if (choose== 7)
    	morse();
    else if (choose==8)
    	XOR();
    else if (choose == 2)
    	Atbash_cipher();
    else if (choose == 5)
    	simple_substitution_cipher();
    else if (choose == 0)
    	Affine_cipher();
    else if (choose == 3)
    	Vignere ();
    else if (choose == 6)
    	Caesar();
    else
        cout << "thanks";
}
    return 0;
}

void XOR()
{
    int option;
    cout << "Welcome dear user. \n" << "What would you like to do today? \n";
    cout << "1- Cipher a message. \n" << "2- Decipher a message. \n" << "3- Exit \n";
    cin >> option;
    if (option == 3) {
        return;
    }
    else {
        char message[100];
        char key;
        cout << "Please enter the key you'd like to use for encrypting/decrypting. \n";
        cin >> key;
        cin.ignore(256, '\n'); // remaining input characters up to the next newline character
                       // are ignored
        cout << "Please enter the message you'd like to encrypt/decrypt: \n";
        cin.getline(message, 100, '\n');
        int length = strlen(message);

        for (int i = 0; i < length; i++)
        {
            message[i] = message[i] ^ key; // XOR each character with the key
            printf("%c", message[i]);
        }
        cout << endl; // print a new line after the cipher
        //const char* array = message.c_str();
        //int value = stoi(array);
        //printf("%c", message);
        // cout doesn't recognize all of the characters used
            // so we used printf to make all the symbols readable

        for (int i = 0; i < length; i++)
        {
            message[i] = message[i] ^ key; // XOR each character with the key
            cout << hex << message[i];
        }
    }

}


void railfence() {
    int option;
    cout << "Welcome dear user. \n" << "What would you like to do today? \n";
    cout << "1- Cipher a message. \n" << "2- Decipher a message. \n" << "3- Exit \n";
    cin >> option;
    if (option == 1) {
        string message;
        cout << "Please enter what you'd like to cipher: ";
        cin.ignore(256, '\n'); // remaining input characters up to the next newline character
        getline(cin, message);
        int length = message.length();
        char rail[3][length];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < length; j++) {
                rail[i][j] = '\n';
            }
        }
        // to find the direction
        bool dir_down = false;
        int row = 0, col = 0;

        for (int i = 0; i < message.length(); i++) {
            // check the direction of flow
            // reverse the direction if we've just
            // filled the top or bottom rail
            if (row == 0 || row == 2)
                dir_down = !dir_down;

            // fill the corresponding alphabet
            rail[row][col++] = message[i];

            // find the next row using direction flag
            dir_down ? row++ : row--;
        }

        //now we can construct the cipher using the rail matrix
        string result;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < length; j++)
                if (rail[i][j] != '\n')
                    result.push_back(rail[i][j]);

        cout << result;
    }
    else if (option == 2) {
        string message;
        cout << "Please enter what you'd like to decipher: ";
        cin.ignore(256, '\n'); // remaining input characters up to the next newline character
        getline(cin, message);
        int length = message.length();
        // create the matrix to cipher plain text
        // key = rows , length(text) = columns
        char rail[3][message.length()];

        // filling the rail matrix to distinguish filled
        // spaces from blank ones
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < length; j++)
                rail[i][j] = '\n';

        // to find the direction
        bool dir_down;

        int row = 0, col = 0;

        // mark the places with '*'
        for (int i = 0; i < length; i++)
        {
            // check the direction of flow
            if (row == 0)
                dir_down = true;
            if (row == 2)
                dir_down = false;

            // place the marker
            rail[row][col++] = '*';

            // find the next row using direction flag
            dir_down ? row++ : row--;
        }

        // now we can construct the fill the rail matrix
        int index = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < length; j++)
                if (rail[i][j] == '*' && index < length)
                    rail[i][j] = message[index++];


        // now read the matrix in zig-zag manner to construct
        // the resultant text
        string result;

        row = 0, col = 0;
        for (int i = 0; i < length; i++)
        {
            // check the direction of flow
            if (row == 0)
                dir_down = true;
            if (row == 2)
                dir_down = false;

            // place the marker
            if (rail[row][col] != '*')
                result.push_back(rail[row][col++]);

            // find the next row using direction flag
            dir_down ? row++ : row--;
        }
        cout << result;

    }
    else if (option == 3) {
        return;
    }
    else {
        cout << "Invalid option number.";
    }

}


void baconian() {
    string word, token;
    istringstream scin(""); // input string stream, it treats it like cin
    int option;
    bool isValid;
    isValid = false;
    std::map<char, string> cipher{
                {'A', "aaaaa"},                {'B', "aaaab"},                {'C', "aaaba"},                {'D', "aaabb"},
                {'E', "aabaa"},                {'F', "aabab"},                {'G', "aabba"},                {'H', "aabbb"},
                {'I', "abaaa"},                {'J', "abaab"},                {'K', "ababa"},                {'L', "ababb"},
                {'M', "abbaa"},                {'N', "abbab"},                {'O', "abbba"},                {'P', "abbbb"},
                {'Q', "baaaa"},                {'R', "baaab"},                {'S', "baaba"},                {'T', "baabb"},
                {'U', "babaa"},                {'V', "babab"},                {'W', "babba"},                {'X', "babbb"},
                {'Y', "bbaaa"},                {'Z', "bbaab"},
    };
    cout << "What would you like to do today? (Please input the option number)\n";
    cout << "1- Cipher a message\n";
    cout << "2- Decipher a message\n";
    cout << "3- End\n";
    cin >> option;
    while (isValid == false)
    {
        if (option == 1)
        {
            isValid = true;
            cout << "Please enter one word to cipher: \n";
            cin >> word;
            for (char letter : word)
            {
                letter = toupper(letter);
                cout << cipher[letter] << " ";
            }
            return;
        }
        if (option == 2)
        {
            isValid = true;
            cout << "Please enter the code you'd like to decipher (add a space after the last letter).: " << endl;
            for (string code; getline(cin, code, ' '); ) {
            int length = code.length();
                for (int i = 0; i < length; i++)
                {
                    const char* value;
                    value = &code[i];
                    for (char letter = 64; letter < 91; letter++)
                    {
                        if (cipher[letter] == value)
                        {
                            cout << letter;
                            break;
                        }
                    }
                }
            }



            return;
        }
        if (option == 3)
        {
            isValid = true;
            return;
        }
        else
        {
            isValid = false;
            cout << "Please enter a valid option number.\n";
            cin >> option;
        }
    }
    return;
}

void morse() {
    string word, token;
    istringstream scin(""); // input string stream, it treats it like cin
    int option;
    bool isValid;
    isValid = false;
    std::map<char, string> cipher{
                {'A', ".-"},                {'B', "-..."},                {'C', "-.-."},                {'D', "-.."},
                {'E', "."},                {'F', "..-."},                {'G', "--."},                {'H', "...."},
                {'I', ".."},                {'J', ".---"},                {'K', "-.-"},                {'L', ".-.."},
                {'M', "--"},                {'N', "-."},                {'O', "---"},                {'P', ".--."},
                {'Q', "--.-"},                {'R', ".-."},                {'S', "..."},                {'T', "-"},
                {'U', "..-"},                {'V', "...-"},                {'W', ".--"},                {'X', "-..-"},
                {'Y', "-.--"},                {'Z', "--.."},
    };
    cout << "What would you like to do today? (Please input the option number)\n";
    cout << "1- Cipher a message\n";
    cout << "2- Decipher a message\n";
    cout << "3- End\n";
    cin >> option;
    while (isValid == false)
    {
        if (option == 1)
        {
            isValid = true;
            cout << "Please enter one word to cipher: \n";
            cin >> word;
            for (char letter : word)
            {
                letter = toupper(letter);
                cout << cipher[letter] << " ";
            }
            return;
        }
        if (option == 2)
        {
            isValid = true;
            cout << "Please enter the code you'd like to decipher (add a space after the last letter).: " << endl;
            for (string code; getline(cin, code, ' '); ) {
                int length = code.length();
                for (int i = 0; i < length; i++)
                {
                    const char* value;
                    value = &code[i];
                    for (char letter = 64; letter < 91; letter++)
                    {
                        if (cipher[letter] == value)
                        {
                            cout << letter;
                            break;
                        }
                    }
                }
            }



            return;
        }
        if (option == 3)
        {
            isValid = true;
            return;
        }
        else
        {
            isValid = false;
            cout << "Please enter a valid option number.\n";
            cin >> option;
        }
    }
    return;
}
void Caesar () //this function let user to choose between encryption and decryption
{
 	int chosse =1 ;
	while ((chosse == 1 ) ||(chosse == 2))

	{	cout << "Welcome dear user. \n" << "What would you like to do today? \n";
	    cout << "1- Cipher a message. \n" << "2- Decipher a message. \n" << "3- Exit \n";
		cin>>chosse;
		if (chosse == 1)
			encryptCaesar ();
		else if (chosse == 2)
			decryptCaesar ();
		else 
			cout <<" thanks ";
	}    
}
char shiftChar(char character, int n_shift)// this function shift characters to encrypt massedges
{
   
    if ( abs(n_shift)> 26)
         n_shift = n_shift%26;
    if ((n_shift >= 0) &&  (isalpha(character))) 
        {
            if ((islower(character)&&((character+n_shift)>'z'))||(isupper(character)&&((character+n_shift)>'Z')))
                  character -= (26 - n_shift) ;
            else
                  character += n_shift;
        
        }    
                
     if ((n_shift < 0) &&  (isalpha(character)))  
        {
            if ((islower(character)&&((character+n_shift)<'a'))||(isupper(character)&&((character+n_shift)<'A')))
                character += (26 + n_shift) ;
            else    
                 character += n_shift;
        }
  return character;
   
}
void encryptCaesar () // this function encrypt massedges by shift characters 
{
    char message[10000] ;
    int n_shift;
    cout << "enter the text to encrypt it " <<endl;
    char n ;
    cin >>n;
    cin.getline (message,10000,'\n');
    
    //cout << "Note : if you want shife to right enter (+ve) n_shift\n";
    //cout << "       if you want shife to left  enter (-ve) n_shift\n";
    cout <<endl<< "enter the number of shift please : ";
    cin  >> n_shift;
    for (int i = 0 ; i <= strlen(message); i++)
        message[i] = shiftChar(message[i],n_shift);
    cout<<endl<<"the encryption : "<< message<<endl;

    
}
void decryptCaesar () // this function decrypt massedges  
{
    char message[10000] ;
    int n_shift;
    cout << "enter the text to decrypt it " <<endl;
    char n ;
    cin >>n;
    cin.getline (message,10000,'\n');
    //cout << "Note : you must enter the same nuber of shift that used in encryption ";
    cout << "enter the number of shift please : ";
    cin  >> n_shift;
    for (int i = 0 ; i <= strlen(message); i++)
        message[i] = shiftChar(message[i],-n_shift);
    cout<<"\nthe decryption :  "<< message<<endl;
}
void Atbash_cipher()
{
    int nchoice;
    string cipher = "", decipher = "", message = "";

    // show chooses.
    cout << "What do you like to do today" << endl;
    cout << "1 - Cipher a message" << endl;
    cout << "2 - Decipher a message" << endl;
    cout << endl;
    // taking what user picked .
    cout << "please Enter choice: ";
    cin >> nchoice;


    // check if the choice input is not good(invalid)
    while(cin.good() == false)
    {
        // report the problem
        cout << "ERROR, please Enter a valid input" << endl;

        // clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        // set input again
        cout << "please Enter choice: ";
        cin >> nchoice;
    }
    // to clear the the line from any extra spaces.
    if(cin.peek()== '\n')
        cin.ignore();



    // if the user wanted to encrypt.
    if(nchoice == 1)
    {
        // taking the message to cipher it
        cout << "Please Enter your message to cipher it: ";
        getline(cin , message);

        // first for loop to go over every letter and work on it.
        for(int i = 0; i < message.length(); i++)
        {
            // converting all of letter of the message to uppercase .
            message[i] = toupper(message[i]);

            // if (i) is alphabetic, encrypt it.
            if(isalpha(message[i]))
            {
                // second for loop for searching for the letter(i) in the array(arr1).
                for(int j = 0; j < 26; j++)
                {
                    /// and take the position of this letter(i).
                    if(message[i] == arr1[j])
                    {
                        // then replace it with the equivalent to it in array(arr2)
                        cipher += arr2[j];
                    }
                }
            }else
            {
                cipher += message[i];
            }
        }cout << "ciphred message: "<< cipher << endl;

    // if the user want to decrypt.
    }else if (nchoice == 2)
    {
        // taking the message to cipher it
        cout << "Please Enter your message to decipher it: ";
        getline(cin , message);

        // first for loop to go over every letter and work on it.
        for(int i = 0; i < message.length(); i++)
        {
            // converting all of letter of the message to uppercase .
            message[i] = toupper(message[i]);

            // if (i) is alphabetic, deencrypt it.
            if(isalpha(message[i]))
            {
                // to looping in arr1
                for(int j = 0; j < 26; j++)
                {
                    /// if the letter(i) == some position in the array , 
                    if(message[i] == arr2[j])
                    {
                        // then replace it with the equivalent to it in array(arr1)
                        decipher += arr1[j];
                    }
                }
            }else
            {
                decipher += message[i];
            }
        }cout << "deciphred message: "<< decipher << endl;
    }
    
}
void simple_substitution_cipher()
{
    int nchoice;
    string cipher = "", decipher = "", message = "", key = "";
    string basic_alpha = "abcdefghijklmnopqrstuvwxyz";
    string new_alpha =   "abcdefghijklmnopqrstuvwxyz"; // this one will be edited according to the key(will be taken from user)

    // show chooses.
    cout << "What do you like to do today" << endl;
    cout << "1 - Cipher a message" << endl;
    cout << "2 - Decipher a message" << endl;
    cout << endl;

    // taking what user picked .
    cout << "please Enter choice: ";
    cin >> nchoice;

    // check if the choice input is not good(invalid)
    // (defensive input)
    while(cin.good() == false)
    {
        // report the problem
        cout << "ERROR, please Enter a valid input" << endl;

        // clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        // set input again
        cout << "please Enter choice: ";
        cin >> nchoice;
    }

    // check if there is useless spaces and ignore it
    if(cin.peek() == '\n')
        cin.ignore();
    // (take key)
    do
    {
        // ask from user to Enter the key
        cout << "Enter the key please(5 letters):";
        getline(cin, key);
        
    // keep taking the key till the user enter a right one.
    } while (key.length() != 5);

    // (reconstruct alphabetic string)
    // here i will reconstruct my alphabetic string according to the key that was given .
    for(int i = 0; i < 5; i++)
    {
        // first i want to search for every letter in the key
        // and save it's position.
        int pos = 0;
        pos = basic_alpha.find(key[i]);

        if(key[i] == new_alpha[pos])
        {
            // then i will delete them .
            new_alpha.erase(pos, 1);
            // after deleting the letter i need to replace it with space 
            // to keep the process of finding positions going in the right way.
            new_alpha.insert(pos," ");
        }     

    }
    // after deleting the keys letters 
    // we need to delete the spaces that we add.
    for(int k = 0; k < new_alpha.length(); k++)
        {
            if(new_alpha[k] == ' ')
                new_alpha.erase(k, 1);
        }

    // then i will insert the key in the beginning of the new alphabetical string.
    new_alpha.insert(0, key);

    // (encrypt message)
    if (nchoice == 1)
    {
        // taking the message to cipher it
        cout << "Please Enter your message to cipher it: ";
        getline(cin , message);

        // first for loop to go over every letter and work on it.
        for(int i = 0; i < message.length(); i++)
        {
            // converting all of letter of the message to uppercase .
            message[i] = tolower(message[i]);

            // if (i) is alphabetic, encrypt it.
            if(isalpha(message[i]))
            {
                // second for loop for searching for the letter(i) in the string(basic_alpha).
                for(int j = 0; j < 26; j++)
                {
                    /// and take the position of this letter(i).
                    if(message[i] == basic_alpha[j])
                    {
                        // then replace it with the equivalent to it in string(new_alpha)
                        cipher += new_alpha[j];
                    }
                }
            }else
            {
                cipher += message[i];
            }
        }cout << "ciphred message: "<< cipher << endl;

    // (decrypt message)
    }else if (nchoice == 2)
    {
        // taking the message to cipher it
        cout << "Please Enter your message to decipher it: ";
        getline(cin , message);

        // first for loop to go over every letter and work on it.
        for(int i = 0; i < message.length(); i++)
        {
            // converting all of letter of the message to uppercase .
            message[i] = tolower(message[i]);

            // if (i) is alphabetic, deencrypt it.
            if(isalpha(message[i]))
            {
                // to looping in arr1
                for(int j = 0; j < 26; j++)
                {
                    /// if the letter(i) == some position in the string , 
                    if(message[i] == new_alpha[j])
                    {
                        // then replace it with the equivalent to it in string(basic_alpha)
                        decipher += basic_alpha[j];
                    }
                }
            }else
            {
                decipher += message[i];
            }
        }cout << "deciphred message: "<< decipher << endl;
    }
}

void Affine_cipher()
{
    int nchoice;
    int x = 0, y= 0;
    int newposition = 0, old_position = 0;
    int a, b, c;
    string cipher = "", decipher = "", message = "";

    cout << "What do you like to do today" << endl;
    cout << "1 - Cipher a message" << endl;
    cout << "2 - Decipher a message" << endl;
    cout << endl;

    // handling chioce form user
    cout << "please Enter choice: ";
    cin >> nchoice;

    // check if the input is not good(invalid)
    while(cin.good() == false)
    {
        // report the problem
        cout << "ERROR, please Enter a valid input" << endl;

        // clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');

        // set input again
        cout << "please Enter choice: ";
        cin >> nchoice;
    }
    
    if(nchoice == 1)
    {
        // taking the arrbitraries.
        cout << "Enter arbitraries (a, b , c) recommended(5, 8, 21): ";
        cin >> a >> b >> c;

        // to clear the the line from any extra spaces.
            if(cin.peek()== '\n')
                cin.ignore();

        if((a * c) % 26 == 1)
        {
            // taking the message to cipher it
            cout << "Please Enter your message to cipher it: ";
            getline(cin , message);

            // first for loop for going to every letter in the message and work on it.
            for(int i = 0; i < message.length(); i++)
            {
                // check if it is an alphabetic .
                if(isalpha(message[i]))
                {
                    //converting from lowercase to uppercase
                    // because my array is upper case.
                    message[i] = toupper(message[i]);

                    // second for loop , we will use it to transport the letter i
                    for(int j = 0; j < 26; j++)
                    {
                        // find the position of letter i in the array.
                        if(message[i] == arr1[j])
                        {
                            // store this position in variable (x)
                            x = j;
                            // transform it to new position according this equation
                            newposition = ((a * x) + b) % 26;

                            // After taking new position for the letter i ,
                            // we will store it in cipher variable
                            cipher += arr1[newposition];
                        }
                    }
                }else
                {   // if the letter isn't alphabetic, store it(don't encrypt it)
                    cipher += message[i];
                }
            }// show ciphered message
            cout << "Ciphered message: " << cipher << endl;
        }else
        {   // IF the arbitraries is invalid .
            cout << "invalid arbitraries... " <<endl;
        }
    }else if(nchoice == 2)
    {
        // taking the arrbitraries.
        cout << "Enter arbitraries (a, b , c) recommended(5, 8, 21): ";
        cin >> a >> b >> c;

        // if it's valid arbitraries, encrypt the message.
        if((a * c) % 26 == 1)
        {
            // to clear the the line from any extra spaces. 
            if(cin.peek()== '\n')
                cin.ignore();

            // taking the message to cipher it
            cout << "Please Enter your message to decipher it: ";
            getline(cin , message);

            // first for loop for going to every letter in the message and work on it.
            for(int i = 0; i < message.length(); i++)
            {   
                // check if it is an alphabetic
                if(isalpha(message[i]))
                {
                    //converting from lowercase to uppercase
                    // because my array is upper case.
                    message[i] = toupper(message[i]);

                    // second for loop , we will use it to transport the letter i
                    for(int j = 0; j < 26; j++)
                    {
                        // find the position of letter i in the array.
                        if(message[i] == arr1[j])
                        {
                            y = j;
                            old_position = (c * (y - b)) % 26;

                            // check if there is a negative number , to convert it to positive
                            if (old_position < 0)
                                old_position += 26;
                            
                            // After taking old position for the letter i ,
                            // we will store it in decipher variable
                            decipher += arr1[old_position];
                        }
                    }
                }else
                {   // if the letter isn't alphabetic, store it(don't encrypt it)
                    decipher += message[i];
                }
            }
            // this function to transform a uppercase string to lowercase.
            transform(decipher.begin(), decipher.end(), decipher.begin(), ::towlower);

            // then show it to user
            cout << "Deciphered message:  " <<  decipher << endl;
        }else
        {   // if the arbitraries is invalid.
            cout << "invalid arbitraries... " <<endl;
        }
    }
}


void Vignere () //this function let user to choose between encryption and decryption
{
 	int chosse =1 ;
	while ((chosse == 1 ) ||(chosse == 2))

	{	
		cout << "Welcome dear user. \n" << "What would you like to do today? \n";
	    cout << "1- Cipher a message. \n" << "2- Decipher a message. \n" << "3- Exit \n";
		cin>>chosse;
		if (chosse == 1)
			encrypt_Vignere ();
		else if (chosse == 2)
		     decryption();
		else 
			cout <<" thanks ";
			
	cout <<endl;
	} 
}
void encrypt_Vignere ()
{  
  int j = 0, x = 0, z = 0, m =0;
  char original_Massage[80];
  std::cout << "Enter a massage : " << std::endl;
    char n ;
    cin >>n;
  std::cin.getline(original_Massage, 80, '\n');
  int size1 = strlen(original_Massage);
  while (size1 > 80)
  {
    std::cout << "Enter a massage : " << std::endl;
    std::cin.getline(original_Massage, 80, '\n');
    int size1 = strlen(original_Massage);
  }
 // std::cout << "The original massage is : " << original_Massage << std::endl;
 // std::cout << "The size1 = " << size1 << std::endl;
  for (int i = 0; i < size1; i++)
  {
    original_Massage[i] = toupper(original_Massage[i]);
  }
  std::cout << "The upper original massage is : " << original_Massage << std::endl;
  char keyword1[8], keyword2[8];
  std::cout << "Enter a keyword : " << std::endl;
    char o ;
    cin >>o;
  std::cin.getline(keyword1, 8, '\n');
  int size2 = strlen(keyword1);
 // std::cout << "The original keyword is : " << keyword1 << std::endl;
 // std::cout << "The size2.1 = " << size2 << std::endl;
  for (int i = 0; i < size2 ; i++) 
  {
    if (!isspace(keyword1[i])) 
    {
      keyword2[j] = keyword1[i];
      j++;
    }
  }
  keyword2[j] = NULL;
  size2 = strlen(keyword2);
  for (int i = 0; i < size2 ; i++)
  {
    keyword2[i] = toupper(keyword2[i]);
  }
  char repeated_keyword[80];
  //repeated_keyword[j] = NULL;
  //repeated_keyword[x] = NULL;
  //keyword2[j] = NULL;
  //keyword2[x] = NULL;
  for (z ; z < size1; z++)
  {
    if (x == (size2))
    {
      x = 0;
      repeated_keyword[z] = keyword2[x];
      //std::cout << "adham" << std::endl;;
      //std::cout << repeated_keyword[z] << std::endl;
    }
    else if (x != (size2))
    {
      repeated_keyword[z] = keyword2[x];
      //std::cout << "allam" << std::endl;
      //std::cout << repeated_keyword[x] << std::endl;
    }
    x++;
   // std::cout << "size2 = " << size2 << std::endl;
   // std::cout << "x = " << x << std::endl;
  }
  repeated_keyword[z] = NULL;
  //repeated_keyword[x] = NULL;
  //repeated_keyword[j] = NULL;
  int size3 = strlen(repeated_keyword);
 // std::cout << "The used keyword is : " << keyword2 << std::endl;
 // std::cout << "The size2.2 = " << size2 << std::endl;
  //std::cout << "The repeated keyword is : " << repeated_keyword << std::endl;
  //std::cout << "The size3 = " << size3 << std::endl;
  char encrypted_massage[80];
  for (m ; m < size1; m++)
  {
    if ((isspace(original_Massage[m])) || (isdigit(original_Massage[m])))
    {
      encrypted_massage[m] = original_Massage[m];
      continue;
    }
    int sum = original_Massage[m] + repeated_keyword[m];
    int mod = sum % 26;
    int new_letter = 65 + mod;
    //std::cout << "new letter = " << new_letter << std::endl;
    encrypted_massage[m] = new_letter;
    //std::cout << "The first letter in encrypted massage is : " << encrypted_massage[m] << std::endl;
  }
  encrypted_massage[m] = NULL;
  
  std::cout << "The encrypted massage is: " << encrypted_massage << std::endl;
}
void decryption()
{
  int j = 0, x = 0, z = 0, m = 0, new_letter = 0;
  char encrypted_Massage[80] = { '\0' };
  std::cout << "Enter a massage to decrypt : " << std::endl;
  cin >> std::ws;
  std::cin.getline(encrypted_Massage, 80, '\n');
  int size1 = strlen(encrypted_Massage);
  while (size1 > 80)
  {
    std::cout << "Invalid size.Try again : " << std::endl;
    cin >> std::ws;
    std::cin.getline(encrypted_Massage, 80, '\n');
    int size1 = strlen(encrypted_Massage);
  }
  for (int i = 0; i < size1; i++)
  {
    encrypted_Massage[i] = toupper(encrypted_Massage[i]);
  }
  char keyword1[8] = { '\0' }, keyword2[8] = { '\0' };
  std::cout << "Enter a keyword : " << std::endl;
  cin >> std::ws;
  std::cin.getline(keyword1, 8, '\n');
  int size2 = strlen(keyword1);
  for (int i = 0; i < size2; i++)
  {
    if (!isspace(keyword1[i]))
    {
      keyword2[j] = keyword1[i];
      j++;
    }
  }
  size2 = strlen(keyword2);
  for (int i = 0; i < size2; i++)
  {
    keyword2[i] = toupper(keyword2[i]);
  }
  char repeated_keyword[80] = {'\0'};
  for (z; z < size1; z++)
  {
    if (x == (size2))
    {
      x = 0;
      repeated_keyword[z] = keyword2[x];
    }
    else if (x != (size2))
    {
      repeated_keyword[z] = keyword2[x];
    }
    x++;
  }
  int size3 = strlen(repeated_keyword);
  char original_massage[80] = {'\0'};
  int i = 0, b = 0;
  for (m; m < size1; m++)
  {
    if (!isalpha(encrypted_Massage[m]))
    {
      original_massage[m] = encrypted_Massage[m];
      continue;
    }
    int sum = 0;
    int mod = encrypted_Massage[m] - 65;
    for (i = repeated_keyword[m]; i < (repeated_keyword[m] + 90); ++i)
    {
      if (i % 26 == mod)
      {
        b = i;
      }
    }
    int new_letter = b - repeated_keyword[m];
    original_massage[m] = new_letter;
  }
  //std::cout << "The decrypted massage is : " << encrypted_Massage << std::endl;
  //std::cout << "The repeated keyword is  : " << repeated_keyword << std::endl;
  std::cout << "The decrypted massage is  : " << original_massage << std::endl;
}
