#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>

using namespace std;

// Function to generate a random password
string generatePassword(int length) {
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*/";
    string password;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, chars.size() - 1);
    
    for (int i = 0; i < length; ++i) {   
        password += chars[dis(gen)];
    }
    return password;
}

// Function to save password to file
void savePassword(const string& service, const string& username, const string& password) {
    ofstream file("passwords.txt", ios::app);
    if (file.is_open()) {
        file << "Service: " << service << "\nUsername: " << username << "\nPassword: " << password << "\n\n";
        file.close();
        cout << "Password saved successfully!\n";
    } else {
        cout << "Error opening file.\n";
    }
}

// Function to view saved passwords
void viewPasswords() {
    ifstream file("passwords.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No saved passwords or file not found.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nPassword Generator and Saver\n";
        cout << "1. Generate Password\n";
        cout << "2. Save Password\n";
        cout << "3. View Saved Passwords\n";
        cout << "4. Exit\n";
        cout << "Please enter choice: ";
        cin >> choice;
        
        if (choice == 1) {
            int length;
            cout << "Enter password length: ";
            cin >> length;
            string pwd = generatePassword(length);
            cout << "Generated Password: " << pwd << endl;
        } else if (choice == 2) {
            string service, username, password;
            cout << "Enter service name: ";
            cin >> service;
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password (or generate one first): ";
            cin >> password;
            savePassword(service, username, password);
        } else if (choice == 3) {
            viewPasswords();
        }
    } while (choice != 4);
    
    return 0;
}


