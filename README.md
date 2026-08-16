
# Inverted Search in C

## 📌 Overview

Inverted Search is a file indexing and searching project implemented in **C**.

The project creates an **inverted index** from multiple `.txt` files. Instead of searching through every file whenever a word is queried, the program maintains a database that maps each word to the files in which it occurs.

For example:

```text
Search Word: data

data
 ├── file1.txt → 5 occurrences
 ├── file2.txt → 2 occurrences
 └── file3.txt → 7 occurrences
```

This allows the program to retrieve information about a word without scanning every file again.

---

## 🎯 Objectives

The main objectives of this project are:

* Implement an inverted index using C
* Understand and implement hash tables
* Handle hash collisions using linked lists
* Work with structures and pointers
* Practice dynamic memory allocation
* Implement file handling in C
* Implement searching and indexing
* Store and retrieve the database using files

---

## ⚙️ Features

### 1. Create Database

The program reads words from the given `.txt` files and creates the inverted index.

During database creation, the program:

* Reads each file
* Extracts individual words
* Calculates the hash index
* Creates nodes for new words
* Updates existing words
* Stores file names
* Maintains the occurrence count of each word

---

### 2. Display Database

Displays the complete inverted index.

The database contains information such as:

* Hash index
* Word
* Number of files containing the word
* File name
* Number of occurrences in each file

Example:

```text
---------------------------------------------------------------------------
Index    Word          File Count       File Name        Word Count
---------------------------------------------------------------------------
0        apple         2                 file1.txt          4
                                         file2.txt          2

1        data          3                 file1.txt          5
                                         file2.txt          2
                                         file3.txt          7
---------------------------------------------------------------------------
```

---

### 3. Search

Allows the user to search for a particular word.

If the word exists, the program displays:

* The word
* Number of files containing the word
* File names
* Number of occurrences in each file

Example:

```text
Enter the word to search: data

Word Found: data
File Count: 2

file1.txt → 5 occurrences
file2.txt → 3 occurrences
```

If the word does not exist, an appropriate message is displayed.

---

### 4. Update Database

New `.txt` files can be added to an existing database.

The existing index is retained while information from the newly added files is incorporated into the database.

If a word already exists, its file information and occurrence count are updated.

If the word is new, a new node is created.

---

### 5. Save Database

The current inverted index can be saved into a file.

This allows the database to be preserved even after the program terminates.

The saved database can later be restored without recreating the entire index from the original text files.

---

### 6. Restore Database

A previously saved database can be restored from a file.

The program reconstructs the inverted index in memory, allowing operations such as:

* Display
* Search
* Update

to be performed on the restored database.

---

## 🛠️ Technologies Used

* **Language:** C
* **Data Structures:**

  * Hash Table
  * Linked List
* **Concepts:**

  * Structures
  * Pointers
  * Dynamic Memory Allocation
  * File Handling
  * String Handling
  * Hashing
  * Linked Lists
  * Modular Programming

---

## ▶️ Compilation

Clone the repository:

```bash
git clone <repository-url>
```

Navigate into the project directory:

```bash
cd Inverted_Search
```

Compile using GCC:

```bash
gcc *.c -o inverted_search
```

Since `Makefile` is provided, the project can also be compiled using:

```bash
make
```

---

## ▶️ Running the Program

Run the executable using:

```bash
./inverted_search
```

The program provides a menu for performing different operations.

Example:

```text
1. Create Database
2. Display Database
3. Search
4. Save Database
5. Update Database
6. Restore Database
7. Exit
```

Select the required option and follow the instructions displayed by the program.

---

## 📚 Concepts Learned

This project provided practical experience with:

* Hash table implementation
* Collision handling
* Linked lists
* Structures
* Nested structures
* Pointer manipulation
* Dynamic memory allocation
* File I/O
* String processing
* Modular programming
* Database persistence
* Debugging segmentation faults
* Managing dynamically allocated memory

The project also helped bridge the gap between understanding data structures theoretically and implementing them in a real C application.

---

## 🚀 Future Improvements

Some possible improvements include:

* Implementing a more optimized hash function
* Supporting more file formats
* Improving database serialization

---

## 👨‍💻 Author

**Manoj B**



