#include <iostream>
#include <string>
#include <ctime>
#include <cctype>
#include <conio.h>
#include <fstream>

const int MAX_ROWS = 1000;
const int MAX_COLS = 5;
const int MAX_ROWS_MESSAGE = 1000;
const int MAX_COLS_MESSAGE = 3;
using namespace std;

void home(char &);

void signupPage(string &, string &, string &, string &, string &, string &);

void usernameChecker(string &);

void passwordChecker(string &, string &);

void saveToFile(string [], int, string);

void dataBaseSearch(string, string, string &, string &, string &, string &, string &);

bool usernameSearch(string, string);

void editUsername(string, string, string, string &);

void editPassword(string, string, string &);

void editFirstname(string, string, string &);

void editLastname(string, string, string &);

void deleteAccount(string, string);

void dataMessageSearch(string, string);

class Signup {
public:
    Signup(string &username,
           string &password,
           string &rePassword,
           string &firstname,
           string &lastname,
           string &id)
            : username(username), password(password), rePassword(rePassword),
              firstname(firstname), lastname(lastname), id(id) {}

    static void successful() {
        cout << "Smile messenger \nWelcome! \nYou Are Signed Up!" << endl;
    }

    string username;
    string password;
    string rePassword;
    string firstname;
    string lastname;
    string id;
};

