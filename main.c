#include <stdio.h>

#include "list.h"

int main() {
  
  printf("\n");
  printf("#################################################\n");
  printf("##### Tests for linked list implementation ######\n");
  printf("#################################################\n");
  printf("\n");
  
  list_t *test_list = list_alloc();
  
  //  Add Functions 
  list_add_to_back(test_list, 4);        //  4
  list_add_to_back(test_list, 5);        //  4 -> 5
  list_add_to_back(test_list, 6);        //  4 -> 5 -> 6
  list_add_to_back(test_list, 7);        //  4 -> 5 -> 6 -> 7
  list_add_to_front(test_list, 2);       //  2 -> 4 -> 5 -> 6 -> 7
  list_add_to_front(test_list, 1);       //  1 -> 2 -> 4 -> 5 -> 6 -> 7
  list_add_at_index(test_list, 3, 2);    //  1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7
  
  list_print(test_list);
  printf("List length: %d\n", list_length(test_list));   //  7
  
  //  Remove Functions 
  list_remove_from_back(test_list);      //  1 -> 2 -> 3 -> 4 -> 5 -> 6
  list_remove_from_front(test_list);     //  2 -> 3 -> 4 -> 5 -> 6
  list_remove_at_index(test_list, 2);    //  2 -> 3 -> 5 -> 6
  list_remove_at_index(test_list, 20);   //  2 -> 3 -> 5 -> 6
  list_remove_at_index(test_list, -2);    //  2 -> 3 -> 5 -> 6
  
  list_print(test_list);
  printf("List length: %d\n", list_length(test_list));
  
  //  Search Functions
  printf("4 in the list? (0: false, 1: true): %d\n", list_is_in(test_list, 4));              //  0  - false
  printf("5 in the list? (0: false, 1: true): %d\n", list_is_in(test_list, 5));              //  1  - true 
  printf("The element at index 2 is: %d\n", list_get_elem_at(test_list, 2));                 //  5
  printf("The index of element 6 is: %d\n", list_get_index_of(test_list, 6));                //  3
  printf("The index of element 66 is: %d\n", list_get_index_of(test_list, 66));              //  -1
  printf("\n");
  
  list_t *empty_list = list_alloc();
  printf("The empty list: ");
  list_print(empty_list);
  printf("\n");
  list_remove_from_back(empty_list);
  list_remove_from_front(empty_list);   
  list_remove_at_index(empty_list, 2);
  printf("4 in the list? (0: false, 1: true): %d\n", list_is_in(empty_list, 4));              
  printf("5 in the list? (0: false, 1: true): %d\n", list_is_in(empty_list, 5));              
  printf("The element at index 2 is: %d\n", list_get_elem_at(empty_list, 2));                 
  printf("The index of element 6 is: %d\n", list_get_index_of(empty_list, 6));
  printf("\n");
  
  list_free(test_list);
  list_free(empty_list);
  return 0;
}