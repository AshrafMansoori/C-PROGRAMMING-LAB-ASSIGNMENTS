# String Utility Toolkit

This C program implements a simple string utility toolkit with menu-driven functionality. It allows the user to enter a string and perform several operations such as measuring length, reversing the string, checking for palindrome, counting vowels, digits, spaces, and displaying character frequency.

## Features

- Input a string
- Find string length
- Reverse the string
- Check if the string is a palindrome
- Count the number of vowels in the string
- Count the number of digits in the string
- Count the number of spaces in the string
- Display frequency of each character

## Files

- `Assignment.c` - main C source file containing the string utility program
- `README.md` - this markdown documentation file

## Usage

1. Compile the program using a C compiler such as `gcc`:

```sh
gcc Assignment.c -o Assignment
```

2. Run the compiled executable:

```sh
./Assignment
```

3. Use the menu options to enter a string and perform desired operations.

## Example

- Choose option `1` to enter a string
- Choose option `2` to display the length
- Choose option `3` to see the reversed string
- Choose option `4` to check palindrome status
- Choose option `5` to count vowels
- Choose option `6` to count digits
- Choose option `7` to count spaces
- Choose option `8` to display character frequency
- Choose option `9` to exit

## Notes

- The program uses `fgets` to read the string and removes the trailing newline.
- The string buffer is limited to 100 characters.
- Input is case-insensitive for vowel counting when using `tolower`.
