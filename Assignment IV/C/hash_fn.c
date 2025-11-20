/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h

   Developer: En-Chi Yang <s1133334@mail.yzu.edu.tw>
 */
#include <stdio.h>

#include "hash_fn.h"

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    // 防止 key 為負數的情況
    unsigned int x = (unsigned int) key;

    // Knuth multiplicative method (0x9e3779b9 是黃金比例常數)
    x = x * 0x9e3779b9;

    // 混合位元（增加隨機性）
    x ^= (x >> 16);

    // 取餘數，產生在 0 ~ m-1 的 hash
    return x % m;  // division method example
}

int myHashString(const char* str, int m) {
    const unsigned int P = 1315423911u;  // 大質數
    unsigned long long hash = 0;

    // 使用 C 的方式操作字串：用指標逐字元讀取
    while (*str) {
        hash = (hash * 131) + (unsigned char)(*str);  
        hash ^= (hash >> 16);  
        str++;  
    }

    return (int)(hash % m); // basic division method
}