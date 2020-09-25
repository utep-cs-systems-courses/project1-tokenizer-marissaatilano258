#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int get_length(char *str)
{
  char *strCopy = str;
  while(*strCopy){
    strCopy++;
  }
  int diff = strCopy - str;
  return diff;
}

int main()
{
  List *history = init_history();
  int i = 0;
  while(i <5){
    char str[50];
    printf("Please enter a string to tokenize, a history id, or q to quit");
    printf(">");
    scanf("%[^\n]%*c", str);
    int strLength = get_length(str);
    if(strLength == 1 && str[0] == 'q'){
      return 1;
    } else if(strLength == 2 && str[0] == '!' && (str[1] >'0' && str[1] <='9')){
      int i = str[1]-'0';
      printf("%s\n", get_history(history,i));
    }
    else{
      printf("%s\n", str);
      char** tokens = tokenize(str);
      print_tokens(tokens);
      add_history(history,copy_str(str,strLength));
      free_tokens(tokens);
      free(tokens);
    }
    i++;
  }
  free_history(history);
  return 0;
}

