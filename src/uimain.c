#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char str[50];
  printf(">");
  scanf("%[^\n]%*c", str);
  printf("%s\n", str);
  printf("is space char %d\n", space_char(str[0]));
  printf("is non space char %d\n", non_space_char(str[0]));
  char test1[50] = "find the start\0";
  char test2[50] = "this\0";
  char *p = word_start(test1);
  printf("start should be f %c\n",*p);
  char *f = word_terminator(test2);
  printf("end should be s %c\n",*(f-1));
  char test3[50] = "there are four words\0";
  printf("four words %d\n", count_words(test3));
  char test4[50] = "copy me!\0";;
  char *test5 = copy_str(test4, 8);
  printf("%s\n", test5);
  char test6[50] = "Time to tokenize\0";
  char **test8 = tokenize(test6);
  print_tokens(test8);
  
  return 0;
}

