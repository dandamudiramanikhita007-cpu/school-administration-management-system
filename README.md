# school-administration-management-system
📘 Project Title

School Administration Management System using Class Hierarchy Tree

📌 Problem Statement

Managing school data such as classes and students manually is difficult and time-consuming. There is a need for a system that can organize and manage hierarchical data efficiently. The system should support operations like adding, viewing, updating, and deleting records.

🌍 Real-world Application
School and college management systems
Company organizational hierarchy
File and folder systems in computers
Library management systems

👉 Used wherever parent-child relationships exist

🌳 Data Structure Used

Tree (Class Hierarchy Tree using Child-Sibling Representation)

🔹 Explanation
The structure follows a hierarchy:
Root → School
Intermediate nodes → Classes
Leaf nodes → Students
Each node contains:
Data (name)
Link to child
Link to sibling
🏗️ System Design
7
Structure:
School
  ├── Class1
  │     ├── Student1
  │     └── Student2
  └── Class2
        └── Student3
⚙️ Algorithm
🔹 Create (Add Node)
Start from root (School)
Enter parent node
If parent exists → add new node as child or sibling
Else → display error
🔹 Read (Display)
Start from root
Print node
Recursively display child nodes
Move to sibling nodes
🔹 Update (Modify Node)
Search for node by name
If found → change data
Else → display "Not found"
🔹 Delete (Remove Node)
Search for node
Remove it from parent link
Free memory
Adjust sibling links
🔹 Search
Compare current node
If not found → search child
Then search sibling
⚙️ Implementation (Concepts Used)
C language
Structures (struct)
Dynamic memory allocation (malloc, free)
Functions (modular programming)
Recursion
Menu-driven approach
<img width="374" height="293" alt="Screenshot 2026-03-27 144047" src="https://github.com/user-attachments/assets/924e5ed0-95ed-4044-9789-d283645721d6" />
<img width="414" height="312" alt="Screenshot 2026-03-27 144041" src="https://github.com/user-attachments/assets/d38bfdc8-49b1-4ca0-b317-138435182b31" />


🎯 Conclusion

This project demonstrates how a tree data structure can be used to manage hierarchical data in a school system. It efficiently supports CRUD operations and follows modular programming. The system is simple, flexible, and can be extended for real-world applications.
