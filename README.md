# 🧭 Graph Algorithms in C++ — BFS, DFS, and Dijkstra

![Graph Algorithms](https://upload.wikimedia.org/wikipedia/commons/5/5d/Graph_algorithms.png)

## 📖 Overview
This project is a **menu-driven C++ program** that demonstrates three fundamental graph algorithms —  
**Breadth-First Search (BFS)**, **Depth-First Search (DFS)**, and **Dijkstra’s Shortest Path Algorithm** — all integrated into one file.

It allows users to:
- Build a graph using **user input**
- Choose an algorithm to execute
- Visualize traversal or shortest paths directly in the terminal

---

## 🚀 Features
- 🧩 Single program for **BFS**, **DFS**, and **Dijkstra**
- 🔁 **Interactive menu** to choose algorithms  
- ⚡ Supports **weighted** and **unweighted** graphs  
- 🧠 Clean and beginner-friendly **C++ code structure**  
- 📚 Great for learning and demonstration  

---

## 🧠 Algorithms Explained

### 🔹 **1. Breadth-First Search (BFS)**
**Type:** Traversal (Unweighted Graphs)  
**Working:**  
- BFS explores the graph **level by level**, starting from the source node.  
- It uses a **queue** to visit neighbors first before moving deeper.  
- This guarantees the **shortest path** in an unweighted graph.  

**Example Traversal:**  
For the graph:  
0 - 1 - 3
| |
2 - 4 - 5

markdown
Copy code
Starting from node `0` → **Traversal:** `0 → 1 → 2 → 3 → 4 → 5`

**Time Complexity:** O(V + E)  
**Space Complexity:** O(V)  

---

### 🔹 **2. Depth-First Search (DFS)**
**Type:** Traversal (Recursive or Stack-based)  
**Working:**  
- DFS goes **deep into one branch** of the graph before backtracking.  
- It uses **recursion or a stack** to track visited nodes.  
- Ideal for detecting **cycles**, **connected components**, and performing **topological sorting**.  

**Example Traversal:**  
For the same graph as above:  
0 - 1 - 3
| |
2 - 4 - 5

pgsql
Copy code
Starting from node `0` → **Traversal:** `0 → 1 → 3 → 5 → 4 → 2`

**Time Complexity:** O(V + E)  
**Space Complexity:** O(V)  

---

### 🔹 **3. Dijkstra’s Shortest Path Algorithm**
**Type:** Pathfinding (Weighted Graphs, No Negative Weights)  
**Working:**  
- Dijkstra’s algorithm finds the **shortest path** from a source node to all others.  
- It uses a **priority queue (min-heap)** to always expand the node with the smallest tentative distance.  
- Updates the shortest distance of each neighbor if a shorter path is found.  

**Example Graph:**
0 --(4)-- 1
| \ |
(2) (5) (10)
| \ |
2 --(3)-- 4 --(4)-- 3 --(11)-- 5

javascript
Copy code
Starting from node `0`:
Shortest distances:
To 0 = 0
To 1 = 4
To 2 = 2
To 3 = 9
To 4 = 5
To 5 = 20

yaml
Copy code

**Time Complexity:** O((V + E) log V)  
**Space Complexity:** O(V + E)

---

## 💻 How to Run

### 1️⃣ Clone the Repository
```bash
git clone https://github.com/your-username/graph-algorithms-cpp.git
cd graph-algorithms-cpp