int main() {
    system("color F0");
    n:
    system("cls");
    char ch;
    home(ch);
    while (true) {
        if (ch == '1') {
            system("cls");
            string username, password, rePassword, firstname, lastname, id;
            signupPage(username, password, rePassword, firstname, lastname, id);
            usernameChecker(username);
            passwordChecker(password, rePassword);
            Signup user(username, password, rePassword, firstname, lastname, id);
            string str[5] = {username, password, firstname, lastname, id};
            string filename = "DATA_BASE.txt";
            saveToFile(str, 5, filename);
            system("cls");
            Signup::successful();
            cout << "Your ID is: " << user.id << endl;
            cout << endl << "Press enter to back [home]";
            getch();
            system("cls");
            home(ch);
        } else if (ch == '2') {
            system("cls");
            string username, password, u = "", p = "", f = "", l = "", id = "";
            string filename = "DATA_BASE.txt";
            while (true) {
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                if (usernameSearch(username, filename)) {
                    dataBaseSearch(username, filename, u, p, f, l, id);
                    if (password == p) {
                        system("cls");
                        cout << "You are login was successful!" << endl;
                        Signup user(u, p, p, f, l, id);
                        m:
                        cout << "[1] inbox" << endl;
                        cout << "[2] sent" << endl;
                        cout << "[3] edit" << endl;
                        cout << "[4] delete account" << endl;
                        cout << "[5] exit" << endl;
                        char ch;
                        cin >> ch;


                        if (ch == '2') {
                            sor:
                            system("cls");
                            string username, filename = "DATA_BASE.txt";
                            cout << "The username that you want to send message: ";
                            cin >> username;
                            if (user.username == username) {
                                system("cls");
                                cout << "This username is same with your username!" << endl;
                                cout << "Press enter to back [home]";
                                getch();
                                system("cls");
                                goto m;
                            }
                            while (true) {
                                if (usernameSearch(username, filename)) {
                                    cout << "Your message to " << username << ": ";
                                    string message;
                                    cin >> message;
                                    string arr[3] = {user.username, username, message};
                                    string filename = "MESSAGE.txt";
                                    saveToFile(arr, 3, filename);
                                    system("cls");
                                    cout << "Your message succefully sent." << endl;
                                    cout << "Press enter to back [home]";
                                    getch();
                                    system("cls");
                                    break;
                                } else {
                                    system("cls");
                                    cout << "This username not found!" << endl;
                                    cout << "Do you want to continue? [y/n]" << endl;
                                    char e;
                                    cin >> e;
                                    if (e == 'y') {
                                        system("cls");
                                        goto sor;
                                    } else if (e == 'n') {
                                        system("cls");
                                        goto m;
                                    }
                                }
                            }
                            goto m;
                            system("cls");
                        }


                        if (ch == '1') {
                            system("cls");
                            string filename = "MESSAGE.txt";
                            dataMessageSearch(user.username, filename);
                            cout << "Press enter to back [home]";
                            getch();
                            system("cls");
                            goto m;
                        }


                        if (ch == '4') {
                            string p;
                            bool flag = false;
                            while (true) {
                                system("cls");
                                if (flag)
                                    cout << "Password doesn't match!" << endl << "Try again!" << endl;
                                cout << "Enter password: ";
                                cin >> p;
                                flag = true;
                                if (p == user.password)
                                    break;
                            }
                            system("cls");
                            cout << "Do you want to continue? [y/n]" << endl;
                            char ch;
                            cin >> ch;
                            if (ch == 'n') {
                                system("cls");
                                goto m;
                            }
                            if (ch == 'y') {
                                system("cls");
                                string filename = "DATA_BASE.txt";
                                deleteAccount(user.username, filename);
                                system("cls");
                                cout << "Your account has been successfully deleted";
                                cout << endl << "Press enter to back [home]";
                                getch();
                                goto n;
                            }
                        }
                        if (ch == '5') {
                            system("cls");
                            goto n;
                        }
                        if (ch == '3') {
                            system("cls");
                            cout << "[1] Edit Username" << endl;
                            cout << "[2] Edit Password" << endl;
                            cout << "[3] Edit Firstname" << endl;
                            cout << "[4] Edit Lastname" << endl;
                            char ch;
                            cin >> ch;
                            if (ch == '1') {
                                system("cls");
                                string u;
                                bool flag = false;
                                cout << "New username: ";
                                cin >> u;
                                while (true) {
                                    if (u == user.username) {
                                        system("cls");
                                        cout << "This username is similar with previous one." << endl;
                                        cout << "New username: ";
                                        cin >> u;
                                    }
                                    if (u != user.username) {
                                        system("cls");
                                        usernameChecker(u);
                                        flag = true;
                                    }
                                    if (flag)
                                        break;
                                }
                                string filename_Data = "DATA_BASE.txt";
                                string filename_Message = "MESSAGE.txt";
                                editUsername(user.username, filename_Data, filename_Message, u);
                                system("cls");
                                cout << "Your username successfully changed!" << endl;
                                user.username = u;
                                cout << "Press Enter to back [Menu]";
                                getch();
                                system("cls");
                                goto m;
                            }
                            if (ch == '2') {
                                system("cls");
                                string s;
                                while (true) {
                                    cout << "Older password:";
                                    cin >> s;
                                    if (s == user.password)
                                        break;
                                    else {
                                        system("cls");
                                        cout << "Password doesn't match." << endl;
                                    }
                                }
                                string u1, u2;
                                cout << "New Password: ";
                                cin >> u1;
                                cout << "Re-Enter Password: ";
                                cin >> u2;
                                passwordChecker(u1, u2);
                                while (true) {
                                    if (u1 == user.password) {
                                        system("cls");
                                        cout << "This password is similar with previous one." << endl;
                                        cout << "New Password: ";
                                        cin >> u1;
                                        cout << "Re-Enter Password: ";
                                        cin >> u2;
                                        passwordChecker(u1, u2);
                                    } else break;
                                }
                                string filename = "DATA_BASE.txt";
                                editPassword(user.username, filename, u1);
                                system("cls");
                                cout << "Your password successfully changed!" << endl;
                                user.password = u1;
                                user.rePassword = u1;
                                cout << "Press Enter to back [Menu]";
                                getch();
                                system("cls");
                                goto m;
                            }
                            if (ch == '3') {
                                system("cls");
                                string u;
                                cout << "Firstname: ";
                                cin >> u;
                                while (true) {
                                    if (u == user.firstname) {
                                        system("cls");
                                        cout << "This firstname is similar with previous one." << endl;
                                        cout << "Firstname: ";
                                        cin >> u;
                                    } else break;
                                }
                                string filename = "DATA_BASE.txt";
                                editFirstname(user.username, filename, u);
                                system("cls");
                                cout << "Your firstname successfully changed!" << endl;
                                user.firstname = u;
                                cout << "Press Enter to back [Menu]";
                                getch();
                                system("cls");
                                goto m;
                            }
                            if (ch == '4') {
                                system("cls");
                                string u;
                                cout << "Lastname: ";
                                cin >> u;
                                while (true) {
                                    if (u == user.lastname) {
                                        system("cls");
                                        cout << "This lastname is similar with previous one." << endl;
                                        cout << "Lastname: ";
                                        cin >> u;
                                    } else break;
                                }
                                string filename = "DATA_BASE.txt";
                                editLastname(user.username, filename, u);
                                system("cls");
                                cout << "Your firstname successfully changed!" << endl;
                                user.lastname = u;
                                cout << "Press Enter to back [Menu]";
                                getch();
                                system("cls");
                                goto m;
                            }
                        }
                    } else {
                        system("cls");
                        cout << "Password doesn't match." << endl;
                    }
                } else {
                    system("cls");
                    cout << "This username not found" << endl;
                }
            }
        } else if (ch == '3')
            return 0;
    }
}

