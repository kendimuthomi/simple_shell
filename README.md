0x16 Simple Shell

About
The shell acts like a simpler Linux command interpreter. It offers an interface bewteen the kernel and the user
and executes programs referred to as commands. For instance, when a user enters ls, the shell will execute that
command.
This project is a custom implementation of the simple UNIX shell. The project will take minimalistic approach and
various functions will be deployed.For instance;
exit, fork, free, fstat, getline, malloc, perror, signal, stat, wait, write.

File Descriptions
Authors - lists the authors of this project
man_1_simple_shell - The manual describing how simple shell is used
shell.h - The header file used in the project

Requirements
Allowed editors vi, vim, emacs
All files were compiled on ubuntu 20.04 LTS using gcc with the options;-Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Betty style of coding must be observed
There are no memory leaks on this simple shell project

More Information and Clarification
The project is designed to run on Ubuntu 20.04 LTS, and the simple_shell can be installed as follows:
        The current repository can be cloned with the command: git clone "https://github.com/jacklinemuthomi/simple_shell.git"
cd into the repository that has already been cloned: cd 0x016-simple_shell
An executable will be created using gcc -Wall -Werror -Wextra -pedantic *.c --o hsh
The executable can either be run in interactive mode using ./hsh or non-interactive mode echo "pwd" | ./hsh

Examples
Example of error with sh:
$ echo "qwerty" | /bin/sh
/bin/sh: 1: killme: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/ ../bin/sh: 1: qwerty not found
$

Same error with our program hsh:
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
