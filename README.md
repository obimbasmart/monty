# Monty
`monty` is a program that takes a file (monty ByteCodes file) as input, then manipulates a `stack` or a `queue` based on the instructions in the file. `ByteCode` files usually have a `.m` extension, there is not more than one instruction per line, and there can be any number of spaces before or after the opcode and its argument.

Some of the valid `opcodes`  for the Monty bytecode file include, but are not limited to:
- `push 3` - append an integer to a stack or queue
- `pall` - print the stack/queue
- `pint` - print the topmost element in the stack or queue
- `pop` - remove the topmost element in the stack
- `stack` - treat the list as a stack
- `queue` - treat the list as a queue
- etc

Some of the opcodes require no argument, they do not manipulate the list (stack or queue) but simply print something to the console `e.g. (pall)` or change the mode of the list `e.g. (stack, queue)`. There are opcodes that take an extra argument, `e.g. (push)`, which appends the argument to the stack if it's a valid integer.

### Example
```bash
    obimbasmart@MyXubuntu:~/alx-repos/monty$ cat monty_testfile.m
    push 1
    push 2
    push 3
    pall
    pop
    pall
    obimbasmart@MyXubuntu:~/alx-repos/monty$./monty monty_testfile.m
    3
    2
    1
    2
    1
```

### To use monty:
- Clone the repository
- compile all files:  `gcc -Wall -pedantic -Werror -Wextra -std=gnu89 *.c -o monty`
    - This would generate a `monty` executable file
- run: `./monty testfile.m`
    - where testfile.m is a bytecode file opcodes

### File structure
- **tests/**: This directory contains all test files containing opcodes used for testing purposes for this program
- **main.c**: entry point of the program
- **monty.h**: header file
- **stack_queue_ops.c**: These files contain functions specific for each opcode call
- **stack_queue_utils.c**: contains helper functions for the `stack_queue_ops.c` functions
- **utility_functions.c**: utility functions used within the program

## Authors
- [Obimba Smart](https://github.com/obimbasmart)
-  [MauricespazzoZeRo](https://github.com/MauricespazzoZeRo)

## Contributing
Contributions are welcome to improve the project. If you find any issues or have ideas for enhancements, please open an issue or submit a pull request
