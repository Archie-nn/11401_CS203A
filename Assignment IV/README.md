# Homework Assignment IV: Hash Function Design & Observation (C/C++ Version)

This assignment focuses on the design and observation of hash functions using C/C++. 
Students are expected to implement and analyze the behavior of hash functions, 
evaluate their efficiency, and understand their applications in computer science.

Developer: En-Chi Yang
Email: s1133334@mail.stu.yzu.tw

## My Hash Function
### Integer Keys 
- Formula / pseudocode:
```text
 [x = unsigned(key)        // Avoid negative values
  x = x * 0x9e3779b9       // Knuth multiplicative hashing constant
  x = x XOR (x >> 16)      // Mix high and low bits
  return x mod m           // Map to 0...(m-1)]
 ```
- Rationale: [
1. 使用 Knuth’s multiplicative constant (0x9e3779b9)

這個常數來源於黃金比例，對於 hash 運算具有以下優點：

能使輸入 key 產生高度擴散（bit diffusion）

相鄰 key（如 100、101、102）會被打散成看起來隨機的 index

減少 clustering（集中在某些 index）

2. 使用 XOR-shift 混合高低位元

x ^= (x >> 16) 的作用是：

將高位 bit 混合到低位

減少簡單乘法可能留下的規律性 pattern

增加 hash 的隨機性（更均勻）

3. 最後使用 modulo m 映射到 table size

x % m 是 division method，可與適當的 m 一起搭配達到良好效果。]

### Non-integer Keys
- Formula / pseudocode:
```text
 [hash = 0
  for each character c in str:
  hash = hash * 131 + ASCII(c)   // Polynomial rolling hash
  hash = hash XOR (hash >> 16)   // Bit mixing
  return hash mod m]
 ```
- Rationale: [
1. Polynomial Rolling Hash（底數 131）

此方法是字串 hash 的標準作法，具有：

對不同字串敏感（例如 "abc" 和 "acb" 結果差很多）

常用在字典、hash table 與字串比對演算法（KMP、Rabin-Karp）

底數選擇 131 的理由：

131 是常見的質數底數（C++ unordered_map 中也採用類似方法）

能夠避免許多字串輸入產生規律性碰撞

2. XOR-shift mixing

hash ^= (hash >> 16); 能夠：

將 hash 的高位與低位打散

增加隨機感

減少字串結構導致的碰撞（例如 "AAA" vs "AAB" vs "AAC"）

3. 最後使用 mod m

確保輸出仍然落在 0 ~ m-1 的 index 範圍。]

## Experimental Setup
- Table sizes tested (m): 10, 11, 37
- Test dataset:
- Integers: 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60
- Strings: "cat", "dog", "bat", "cow", "ant", "owl", "bee", "hen", "pig", "fox"
- Compiler: GCC and G++
- Standard: C23 and C++23

## Results
| Table Size (m) | Index Sequence         | Observation              |
|----------------|------------------------|--------------------------|
| 10             | 1, 2, 3, 4, ...        | Pattern repeats every 10 |
| 11             | 10, 0, 1, 2, ...       | More uniform             |
| 37             | 20, 21, 22, 23, ...    | Near-uniform             |

## Compilation, Build, Execution, and Output

### Compilation
- The project uses a comprehensive Makefile that builds both C and C++ versions with proper flags:
  ```bash
  # Build both C and C++ versions
  make all
  
  # Build only C version
  make c
  
  # Build only C++ version
  make cxx
  ```

### Manual Compilation (if needed)
- Command for C:
```bash
  gcc -std=c23 -o hash_function main.c
  gcc -std=c23 -Wall -Wextra -Wpedantic -g -o C/hash_function C/main.c C/hash_fn.c
```
- Command for C++:
```bash
  g++ -std=c++23 -o hash_function_cpp main.cpp
  g++ -std=c++23 -Wall -Wextra -Wpedantic -g -o CXX/hash_function_cpp CXX/main.cpp CXX/hash_fn.cpp
```

### Make Binary
- Use the following `Makefile` to automate the build process:
  ```makefile
  all:
      gcc -std=c23 -o hash_function main.c
      g++ -std=c++23 -o hash_function_cpp main.cpp
  clean:
      rm -f hash_function hash_function_cpp
### Clean Build Files
- Remove all compiled files:
  ```bash
  make clean
```

### Execution
- Run the compiled binary:
```bash
./hash_function
```
or
```bash
./hash_function_cpp
```

### Result Snapshot
- Example output for integers:
```
 === Hash Function Observation (C Version) ===

 === Table Size m = 10 ===
 Key     Index
 -----------------
 21      1
 22      2
 ...

 === Table Size m = 11 ===
 Key     Index
 -----------------
 21      10
 22      0
 ...

 === Table Size m = 37 ===
 Key     Index
 -----------------
 21      21
 22      22
 ...

 === Hash Function Observation (C++ Version) ===

 === Table Size m = 10 ===
 Key     Index
 -----------------
 21      1
 22      2
 ...

 === Table Size m = 11 ===
 Key     Index
 -----------------
 21      10
 22      0
 ...

 === Table Size m = 37 ===
 Key     Index
 -----------------
 21      21
 22      22
 ...
 ```

- Example output for strings:
```
 === String Hash (m = 10) ===
 Key     Index
 -----------------
 cat     0
 dog     0
 ...

 === String Hash (m = 11) ===
 Key     Index
 -----------------
 cat     0
 dog     0
 ...

 === String Hash (m = 37) ===
 Key     Index
 -----------------
 cat     0
 dog     0
 ...
 ```

- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
```
 Hash table (m=10): [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
 Hash table (m=11): [10, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
 Hash table (m=37): [20, 21, 22, 23, 24, 25, 26, 27, 28, 29, ...]
 ```
- Example output for strings:
```
 Hash table (m=10): ["cat", "dog", "bat", "cow", "ant", ...]
 Hash table (m=11): ["fox", "cat", "dog", "bat", "cow", ...]
 Hash table (m=37): ["bee", "hen", "pig", "fox", "cat", ...]
 ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.

## Analysis
- Prime vs non-prime `m`: Prime table sizes generally result in better distribution and fewer collisions.
- Patterns or collisions: Non-prime table sizes tend to produce repetitive patterns, leading to more collisions.
- Improvements: Use a prime table size and a well-designed hash function to enhance distribution.

## Reflection
1. Designing hash functions requires balancing simplicity and effectiveness to minimize collisions.
2. Table size significantly impacts the uniformity of the hash distribution, with prime sizes performing better.
3. The design using a prime table size and a linear transformation formula produced the most uniform index sequence.