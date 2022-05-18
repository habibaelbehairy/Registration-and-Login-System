#include"function.h"

void data_information_file(string str1,string str2,string str3,string str4,string str5)
{
    string data_information("data_information_file.txt");
    ofstream datafile;
    datafile.open(data_information, ios_base::app);
    datafile<<str1<<endl<<str2<<endl<<str3<<endl;
    datafile<<str4<<endl;
    datafile<<str5<<endl;
}

//______________________________//
void extract_data()
{
    ifstream datafile;
    char read[500];
    datafile.open("data_information_file.txt");
    datafile.getline(read,500);
    while(!datafile.eof())
    {  
        user[i].user_ID=read;
        datafile.getline(read,500);
        user[i].username=read;
        datafile.getline(read,500);
        user[i].email=read;
        datafile.getline(read,500);
        user[i].password = read;
        datafile.getline(read, 500);
        user[i].phonenumber=read;
        datafile.getline(read,500);
        i++;
    }
    datafile.close();
} 

void giveID()
{

    newID = i + 20000;
    User_ID = to_string(newID);

}
//_____________________________//
// void valid_userid()
// {
//     cout<<"Please enter your ID: ";
//     cin>>str.user_ID;
//     string ID=str.user_ID;
//     regex validuserID("[0-9]+");
//     while(!regex_match(ID,validuserID))
//     {
//         cout<<"Invalid ID"<<endl;
//         cout<<"please enter a valid ID: ";
//         cin>>ID;
//     }
//     //cout<<"valid username \n";
//     User_ID=ID;
//     cout<<User_ID<<endl;
// }
//_____________________________//
void valid_username ()
{   
    cout<<"Please enter your username : ";
    getline(cin,str.username);
    string name=str.username;
    regex validusername("[a-zA-Z\\_]+");
    while(!regex_match(name,validusername))
    {
        cout<<"invalid username"<<endl;
        cout<<"please enter a valid username: ";
        getline(cin,name);
    }
    //cout<<"valid username \n";
    User_Name=name;
    cout<<User_Name<<endl;
}
//_____________________________//
void valid_email()
{
    cout<<"Please enter your email : ";
    regex validemail("([a-zA-Z]+([a-zA-Z0-9#!%$‘&\\+\\*\\–\\/=\?^_`\\{\\|\\}~]+)?([\\.]{1})?([a-zA-Z0-9#!%$‘&\\+\\*\\–\\/=\?^_`\\{\\|\\}~]+)?)([@]){1}([a-zA-Z0-9]+)(([\\.]){1}(com))");
    cin>>str.email;
    string email=str.email;
    while(!regex_match(email,validemail)){
        cout<<"invalid email "<<endl;
        cout<<"please enter a valid email: ";
        cin>>email;
    }
    //cout<<"valid email \n";
    User_Email=email;
    cout<<User_Email<<endl;
}
//_____________________________//
string stars()
{
    char ch;
    string password = "";
    while ((ch = getch())!= '\r')
    {
        if (ch == 8)
        {
            cout << "\b \b";
            password.pop_back();
        }
        else
        {
            cout << "*";
            password = password + ch;
        } 
    }
    cout << endl;
    return password;
}
//_____________________________//
string encrypt(string text)
{  
    string encryption = "";
    int numofshifts = 2;
    for (int c = 0; c < text.length(); c++)
    {
        encryption += char(int(text[c]) + numofshifts);   
    } 
    return encryption;
}
//_____________________________//
string decrypt(string text)
{  
    string encryption = "";
    int numofshifts = 2;
    for (int c = 0; c < text.length(); c++)
    {
        encryption += char(int(text[c]) - numofshifts);   
    } 
    return encryption;
}
//_____________________________//
void valid_password()
{
    string confirmed_pass;
    cout << "Please enter Password:" << endl
         << "Your password can include letters, numbers and special characters" << endl
         << "Your password should be strong here a conditions for a storng password: " << endl
         << "1-Is at least 12 characters long and 16 max.\n2-Must include at least one uppercase and at least one lowercase letters\n3-Must include numbers and special symbols:"
         << endl;
    str.password = stars();
    regex validpassword("(?=.*[a-z])(?=.*[0-9])(?=.*[A-Z])(?=.*[#!%$‘&\\+\\*\\–\\/=\?^_`\\{\\|\\}\\.~])[a-zA-Z0-9#!%$‘&\\+\\*\\–\\/=\?^_`\\{\\|\\}\\.~]{12,16}");
    while (!regex_match(str.password,validpassword))
    {
        cout << "Not a strong password" << endl
             << "Please enter a storng password and here a format of strong password: " << endl
             << "1-Is at least 12 characters long and 16 max.\n2-Must include at least one uppercase and at least one lowercase letters\n3-Must include numbers and special symbols:"
             << endl;
        str.password = stars();
    }
    cout << "Please Enter the password one more time: " << endl;
    confirmed_pass = stars();
    while (str.password != confirmed_pass)
    {
        cout << "Its Not the same one" << endl
             << "Please Enter the password one more time: ";
        confirmed_pass = stars();
    }
    User_password = encrypt(confirmed_pass);
    str.password = User_password;
}
//_____________________________//
void valid_number ()
{
    cout<<"Please enter your number : ";
    cin>>str.phonenumber;
    string number=str.phonenumber;
    regex validnumber("(010|011|012|015)(([0-9]{8})+)");
    while(!regex_match(number,validnumber)){
        cout<<"Invalid number"<<endl;
        cout<<"please enter a valid number: ";
        cin>>number;
    }
    User_Number=number;
    cout<<User_Number<<endl;
}
//_____________________________//
// bool comparing_ID_data()
// {
//     for(int j=0;j<i;j++)
//     {
//         if(str.user_ID==user[j].user_ID)
//         {
//             cout<<"invalid ID"<<endl;
//             return false;
//         }
//     }
//     return true;
// }
//_____________________________//
bool comparing_username_data()
{
    for(int j=0;j<i;j++)
    {
        if (str.username==user[j].username)
        {
            cout<<"invalid username"<<endl;
            return false;
        } 
    }
    return true;
}
//_____________________________//
bool comparing_email_data()
{
    for(int j=0;j<i;j++)
    {
        if (str.email==user[j].email)
        {
            cout<<"invalid email"<<endl;
            return false;
        }
    }
    return true;
}
//_____________________________//
bool comparing_password_data()
{
    for (int j = 0; j < i; j++)
    {
        if (str.password == user[j].password)
        {
            cout << "Invalid password" << endl;
            return false;
        }  
    }
    return true;
}
//_____________________________//
bool comparing_number_data()
{
    for(int j=0;j<i;j++)
    {
        if (str.phonenumber==user[j].phonenumber)
        {
            cout<<"invalid number"<<endl;
            return false;
        }
    }
    return true;
}   
//______________________________//
void assign_to_array()
{
    user[i].user_ID == str.user_ID;
    user[i].username == str.username;
    user[i].email == str.email;
    user[i].password == str.password;
    user[i].phonenumber==str.phonenumber;
}
//______________________________//
void Register ()
{
    giveID();
    // valid_userid();
    // while(!comparing_ID_data())
    // {
    //     valid_userid();
    // }
    cout<<"//______________________________//\n";

    cin.ignore();
    valid_username();
    while(!comparing_username_data())
    {
        valid_username();
    }
    cout<<"//______________________________//\n";

    valid_email();
    while(!comparing_email_data())
    {
        valid_email();
    }
    cout<<"//______________________________//\n";
    
    valid_password();
    while (!comparing_password_data())
    {
        valid_password();
    }
    cout<<"//______________________________//\n";

    valid_number();
    while(!comparing_number_data())
    {
        valid_number();
    }
    cout<<"//______________________________//\n"; 
    cout << "Registared Successfully!"<< endl;
    cout << "Your ID is: " <<User_ID << endl;
    cout<<"//______________________________//\n"; 
    assign_to_array();
    data_information_file(User_ID,User_Name,User_Email,User_password,User_Number);
}
//______________________________//
void login()
{   
    getData();
    while (!compare_login_PW(login_ID, login_PW))
    {
        login_counter += 1;
        if (login_attemps())
        {
            cout<<"//______________________________//\n";
            cout << "You've reached the maximum login attemps\n"<<
            "you're deniend access to the system!"<<endl;
            cout<<"//______________________________//\n";
            break;
        }
        cout<<"//______________________________//\n";
        cout << "Failed Logit, Try Again"<<endl;
        getData();
    }
    if (compare_login_PW(login_ID, login_PW))
    {
    cout << "Successful login, Welcome " << get_username(login_ID) << '!' << endl;
    }
}
//______________________________//
bool compare_login_PW(string entered_ID, string entered_PW)
{

    for (int j = 0; j < i; j++)
    {
        if (entered_ID == user[j].user_ID)
        {
            entered_PW = encrypt(entered_PW);
            if (user[j].password == entered_PW)
                {
                    return true;
                }
        }
    }
    return false;
}
//______________________________//
string get_username(string entered_ID)
{
    string name;
    for (int j = 0; j < i; j++)
    {
        if (entered_ID == user[j].user_ID)
        {
            name = user[j].username;
            return name;
        }  
    }
}
//______________________________//
bool login_attemps()
{
    if (login_counter == 3)
    {
        return true;
    }
    return false;
}
//______________________________//
void getData()
{
    cout << "Please Enter Your ID: ";
    cin >> login_ID;
    cout << "Please Enter Your Password: ";
    login_PW = stars();
}
//______________________________//
void change_password()
{
    string confirmed_pass;
    cout << "Please enter your old password: ";
    login_PW = stars();

    while (!compare_login_PW(login_ID, login_PW))
    {
        cout<<"//______________________________//\n";
        cout << "Wrong Password!\n" << "Enter your password again: ";
        login_PW = stars();
    }
    cout<<"//______________________________//\n";
    if (compare_login_PW(login_ID, login_PW))
    {
        cout << "Please enter your new password:" << endl
         << "Your password can include letters, numbers and special characters" << endl
         << "Your password should be strong here a conditions for a storng password: " << endl
         << "1-Is at least 12 characters long and 16 max.\n2-Must include at least one uppercase and at least one lowercase letters\n3-Must include numbers and special symbols:"
         << endl;
        new_PW = stars();
        regex validpassword("(?=.*[a-z])(?=.*[0-9])(?=.*[A-Z])(?=.*[#!%$‘&\\+\\*\\–\\/=\?^_`\\{\\|\\}\\.~])[a-zA-Z0-9#!%$‘&\\+\\*\\–\\/=\?^_`\\{\\|\\}\\.~]{12,16}");
        while (!regex_match(new_PW,validpassword))
        {
            cout<<"//______________________________//\n";
            cout << "Not a strong password" << endl
                << "Please enter a storng password and here a format of strong password: " << endl
                << "1-Is at least 12 characters long and 16 max.\n2-Must include at least one uppercase and at least one lowercase letters\n3-Must include numbers and special symbols:"
                << endl;
            new_PW = stars();
        }
        cout<<"//______________________________//\n";
        cout << "Please Enter the password one more time: " << endl;
        confirmed_pass = stars();
        while (new_PW != confirmed_pass)
        {
            cout << "Its Not the same one" << endl
                << "Please Enter the password one more time: ";
            confirmed_pass = stars();
        }
        new_PW = encrypt(new_PW);
        password_replace(login_ID, new_PW);
        update_data();
        cout << "Your password was changed successfully!";
        cout<<"//______________________________//\n";
    }

}

void password_replace(string entered_ID, string entered_NPW)
{
    for (int j = 0; j < i; j++)
    {
        if (entered_ID == user[j].user_ID)
        {
            user[j].password = entered_NPW;
        }  
    }
}

void update_data()
{
    int numOfUsers = 0;
    string data_information("data_information_file.txt");
    ofstream datafile;
    datafile.open(data_information, std::ofstream::out | std::ofstream::trunc);
    datafile.close();
    datafile.open(data_information, ios_base::app);
    while (numOfUsers < i)
    {
        datafile<<user[numOfUsers].user_ID<<endl<<user[numOfUsers].username<<endl<<user[numOfUsers].email<<endl;
        datafile<<user[numOfUsers].password<<endl;
        datafile<<user[numOfUsers].phonenumber<<endl;
        numOfUsers += 1;
    }
    datafile.close();
}

void forget()
{
    string email;
    int otp;
    cout << "Please Enter Your Email: "<<endl;
    cin >> email;
    cout << "If you entered the email correctly you'll recieve otp"<< endl;
    cout << "Please Enter The OTP: ";
    cin >> otp;
    if (otp == generalOtp)
    {
        change_password();
    }
    else
    {
        cout << "invalid otp"<<endl;
    }

}
