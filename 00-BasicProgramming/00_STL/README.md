# C++ Standard Template Library (STL) Guide

## Table of Contents
1. [Containers](#containers)
2. [Algorithms](#algorithms)
3. [Functions](#functions)

## Containers

### Sequence Containers

#### 1. Vector
- **Description**: Dynamic array that grows automatically
- **Use Cases**:
  - When you need fast random access
  - When you need to add/remove elements from the end
  - When you need contiguous memory storage
- **Time Complexity**:
  - Access: O(1)
  - Insert/Delete at end: O(1)
  - Insert/Delete at middle: O(n)
```cpp
std::vector<int> vec = {1, 2, 3};
vec.push_back(4);  // Add element
```

#### 2. List
- **Description**: Doubly-linked list
- **Use Cases**:
  - When you need fast insertions/deletions at any position
  - When you don't need random access
  - When memory locality is not important
- **Time Complexity**:
  - Access: O(n)
  - Insert/Delete at position: O(1)
```cpp
std::list<int> lst = {1, 2, 3};
lst.push_front(0);  // Add at beginning
```

#### 3. Deque
- **Description**: Double-ended queue
- **Use Cases**:
  - When you need fast insertions/deletions at both ends
  - When you need random access
- **Time Complexity**:
  - Access: O(1)
  - Insert/Delete at ends: O(1)
```cpp
std::deque<int> dq = {1, 2, 3};
dq.push_front(0);   // Add at front
dq.push_back(4);    // Add at back
```

### Associative Containers

#### 1. Set
- **Description**: Collection of unique sorted elements
- **Use Cases**:
  - When you need to maintain unique sorted elements
  - When you need fast search operations
- **Time Complexity**:
  - Search/Insert/Delete: O(log n)
```cpp
std::set<int> s = {3, 1, 4, 1, 5};  // Stores: 1, 3, 4, 5
```

#### 2. Map
- **Description**: Collection of key-value pairs, sorted by key
- **Use Cases**:
  - When you need to associate values with unique keys
  - When you need sorted key-value pairs
- **Time Complexity**:
  - Search/Insert/Delete: O(log n)
```cpp
std::map<string, int> m = {{"apple", 1}, {"banana", 2}};
```

### Unordered Containers

#### 1. Unordered Set
- **Description**: Hash table of unique elements
- **Use Cases**:
  - When you need fast lookups
  - When order doesn't matter
- **Time Complexity**:
  - Average case: O(1) for all operations
```cpp
std::unordered_set<int> us = {4, 1, 3, 1};  // Stores: 1, 3, 4
```

#### 2. Unordered Map
- **Description**: Hash table of key-value pairs
- **Use Cases**:
  - When you need fast key-value lookups
  - When key order doesn't matter
- **Time Complexity**:
  - Average case: O(1) for all operations
```cpp
std::unordered_map<string, int> um = {{"cat", 1}, {"dog", 2}};
```

## Algorithms

### Sorting
```cpp
std::sort(vec.begin(), vec.end());  // Basic sort
std::sort(vec.begin(), vec.end(), greater<int>());  // Sort descending
```

### Searching
```cpp
// Binary search (on sorted container)
binary_search(vec.begin(), vec.end(), value);

// Find element
auto it = find(vec.begin(), vec.end(), value);
```

### Modifying Sequences
```cpp
// Remove elements
remove(vec.begin(), vec.end(), value);
remove_if(vec.begin(), vec.end(), predicate);

// Replace elements
replace(vec.begin(), vec.end(), old_value, new_value);
```

### Numeric Operations
```cpp
// Sum of elements
int sum = accumulate(vec.begin(), vec.end(), 0);

// Product of elements
int product = accumulate(vec.begin(), vec.end(), 1, multiplies<int>());
```

## Functions

### Function Objects (Functors)
```cpp
// Built-in functors
plus<int> add;
int result = add(1, 2);  // result = 3

// Custom functor
struct Compare {
    bool operator()(int a, int b) { return a > b; }
};
```

### Lambda Functions
```cpp
// Basic lambda
auto square = [](int x) { return x * x; };

// Lambda with capture
int multiplier = 10;
auto multiply = [multiplier](int x) { return x * multiplier; };
```

### Function Wrappers
```cpp
// std::function
std::function<int(int)> func = square;
int result = func(5);  // result = 25
```

## Best Practices

1. **Choose the Right Container**:
   - Use `vector` as the default container
   - Use `list` when frequent insertions/deletions are needed
   - Use `map`/`set` when you need sorted data
   - Use unordered containers for fastest lookups

2. **Performance Considerations**:
   - Reserve vector capacity when size is known
   - Use emplace_back() instead of push_back() when possible
   - Use references to avoid copying
   - Consider using views (C++20) for non-owning sequences

3. **Memory Management**:
   - Clear containers when no longer needed
   - Use shrink_to_fit() to release unused memory
   - Be careful with circular references in containers

4. **Iterator Usage**:
   - Always check iterator validity
   - Use const_iterator when possible
   - Be careful with iterator invalidation

Remember that choosing the right STL component depends on:
- The type of data you're storing
- The operations you'll perform most frequently
- Memory usage requirements
- Performance requirements