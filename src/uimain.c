#include <stdio.h>
#include <stdlib.h>
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
  char test4[50] = "copy me!\0";
  char *test5 = copy_str(test4, 8);
  printf("%s\n", test5);
  char test6[50] = "Time to tokenize\0";
  char **test8 = tokenize(test6);
  print_tokens(test8);
  List *testList1 = malloc(sizeof(List*));
  testList1 = init_history();
  char testString[50] = "howdy there partner\0";
  add_history(testList1, testString);
  char testString2[50] = "such lovely we@ther \0";
  char testString3[50] = "   hello   world   \0";
  add_history(testList1, testString2);
  add_history(testList1, testString3);
  char *returnedStr = get_history(testList1, 3);
  if(returnedStr){
    printf("%s\n", get_history(testList1, 3));
  }
  List *testList2 = init_history();
  print_history(testList2);
  print_history(testList1);
  free_history(testList1);
  printf("list %p root %p", testList1, testList1->root);
  return 0;
}

