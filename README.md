# Bhaashakaar: The Hindi-Inspired Programming Language

## 📜 Project Description

Bhaashakaar (meaning "The Linguist" in Hindi) is a unique programming language inspired by the Hindi language and Indian ethos. Designed to make coding more accessible to native Hindi speakers and promote cultural inclusivity in computing, Bhaashakaar integrates familiar linguistic constructs into programming paradigms.

This language is a tribute to the linguistic richness of Hindi and the structural discipline of traditional compilers. It promotes a more intuitive and culturally grounded approach to learning programming concepts.

It follows principles that resonate with the Indian way of learning:

- Spashtata (Clarity) — Programs should be easy to read and understand  
- Uddeshya (Purpose) — Every line of code must have a meaningful role  
- Samanvay (Coordination) — Code should be cohesive and well-structured  
- Saundarya (Elegance) — Aesthetic in logic and presentation  

---

## 👤 Student Information

- Student Name: Sahil Agrawal
- Enrollment ID: 22000927

---

## 📦 Project Components

- bhaashakaar.l — Flex file for lexical analysis using Hindi-style tokens  
- bhaashakaar.y — Bison file defining the grammar and parsing rules  
- bhaashakaar.tab.c / bhaashakaar.tab.h — Auto-generated parser code  
- lex.yy.c — Auto-generated lexer code  
- compiler.exe, bhashakaar.exe, bhaashakaar.exe — Compiled binaries  
- sample/ — Folder containing sample Hindi-based programs:
  - hello_world.txt
  - if_else.txt
  - for.txt
  - while.txt
  - arithmetic_op.txt

---

## ⚙️ How to Run Bhaashakaar Programs

### 🧱 Compilation Instructions

To compile and execute Bhaashakaar programs, follow these steps:

1. Generate the parser using Bison:
   bash
   bison -d bhaashakaar.y

2. *Generate the lexer using Flex:*
   bash
   flex bhaashakaar.l

3. Compile the generated files using GCC:
   bash
   gcc lex.yy.c bhaashakaar.tab.c -o bhaashakaar

4. *Run a sample Bhaashakaar program:*
   bash
   ./bhaashakaar sample/hello_world.txt

### 📂 Example Program (hello_world.txt)
program main {
    sankhya main() {
        chhap "Hello, World!";
        return 0;
    }
}
ant

### 💻 System Requirements
- GCC Compiler
- Flex (Fast Lexical Analyzer)
- Bison (GNU Parser Generator)
- Unix/Linux or compatible environment

### ✨ Features
- Hindi-based syntax for core programming constructs
- Support for control structures like loops and conditionals
- Standard output printing with native terms 
- Simple grammar encouraging beginner-friendly programming
- Ideal for academic projects in compiler design and linguistics integration

### 🙏 Acknowledgments
- Heartfelt thanks to Prof. Vaibhavi Patel for her continuous support and motivation during this project
- Special appreciation to Heer Patel for his contribution and helping me test and refine the language

### 📚 Inspiration
Bhaashakaar is more than a compiler project — it's a cultural experiment aimed at merging regional language learning with global tech fluency. It makes programming more inclusive by reflecting the language of its users and bridges the gap between native thought and computational logic.
