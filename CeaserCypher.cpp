#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

//--------------Encryption----------------------//
string alphabet = "abcdefghijklmnopqrstuvwxyz";
//Encryption using array
string ceaserCypherLookUp(int key, string s) {
    string encryptedMessage = "";
    for (char c : s) {
        if (isalpha(c)) {
            int pos = alphabet.find(c);
            if (pos != string::npos) {
                int newPos = (pos + key) % 26;
                encryptedMessage += alphabet[newPos];
            }
        } else{encryptedMessage += c;} //In case user entered a non alpha char
    }
    return encryptedMessage;
}
// Encryption using Ascii value and math
string ceaserCypher(int key, string s) {
    string newMessage = "";
    for (int i = 0; i < s.length(); i++) {
        if (isalpha(s[i])) {
            newMessage += char(int(s[i] + key - 97) % 26 + 97);
        }
    }
    return newMessage;
}
//Encryption using HashMap
string ceaserCypherHash(int key, string s) {
    string shiftedMessage = "";
    unordered_map charToIndex = unordered_map<char, int>();
    unordered_map indexToChar = unordered_map<int, char>();
    //Populate hash map a = 0, b = 1....
    for (int i = 0; i < 26; i++) {
        char c = 'a' + i;
        charToIndex[c] = i;
        indexToChar[i] = c;
    }
    //Actual shifting
    for (char c : s) {
        if (isalpha(c)) {
            int pos = charToIndex[c];
            int newPos = (pos + key) % 26;
            char newChar = indexToChar[newPos];
            shiftedMessage += newChar;
        } else{shiftedMessage += c;}
    }
    return shiftedMessage;
}
//--------- Decryption-----------//
//Decryption function using Key
string ceaserCypherSolve(int key, string s) {
    string decryptedMessage = "";
    for (char c : s) {
        if (isalpha(c)) {
            int pos = alphabet.find(c);
            if (pos != string::npos) {
                int newPos = ((pos - key) % 26 + 26) % 26;
                decryptedMessage += alphabet[newPos];
            }
        } else{decryptedMessage += c;} //In case user entered a non alpha char
    }
    return decryptedMessage;
}

//Brute force added finally 
void ceaserCypherBruteForce(string encrypted) {
    cout << "\nBrute Force - All 26 Keys:" << endl;
    for (int key = 1; key < 26; key++) {
        string decrypted = ceaserCypherSolve(key, encrypted);
        cout << "Key " << key << ": " << decrypted << endl;
    }
}

//--------------Main---------------//
int main() {
    string message, input;
    int key;

    // General Input from user
    cout << "What would you like your key to be?(1-26)" << endl;
    cin >> key;
    cin.ignore();
    cout << "Enter the  string you would like to encrypt" << endl;
    getline(cin, message);

    for (char& x : message) {x = tolower(x);} //Make message lowercase before we pass to function

    // 3 different versions to encrypt using ceaser cypher
    //Use Array
    cout << "Using Array" << endl;
    string encryptedMessage = ceaserCypherLookUp(key,message);
    cout << encryptedMessage << endl;

    //Use Ascii value and math
    cout << "Using Ascii value & Math" << endl;
    string newMessage = ceaserCypher(key, message);
    cout << newMessage << endl;

    //Use HashMap
    cout << "Using Hash Map" << endl;
    string shiftedMessage = ceaserCypherHash(key, message);
    cout << shiftedMessage << endl;

    cout << "Would you like to decypher?(Enter: Yes or No)"<< endl;
    cin >> input;
    for (char x : input) {x = tolower(x);}
    if (input[0] == 'y') {
        cout << "Decryption using key" << endl;
        string decryptedMessage = ceaserCypherSolve(key,encryptedMessage);
        cout << decryptedMessage << endl;
    
        cout << "\nTry brute force? (y/n): ";
        string bruteInput;
        cin >> bruteInput;
        if (tolower(bruteInput[0]) == 'y') {
            ceaserCypherBruteForce(encryptedMessage);
        }
    }
}