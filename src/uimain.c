#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int get_length(char *str)        /*This method is used to determine the length of the input*/
{
  char *strCopy = str;           /*The pointer is copied and traversed until it reaches a '\0'*/
  while(*strCopy){
    strCopy++;
  }
  int diff = strCopy - str;      /*The difference in values is the length*/
  return diff;
}

int main()
{
  List *history = init_history(); /*First the history is initialized*/
  int i = 1;
  while(i){                       /*The loop is infinite until the user quits*/
    char str[50];
    printf("Please enter a string to tokenize, a history id (ex: '!2'), or q to quit");
    printf(">");                 /*Prompts the user for input*/
    scanf("%[^\n]%*c", str);
    int strLength = get_length(str);
    if(strLength == 1 && str[0] == 'q'){ /*If the input requests to quit the program, it quits*/
      return 1;
    } else if(strLength == 2 && str[0] == '!' && (str[1] >'0' && str[1] <='9')){
      /*If the input requests for a history recall, it prints the string of the id*/
      int i = str[1]-'0';
      printf("%s\n", get_history(history,i));
    }
    else{
      /*Tokenizes the input of the user*/
      printf("%s\n", str);
      char** tokens = tokenize(str);
      print_tokens(tokens);
      add_history(history,copy_str(str,strLength)); /*Adds the tokenized string to history*/
      free_tokens(tokens);
      free(tokens);
    }
  }
  free_history(history);
  free(history);
  return 0;
}

