#ifndef FUNCTION_H
#define FUNCTION_H
#include<iostream>
#include<string>
#include<regex>
#include<fstream>
#include<conio.h>
#include <iomanip>

using namespace std;


void data_information_file(); 
void extract_data();
void giveID();
// void valid_userid();
void valid_username();
void valid_email();
string stars();
string encrypt();
string decrypt(string text);
void valid_password();
void valid_number();
// bool comparing_ID_data();
bool comparing_username_data();
bool comparing_email_data();
bool comparing_password_data();
bool comparing_number_data();
void assign_to_array();
void Register();
void login();
bool compare_login_PW(string entered_ID, string entered_PW);
string get_username(string entered_ID);
bool login_attemps();
void getData();
void change_password();
void password_replace(string entered_ID, string entered_NPW);
void update_data();
//_____________________________//
struct data
{
    string user_ID;
    string username;
    string email;
    string password;
    string phonenumber;
}user[100];

data str;
string User_ID,User_Name,User_Email,User_Number,User_password, newID2;
int i=0;
int newID = 20000;
// login variables 
string login_ID, login_PW, login_name;
int login_counter = 0;
int generalOtp;
//change password variables
string new_PW;


#endif