//utils.c 是一个C语言源文件，包含了实际的函数实现。
#include "utils.h"
//定义了一个名为 open_file 的函数，该函数与头文件中的声明相匹配。
FILE *open_file(char filename[], char mode[]){
    FILE *file = fopen(filename, mode);
    if (file == NULL){
        perror("");
        exit(1);
    }
    return file;
}