void home(char &ch) {
    cout << "Smile Messenger" << endl;
    cout << "[1] Signup" << endl;
    cout << "[2] Login" << endl;
    cout << "[3] Exit" << endl;
    cin >> ch;
}

void
signupPage(string &username, string &password, string &rePassword, string &firstname, string &lastname,
           string &id) {
    cout << "You can use a-z,0-9 and underscores. Minimum length is 5 characters." << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "Re-Enter Password: ";
    cin >> rePassword;
    cout << "Firstname: ";
    cin >> firstname;
    cout << "Lastname: ";
    cin >> lastname;
    srand((unsigned) time(0));
    int i;
    i = (rand());
    id = to_string((i));
}

void passwordChecker(string &password, string &rePassword) {
    while (true) {
        if ((password.length() < 8) && (password != rePassword)) {
            system("cls");
            cout << "The password is too short. At least 8 characters." << endl;
            cout << "Password don't match. Please Try again." << endl;
            cout << "Password: ";
            cin >> password;
            cout << "Re-Enter Password: ";
            cin >> rePassword;
        } else if (password.length() < 8) {
            system("cls");
            cout << "The password is too short. At least 8 characters." << endl;
            cout << "Password: ";
            cin >> password;
            cout << "Re-Enter Password: ";
            cin >> rePassword;
        } else if (password != rePassword) {
            system("cls");
            cout << "Password don't match. Please Try again." << endl;
            cout << "Password: ";
            cin >> password;
            cout << "Re-Enter Password: ";
            cin >> rePassword;
        } else {
            break;
        }
    }
}

void usernameChecker(string &username) {
    while (true) {
        int counter = 0, d = 0;
        for (int i = 0; i < username.length(); i++) {
            {
                if (isalpha(username[i]) || isdigit(username[i]) || username[i] == '_') {
                    if (isdigit(username[i]) || username[i] == '_') { d++; }
                    counter++;
                }
            }
        }
        string filename = "DATA_BASE.txt";
        if (isdigit(username[0])) {
            system("cls");
            cout << "Usernames can't start with a number.";
        } else if (counter != username.length() || username.length() < 5 || username.length() > 32 ||
                   username[0] == '_' ||
                   username[username.length() - 1] == '_' || d == username.length()) {
            system("cls");
            cout << "This username is invalid" << endl;
            cout << "You can use a-z, 0-9 and underscores. Minimum length is 5 characters." << endl;
        } else if (usernameSearch(username, filename)) {
            system("cls");
            cout << "This username is already taken" << endl;
        } else
            break;
        cout << "Username: ";
        cin >> username;
    }
}

void saveToFile(string arr[], int size, string filename) {
    ofstream outFile(filename, ios::app);
    for (int i = 0; i < size; i++) {
        outFile << arr[i] << ' ';
    }
    outFile << endl;
    outFile.close();
}

void dataBaseSearch(string target, string filename, string &u, string &p, string &f, string &l, string &id) {
    ifstream inFile(filename);
    string arr[MAX_ROWS][MAX_COLS];
    int rows = 0;
    int cols = 0;
    while (inFile >> arr[rows][cols]) {
        cols++;
        if (cols == MAX_COLS) {
            rows++;
            cols = 0;
        }
    }
    for (int i = 0; i < rows; i++) {
        if (arr[i][0] == target) {
            {
                u = arr[i][0];
                p = arr[i][1];
                f = arr[i][2];
                l = arr[i][3];
                id = arr[i][4];
            }
        }
    }
    inFile.close();
}

bool usernameSearch(string target, string filename) {
    ifstream inFile(filename);
    string arr[MAX_ROWS][MAX_COLS];
    int rows = 0;
    int cols = 0;
    while (inFile >> arr[rows][cols]) {
        cols++;
        if (cols == MAX_COLS) {
            rows++;
            cols = 0;
        }
    }
    bool flag = false;
    for (int i = 0; i < rows; ++i) {
        if (arr[i][0] == target) {
            {
                flag = true;
                break;
            }
        }
    }
    inFile.close();
    return flag;
}

