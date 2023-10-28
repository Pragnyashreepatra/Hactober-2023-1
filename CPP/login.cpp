#include<iostream>
#include<fstream>
using namespace std;

void store_username(string username) {
    ofstream create(username);
}

void store_password(string username) {
    ofstream pass;
    cout << "Enter new password" << endl;
    string password;
    cin >> password;
    pass.open(username);
    pass << password;
}

bool get_id(string username) {
    ifstream read;
    read.open(username + ".txt");
    if(!read) {
        return false;
    }
    else {
        return true;
    }
}

bool check_pass(string password, string username) {
    ifstream check;
    string pass;
    check.open(username + ".txt");
    getline(cin, pass);
    if(pass == password) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    cout << "Enter y for login and n for signup" << endl;
    char choose;
    cin >> choose;
    if(choose == 'n') {
        cout << "Please enter new username" << endl;
        string user;
        cin >> user;
        string username = user + ".txt";
        store_username(username);
        store_password(username);
        cout << "You are succesfully registered" << endl;
    }
    if(choose == 'y') {
        cout << "Enter username" << endl;
        string user_log;
        cin >> user_log;
        bool is_exist = get_id(user_log);
        if(is_exist == false) {
            cout << "Username does not exist";
        }
        else {
            cout << "Enter password" << endl;
            string pass;
            cin >> pass;
            bool correct = check_pass(pass, user_log);
            if(correct == true) {
                cout << "You are logged in succesfully";
            }
            else {
                cout << "Wrong password";
            }
        }
    }
}