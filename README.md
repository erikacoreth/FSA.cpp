# Finite State Automaton (FSA) in C++

This project implements a simple **Finite State Automaton (FSA)** in C++ that processes strings over the alphabet `{ a, b, c }`. The FSA accepts strings that:

- Are **at least three characters long**, and  
- Contain **a sequence of three consecutive 'a's or three consecutive 'b's**.

---

## 🧠 Project Purpose

This project was built as a learning exercise to:

- Practice building state machines in C++
- Gain comfort with classes, enums, and input/output in C++
- Translate logic I originally wrote in Python to C++ syntax and style

---

## 🗂️ Files in This Project

- `main.cpp` – Contains the `FSA` class and main logic to process input strings
- `Python_vs_Cpp_CheatSheet.pdf` – A beginner-friendly cheat sheet comparing Python vs C++ syntax

---

## 🔧 How It Works

The `FSA` class defines:
- An `enum` for states (Start, A1, A2, B1, B2, Accept, Reject)
- A method `ProcessChar(char c)` to transition between states
- A method `IsAccepted()` that returns whether the input string was accepted

The `main()` function:
1. Prompts the user to enter a string
2. Feeds each character to the FSA
3. Prints whether the string is accepted or rejected


---

## 📚 How to Run

1. Clone this repo:
   ```bash
   git clone https://github.com/your-username/fsa-cpp-project.git
   cd fsa-cpp-project

compile this program:
g++ -o fsa main.cpp

run the executable:
./fsa

