#include <iostream>
#include <unordered_map>
using namespace std;
 
// ROT13 cipher map (shifts by 13 positions)
unordered_map<char, char> rotalpha = {
    {'A', 'N'}, {'B', 'O'}, {'C', 'P'}, {'D', 'Q'},
    {'E', 'R'}, {'F', 'S'}, {'G', 'T'}, {'H', 'U'},
    {'I', 'V'}, {'J', 'W'}, {'K', 'X'}, {'L', 'Y'},
    {'M', 'Z'}, {'N', 'A'}, {'O', 'B'}, {'P', 'C'},
    {'Q', 'D'}, {'R', 'E'}, {'S', 'F'}, {'T', 'G'},
    {'U', 'H'}, {'V', 'I'}, {'W', 'J'}, {'X', 'K'},
    {'Y', 'L'}, {'Z', 'M'}, {'a', 'n'}, {'b', 'o'},
    {'c', 'p'}, {'d', 'q'}, {'e', 'r'}, {'f', 's'},
    {'g', 't'}, {'h', 'u'}, {'i', 'v'}, {'j', 'w'},
    {'k', 'x'}, {'l', 'y'}, {'m', 'z'}, {'n', 'a'},
    {'o', 'b'}, {'p', 'c'}, {'q', 'd'}, {'r', 'e'},
    {'s', 'f'}, {'t', 'g'}, {'u', 'h'}, {'v', 'i'},
    {'w', 'j'}, {'x', 'k'}, {'y', 'l'}, {'z', 'm'}
};
 
// Encryption function
string encrypt(string text) {
    string encrypted = "";
    for(char c : text) {
        if(rotalpha.find(c) != rotalpha.end()) {
            encrypted += rotalpha[c];
        } else {
            encrypted += c;  // Keep non-alpha characters
        }
    }
    return encrypted;
}
 
// Decryption function
string decrypt(string text) {
    string decrypted = "";
    for(char c : text) {
        if(rotalpha.find(c) != rotalpha.end()) {
            decrypted += rotalpha[c];
        } else {
            decrypted += c;  // Keep non-alpha characters
        }
    }
    return decrypted;
}
 
int main() {
    string text;
    int choice;
 
    cout << "=== ROT13 Cipher ===" << endl;
    cout << "1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cout << "Enter choice (1 or 2): ";
    cin >> choice;
    cin.ignore();  // Clear input buffer
 
    cout << "Enter text: ";
    getline(cin, text);
 
    if(choice == 1) {
        cout << "Encrypted: " << encrypt(text) << endl;
    } else if(choice == 2) {
        cout << "Decrypted: " << decrypt(text) << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }
 
    return 0;
}
