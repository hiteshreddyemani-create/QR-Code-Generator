# QR Code Generator

A menu-driven QR Code Generator developed in **C++** that supports generating multiple types of QR codes, including Website URLs, Plain Text, Wi-Fi credentials, Email, Phone Numbers, Contact (vCard), and UPI Payments.

The application features configurable QR Error Correction Levels, input validation, history logging, overwrite protection, and an organized folder structure for generated QR codes.

---

## Features

* Website URL QR Code Generation
* Plain Text QR Code Generation
* Wi-Fi QR Code Generation
* Email QR Code Generation
* Phone Number QR Code Generation
* Contact (vCard) QR Code Generation
* UPI Payment QR Code Generation
* Configurable Error Correction Levels (LOW, MEDIUM, QUARTILE, HIGH)
* QR Generation History Logging
* View History from the Application Menu
* Automatic URL Formatting (`https://`)
* Input Validation
* Whitespace Trimming
* Duplicate Filename Detection
* Overwrite Confirmation
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

## Project Structure

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

| QR Type         | Purpose                                  |
| --------------- | ---------------------------------------- |
| Website         | Open websites directly                   |
| Plain Text      | Store any text                           |
| Wi-Fi           | Share Wi-Fi credentials                  |
| Email           | Compose an email with pre-filled details |
| Phone           | Dial a phone number                      |
| Contact (vCard) | Share contact information                |
| UPI Payment     | Make UPI payments                        |

---

## Input Validation

The application includes validation for:

* Empty inputs
* Phone number format
* UPI ID format
* Email fields
* URL formatting
* Leading and trailing whitespace
* Duplicate filenames before saving

---

## Error Correction Levels

Users can choose one of four QR Error Correction Levels.

| Level    | Recovery Capacity |
| -------- | ----------------- |
| LOW      | ~7%               |
| MEDIUM   | ~15%              |
| QUARTILE | ~25%              |
| HIGH     | ~30%              |

---

## Build Instructions

Compile the project:

```bash
g++ src/main.cpp src/qrcodegen.cpp -Iinclude -std=c++11 -o qr
```

Run the application:

### Windows

```powershell
.\qr.exe
```

### Linux/macOS

```bash
./qr
```

---

## Usage

1. Launch the application.
2. Select the desired QR type.
3. Enter the required information.
4. Choose an Error Correction Level.
5. Enter an output filename.
6. The QR code will be saved to the appropriate folder.
7. View QR generation history directly from the application menu.

---

## Screenshots

> Screenshots will be added soon.

Suggested screenshots:

* Main Menu
* Website QR Generation
* Wi-Fi QR Generation
* UPI QR Generation
* QR History Viewer

---

## Future Enhancements

* PNG Export
* GUI Version
* QR Code Scanner
* Batch QR Generation
* Logo Embedding
* Custom QR Colors

---

## Author

**Hitesh Reddy**

---

## License

This project is licensed under the MIT License.
