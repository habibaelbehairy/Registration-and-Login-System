#include <tchar.h>
#include <Windows.h>
#include<iostream>
#include "EASendMailObj.tlh"
#include<sstream> 
#include<string>

int x = rand() % 9000 + 1000;
using namespace EASendMailObjLib;
const int ConnectNormal = 0;
const int ConnectSSLAuto = 1;
const int ConnectSTARTTLS = 2;
const int ConnectDirectSSL = 3;
const int ConnectTryTLS = 4;

int _tmain(int argc, _TCHAR* argv[])
{
    std::string email;
    std::cout << "Please Enter your email: ";
    std::cin >> email;
    int otp = rand() % 9000 + 1000;
    std::string s = std::to_string(otp);
    std::string message = "Your OTP Is: " + s;
    ::CoInitialize(NULL);

    IMailPtr oSmtp = NULL;
    oSmtp.CreateInstance(__uuidof(EASendMailObjLib::Mail));
    oSmtp->LicenseCode = _T("TryIt");

    // Set your sender email address
    oSmtp->FromAddr = _T("fcaipw@gmail.com");
    // Add recipient email address
    oSmtp->AddRecipientEx((email.c_str()), 0);

    // Set email subject
    oSmtp->Subject = _T("OTP Change Password");
    // Set email body
    oSmtp->BodyText = (message.c_str());

    // Your SMTP server address
    oSmtp->ServerAddr = _T("smtp.gmail.com");

    // User and password for ESMTP authentication, if your server doesn't
    // require User authentication, please remove the following codes.
    oSmtp->UserName = _T("fcaipw@gmail.com"); // here
    oSmtp->Password = _T("dhcdvsuqvqnbzeva"); // here

    // Most mordern SMTP servers require SSL/TLS connection now.
    // ConnectTryTLS means if server supports SSL/TLS, SSL/TLS will be used automatically.
    oSmtp->ConnectType = ConnectTryTLS;

    // If your SMTP server uses 587 port
    oSmtp->ServerPort = 587;

    // If your SMTP server requires SSL/TLS connection on 25/587/465 port
    // oSmtp->ServerPort = 25; // 25 or 587 or 465
    // oSmtp->ConnectType = ConnectSSLAuto;

    _tprintf(_T("Start to send email ...\r\n"));

    if (oSmtp->SendMail() == 0)
    {
        _tprintf(_T("email was sent successfully!\r\n"));
    }
    else
    {
        _tprintf(_T("failed to send email with the following error: %s\r\n"),
            (const TCHAR*)oSmtp->GetLastErrDescription());
    }

    return 0;
}