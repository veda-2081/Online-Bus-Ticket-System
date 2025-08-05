# 🚌 Online Bus Ticket Reservation System

## 📌 Project Description

This project implements an **Online Bus Ticket Reservation System** using **C++** with core **Data Structures and Algorithms**. The system allows users to **book, cancel, modify, and view bus tickets** efficiently through a menu-driven console application. 

It is ideal for learning and demonstrating how arrays, linked lists, queues, and trees can be applied in a real-world reservation system.

---

## 🧩 Features

- 🎫 Book tickets with passenger details
- ❌ Cancel booked tickets
- 🔄 Modify passenger details
- 🧾 Display all reservations
- 🚍 Maintain bus information (seats, routes, times)
- 📚 Console-based user interface

---

## 🛠️ Technologies Used

- 💻 Language: C++  
- 📂 Platform: Terminal / CLI  
- 🧠 Concepts:  
  - Arrays for seat allocation  
  - Linked Lists for reservation records  
  - Trees or Graphs for route suggestions (optional)  
  - Sorting algorithms for passenger lists  

---

## 🗂️ File Structure

```

├── bus reservation system.cpp   # Main source code
├── DS PROJECT Batch-9.pptx      # Project presentation slides
├── LICENSE                      # MIT License
├── README.md                    # Project documentation

````

---

## 🚀 How to Run

### Compile:
```bash
g++ "bus reservation system.cpp" -o bus_reservation
````

### Run:

```bash
./bus_reservation
```

> Make sure you’re using a C++11+ compatible compiler.

---

## 📈 Sample Data Structures Used

```cpp
struct Passenger {
    string name;
    int age;
    string gender;
    Passenger* next;
};
```

* Linked list to manage multiple passengers
* Array to store and update seat status
* Optionally: Graph or matrix for routes

---

## 🎯 Learning Outcomes

* Application of core DSA in real-world scenarios
* Dynamic memory allocation using linked lists
* Menu-driven programming with proper control flow
* Better understanding of object-oriented programming in C++

---

## 📄 License

This project is licensed under the **MIT License**.
See the `LICENSE` file for more details.

---

## 🙌 Contributions

Pull requests and suggestions are welcome!
Feel free to fork the project and enhance features like:

* Add GUI using Qt or Python
* Use files for persistent storage
* Route optimization logic

