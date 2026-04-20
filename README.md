# Address Book Application in C

## Project Overview

The **Address Book Application** is a menu-driven program developed using **C programming** that allows users to store, manage, and retrieve contact information efficiently.

This project demonstrates the use of **file handling**, **structures**, and **CRUD operations (Create, Read, Update, Delete)** to maintain persistent contact records.

---

##  Features

 Add new contact details  
 View all saved contacts  
 Search contact by name  
 Edit existing contact information  
 Delete unwanted contacts  
 Store contact data permanently using file handling  
 Menu-driven user interface  

---

## Technologies Used

- **Programming Language:** C  
- **Concepts Applied:**
  - Structures
  - File Handling
  - Functions
  - Arrays
  - CRUD Operations
  - Menu-driven Programming

---

## Project Structure
Address-Book/
│
├── main.c → Main program execution
├── contact.c → Contact operations
├── file.c → File handling operations
├── file.h → Header file
├── contacts.txt → Contact data storage
├── README.md → Project documentation

 
---

## How to Compile

Use GCC compiler:

```bash
gcc main.c contact.c file.c -o addressbook

How to Run
./addressbook

Sample Output
===== Address Book Menu =====

1. Add Contact
2. View Contacts
3. Search Contact
4. Edit Contact
5. Delete Contact
6. Exit

Enter your choice:


Learning Outcomes

✔ Learned file handling techniques in C
✔ Implemented structured data storage
✔ Practiced CRUD operations
✔ Developed menu-driven console applications
✔ Improved problem-solving and logic-building skills

🔮 Future Enhancements

🔹 Add phone number validation
🔹 Implement sorting contacts
🔹 Add password protection
🔹 Improve user interface
