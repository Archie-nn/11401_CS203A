/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp

   Developer: En-Chi Yang <s1133334@mail.yzu.edu.tw>
 */
#include <string>
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    return key % m;  // basic division method
}

int myHashString(const std::string& str, int m) {
    unsigned long hash = 0;
    // TODO: replace with your own design
    return static_cast<int>(hash % m);  // basic division method
}