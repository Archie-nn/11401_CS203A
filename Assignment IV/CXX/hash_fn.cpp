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
    // 防止 key 為負數的情況
    unsigned int x = (unsigned int) key;

    // Knuth multiplicative method (0x9e3779b9 是黃金比例常數)
    x = x * 0x9e3779b9;

    // 混合位元（增加隨機性）
    x ^= (x >> 16);

    // 取餘數，產生在 0 ~ m-1 的 hash
    return x % m; // basic division method
}

int myHashString(const std::string& str, int m) {
    const unsigned int P = 1315423911u;  // 大質數
    unsigned long long hash = 0;

    for (char c : str) {
        hash = (hash * 131) + (unsigned char)c;  // 131 是常用 hash 底數
        hash ^= (hash >> 16);                    // 混合
    }

    return (int)(hash % m);  // basic division method
}