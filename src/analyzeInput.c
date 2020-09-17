#include <stdio.h>
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
