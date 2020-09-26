#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *history = malloc(sizeof(List*)); /*Allocates memory for the new List history*/
  return history;
}

void add_history(List *list, char *str)
{
  Item *temp = malloc(sizeof(Item*));   /*temp is used to traverse the list*/
  Item *newItem = malloc(sizeof(Item)); /*Allocates memory for the new item*/
  if(list->root){                       /*If the list is not empty, */
    temp = list->root;                  /*the last item points to the next item*/
    while(temp->next){
      temp = temp->next;
    }
    newItem->id = (temp->id)+1;
    temp->next = newItem;
  } else{                               /*If the list is empty, the new item becomes the root*/
    list->root = newItem;
    newItem->id = 1;
  }
  newItem->str = str;
}

char *get_history(List *list, int id)
{
  Item *temp = malloc(sizeof(Item*));
  temp = list->root;
  while(temp){        /*Traverses the list until an item with the same id is found*/
    if(temp->id == id){
      return temp->str;
    }
    temp = temp->next;
  }
  return NULL;
}

void print_history(List *list)
{
  Item *temp = malloc(sizeof(Item*));
  temp = list->root;
  while(temp){        /*Prints the data of the item temp until temp is NULL*/
    printf("%d. %s Next->%p\n", temp->id, temp->str, temp->next);
    temp = temp->next;
  }
}

void free_history(List *list)
{
  while(list->root){        /*Frees each item in the list starting from the first item*/
    Item *firstItem = list->root;
    list->root = list->root->next;
    free(firstItem);
  }
}
