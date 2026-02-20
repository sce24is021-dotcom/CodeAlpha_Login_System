#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void registerUser() {
    string username, password;

    cout << "\n--- Registration ---" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration Successful!\n";
}

void loginUser() {
    string username, password;
    string storedUsername, storedPassword;
    bool found = false;

    cout << "\n--- Login ---" << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    ifstream file("users.txt");

    while (file >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
        cout << "Login Successful!\n";
    else
        cout << "Invalid Username or Password!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== Login System =====" << endl;
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
