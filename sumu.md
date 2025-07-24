# ðŸ§  Merge Sort Simulation for `[5, 7, 8, 9, 3, 2, 1]`

---

## ðŸ” Step 1: Divide Phase (Recursive Splitting)

```
[5, 7, 8, 9, 3, 2, 1]
-> Split into:
[5, 7, 8]       [9, 3, 2, 1]

-> Split further:
[5] [7, 8]      [9, 3] [2, 1]

-> Again:
[5] [7] [8]     [9] [3] [2] [1]
```

---

## ðŸ”€ Step 2: Merge Phase (Sorted Merging)

We now merge smallest to largest, keeping track of `i`, `j`, and `k`.

---

### ðŸ”¹ Merge `[7]` and `[8]`

```
i=0, j=0, k=0

[7]   [8]
 â†“     â†“
[7 < 8] => arr[k] = 7

i=1 (end), j=0, k=1 => arr[k] = 8

Result: [7, 8]
```

---

### ðŸ”¹ Merge `[5]` and `[7, 8]`

```
i=0, j=0, k=0

[5]   [7, 8]
 â†“     â†“
[5 < 7] => arr[k] = 5

i=1 (end), j=0, k=1 => arr[k] = 7  
j=1, k=2 => arr[k] = 8

Result: [5, 7, 8]
```

---

### ðŸ”¹ Merge `[9]` and `[3]`

```
i=0, j=0, k=0

[9]   [3]
 â†“     â†“
[3 < 9] => arr[k] = 3

i=0, j=1 (end), k=1 => arr[k] = 9

Result: [3, 9]
```

---

### ðŸ”¹ Merge `[2]` and `[1]`

```
i=0, j=0, k=0

[2]   [1]
 â†“     â†“
[1 < 2] => arr[k] = 1

i=0, j=1 (end), k=1 => arr[k] = 2

Result: [1, 2]
```

---

### ðŸ”¹ Merge `[3, 9]` and `[1, 2]`

```
i=0, j=0, k=0

[3, 9]   [1, 2]
  â†“        â†“
[1 < 3] => arr[k] = 1

j=1, i=0, k=1 => [2 < 3] => arr[k] = 2  
j=2 (end), i=0, k=2 => arr[k] = 3  
i=1, k=3 => arr[k] = 9

Result: [1, 2, 3, 9]
```

---

### ðŸ”¹ Final Merge: `[5, 7, 8]` and `[1, 2, 3, 9]`

```
i=0, j=0, k=0

[5, 7, 8]   [1, 2, 3, 9]
  â†“           â†“
[1 < 5] => arr[k] = 1  
j=1, k=1 => arr[k] = 2  
j=2, k=2 => arr[k] = 3  
j=3, k=3 => arr[k] = 5  
i=1, k=4 => arr[k] = 7  
i=2, k=5 => arr[k] = 8  
i=3 (end), j=3, k=6 => arr[k] = 9

âœ… Final Sorted Result: `[1, 2, 3, 5, 7, 8, 9]`
```

---

## âœ… Final Sorted Array

```
[1, 2, 3, 5, 7, 8, 9]
```

---