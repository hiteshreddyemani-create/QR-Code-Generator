#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "qrcodegen.hpp"

using namespace std;
using qrcodegen::QrCode;
string trim(string str)
{
    int start = 0;
    int end = str.length() - 1;

    while (start <= end && isspace(str[start]))
        start++;

    while (end >= start && isspace(str[end]))
        end--;

    return str.substr(start, end - start + 1);
}

void saveSvg(const QrCode &qr, const string &filename)
{
    ofstream file(filename);

    int border = 4;

    file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    file << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" viewBox=\"0 0 "
         << qr.getSize() + border * 2 << " "
         << qr.getSize() + border * 2 << "\">\n";

    file << "<rect width=\"100%\" height=\"100%\" fill=\"white\"/>\n";

    for (int y = 0; y < qr.getSize(); y++)
    {
        for (int x = 0; x < qr.getSize(); x++)
        {
            if (qr.getModule(x, y))
            {
                file << "<rect x=\"" << x + border
                     << "\" y=\"" << y + border
                     << "\" width=\"1\" height=\"1\" fill=\"black\"/>\n";
            }
        }
    }

    file << "</svg>\n";
}

void generateWebsiteQR()
{
    cin.ignore();

    string url;
    string filename;

    cout << "\nEnter Website URL: ";
    getline(cin, url);
    url = trim(url);

    
    if (url.empty())
    {
        cout << "\nError: Website URL cannot be empty!\n";
        return;
    }

    
    if (url.find("http://") != 0 && url.find("https://") != 0)
    {
        url = "https://" + url;
    }

    cout << "Enter output file name (without .svg): ";
    getline(cin, filename);
    filename = trim(filename);

    QrCode qr = QrCode::encodeText(url.c_str(), QrCode::Ecc::LOW);

    saveSvg(qr, "output/websites/" + filename + ".svg");

    cout << "\nQR Code generated successfully!\n";
    cout << "Saved as: output/websites/" << filename << ".svg\n";
}
void generateTextQR()
{
    cin.ignore();

    string text;
    string filename;

    cout << "\nEnter Text: ";
    getline(cin, text);
    text = trim(text);

    cout << "Enter output file name (without .svg): ";
    getline(cin, filename);
    filename= trim(filename);

    QrCode qr = QrCode::encodeText(text.c_str(), QrCode::Ecc::LOW);

    saveSvg(qr, "output/text/" + filename + ".svg");

    cout << "\nQR Code generated successfully!\n";
    cout << "Saved as: output/text/" << filename << ".svg\n";
}
void generateWiFiQR()
{
    cin.ignore();

    string ssid;
    string password;
    string security;
    string filename;

    cout << "\nEnter Wi-Fi Name (SSID): ";
    getline(cin, ssid);
    ssid = trim(ssid);

    if (ssid.empty())
    {
        cout << "\nError: Wi-Fi Name (SSID) cannot be empty!\n";
        return;
    }

    cout << "Enter Security Type (WPA/WPA2/WEP/nopass): ";
    getline(cin, security);
    security = trim(security);

    // Convert security type to lowercase
    for (char &ch : security)
    {
        ch = tolower(ch);
    }

    // Validate security type
    if (security != "wpa" &&
        security != "wpa2" &&
        security != "wep" &&
        security != "nopass")
    {
        cout << "\nError: Invalid security type!\n";
        return;
    }

    if (security != "nopass")
    {
        cout << "Enter Wi-Fi Password: ";
        getline(cin, password);
        password = trim(password);

        if (password.empty())
        {
            cout << "\nError: Password cannot be empty for secured networks!\n";
            return;
        }
    }

    cout << "Enter output file name (without .svg): ";
    getline(cin, filename);
    filename = trim(filename);

    if (filename.empty())
    {
        cout << "\nError: File name cannot be empty!\n";
        return;
    }

    // Convert to QR format
    string qrSecurity;

    if (security == "wpa")
        qrSecurity = "WPA";
    else if (security == "wpa2")
        qrSecurity = "WPA2";
    else if (security == "wep")
        qrSecurity = "WEP";
    else
        qrSecurity = "nopass";

    string wifiData;

    if (qrSecurity == "nopass")
    {
        wifiData = "WIFI:T:nopass;S:" + ssid + ";;";
    }
    else
    {
        wifiData = "WIFI:T:" + qrSecurity +
                   ";S:" + ssid +
                   ";P:" + password + ";;";
    }

    QrCode qr = QrCode::encodeText(wifiData.c_str(), QrCode::Ecc::LOW);

    saveSvg(qr, "output/wifi/" + filename + ".svg");

    cout << "\n====================================\n";
    cout << "  Wi-Fi QR Generated Successfully\n";
    cout << "====================================\n";
    cout << "Saved as: output/wifi/" << filename << ".svg\n";
}
void generateEmailQR()
{
    cin.ignore();

    string email;
    string subject;
    string body;
    string line;
    string filename;

    cout << "\nEnter Recipient Email Address: ";
    getline(cin, email);
    email=trim(email);

    if (email.empty())
    {
        cout << "\nError: Email address cannot be empty!\n";
        return;
    }

    if (email.find('@') == string::npos)
    {
        cout << "\nError: Invalid email address!\n";
        return;
    }

    cout << "Enter Email Subject: ";
    getline(cin, subject);

    if (subject.empty())
    {
        cout << "\nError: Subject cannot be empty!\n";
        return;
    }

    cout << "\nEnter Email Body (Type END on a new line to finish):\n";

    while (true)
    {
        getline(cin, line);

        if (line == "END")
            break;

        body += line + "\n";
    }

    cout << "Enter output file name (without .svg): ";
    getline(cin, filename);
    filename =trim(filename);

    if (filename.empty())
    {
        cout << "\nError: File name cannot be empty!\n";
        return;
    }

    string emailData = "mailto:" + email + "?subject=" + subject;

    if (!body.empty())
    {
        emailData += "&body=" + body;
    }

    QrCode qr = QrCode::encodeText(emailData.c_str(), QrCode::Ecc::LOW);

    saveSvg(qr, "output/email/" + filename + ".svg");

    cout << "\nEmail QR generated successfully!\n";
    cout << "Saved as: output/email/" << filename << ".svg\n";
}
void generatePhoneQR()
{
    cin.ignore();

    string countryCode;
    string mobileNumber;
    string filename;

    cout << "\nEnter Country Code (without +): ";
    getline(cin, countryCode);
    countryCode = trim(countryCode);

    
    if (countryCode.empty())
    {
        cout << "\nError: Country code cannot be empty!\n";
        return;
    }

    if (countryCode.length() > 3)
    {
        cout << "\nError: Country code must contain 1 to 3 digits!\n";
        return;
    }

    for (char ch : countryCode)
    {
        if (!isdigit(ch))
        {
            cout << "\nError: Country code should contain only digits!\n";
            return;
        }
    }

    cout << "Enter 10-digit Mobile Number: ";
    getline(cin, mobileNumber);
    mobileNumber = trim(mobileNumber);

    
    if (mobileNumber.length() != 10)
    {
        cout << "\nError: Mobile number must contain exactly 10 digits!\n";
        return;
    }

    for (char ch : mobileNumber)
    {
        if (!isdigit(ch))
        {
            cout << "\nError: Mobile number should contain only digits!\n";
            return;
        }
    }

    cout << "Enter output file name (without .svg): ";
    getline(cin, filename);
    filename =trim(filename);

    if (filename.empty())
    {
        cout << "\nError: File name cannot be empty!\n";
        return;
    }

    string phoneData = "tel:+" + countryCode + mobileNumber;

    QrCode qr = QrCode::encodeText(phoneData.c_str(), QrCode::Ecc::LOW);

    saveSvg(qr, "output/phone/" + filename + ".svg");

    cout << "\nPhone QR generated successfully!\n";
    cout << "Saved as: output/phone/" << filename << ".svg\n";
}
void generateContactQR()
{
    cin.ignore();

    string name;
    string countryCode;
    string mobileNumber;
    string email;
    string organization;
    string filename;

    cout << "\nEnter Full Name: ";
    getline(cin, name);
    name= trim(name);

    if (name.empty())
    {
        cout << "\nError: Name cannot be empty!\n";
        return;
    }

    cout << "Enter Country Code (without +): ";
    getline(cin, countryCode);
    countryCode= trim(countryCode);

    if (countryCode.empty())
    {
        cout << "\nError: Country code cannot be empty!\n";
        return;
    }

    if (countryCode.length() > 3)
    {
        cout << "\nError: Country code must contain 1 to 3 digits!\n";
        return;
    }

    for (char ch : countryCode)
    {
        if (!isdigit(ch))
        {
            cout << "\nError: Country code should contain only digits!\n";
            return;
        }
    }

    cout << "Enter 10-digit Mobile Number: ";
    getline(cin, mobileNumber);
    mobileNumber = trim(mobileNumber);

    if (mobileNumber.length() != 10)
    {
        cout << "\nError: Mobile number must contain exactly 10 digits!\n";
        return;
    }

    for (char ch : mobileNumber)
    {
        if (!isdigit(ch))
        {
            cout << "\nError: Mobile number should contain only digits!\n";
            return;
        }
    }

    cout << "Enter Email Address (Press Enter to skip): ";
    getline(cin, email);
    email = trim(email);

    if (!email.empty())
    {
        if (email.find('@') == string::npos)
        {
            cout << "\nError: Invalid email address!\n";
            return;
        }
    }

    cout << "Enter Organization (Press Enter to skip): ";
    getline(cin, organization);
    organization = trim(organization);

    cout << "Enter output file name (without .svg): ";
    getline(cin, filename);
    filename =trim(filename);

    if (filename.empty())
    {
        cout << "\nError: File name cannot be empty!\n";
        return;
    }

    string phone = "+" + countryCode + mobileNumber;

    string vcard = "BEGIN:VCARD\n";
    vcard += "VERSION:3.0\n";
    vcard += "FN:" + name + "\n";
    vcard += "TEL;TYPE=CELL:" + phone + "\n";

    if (!email.empty())
        vcard += "EMAIL:" + email + "\n";

    if (!organization.empty())
        vcard += "ORG:" + organization + "\n";

    vcard += "END:VCARD";

    QrCode qr = QrCode::encodeText(vcard.c_str(), QrCode::Ecc::LOW);

    saveSvg(qr, "output/contacts/" + filename + ".svg");

    cout << "\nContact QR generated successfully!\n";
    cout << "Saved as: output/contacts/" << filename << ".svg\n";
}
void generateUPIQR()
{
    cin.ignore();

    string upiId;
    string name;
    string amount;
    string note;
    string filename;

    cout << "\nEnter UPI ID: ";
    getline(cin, upiId);
    upiId = trim(upiId);

    // Validate UPI ID
    if (upiId.empty())
    {
        cout << "\nError: UPI ID cannot be empty!\n";
        return;
    }

    if (upiId.find('@') == string::npos)
    {
        cout << "\nError: Invalid UPI ID!\n";
        return;
    }

    cout << "Enter Payee Name: ";
    getline(cin, name);
    name = trim(name);

    if (name.empty())
    {
        cout << "\nError: Payee name cannot be empty!\n";
        return;
    }

    cout << "Enter Amount (Press Enter to skip): ";
    getline(cin, amount);
    amount = trim(amount);

// Validate Amount
if (!amount.empty())
{
    bool decimalFound = false;

    // Decimal cannot be first or last
    if (amount.front() == '.' || amount.back() == '.')
    {
        cout << "\nError: Invalid amount format!\n";
        return;
    }

    for (char ch : amount)
    {
        if (isdigit(ch))
        {
            continue;
        }
        else if (ch == '.')
        {
            if (decimalFound)
            {
                cout << "\nError: Invalid amount format!\n";
                return;
            }

            decimalFound = true;
        }
        else
        {
            cout << "\nError: Amount should contain only digits and one decimal point!\n";
            return;
        }
    }

    

    size_t decimalPos = amount.find('.');

    if (decimalPos == string::npos)
    {
        // No decimal point
        size_t firstNonZero = amount.find_first_not_of('0');

        if (firstNonZero == string::npos)
            amount = "0";
        else
            amount = amount.substr(firstNonZero);
    }
    else
    {
        string integerPart = amount.substr(0, decimalPos);
        string decimalPart = amount.substr(decimalPos + 1);

        size_t firstNonZero = integerPart.find_first_not_of('0');

        if (firstNonZero == string::npos)
            integerPart = "0";
        else
            integerPart = integerPart.substr(firstNonZero);

        amount = integerPart + "." + decimalPart;
    }
}

    cout << "Enter Payment Note (Press Enter to skip): ";
    getline(cin, note);
    note = trim(note);

    cout << "Enter output file name (without .svg): ";
    getline(cin, filename);
    filename =trim(filename);

    // Validate File Name
    if (filename.empty())
    {
        cout << "\nError: File name cannot be empty!\n";
        return;
    }

    string upiData = "upi://pay?";
    upiData += "pa=" + upiId;
    upiData += "&pn=" + name;

    if (!amount.empty())
        upiData += "&am=" + amount;

    upiData += "&cu=INR";

    if (!note.empty())
        upiData += "&tn=" + note;

    QrCode qr = QrCode::encodeText(upiData.c_str(), QrCode::Ecc::LOW);

    saveSvg(qr, "output/upi/" + filename + ".svg");

    cout << "\nUPI Payment QR generated successfully!\n";
    cout << "Saved as: output/upi/" << filename << ".svg\n";
}
void showMenu()
{
    cout << "\n====================================\n";
    cout << "      QR Code Generator\n";
    cout << "====================================\n";
    cout << "1. Website URL\n";
    cout << "2. Plain Text\n";
    cout << "3. Wi-Fi QR\n";
    cout << "4. Email QR\n";
    cout << "5. Phone QR\n";
    cout << "6. Contact (vCard)\n";
    cout << "7. UPI Payment QR\n";
    cout << "8. Exit\n";
    cout << "\nEnter your choice: ";
}

int main()
{
    int choice;

    while (true)
    {
        showMenu();

        cin >> choice;

        switch (choice)
        {
            case 1:
            generateWebsiteQR();
            break;

            case 2:
            generateTextQR();
            break;

            case 3:
            generateWiFiQR();
            break;

            case 4:
            generateEmailQR();
            break;

            case 5:
            generatePhoneQR();
            break;

            case 6:
            generateContactQR();
            break;

            case 7:
            generateUPIQR();
            break;

            case 8:
            cout << "\nThank you for using QR Code Generator!\n";
            return 0;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
}