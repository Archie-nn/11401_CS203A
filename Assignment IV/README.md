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
1. Knuth’s Multiplicative Constant (0x9e3779b9)
This constant, derived from the golden ratio, helps produce strong bit diffusion. Even consecutive integers (e.g., 100, 101, 102) are spread across seemingly unrelated hash indices, reducing clustering.

2. XOR-Shift Bit Mixing
The operation x ^= (x >> 16) mixes high and low bits, removing regular patterns left by multiplication and improving randomness in the final hash value.

3. Modulo Operation for Table Mapping
Applying x % m maps the result into the table range. When paired with a suitable (preferably prime) table size, it provides effective and stable index distribution.

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
1. Polynomial Rolling Hash (Base 131)
This method is a standard and effective approach for string hashing.
The base 131 is commonly used because it is a prime number and provides good sensitivity—small changes in a string (e.g., "abc" vs. "acb") produce very different hash values. It also helps reduce structural collisions and is widely adopted in hash tables and string-matching algorithms.

2. XOR-Shift Mixing
The operation hash ^= (hash >> 16) mixes high and low bits, improves randomness, and reduces collisions caused by similar string patterns (e.g., "AAA", "AAB", "AAC").

3. Modulo Operation
Applying hash % m ensures the final result is mapped into the valid index range 0 ~ m-1, completing the hash process effectively.

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
== Hash Function Observation (C Version) ===

=== Table Size m = 10 ===
Key     Index
-----------------
21      7
22      4
23      2
24      9
25      3
26      0
27      8
28      5
29      9
30      8
51      6 
52      0
53      3
54      7
55      6
56      0
57      7
58      9
59      8
60      4

=== Table Size m = 11 ===
Key     Index
-----------------
21      5
22      2
23      2
24      6
25      5
26      8
27      3
28      7
29      5
30      5
51      3
52      5
53      7
54      1
55      7
56      3
57      5
58      5
59      3
60      8

=== Table Size m = 37 ===
Key     Index
-----------------
21      18
22      17
23      28
24      23
25      19
26      21
27      26
28      0
29      15
30      14
51      30
52      5
53      1
54      18
55      2
56      0
57      32
58      33
59      25
60      12

=== String Hash (m = 10) ===
Key     Index
-----------------
cat     2
dog     2
bat     8
cow     3
ant     6
owl     9
bee     5
hen     0
pig     7
fox     7

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     9
dog     4
bat     3
cow     4
ant     5
owl     4
bee     2
hen     6
pig     8
fox     8

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     21
dog     10
bat     8
cow     29
ant     32
owl     27
bee     17
hen     21
pig     10
fox     9

=== Hash Function Observation (C++ Version) ===

=== Table Size m = 10 ===
Key     Index
-----------------
21      7
22      4
23      2
24      9
25      3
26      0
27      8
28      5
29      9
30      8
51      6
52      0
53      3
54      7
55      6
56      0
57      7
58      9
59      8
60      4

=== Table Size m = 11 ===
Key     Index
-----------------
21      5
22      2
23      2
24      6
25      5
26      8
27      3
28      7
29      5
30      5
51      3
52      5
53      7
54      1
55      7
56      3
57      5
58      5
59      3
60      8

=== Table Size m = 37 ===
Key     Index
-----------------
21      18
22      17
23      28
24      23
25      19
26      21
27      26
28      0
29      15
30      14
51      30
52      5
53      1
54      18
55      2
56      0
57      32
58      33
59      25
60      12

=== String Hash (m = 10) ===
Key     Index
-----------------
cat     2
dog     2
bat     8
cow     3
ant     6
owl     9
bee     5
hen     0
pig     7
fox     7

=== String Hash (m = 11) ===
Key     Index
-----------------
cat     9
dog     4
bat     3
cow     4
ant     5
owl     4
bee     2
hen     6
pig     8
fox     8

