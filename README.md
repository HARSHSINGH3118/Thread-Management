# 🧵 Custom Thread Library with Advanced Synchronization Mechanisms in C for Windows

## 📋 Project Overview

This project implements a **custom thread library in C** using the Windows API. The library provides functionalities for creating, joining, and managing threads, along with advanced synchronization mechanisms like mutexes and condition variables. The project demonstrates how threads can be utilized to perform various calculations in parallel, with added control over synchronization for safe access to shared resources.

## ✨ Features

- **Thread Management**: Functions to create, join, and exit threads.
- **Synchronization Primitives**: Custom mutexes to prevent race conditions when accessing shared resources.
- **Condition Variables**: Allows threads to wait and signal based on specific conditions.
- **Advanced Calculations**: Threads perform tasks like factorial, prime calculations, and shared counter management.
- **User Interaction**: Accepts user input for dynamic, interactive testing of thread functionality.

## 📂 Project Structure

```plaintext
ThreadLibraryProject/
│
├── src/
│   ├── thread.h             # Header file for thread declarations
│   ├── thread.c             # Core implementation of thread library using Windows API
│   ├── sync_primitives.h    # Header file for synchronization primitives
│   ├── sync_primitives.c    # Implementation of mutexes and condition variables
│   ├── main.c               # Demonstration and test cases
│
├── compile.bat              # Batch script to compile and link files
└── README.md                # Project documentation and instructions
```
## 🛠️ Prerequisites
GCC Compiler for Windows: Install MinGW if you don’t already have GCC on your system.
Windows OS: This project is developed for and tested on Windows with the Windows API.
## 🚀 Setup Instructions
1. Clone or Download the Project
bash
Copy code
git clone <repository_url>
cd ThreadLibraryProject
2. Compile the Project
Run the provided compile.bat script in the Command Prompt:

batch
Copy code
compile.bat
This will compile all source files and create an executable in the build directory named thread_library.exe.

3. Run the Program
Run the executable:
```plaintext
batch
Copy code
build\thread_library.exe
```
## 🎮 Usage
When you run the program, it will prompt you for input values to test various threading functions. Below are some examples of interactions and what each feature demonstrates:

Factorial and Prime Calculations:

The program will ask for a number to calculate its factorial and another number to find all primes up to that number.
It demonstrates multithreading for performing independent computations concurrently.
Condition Variables:

The program creates two threads: one that waits for a condition to be met and another that signals the condition.
Demonstrates the use of condition variables to control thread execution flow based on specific events.
Shared Counter with Mutex:

The user specifies the number of threads that increment a shared counter.
Mutexes are used to prevent race conditions, ensuring that each thread safely increments the counter without interference.
Sample Interaction
```plaintext
Copy code
Enter a number to calculate its factorial: 5
Enter a number to find prime numbers up to that value: 10

Example: Factorial and Prime Number Calculations
Factorial of 5 is 120
Prime numbers up to 10: 2 3 5 7 

Example: Condition Variable with Waiter and Signaler
Thread waiting for condition...
Condition met! Signaling waiting threads.
Thread resumed after condition met.

All threads completed.
```
## 🧩 Code Explanation
1. thread.h and thread.c
Defines and implements core thread functions:

my_thread_create: Creates a new thread using the Windows API.
my_thread_join: Waits for a thread to complete execution.
my_thread_exit: Exits a thread.
2. sync_primitives.h and sync_primitives.c
Defines and implements synchronization mechanisms:

Mutexes: Implemented using CRITICAL_SECTION to lock and unlock critical sections, ensuring safe access to shared resources.
Condition Variables: Allows threads to wait for specific conditions to be met, implemented with CONDITION_VARIABLE.
3. main.c
Demonstrates how to use the custom thread library for various calculations and synchronization scenarios:

Factorial and Prime Calculations: Parallel computations.
Condition Variable: Simulates threads waiting and signaling based on conditions.
Shared Counter with Mutex: Ensures safe access to shared variables.
## 🔍 Advanced Features
User Interaction: Takes input from users to dynamically test different thread functions.
Condition Variables: Implements thread synchronization with condition variables for complex signaling requirements.
Error Handling: Includes basic error handling to ensure stable execution.
## 📌 Compilation and Execution Notes
Ensure that compile.bat runs without errors by verifying your GCC and MinGW installations.
When prompted for input, enter appropriate numbers to observe the output from different threads.
## 🌱 Future Enhancements
Some possible improvements include:
Detached Threads: Implement detached threads that do not require joining.
Priority Scheduling: Add options to control thread priority.
Dynamic Thread Pool: Implement a thread pool for managing reusable threads efficiently.
##🤝 Contributing
Feel free to submit pull requests or suggest improvements! All contributions are welcome to expand and enhance this custom thread library project.