void editUsername(string target, string filename_Data, string filename_Message, string &u) {
    ifstream inFile(filename_Data);
    string arr[MAX_ROWS][MAX_COLS];
    int rows = 0;
    int cols = 0;
    while (inFile >> arr[rows][cols]) {
        cols++;
        if (cols == MAX_COLS) {
            rows++;
            cols = 0;
        }
    }
    inFile.close();
    for (int i = 0; i < rows; i++) {
        if (arr[i][0] == target) {
            {
                arr[i][0] = u;
                break;
            }
        }
    }
    ofstream outFile(filename_Data);
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            outFile << arr[i][j] << ' ';
        }
        outFile << endl;
    }
    outFile.close();


    ifstream inFile1(filename_Message);
    string arr1[MAX_ROWS_MESSAGE][MAX_COLS_MESSAGE];
    int rows1 = 0;
    int cols1 = 0;

    while (inFile1 >> arr1[rows1][cols1]) {
        cols1++;
        if (cols1 == MAX_COLS_MESSAGE) {
            rows1++;
            cols1 = 0;
        }
    }

    for (int i = 0; i < rows; i++) {
        if (arr1[i][0] == target)
            arr1[i][0] = u;
        if (arr1[i][1] == target)
            arr1[i][1] = u;
    }
    inFile1.close();


    ofstream f3(filename_Message);
    for (int i = 0; i < MAX_COLS_MESSAGE; i++) {
        for (int j = 0; j < 3; j++) {
            f3 << arr1[i][j] << ' ';
        }
        f3 << endl;
    }
    f3.close();
}

void editPassword(string target, string filename, string &u) {
    ifstream inFile(filename);
    string arr[MAX_ROWS][MAX_COLS];
    int rows = 0;
    int cols = 0;
    while (inFile >> arr[rows][cols]) {
        cols++;
        if (cols == MAX_COLS) {
            rows++;
            cols = 0;
        }
    }
    inFile.close();
    for (int i = 0; i < rows; i++) {
        if (arr[i][0] == target) {
            {
                arr[i][1] = u;
                break;
            }
        }
    }
    ofstream outFile(filename);
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            outFile << arr[i][j] << ' ';
        }
        outFile << endl;
    }
    outFile.close();
}

void editFirstname(string target, string filename, string &u) {
    ifstream inFile(filename);
    string arr[MAX_ROWS][MAX_COLS];
    int rows = 0;
    int cols = 0;
    while (inFile >> arr[rows][cols]) {
        cols++;
        if (cols == MAX_COLS) {
            rows++;
            cols = 0;
        }
    }
    inFile.close();
    for (int i = 0; i < rows; i++) {
        if (arr[i][0] == target) {
            {
                arr[i][2] = u;
                break;
            }
        }
    }
    ofstream outFile(filename);
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            outFile << arr[i][j] << ' ';
        }
        outFile << endl;
    }
    outFile.close();
}

void editLastname(string target, string filename, string &u) {
    ifstream inFile(filename);
    string arr[MAX_ROWS][MAX_COLS];
    int rows = 0;
    int cols = 0;
    while (inFile >> arr[rows][cols]) {
        cols++;
        if (cols == MAX_COLS) {
            rows++;
            cols = 0;
        }
    }
    inFile.close();
    for (int i = 0; i < rows; i++) {
        if (arr[i][0] == target) {
            {
                arr[i][3] = u;
                break;
            }
        }
    }
    ofstream outFile(filename);
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            outFile << arr[i][j] << ' ';
        }
        outFile << endl;
    }
    outFile.close();
}

void deleteAccount(string target, string filename) {
    ifstream inFile(filename);
    string arr[MAX_ROWS][MAX_COLS];
    int rows = 0;
    int cols = 0;
    while (inFile >> arr[rows][cols]) {
        cols++;
        if (cols == MAX_COLS) {
            rows++;
            cols = 0;
        }
    }
    inFile.close();
    for (int i = 0; i < rows; i++) {
        if (arr[i][0] == target) {
            {
                arr[i][0] = "";
                arr[i][1] = "";
                arr[i][2] = "";
                arr[i][3] = "";
                arr[i][4] = "";
                break;
            }
        }
    }
    ofstream outFile(filename);
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            outFile << arr[i][j] << ' ';
        }
        outFile << endl;
    }
    outFile.close();
}

void dataMessageSearch(string target, string filename) {
    ifstream inFile(filename);
    string arr[MAX_ROWS_MESSAGE][MAX_COLS_MESSAGE];
    int rows = 0;
    int cols = 0;

    while (inFile >> arr[rows][cols]) {
        cols++;
        if (cols == MAX_COLS_MESSAGE) {
            rows++;
            cols = 0;
        }
    }

    for (int i = 0; i < rows; i++) {
        if (arr[i][1] == target)
            cout << arr[i][0] << ": " << arr[i][2] << endl;
    }

    inFile.close();
}