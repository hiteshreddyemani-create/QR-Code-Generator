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
                cout << "\nPlain Text selected.\n";
                break;

            case 3:
                cout << "\nWi-Fi selected.\n";
                break;

            case 4:
                cout << "\nEmail selected.\n";
                break;

            case 5:
                cout << "\nPhone selected.\n";
                break;

            case 6:
                cout << "\nContact selected.\n";
                break;

            case 7:
                cout << "\nThank you for using QR Code Generator!\n";
                return 0;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }
    }
}