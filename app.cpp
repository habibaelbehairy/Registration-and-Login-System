/*FCI – Programming 1 – 2022 - Assignment 4 
Program Name:CS112-2022-2nd –S7 S8-20210121-20210183-20210331A4LoginApp               
Last Modification Date: 16 May 2022
Author1 and ID and Group: Habiba Alaa Mohamed 20210121
Author2 and ID and Group: Shahd Salah El-Dein Abd El-Tawab 20210183
Author3 and ID and Group: Mohamed Ehab Tawfik 20210331

Teaching Assistant: Eng. Abdelrahman Abdelmonem
Purpose: Make user regist and get his id then he can login in our app and he could change his password also
Version:1.0*/

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
            cout<<"\n";
            cout << "You've reached the maximum login attemps\n"<<
            "you're deniend access to the system!\n";
            cout<<"//______________________________//\n";
            break;
        }
        else
        {
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
