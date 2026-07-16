# QR Code Generator

A menu-driven **QR Code Generator** built in **C++** that supports generating multiple types of QR codes including Website URLs, Plain Text, Wi-Fi, Email, Phone Numbers, Contact (vCard), and UPI Payments.

The application provides configurable QR Error Correction Levels, input validation, history logging, overwrite protection, and an organized output structure.

---

## Features

* Generate Website URL QR Codes
* Generate Plain Text QR Codes
* Generate Wi-Fi QR Codes
* Generate Email QR Codes
* Generate Phone Number QR Codes
* Generate Contact (vCard) QR Codes
* Generate UPI Payment QR Codes
* Configurable Error Correction Levels (LOW, MEDIUM, QUARTILE, HIGH)
* Input Validation
* Automatic URL Formatting (`https://`)
* Whitespace Trimming
* QR Generation History Logging
* View History from the Menu
* Prevent Accidental File Overwriting
* Organized Output Folder Structure

---

## Technologies Used

* C++
* Standard Template Library (STL)
* File Handling
* SVG File Generation
* Visual Studio Code
* MinGW g++
* Git
* GitHub

---

## Folder Structure

```text
QR-Code-Generator/
│
├── include/
│   └── qrcodegen.hpp
│
├── src/
│   ├── main.cpp
│   └── qrcodegen.cpp
│
├── output/
│   ├── websites/
│   ├── text/
│   ├── wifi/
│   ├── email/
│   ├── phone/
│   ├── contacts/
│   └── upi/
│
├── logs/
│   └── history.txt
│
├── README.md
├── LICENSE
└── .gitignore
```

---

## Supported QR Types

| QR Type         | Description                                   |
| --------------- | --------------------------------------------- |
| Website         | Generate QR codes for website URLs            |
| Plain Text      | Encode any text into a QR code                |
| Wi-Fi           | Share Wi-Fi credentials instantly             |
| Email           | Open email client with pre-filled information |
| Phone           | Dial a phone number directly                  |
| Contact (vCard) | Share complete contact details                |
| UPI Payment     | Make instant UPI payments                     |

---

## Input Validation

The application validates user input to improve reliability.

* Empty input detection
* Valid phone number format
* Valid UPI ID format
* URL auto-formatting
* Input trimming
* Duplicate filename detection
* Overwrite confirmation

---

## Error Correction Levels

Users can choose from four QR Error Correction Levels.

| Level    | Recovery Capacity |
| -------- | ----------------- |
| LOW      | ~7%               |
| MEDIUM   | ~15%              |
| QUARTILE | ~25%              |
| HIGH     | ~30%              |

---

## Build Instructions

Compile the project using:

```bash
g++ src/main.cpp src/qrcodegen.cpp -Iinclude -std=c++11 -o qr
```

Run the application:

```bash
./qr
```

On Windows PowerShell:

```powershell
.\qr.exe
```

---

## Usage

1. Launch the application.
2. Select the desired QR type.
3. Enter the required information.
4. Choose the Error Correction Level.
5. Enter the output filename.
6. The generated QR code will be saved in the corresponding output folder.
7. View previously generated QR history from the application menu.

---

## Project Highlights

* Modular C++ implementation
* Menu-driven console interface
* SVG-based QR generation
* History tracking using file handling
* Reusable helper functions
* User-friendly validation and error messages

---

## Future Improvements

* PNG Export
* QR Code Scanner
* Batch QR Generation
* GUI Version
* Custom QR Colors
* Logo Embedding

---

## Author

**Hitesh Reddy**

---

## License

This project is licensed under the MIT License.
