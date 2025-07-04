# Password Generator

This project is a simple C program that generates secure passwords based on user-provided words. The program mutates the words by replacing certain characters with symbols, alternating letter case, and appending a random numeric and symbolic tail.

## Features

- Replaces specific characters with symbols for added security (e.g., `a` → `@`, `e` → `3`).
- Alternates letter case in the mutated words.
- Allows the user to input up to 5 words.
- Adds random separators between words.
- Appends a random numeric and symbolic tail to the password.

## How to Compile

To compile the program, use the following command:

```bash
gcc -o passgen passgen.c
./passgen
```

## Example

```
How many words to use (1–5): 3
Word 1: hello
Word 2: world
Word 3: secure

Generated password: H3Ll0!W0rLd#S3CuR3!42$
```
