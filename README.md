Library Management System in C
A C-based Library Management System that allows users to add, manage, and search for books. This project demonstrates a simple console application with functionality for book management, providing an easy-to-use interface.

Features
Add Books: Add new books with details such as title, author ID, and price.

Display All Books: View all books stored in the library.

Search by Author: Search and display books by a specific author ID.

Total Books: Display the total number of books currently in the library.

Prerequisites
To run this project, you need:

A C Compiler (e.g., GCC).

Project Structure
Copy
LibraryManagement/
│
├── lib.c                # Main program file
└── library.json         # JSON file for storing book data (optional, if using JSON persistence)
How to Run
Step 1: Compile the Program
Use GCC to compile the program:

bash
Copy
gcc lib.c -o library
Step 2: Run the Program
Execute the compiled program:

bash
Copy
./library
Usage
Add Books: Enter book title, author ID, and price.

View Books:

Display all books stored in the library.

Search for books by a specific author using their author ID.

Save Data: If JSON persistence is integrated, book data is saved automatically (e.g., to library.json).

Load Data: If JSON persistence is integrated, data is loaded when the program starts.

Example Workflow
Adding Books
Copy
1. Add Book
Enter book title: CProgrammingBasics
Enter author ID: 101
Enter price: 299.99
Book added successfully!
Displaying All Books
Copy
2. Display All Books
Book Information:
Title: CProgrammingBasics
Author ID: 101
Price: 299.99
Contribution
Contributions are welcome! Feel free to:

Report bugs.

Suggest new features.

Open a pull request with your improvements.

License
This project is open-source and free to use. Add your preferred license here if needed.

Author
Developed by Vishwaridha S. 🎉
