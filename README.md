# 📱 Mobile Shop Inventory Management System

<div align="center">

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![License](https://img.shields.io/badge/license-MIT-green?style=for-the-badge)
![Status](https://img.shields.io/badge/status-active-success?style=for-the-badge)

**A comprehensive console-based inventory management system for mobile phone shops**

[Features](#-features) • [Installation](#-installation) • [Usage](#-usage) • [Tech Stack](#-tech-stack) • [Demo](#-demo)

---

<img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=600&size=28&duration=3000&pause=1000&color=00599C&center=true&vCenter=true&width=600&lines=First+Year+Academic+Project;Refactored+%26+Polished;Fully+Functional+System;Console+Based+C+Application" alt="Typing SVG" />

</div>

## 📖 About The Project

This **Mobile Shop Inventory Management System** was developed as my **first-year academic project** at university. While it may not be the flashiest solution in today's GUI-driven world, it represents a **fully functional console-based application** that gave me invaluable hands-on experience with real-world programming concepts.

### 🌟 The Journey

> *"Every expert was once a beginner."*

After completing my first year, I felt the urge to **revisit and refine** this project. What started as a simple academic assignment has been transformed into a **clean, modular, and production-ready codebase** through careful refactoring and the application of software engineering best practices.

**This project taught me:**
- 📚 Fundamental C programming concepts
- 🏗️ Software architecture and design patterns
- 🔒 Security and input validation
- 📁 File I/O operations and data persistence
- 🐛 Debugging and problem-solving skills
- ♻️ Code refactoring and maintainability

---

## ✨ Features

<details open>
<summary><b>🔐 Role-Based Access Control</b></summary>

```
┌─────────────────────────────────────────┐
│  👤 SELLER                              │
│  • View all products                    │
│  • Search inventory                     │
│  • Check product availability           │
└─────────────────────────────────────────┘

┌─────────────────────────────────────────┐
│  💰 CASHIER (Password Protected)        │
│  • All Seller features                  │
│  • Process sales transactions           │
│  • Generate customer receipts           │
└─────────────────────────────────────────┘

┌─────────────────────────────────────────┐
│  👨‍💼 ADMIN (Password Protected)          │
│  • Complete system control              │
│  • Add/Update/Delete products           │
│  • View sales & income reports          │
│  • Manage inventory                     │
└─────────────────────────────────────────┘
```

</details>

<details open>
<summary><b>📦 Inventory Management</b></summary>

- ➕ **Add Products**: Register new mobile phones with brand, model, price, and quantity
- 🔄 **Update Records**: Modify product details or update stock quantities
- 🗑️ **Delete Products**: Remove discontinued items from inventory
- 📋 **View Inventory**: Display all products with detailed information
- 🔍 **Smart Search**: Search by brand or price range

</details>

<details open>
<summary><b>💼 Sales & Transactions</b></summary>

- 🛒 **Process Sales**: Complete transactions with customer details
- 📊 **Sales Reports**: Daily and monthly sales summaries
- 💵 **Income Tracking**: Monitor revenue with detailed income reports
- 📈 **Profit Analysis**: Automatic profit calculation (MRP - Wholesale Price)

</details>

<details open>
<summary><b>🔔 Low Stock Alert System</b></summary>

- ⚠️ **Visual Indicators**: Red color highlighting for low stock items
- 🔊 **Audio Alerts**: System beep notifications
- 📢 **Real-time Notifications**: Instant alerts after sales
- ⚙️ **Configurable Threshold**: Customizable stock level warnings

</details>

<details open>
<summary><b>🛡️ Security & Validation</b></summary>

- 🔐 **Password Authentication**: Secure access for Cashier and Admin roles
- ✅ **Input Validation**: Prevents negative prices and invalid quantities
- 🚫 **Duplicate Prevention**: Checks for duplicate product IDs
- 🛡️ **Buffer Overflow Protection**: Safe input handling throughout
- 📝 **Data Integrity**: Validates all user inputs before processing

</details>

---

## 🚀 Tech Stack

### **Language & Tools**

| Technology | Purpose |
|-----------|---------|
| ![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white) | Core programming language |
| ![GCC](https://img.shields.io/badge/GCC-Compiler-red?style=flat) | Compilation toolchain |
| ![File I/O](https://img.shields.io/badge/File%20I%2FO-Data%20Storage-green?style=flat) | Binary file operations for data persistence |
| ![Windows](https://img.shields.io/badge/Windows-Terminal-blue?style=flat) | Target platform |

### **Key Concepts Implemented**

```c
✅ Structures & File Handling
✅ Modular Programming & Functions
✅ Input/Output Operations
✅ Search & Sorting Algorithms
✅ Data Validation & Error Handling
✅ Security & Authentication
✅ Memory Management
✅ String Manipulation
```

---

## 📥 Installation

### Prerequisites

- GCC Compiler (MinGW for Windows)
- Windows Operating System
- Terminal/Command Prompt

### Quick Start

```bash
# Clone the repository
git clone https://github.com/avishek-sarkar/Mobile-Shop-Inventory-Management-System.git

# Navigate to project directory
cd Mobile-Shop-Inventory-Management-System

# Compile the program
gcc project.c -o mobile_shop.exe

# Run the application
mobile_shop.exe
```

### Build from Source

```bash
# For detailed compilation
gcc -Wall -Wextra -O2 project.c -o mobile_shop.exe

# For debugging
gcc -g -Wall project.c -o mobile_shop_debug.exe
```

---

## 🎮 Usage

### 1️⃣ **Launch the Application**

```
**********************************************
  WELCOME TO OUR MOBILE SHOP MANAGEMENT SYSTEM
**********************************************

        [1]. SELLER
        [2]. CASHIER
        [3]. ADMIN
        [0]. EXIT

Enter your choice :
```

### 2️⃣ **Navigate Through Roles**

#### **Seller Panel** (No Authentication Required)
```
1. All Products
2. Search for Mobile
0. Main Menu
```

#### **Cashier Panel** (Password: `pass`)
```
1. All Products
2. Search for Mobile
3. Sell Mobile
0. Main Menu
```

#### **Admin Panel** (Password: `admin`)
```
[1]. Add Mobile
[2]. Update Record
[3]. Delete Record
[4]. All Products
[5]. Search For Mobile
[6]. Income Status
[7]. Sell Status
[8]. Sell Products
[0]. Main Menu
```

### 3️⃣ **Sample Operations**

#### Adding a Product
```
Enter the Mobile brand : Samsung
Enter Mobile Id : 101
Enter Model : Galaxy S21
Enter Wholesell Price : 50000
Enter MRP : 65000
Enter quantity of the mobile : 10

Recorded Successfully.........
```

#### Processing a Sale
```
Enter Mobile ID : 101
Enter Mobile Quantity : 2
Enter Total Price : 130000
Enter Customer Name : John Doe
Enter Customer Address : 123 Main St

Recorded Successfully.........

========================================
*** LOW STOCK ALERT! ***
========================================
Brand: samsung | Model: Galaxy S21
ID: 101 | Quantity: 8
Action Required: Restock immediately!
========================================
```

---

## 📊 Demo

### Main Menu
```
**********************************************
  WELCOME TO OUR MOBILE SHOP MANAGEMENT SYSTEM
**********************************************

        [1]. SELLER
        [2]. CASHIER
        [3]. ADMIN
        [0]. EXIT
```

### Product Inventory Display
```
*******All products details*******

BRAND           ID       MODEL           MRP        QUANTITY

samsung         101      Galaxy S21      65000      8
apple           102      iPhone 14       95000      5
vivo            103      V23             35000      1 ** LOW STOCK **
```

### Low Stock Alert
```
========================================
*** LOW STOCK ALERT! ***
========================================
Brand: vivo | Model: V23
ID: 103 | Quantity: 1
Action Required: Restock immediately!
========================================
```

---

## 🏗️ Project Structure

```
mobile-shop-management/
│
├── project.c              # Main source code
├── README.md              # Project documentation
├── LICENSE                # MIT License
│
├── mob.txt                # Product inventory (binary file)
├── admin.txt              # Sales records (binary file)
├── income.txt             # Income records (binary file)
└── temp.txt               # Temporary file for delete operations
```

### Code Architecture

```
📁 Main Components
│
├── 🔧 Utility Functions
│   ├── safe_string_copy()
│   ├── safe_input()
│   ├── to_lowercase()
│   ├── get_current_date()
│   ├── get_positive_integer()
│   └── get_non_negative_integer()
│
├── 🎭 Role Panels
│   ├── seller_panel()
│   ├── cashier_panel()
│   └── admin_panel()
│
├── 📦 CRUD Operations
│   ├── insert_record()
│   ├── update_record()
│   ├── del_record()
│   └── display_record()
│
├── 🔍 Search Operations
│   ├── search_by_brand_prefix()
│   ├── search_brand()
│   └── search_price()
│
├── 💰 Business Logic
│   ├── sell_product()
│   ├── income_status()
│   └── sell_status()
│
└── 🔔 Alert System
    ├── is_low_stock()
    └── show_low_stock_alert()
```

---

## 🎓 Learning Outcomes

### What I Learned Building This Project

#### **Before Refactoring**
- ❌ Code duplication (8 similar search functions)
- ❌ No input validation
- ❌ Hardcoded values throughout
- ❌ Poor error handling
- ❌ Inconsistent naming conventions

#### **After Refactoring**
- ✅ **Modular Design**: Single generic search function
- ✅ **Comprehensive Validation**: All inputs checked
- ✅ **Configuration Constants**: Easy to modify settings
- ✅ **Robust Error Handling**: Graceful failure management
- ✅ **Clean Code**: Consistent style and naming

#### **Key Improvements**
```c
// Before (Code Duplication)
void samsung_search() { /* search code */ }
void apple_search() { /* same search code */ }
void vivo_search() { /* same search code */ }
// ... 8 similar functions

// After (DRY Principle)
void search_by_brand_prefix(const char *prefix, int prefix_len) {
    // Single reusable function
}
```

---

## 🔮 Future Enhancements

While this project is complete for its academic purpose, here are potential improvements:

- [ ] **GUI Interface**: Develop a graphical frontend using Qt or GTK
- [ ] **Database Integration**: Replace file storage with SQLite
- [ ] **Multi-user Support**: Implement concurrent user sessions
- [ ] **Barcode Scanning**: Add barcode/QR code support
- [ ] **Report Generation**: Export reports to PDF/Excel
- [ ] **Cloud Backup**: Implement automatic cloud synchronization
- [ ] **Mobile App**: Create a companion mobile application
- [ ] **Analytics Dashboard**: Add data visualization and charts

---

## 🐛 Known Limitations

> *"Perfect is the enemy of good." - Voltaire*

This is a **console-based application** with inherent limitations:

- 🖥️ **Platform Dependent**: Designed for Windows (uses `conio.h`, `system("cls")`)
- 💾 **File-Based Storage**: Uses binary files instead of a database
- 👤 **Single User**: No concurrent access support
- 🎨 **Limited UI**: Console interface only
- 🔒 **Basic Security**: Simple password system (not encrypted)

**But remember:** This project demonstrates **core programming concepts** and was an excellent learning experience!

---

## 🤝 Contributing

While this is primarily an academic project, suggestions and improvements are welcome!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

---

## 📝 License

Distributed under the MIT License. See `LICENSE` for more information.

---

## 🙏 Acknowledgments

- 🎓 My university professors for guidance
- 📚 Online C programming resources and documentation
- 👥 Peer reviewers who provided feedback
- 💡 Stack Overflow community for problem-solving help

---

## 💭 Final Thoughts

<div align="center">

> *"This project may not be the most practical solution in today's world, but it represents my journey from a beginner to a more confident programmer. Every line of code taught me something new, every bug made me stronger, and every refactoring session improved my understanding of software engineering."*

### ⭐ If you found this project interesting or learned something from it, please consider giving it a star!

[![GitHub stars](https://img.shields.io/github/stars/avishek-sarkar/Mobile-Shop-Inventory-Management-System?style=social)](https://github.com/avishek-sarkar/Mobile-Shop-Inventory-Management-System/stargazers)

---

**Made with ❤️ and ☕ during my First Year at University**

*Last Updated: October 2025*

</div>

---

## 📞 Support

If you have any questions or need help running the project:

- 📧 Email: avishek1416@gmail.com
- 💬 [Open an Issue](https://github.com/avishek-sarkar/Mobile-Shop-Inventory-Management-System/issues)

---

<div align="center">

### 🌟 Thank you for checking out my project! 🌟

![Visitors](https://visitor-badge.laobi.icu/badge?page_id=yourusername.mobile-shop-management)

</div>
