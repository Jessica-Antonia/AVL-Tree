# AVL Tree Map in C++
### A Self-Balancing Binary Search Tree Implemented by **Jessica Venema**

This project implements a fully functional **AVL Tree Map** in C++.  
It behaves like a dictionary: storing and retrieving `(int key, string value)` pairs in **O(log n)** time using self-balancing rotations.

> Designed for CS3100 – Data Structures & Algorithms. The tree supports insertion, search, range queries, formatted printing, and deep copy operations while remaining height-balanced.  
> 

---

## 🔧 Features

### Supported Operations
| Operation | Description | Time Complexity |
|---|---|---|
| `insert(key, value)` | Adds a new key/value pair, rejects duplicates | **O(log n)** |
| `find(key, value&)` | Retrieves the value for a given key | **O(log n)** |
| `findRange(low, high)` | Returns all values with keys in `[low, high]` | **O(k + log n)** |
| `getHeight()` | Returns current tree height | **O(1)** |
| `getSize()` | Returns number of nodes | **O(1)** |
| `operator<<` | Prints the tree sideways | —— |
| Copy Constructor / `operator=` | Creates a deep copy | **O(n)** |
| Destructor | Releases memory with no leaks | **O(n)** |

### 🌳 Balancing Rules
The tree automatically performs:
- **Single Rotations** (LL, RR)
- **Double Rotations** (LR, RL)

This ensures a height of **O(log n)** for all operations.
