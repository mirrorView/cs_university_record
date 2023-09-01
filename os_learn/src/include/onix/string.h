#ifndef ONIX_STRING_H
#define ONIX_STRING_H

#include <onix/types.h>

/**
 * 
 * 复制
*/
char *strcpy(char *dest, const char *src);

/**
 * 
 * 拼接
*/
char *strcat(char *dest, const char *src);

/**
 * 长度
*/
size_t strlen(const char *str);


/**
 * 
 * 比较
 * 
*/
int strcmp(const char *lhs, const char *rhs);


/**
 * 
 * 查询字符的位置
*/
char *strchr(const char *str, int ch);
char *strrchr(const char *str, int ch);

int memcmp(const void *lhs, const void *rhs, size_t count);
void *memset(void *dest, int ch, size_t count);
void *memcpy(void *dest, const void *src, size_t count);
void *memchr(const void *ptr, int ch, size_t count);

#endif