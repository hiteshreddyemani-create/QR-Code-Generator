# QR Code Generator using C++

## Overview

QR Code Generator is a menu-driven C++ application that generates real, scannable QR codes and saves them as SVG files. The project is designed with a modular structure and organized output directories for different QR code categories.

## Features

### Completed Features

* Website URL QR Code Generation
* Real Scannable QR Codes
* SVG File Export
* Custom Output File Names
* Organized Output Folder Structure
* Menu-Driven Interface

### Upcoming Features

* Plain Text QR
* Wi-Fi QR
* Email QR
* Phone Number QR
* Contact (vCard) QR
* Input Validation
* Improved Terminal Interface

## Project Structure

```text
QR-Code-Generator/
│
├── include/
├── src/
├── output/
│   ├── websites/
│   ├── text/
│   ├── wifi/
│   ├── email/
│   ├── phone/
│   └── contacts/
│
├── README.md
└── .gitignore
```

## Technologies Used

* C++
* Visual Studio Code
* MinGW g++
* SVG Format
* Git
* GitHub

## Build

Compile:

```bash
g++ src/main.cpp src/qrcodegen.cpp -Iinclude -std=c++11 -o qr
```

Run:

```bash
.\qr.exe
```

## Project Status

🚧 This project is currently under development. Additional QR code types and features will be added in future updates.
