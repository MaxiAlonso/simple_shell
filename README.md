# 0x16. C - Simple Shell

This is the end of first trimester project of Holberton School curriculum. Our shell replicates parts of a basic shell to comunicate with an operating system, using C programming language to write our sourcecode
## Usage

After compilation, the resulting program can run stand-alone, either in interactive or non-interactive mode.

### Environment

* Language: C
* OS: Ubuntu 20.04 LTS
* Compiler: gcc
* Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)

## Installation and way to use

Clone this repository to your terminal
```
git clone https://github.com/MaxiHBTN/simple_shell.git
```
Compile it using:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
**Interactive mode**
```
./hsh
```
**Non-Interactive mode**
```
echo ls | ./hsh
```

## Built-ins used

| Command             | Definition                                          |
| ------------------- | ----------------------------------------------------|
| exit                | Terminate the process, with an optional exit status.|
| env                 | Obtain the current environment.                     |
| setenv [var][value] | Change or add an environment variable.              |
| unsetenv [var]      | Delete a variable from the environment.             |

We may introduce the following built-in commands in a future version:

| Command             | Definition                        |
| ------------------- | ----------------------------------|
| alias               | Set an alias                      |
| cd [dir]            | Change the directory.             |
| help [built-in]     | Read documentation for a built-in.|
| history             | View the history of the shell.    |

##


### Authors

- Ezequiel Silva - [Github](https://github.com/ezesilva95) / [Linkedin](https://www.linkedin.com/in/ezequiel-silva-perez-1262b115b/)
- Maximiliano Alonso - [Github](https://github.com/MaxiHBTN) / [Linkedin](https://www.linkedin.com/in/maximiliano-alonso-262b05123/)
