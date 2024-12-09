Here’s a concise **Obsidian note** for **`std::vector` in C++**, tailored for competitive programming:

---

## 🚀 Quick Note: `std::vector` (C++)

### **Basics**

- **Declaration:**
    
    ```cpp
    vector<int> v;            // Empty vector
    vector<int> v(n);         // Vector of size `n` (default-initialized)
    vector<int> v(n, val);    // Vector of size `n` with all elements = `val`
    vector<int> v = {1, 2, 3}; // Initialized with values
    ```
    

### **Common Operations**

- **Add Elements:**
    
    ```cpp
    v.push_back(x);  // Add element at end
    ```
    
- **Remove Elements:**
    
    ```cpp
    v.pop_back();    // Remove last element
    ```
    
- **Access Elements:**
    
    ```cpp
    v[i];            // Random access (0-based index)
    v.front();       // First element
    v.back();        // Last element
    ```
    
- **Resize & Clear:**
    
    ```cpp
    v.size();        // Current size
    v.resize(n);     // Resize to `n`
    v.clear();       // Remove all elements
    ```
    

### **Iteration**

- **Range-based:**
    
    ```cpp
    for (int x : v) cout << x;
    ```
    
- **Index-based:**
    
    ```cpp
    for (int i = 0; i < v.size(); i++) cout << v[i];
    ```
    
- **With Iterators:**
    
    ```cpp
    for (auto it = v.begin(); it != v.end(); ++it) cout << *it;
    ```
    

### **Sorting**

- **Ascending:**
    
    ```cpp
    sort(v.begin(), v.end());
    ```
    
- **Descending:**
    
    ```cpp
    sort(v.rbegin(), v.rend());
    ```
    

### **Tricks for Competitive Programming**

- **Initialize with zeros:**
    
    ```cpp
    vector<int> v(n, 0);  // n elements, all zero
    ```
    
- **2D Vector:**
    
    ```cpp
    vector<vector<int>> mat(rows, vector<int>(cols, 0));
    ```
    
- **Remove duplicates:**
    
    ```cpp
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ```
    

### **Performance**

- Amortized O(1) for `push_back`.
- O(n) for resizing or copying.
- Use `reserve(n)` if size is known to prevent resizing overhead.

---

This note is minimal and contains the most commonly used functions and patterns for `std::vector` in competitive programming. You can customize further as needed!