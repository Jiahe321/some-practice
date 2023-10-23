#ifndef UTILS_H//如果不存在UTILS_H。确保UTILS_H只被包含一次
#define UTILS_H
#include <stdlib.h>
#include <stdio.h>
FILE *open_file(char filename[], char mode[]);
//声明了一个函数 open_file，用于打开文件。
//这个头文件的目的是提供其他源文件访问 open_file 函数的声明。
#endif /* UTILS_H */