# 🔢 Set Operations in C++

This C++ program generates random sets (numeric or letter-based), removes duplicates, sorts them, and performs typical set operations such as:

- union of sets
- difference of sets
- intersection of sets

-----------------------------------------------------------------------------------------

## ⚙️ Program Features

- **`generate(n)`** → generates a set of `n` random integers in the range 1–10.  
- **`generater_letters(n)`** → generates a set of `n` random letters from the alphabet.  
- **`repeats(vector<char>& a)`** → removes duplicates and sorts the set (using insertion sort).  
- **`sum_sets(a, b)`** → returns the union of two sets.  
- **`sum_sets(a, b, c)`** → returns the union of three sets.  
- **`diff_sets(a, b)`** → difference of sets (elements in `a` but not in `b`).  
- **`diff_sets(a, b, c)`** → difference of set `c` and the union of `a+b`.  
- **`common(a, b)`** → intersection of two sets.  
- **`common(a, b, c)`** → intersection of three sets.  
- **`sort_insertion(a)`** → sorts a set using **insertion sort**.  
- **`writing(a, name)`** → prints a set in the form `{elements}` (as numbers).  
- **`letter_writing(a, name)`** → prints a set of letters.  

-----------------------------------------------------------------------------------------

## 🖥️ Example Run

Enter the size of set v1: 5
Enter the size of set v2: 4
Enter the size of set v3: 6
Set v1: {7, 2, 4, 7, 9, }
Set v2: {5, 2, 8, 5, }
Set v3: {1, 3, 2, 9, 4, 2, }

Set v1 (no duplicates and sorted): {2, 4, 7, 9, }
Set v2 (no duplicates and sorted): {2, 5, 8, }
Set v3 (no duplicates and sorted): {1, 2, 3, 4, 9, }

Set total sum of v1+v2: {2, 4, 5, 7, 8, 9, }
Set total sum of v1+v2+v3: {1, 2, 3, 4, 5, 7, 8, 9, }
Set difference of v1-v2: {4, 7, 9, }
Set difference of v3-(v1+v2): {1, 3, }
Set common part of v1 and v2: {2, }
Set common part of v1, v2 and v3: {2, }
