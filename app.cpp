#include"function.h"
#include "functions.cpp"
int main()
{
    char choice;
    while (true)
    {
        cout << "Please choice what you want to do:" << endl
             << "(1) Register\n(2) Login\n(3) Change Password\n(4) Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case '1':
            extract_data();
            Register();
            break;
        case '2':
        if (login_attemps())
        {
            cout<<"//______________________________//\n";
            cout << "You've reached the maximum login attemps\n"<<
            "you're deniend access to the system!\n";
            cout<<"//______________________________//\n";
            break;
        }
        else
        {
            cout<<"//______________________________//\n";
            cout << "Welcome Back!\n";
            extract_data();
            login();
            break;
        }
        case '3':
            extract_data();
            login();
            change_password();
            break;
        case '4':
            cout << "Hope you are happy and satisfied with our App";
            return 0;
  
        }
    }
    
}