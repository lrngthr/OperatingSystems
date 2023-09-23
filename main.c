#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
  int x;
  printf("Write your Tests for your linked list implementation\n");
  list_t *mylist;
  mylist = list_alloc();
  list_print(mylist);
  printf("Add element to front Test\n");
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  list_print(mylist);
  list_add_to_front(mylist, 40);
  list_add_to_front(mylist, 50);
  list_add_to_front(mylist, 60);
  list_add_to_front(mylist, 70);
  list_add_to_front(mylist, 80);
  list_add_to_front(mylist, 90);
  list_add_to_front(mylist, 100);

  if(strcmp("100->90->80->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_add_to_front : FAILED\n");
  } else { printf("PASSED!\n");}

  printf("Remove at Index Test\n");
  list_print(mylist);
  list_remove_at_index(mylist, 3);
  list_print(mylist);

  if(strcmp("100->90->80->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_remove_at_index : FAILED\n");
  }  else { printf("PASSED!\n");}

  list_remove_at_index(mylist, 20);
  if(strcmp("100->90->80->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_remove_at_index : FAILED\n");
  }  else { printf("PASSED!\n");}

  list_remove_at_index(mylist, 0);
  if(strcmp("90->80->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_remove_at_index : FAILED\n");
  }  else { printf("PASSED!\n");}

  list_remove_at_index(mylist, 6);
  if(strcmp("90->80->60->50->40->30->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_remove_at_index : FAILED\n");
  }  else { printf("PASSED!\n");}

  
  printf("List Length Test\n");
  printf("The list length is %d\n", list_length(mylist));
  if(list_length(mylist) != 7){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }

  printf("List Add to Back Test\n");
  list_add_to_back(mylist, 39);
  list_add_to_back(mylist, 18);
  list_add_to_back(mylist, 42);
  list_add_to_back(mylist, 190);
  list_free(mylist); 
  if(list_length(mylist) != 0){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }

  printf("List Add to Front & Back Test\n");
  list_add_to_front(mylist, 81);
  list_add_to_back(mylist, 4);
  list_add_to_front(mylist, 308);
  list_add_to_back(mylist, 70);
  list_add_to_front(mylist, 290);
  if(list_length(mylist) != 5){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }
  
  printf("Adding Element at an Index Test\n");
  list_add_at_index(mylist, 21, 1);
  if(list_is_in(mylist, 21) != 1){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }

  list_add_at_index(mylist, 65, 0);
  if(list_is_in(mylist, 65) != 1){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }

  list_add_at_index(mylist, 10, 8);
  if(list_is_in(mylist, 10) != 0){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }

  list_add_at_index(mylist, 10, 7);
  if(list_is_in(mylist, 10) != 1){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }

  printf("Removing Items From the Back\n");
  list_remove_from_back(mylist);
  if(list_get_elem_at(mylist, 6) != 70){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }
  
  printf("Removing Items From the Front\n");
  list_remove_from_front(mylist);
  if(list_get_elem_at(mylist, 0) != 290){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }

  printf("Value is in List Test\n");
  if(list_is_in(mylist, 21) != 1){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }
  if(list_is_in(mylist, 100) != 0){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }

  printf("Get Value at Index Test\n");
  if(list_get_elem_at(mylist, 0) != 290){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }
  if(list_get_elem_at(mylist, 2) != 308){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }

  printf("Get Index of Value Test\n");
  if(list_get_index_of(mylist, 4) != 4){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }
  if(list_get_index_of(mylist, 70) != 5){
      printf("Failed");
  } else {
      printf("PASSED: ");
      list_print(mylist);
  }
  


  
  return 0;
}