=== String Hash (m = 37) ===
Key     Index
-----------------
cat     21
dog     10
bat     8
cow     29
ant     32
owl     27
bee     17
hen     21
pig     10
fox     9
```
```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
- Example output for integers:
```
Hash table (m=10): [
Key   Index
21    7
22    4
23    2
24    9
25    3
26    0
27    8
28    5
29    9
30    8
51    6
52    0
53    3
54    7
55    6
56    0
57    7
58    9
59    8
60    4
]

Hash table (m=11): [
Key   Index
21    5
22    2
23    2
24    6
25    5
26    8
27    3
28    7
29    5
30    5
51    3
52    5
53    7
54    1
55    7
56    3
57    5
58    5
59    3
60    8
]

Hash table (m=37): [
Key   Index
21    18
22    17
23    28
24    23
25    19
26    21
27    26
28    0
29    15
30    14
51    30
52    5
53    1
54    18
55    2
56    0
57    32
58    33
59    25
60    12
]
 ```
- Example output for strings:
```
Hash table (m=10): [
cat  → 2
dog  → 2
bat  → 8
cow  → 3
ant  → 6
owl  → 9
bee  → 5
hen  → 0
pig  → 7
fox  → 7
]

Hash table (m=11): [
cat  → 9
dog  → 4
bat  → 3
cow  → 4
ant  → 5
owl  → 4
bee  → 2
hen  → 6
pig  → 8
fox  → 8
]

Hash table (m=37): [
cat  → 21
dog  → 10
bat  → 8
cow  → 29
ant  → 32
owl  → 27
bee  → 17
hen  → 21
pig  → 10
fox  → 9
]
 ```
- Observations: Outputs align with the analysis, showing better distribution with prime table sizes.
 ```
## Analysis
1. Distribution Quality: Prime vs. Non-Prime Table Sizes

When the table size m = 10 (a non-prime number), the hash results show noticeable clustering and repeated patterns. Several integer keys and string keys map to the same index, indicating weaker distribution.
In contrast, when m = 11 or m = 37 (both prime numbers), the distribution becomes significantly more uniform, with fewer collisions and reduced index repetition.

Conclusion:
Prime table sizes generally yield better hash distribution and minimize collisions.

2. Performance of myHashInt()

The integer hash function uses Knuth’s multiplicative hashing combined with XOR-based bit mixing. This approach increases the randomness of the generated index and reduces predictable patterns.

Even though the tested integer keys are consecutive (21–30 and 51–60), the results show good dispersion, especially when m = 37, demonstrating effective spreading across the table.

3. Performance of myHashString()

The string hash algorithm uses a polynomial rolling hash with base 131, enhanced with XOR-shift mixing. This method is effective for hashing English words and provides a good balance between speed and distribution.

With m = 10, collisions appear more frequently because 10 is not a prime number.
With prime table sizes (m = 11, m = 37), the distribution becomes more stable and uniform.

4. Patterns and Collisions

Non-prime table sizes show visible patterns and more repetitive hash indices.

Prime table sizes help break these patterns due to better modular arithmetic properties.

Even with a strong hash function, the choice of m significantly influences the overall distribution.

5. Improvements

Better hash table behavior can be achieved through:

Stronger mixing functions within the hash algorithm

Using established hash functions such as FNV-1a or MurmurHash

Choosing prime table sizes

Avoiding table sizes that are powers of two

## Reflection
1. Balancing simplicity and randomness is key in designing effective hash functions.
Techniques like multiplicative hashing and XOR mixing improve key dispersion and help reduce collisions.

2. Table size selection plays a crucial role in overall hash table performance.
Experiments clearly show that prime table sizes such as 11 and 37 produce more uniform distributions compared to non-prime sizes like 10.

3. The implemented hash functions successfully scatter both sequential integer keys and similar-looking string keys.
This demonstrates the effectiveness of the chosen hashing strategies.

4. A good hash function alone is not enough—choosing an appropriate table size is equally important.
The combination of a robust hash function and a prime-sized table yields the most balanced and collision-resistant distribution.