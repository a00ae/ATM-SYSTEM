# 🏧 ATM Management System (C++)

A robust and lightweight **Console-Based ATM Application** written in C++. This application allows clients to authenticate using their account credentials and perform standard banking transactions, with automatic file-based data persistence.

---

## ✨ Features

* **🔐 Client Authentication:** Secure login using an Account Number and PIN Code.
* **⚡ Quick Withdraw:** Fast cash withdrawal options with predefined amounts ($20, $50, $100, $200, $400, $600, $800, $1000).
* **💵 Normal Withdraw:** Custom withdrawal amounts validated to ensure they are multiples of 5 and within the client's current balance limit.
* **📥 Account Deposit:** Deposit funds easily with automatic balance updates.
* **📊 Check Balance:** View real-time account balances at any time.
* **💾 Data Persistence:** Client records are automatically read from and written to a flat-file database (`Client.txt`).

---

## 🛠️ Built With

* **Language:** C++
* **Standard Libraries Used:**
  * `<fstream>` — Handling file input/output operations.
  * `<vector>` — Dynamic data structures for client management.
  * `<string>` — String manipulation and parsing.
  * `<iostream>` & `<iomanip>` — Console I/O and text formatting.

---

## 📁 File Data Structure

The application uses a text file named **`Client.txt`** to store account records. Fields are separated using a custom delimiter (`#//#`).

### **Record Format:**
```text
AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance
```

### **Example `Client.txt` Content:**
```text
A101#//#1234#//#John Doe#//#0500000000#//#5000.00
A102#//#4321#//#Jane Smith#//#0550000000#//#1200.00
```

---

## ⚙️ How to Run

1. **Clone or Copy:** Save the source code into a `.cpp` file (e.g., `main.cpp`).
2. **Setup Database File:** Create a file named `Client.txt` in the same directory as your compiled output binary.
3. **Populate Data:** Add sample account entries into `Client.txt` using the delimiter format shown above.
4. **Compile and Run:** Use any C++ compiler or IDE (Visual Studio, Code::Blocks, GCC, CLion):
   ```bash
   g++ -o atm_system main.cpp
   ./atm_system
   ```

---

## 📋 Console Interface Preview

```text
===========================================
            ATM Main Menu Screen
===========================================
    [1] Quick Withdraw.
    [2] Normal Withdraw.
    [3] Deposit.
    [4] Check Balance.
    [5] Logout.
===========================================
```