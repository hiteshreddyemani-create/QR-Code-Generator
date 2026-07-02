#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "qrcodegen.hpp"

using namespace std;
using qrcodegen::QrCode;

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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string url, filename;

    cout << "\nEnter Website URL: ";
    getline(cin, url);

    cout << "Enter output file name (without .svg): ";
    getline(cin, filename);

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

    cout << "Enter output file name (without .svg): ";
    getline(cin, filename);

    QrCode qr = QrCode::encodeText(text.c_str(), QrCode::Ecc::LOW);

    saveSvg(qr, "output/text/" + filename + ".svg");

    cout << "\nQR Code generated successfully!\n";
    cout << "Saved as: output/text/" << filename << ".svg\n";
}
void generateWifiQR()
{
    cin.ignore();

    string ssid;
    string password;
    string security;
    string filename;

    cout << "\nEnter Wi-Fi Name (SSID): ";
    getline(cin, ssid);

    cout << "Enter Password: ";
    getline(cin, password);

    cout << "Security Type (WPA/WEP/nopass): ";
    getline(cin, security);

    cout << "Enter output file name (without .svg): ";
    getline(cin, filename);

    string wifiData = "WIFI:T:" + security +
                      ";S:" + ssid +
                      ";P:" + password + ";;";

    QrCode qr = QrCode::encodeText(wifiData.c_str(), QrCode::Ecc::LOW);

    saveSvg(qr, "output/wifi/" + filename + ".svg");

    cout << "\nWi-Fi QR Code generated successfully!\n";
    cout << "Saved as: output/wifi/" << filename << ".svg\n";
}
void generateEmailQR()
{
    cin.ignore();

    string email;
    string subject;
    string body;
    string filename;

    cout << "\nEnter Email Address: ";
    getline(cin, email);

    cout << "Enter Subject: ";
    getline(cin, subject);

    string line;

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

    string emailData = "mailto:" + email +
                       "?subject=" + subject +
                       "&body=" + body;

    QrCode qr = QrCode::encodeText(emailData.c_str(), QrCode::Ecc::LOW);

    saveSvg(qr, "output/email/" + filename + ".svg");

    cout << "\nEmail QR generated successfully!\n";
    cout << "Saved as: output/email/" << filename << ".svg\n";
}
void generatePhoneQR()
{
    cin.ignore();

    string phone;
    string filename;

    cout << "\nEnter Phone Number (include country code if needed): ";
    getline(cin, phone);

    cout << "Enter output file name (without .svg): ";
    getline(cin, filename);

    string phoneData = "tel:" + phone;

    QrCode qr = QrCode::encodeText(phoneData.c_str(), QrCode::Ecc::LOW);

    saveSvg(qr, "output/phone/" + filename + ".svg");

    cout << "\nPhone QR generated successfully!\n";
    cout << "Saved as: output/phone/" << filename << ".svg\n";
}
void generateContactQR()
{
    cin.ignore();

    string name;
    string phone;
    string email;
    string organization;
    string filename;

    cout << "\nEnter Full Name: ";
    getline(cin, name);

    cout << "Enter Phone Number: ";
    getline(cin, phone);

    cout << "Enter Email Address (Press Enter to skip): ";
    getline(cin, email);

    cout << "Enter Organization (Press Enter to skip): ";
    getline(cin, organization);

    cout << "Enter output file name (without .svg): ";
    getline(cin, filename);

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
    cout << "7. Exit\n";
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
            generateWifiQR();
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
                cout << "\nThank you for using QR Code Generator!\n";
                return 0;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
}