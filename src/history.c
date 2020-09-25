#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *history = malloc(sizeof(List*));
  return history;
}

void add_history(List *list, char *str)
{
  Item *temp = malloc(sizeof(Item*));
  Item *newNode = malloc(sizeof(Item));
  if(list->root){
    temp = list->root;
    while(temp->next){
      temp = temp->next;
    }
    newNode->id = (temp->id)+1;
    temp->next = newNode;
  } else{
    list->root = newNode;
    newNode->id = 1;
  }
  newNode->str = str;
}

char *get_history(List *list, int id)
{
  Item *temp = malloc(sizeof(Item*));
  temp = list->root;
  while(temp){
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
  while(temp){
    printf("%d. %s Next->%p\n", temp->id, temp->str, temp->next);
    temp = temp->next;
  }
}

void free_history(List *list)
{
  while(list->root){
    Item *firstItem = list->root;
    list->root = list->root->next;
    free(firstItem);
  }
}
