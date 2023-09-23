# list/Makefile
#
# Makefile for list implementation and test file.
#
# Guthrie, Lauren


list: main.c list.c list.h
	gcc -o list main.c list.c list.h