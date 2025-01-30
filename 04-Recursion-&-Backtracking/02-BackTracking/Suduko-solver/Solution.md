# Approach (Sudoku Solving using Backtracking)

## Step 1: Problem Samajhna
Humein 9x9 ka ek matrix diya gaya hai jisme 0 ka matlab hai empty space (jisme humein 1-9 tak koi bhi number fill karna hai). Humein ye ensure karna hai ki:

1. Har row me 1 se 9 tak ke numbers ek baar hi aayein.
2. Har column me bhi 1 se 9 tak ke numbers ek baar hi aayein.
3. Har 3x3 box ke andar bhi 1 se 9 tak ke numbers ek baar hi aayein.

## Step 2: Functions ka Explanation

### 1. isSafe(grid, row, col, num)
✅ Ye function check karta hai ki kya num ko row, col position pe rakhna safe hai ya nahi.

✅ Teen cheezein check hoti hain:

* Row me same number hai ya nahi
* Column me same number hai ya nahi
* 3x3 subgrid me same number hai ya nahi

```
bool isSafe(vector<vector<int>> &grid, int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }
    
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}
```

### 2. solveSudokuHelper(grid)
* Ye function backtracking ka use karke Sudoku ko solve karta hai.
* Ye pehle khali cell dhundhta hai (jisme 0 ho), phir usme 1 se 9 tak numbers dalne ki koshish karta hai. 

* Agar number valid hota hai (isSafe return true) toh aage recursion chalta hai.

* Agar kisi point pe koi solution nahi milta, toh backtrack karte hain (wapis 0 kar dete hain aur doosra number try karte hain).

* Jab poora grid bhar jata hai, toh solution mil jata hai.

```
bool solveSudokuHelper(vector<vector<int>> &grid) {
    int row, col;
    bool isEmpty = false;
    
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) break;
    }
    
    if (!isEmpty) return true; // No empty cells left
    
    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudokuHelper(grid)) return true;
            grid[row][col] = 0; // Backtrack
        }
    }
    return false;
}

```

### 3. solveSudoku(mat)
*  Ye function bas helper function ko call karta hai, jo Sudoku ko solve karega.

```
void solveSudoku(vector<vector<int>> &mat) {
    solveSudokuHelper(mat);
}
```

### Summary
* Backtracking ka use kiya
* Har empty cell me 1-9 place karne ki koshish ki
* Jo valid nahi tha, usko hata diya (backtrack)
* Final solution print kar diya😂✅