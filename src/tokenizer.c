#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if(c == ' ' || c == '\t'){    /*Returns true if c is a space or tab character*/
    return 1;
  } else {
    return 0;
  }
}

int non_space_char(char c)
{
  if(space_char(c) == 0 && c != '\0'){ 
    return 1;                  /*Returns true if c is not a space, tab, or zero terminator*/
  } else {
    return 0;
  }
}

char *word_start(char *str)
{
  while(*str){                /*Increments str until a nonspace char or '\0' is found*/
    if(non_space_char(*(str))){
      return (str);
    }
    *str++;
  }
  return str;
}

char *word_terminator(char *str)
{
  while(*str){                /*Increments str until a space char or '\0' is found*/
    if(space_char(*(str))){
      return (str);
    }
    *str++;
  }
  return str;
}

int count_words(char *str)
{
  int numWords = 0;
  while(*str){            /*Increments num words each time a start and end are determined*/
    str = word_start(str);
    str = word_terminator(str);
    numWords++;
  }
  return numWords;
}

char *copy_str(char *inStr, short len)
{
  char *strAlloc = (char *)malloc(sizeof(char) *(len +1));
  for(int i = 0; i < len; i++){       /*Copies the value of each char into a new allocated string*/
    strAlloc[i] = inStr[i];
  }
  return strAlloc;
}

char **tokenize(char* str)
{  
  int numTokens = count_words(str); /*numTokens is determined by the number of words in str*/
  char **tokens = (char**)malloc(sizeof(char*) * (numTokens+1));
  for(int i = 0; i < numTokens; i++){
    char *start = word_start(str);       /*A word is found*/
    char *end = word_terminator(str);
    int diff = end-start;
    char *token = copy_str(start, diff); /*The value of each word is copied as a token*/
    tokens[i] = token;                   /*Then the token is added to tokens*/
    str = str + diff+1;                  /*Then the string is incremented to the next word*/
  }
  return tokens;
}

void print_tokens(char **tokens)
{
  while(*tokens){                /*The value of each token is printed as a string*/
    printf("%s\n", *tokens);
    *tokens++;
  }
  return;
}

void free_tokens(char **tokens)
{
  while(*tokens){    /*Each token within tokens is freed*/
    free(*tokens);
    *tokens++;
  }
}
