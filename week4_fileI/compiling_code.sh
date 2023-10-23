#!/bin/bash
gcc -c utils.c # will produce utils.o
gcc -c create_file_h.c # will produce create_file_h.o
gcc create_file.o utils.o -o create_file