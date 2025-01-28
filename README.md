# Library Management System

A **C program** that allows users to manage a small library system, store book data, and save it in a JSON file for persistence. This project demonstrates the integration of the **cJSON library** for working with JSON data in C.

---

## Features
- **Add Books**: Input book details such as title, author ID, and price.
- **Display All Books**: View the list of all books in the library.
- **Search by Author**: Find books by a specific author using their author ID.
- **Total Books**: Display the total number of books in the library.
- **JSON Storage**: Save and load book data to/from a JSON file (`library.json`).

---

## Prerequisites
- A **C Compiler** (e.g., GCC).
- **VS Code** or any text editor.
---

## Project Structure
-Library Management
-     Lib.c
-     cJSON.c
-     cjson.h

## How to Run
### Step 1: Clone the Repository
Clone the repository to your local system:
```bash
git clone https://github.com/your-username/BookHive.git
cd BookHive

gcc lib.c cJSON.c -o bookhive
./Lib.c
