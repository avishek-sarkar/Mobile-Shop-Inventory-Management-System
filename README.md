# Mobile Shop Inventory Management System

A console-based mobile shop inventory management system written in C. It started as a first-year academic project and was later cleaned up to be more modular, readable, and reliable. In short: a classic C project with a few modern habits.

## About Project

This project manages mobile inventory, sales, income records, and low-stock alerts through a role-based console interface. It is designed for learning, practice, and everyday file-based data handling in C.

## Features

- Role-based access for Seller, Cashier, and Admin
- Password protection for Cashier and Admin
- Add, update, delete, and view mobile records
- Search by brand and price range
- Sales recording with customer details
- Income tracking and sell status reports
- Low-stock alert with color highlight and beep
- Input validation for safer data entry

## Tech Stack

- Language: C
- Compiler: GCC (MinGW)
- Platform: Windows console
- Storage: Binary files (`mob.txt`, `admin.txt`, `income.txt`)

## Installation

### Prerequisites

- Windows OS
- GCC compiler installed

### Clone and build

```bash
git clone https://github.com/avishek-sarkar/Mobile-Shop-Inventory-Management-System.git
cd Mobile-Shop-Inventory-Management-System
gcc -Wall -Wextra -O2 project.c -o mobile_shop.exe
mobile_shop.exe
```

## Project Structure

```text
Mobile-Shop-Inventory-Management-System/
|-- project.c
|-- README.md
|-- admin.txt
|-- mob.txt
|-- income.txt
|-- temp.txt   (created during delete operations)
```

## Code Structure

- Utility functions: safe input, string copy, lowercase conversion, date handling
- Validation helpers: positive and non-negative integer checks
- Role panels: seller, cashier, and admin menus
- Inventory functions: insert, update, delete, display
- Search functions: brand search and price search
- Sales functions: sell product, income status, sell status
- Alert system: low-stock detection and warning display

## Usage

1. Run the program.
2. Choose a role from the main menu.
3. Use Seller to view products and search by brand or price.
4. Use Cashier to search and sell products.
5. Use Admin to manage inventory, sales, and reports.

Default passwords:
- Cashier: `pass`
- Admin: `admin`

## Demo

The examples below mirror the program's printed output. Exact record values depend on the data stored in `mob.txt`, `admin.txt`, and `income.txt`.

### Main Menu

```text
**********************************************
  WELCOME TO OUR MOBILE SHOP MANAGEMENT SYSTEM
**********************************************

        [1]. SELLER
        [2]. CASHIER
        [3]. ADMIN
        [0]. EXIT
```

### Seller Panel

```text
        1. All Products..
        2. Search for Mobile..
        0. Main Menu..

Enter Your Choice : 1
```

### Search Menu

```text
1.SAMSUNG
2.APPLE
3.VIVO
4.OPPO
5.XIAOMI
6.NOKIA
7.LG
8.SYMPHONY
9.Others
0.Main Menu

Enter Your Choice : 1
```

### Search By Brand

```text
Enter Brand : sam

BRAND    : samsung
ID       : 101
MODEL    : Galaxy S21
PRICE    : 65000
QUANTITY : 8
```

### Search By Price Range

```text
Enter Minimum price : 30000
Enter Maximum price : 70000

BRAND    : samsung
ID       : 101
MODEL    : Galaxy S21
PRICE    : 65000
QUANTITY : 8

BRAND    : vivo
ID       : 103
MODEL    : V23
PRICE    : 35000
QUANTITY : 1
```

### Product Inventory Display

```text
*******All products details*******

BRAND           ID       MODEL           MRP        QUANTITY

samsung         101      Galaxy S21      65000      8
apple           102      iPhone 14       95000      5
vivo            103      V23             35000      1 ** LOW STOCK **
```

### Cashier Menu

```text
  1. All Products..
  2. Search for Mobile..
  3. Sell Mobile..
  0. Main Menu..
```

### Cashier Sale

```text
Enter Mobile ID : 101
Enter Mobile Quantity : 2
Enter Total Price : 130000
Enter Customer Name : John Doe
Enter Customer Address : 123 Main St

Recorded Successfully.........
```

### Admin Action

```text
  [1]. Add Mobile..
  [2]. Update Record..
  [3]. Delete Record..
  [4]. All Products..
  [5]. Search For Mobile..
  [6]. Income Status..
  [7]. Sell Status..
  [8]. Sell Products..
  [0]. Main Menu..
```

### Admin Inventory View

```text
*******All products details*******

BRAND           ID       MODEL           WHOLESALEPRICE       MRP        QUANTITY

samsung         101      Galaxy S21      50000                65000      8
apple           102      iPhone 14       75000                95000      5
vivo            103      V23             25000                35000      1 ** LOW STOCK **
```

### Sell Status Menu

```text
        [1]. Todays Sell status !!!...
        [2]. Monthly Sell Status...
        [0]. Main Menu..
```

### Today Sell Status Output

```text
BRAND : samsung
MODEL : Galaxy S21
ID : 101
QUANTITY : 2
TOTAL PRICE : 130000
DATE : 23/04/2026
NAME OF THE CUSTOMER : John Doe
ADDRESS OF THE CUSTOMER : 123 Main St
```

### Income Status Menu

```text
        [1]. Todays Income Status..
        [2]. This Months Income Status..
        [0]. Exit..
```

### Today Income Status Output

```text
BRAND : samsung
ID : 101
INCOME : 30000
TIME : 23/04/2026

Today Total Income : 30000
```

### Low Stock Alert

```text
========================================
*** LOW STOCK ALERT! ***
========================================
Brand: vivo | Model: V23
ID: 103 | Quantity: 1
Action Required: Restock immediately!
========================================
```

## Limitations

- Windows-specific console application
- File-based storage instead of database
- Single-user flow only
- Basic password handling

## Future Enhancements

- Add database support
- Build a GUI version
- Add export options for reports
- Improve authentication security
- Add more advanced analytics

## Contributing

This is primarily an academic project, but suggestions are welcome.

1. Fork the repository
2. Create a branch
3. Commit your changes
4. Open a pull request

## Support

- Email: avishek1416@gmail.com
- Issues: https://github.com/avishek-sarkar/Mobile-Shop-Inventory-Management-System/issues

## Outro

Thanks for checking out the project. It is simple, practical, and built to show what can be done with core C programming, file handling, and a little persistence.
