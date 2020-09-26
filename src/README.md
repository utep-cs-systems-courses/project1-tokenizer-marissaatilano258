Project 1: Tokenizer
====================
# Description:

This program is a tokenizer that maintains a history. The tokenizer divides a
string into tokens using the space character as a delimeter.

A user can also recall  history item using the command line.

#Files:

The following files are included in this program
    -tokenizer.c: Defines functions to tokenize a string based on the space delimeter
    -tokenizer.h: Header file containing all declarations of methods in tokenizer.c
    -history.c: Defines functions to create a history of tokenized strings
    -history.h: Header file containing all declarations of methods in history.c
    -uimain.c: Main file with UI to interact with the user. Based on the user
    input, it will tokenize a string or recall history

You can compile this program using the commands
    $ make clean
    $ make

The following command runs the program
    $ ./tokenizeInput
    
This file is written in the refreshingly simple `markdown` text
formatting language.

To learn about text formatting using markdown, we encourage you to examine 
 - [../README.md](../README.md)
 - the online [Markdown Guide](https://www.markdownguide.org/).
