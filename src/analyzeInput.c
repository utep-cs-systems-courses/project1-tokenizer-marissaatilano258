#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int get_length(char *str){
  char * strCopy = str;
  while(*strCopy++){}
  int len = strCopy - str;
  return len;
}

int space_char(char c)
{
  if(c == ' ' || c == '\t'){
    return 1;
  } else {
    return 0;
  }
}

int non_space_char(char c)
{
  if(space_char(c) == 0 && c != '\0'){
    return 1;
  } else {
    return 0;
  }
}

char *word_start(char *str)
{
  while(*str){
    if(non_space_char(*(str))){
      return (str);
    }
    *str++;
  }
  return str;
}

char *word_terminator(char *str)
{
  while(*str){
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
  while(*str){
    str = word_start(str);
    str = word_terminator(str);
    numWords++;
  }
  return numWords;
}

char *copy_str(char *inStr, short len)
{
  char *strAlloc = (char *)malloc(sizeof(char) *(len +1));
  for(int i = 0; i < len; i++){
    strAlloc[i] = inStr[i];
  }
  return strAlloc;
}

char **tokenize(char* str)
{
  
  int numTokens = count_words(str);
  char **tokens = (char**)malloc(sizeof(char*) * (numTokens+1));
  for(int i = 0; i < numTokens; i++){
    char *start = word_start(str);
    char *end = word_terminator(str);
    int diff = end-start;
    char *token = copy_str(start, diff);
    tokens[i] = token;
    str = str + diff+1;
  }
  return tokens;
}

void print_tokens(char **tokens)
{
  while(*tokens){
    printf("%s ", *tokens);
    *tokens++;
  }
  printf("\n");
  return;
}

void free_tokens(char **tokens)
{
  while(*tokens){
    free(*tokens);
    *tokens++;
  }
  free(tokens);
}
