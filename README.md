# Project Simple Shell

## Synopsis :

This is a Simple Shell commands interpret we made in C for our Holberton School project

## Description :

This project is a simple Unix shell command interpreter. It is designed to replicate basic functionality of a shell program. The shell supports executing commands, handling built-in commands, and performing input/output redirection, among other basic features.

## Installation 
To install and run the Simple Shell, follow these steps: 

1. Clone the repository to your local machine:
```bash
git clone https://github.com/Khosuke/holbertonschool-simple_shell.git
```
2. Navigate to the project directory:
```bash
cd holbertonschool-simple_shell
```
3. Compile the source code:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simpleshell
```

## Requirements
Ubuntu 20.04 LTS, GCC, an editor like vi or emacs, git.

### List of allowed functions and system calls+
all functions from string.h
```access``` (man 2 access)
```chdir``` (man 2 chdir)
```close``` (man 2 close)
```closedir``` (man 3 closedir)
```execve``` (man 2 execve)
```exit``` (man 3 exit)
```_exit``` (man 2 _exit)
```fflush``` (man 3 fflush)
```fork``` (man 2 fork)
```free``` (man 3 free)
```getcwd``` (man 3 getcwd)
```getline``` (man 3 getline)
```getpid``` (man 2 getpid)
```isatty``` (man 3 isatty)
```kill``` (man 2 kill)
```malloc``` (man 3 malloc)
```open``` (man 2 open)
```opendir``` (man 3 opendir)
```perror``` (man 3 perror)
```printf``` (man 3 printf)
```fprintf``` (man 3 fprintf)
```vfprintf``` (man 3 vfprintf)
```sprintf``` (man 3 sprintf)
```putchar``` (man 3 putchar)
```read``` (man 2 read)
```readdir``` (man 3 readdir)
```signal``` (man 2 signal)
```stat``` (__xstat) (man 2 stat)
```lstat``` (__lxstat) (man 2 lstat)
```fstat``` (__fxstat) (man 2 fstat)
```strtok``` (man 3 strtok)
```wait``` (man 2 wait)
```waitpid``` (man 2 waitpid)
```wait3``` (man 2 wait3)
```wait4``` (man 2 wait4)
```write``` (man 2 write)

## Usage 

After successfully compiling and running the shell, you will see a prompt waiting for your input. You can type any valid Unix command, and the shell will execute it. Below are some examples of how to use the shell.

### Exemple of use 
#### In non-interactive mode 
```
user@ubuntu:~/holbertonschool-simpleshell$ echo "/bin/ls" | ./simpleshell
AUTHORS  README.md  _getenv.c  _which.c  free_array.c  main.h  man_simple_shell  simple_shell.c  simpleshell  split_string.c
user@ubuntu:~/holbertonschool-simpleshell$ echo "echo Hello World" | ./simpleshell 
Hello World
```
#### In interactive mode
```
user@ubuntu:~/holbertonschool-simple_shell$ ./simpleshell
Simple Shell $ /bin/ls
AUTHORS  README.md  _getenv.c  _which.c  free_array.c  main.h  man_simple_shell  simple_shell.c  simpleshell  split_string.c
Simple Shell $ echo Hello World
Hello World
Simple Shell $ exit
user@ubuntu:~holbertonschool-simple_shell$
```

## Testing

Testing our simple shell memory leaks and memory error with Valgrind:

```
user@ubuntu:~/holbertonschool-simple_shell$ valgrind ./simpleshell 
==94758== Memcheck, a memory error detector
==94758== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==94758== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==94758== Command: ./simpleshell
==94758== 
Simple Shell $ ls
AUTHORS  README.md  _getenv.c  _which.c  free_array.c  main.h  man_simple_shell  simple_shell.c  simpleshell  split_string.c
Simple Shell $ exit
==94758== 
==94758== HEAP SUMMARY:
==94758==     in use at exit: 0 bytes in 0 blocks
==94758==   total heap usage: 84 allocs, 84 frees, 6,995 bytes allocated
==94758== 
==94758== All heap blocks were freed -- no leaks are possible
==94758== 
==94758== For lists of detected and suppressed errors, rerun with: -s
==94758== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## Man page
Here's a link to the [man page](man_page.1) we made for our Simple Shell
And you can also see the formated version with the command:
```bash
man ./man_simple_shell
```

## Flowchart

This is the flowchart of the general idea of how our Simple Shell is working 


## Authors 
Antonin LEBRE : <9803@holbertonstudents.com>
Frédéric IGLESIAS MONTERO : <9814@holbertonstudents.com>

