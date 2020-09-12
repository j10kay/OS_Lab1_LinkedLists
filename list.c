// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int list_size = 0;
list_t *list_alloc() {
  list_t *l = malloc(sizeof(list_t));
  return l;
}

void list_free(list_t *l) {
    if (!l) {
      return;
    }
    free(l);
}

void list_print(list_t *l) {
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  
  while (current_node != NULL){
    if (current_node->next != NULL){
      printf("%d -> ", current_node->value);
    } else {
      printf("%d\n", current_node->value);
    }
    current_node = current_node->next;
  }
  return;
}

int list_length(list_t *l) {
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  
  if (current_node == NULL){
    return 0;
  }
  
  int list_length = 0;
  while (current_node != NULL){
    list_length++;
    current_node = current_node->next;
  }
  return list_length;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *current_node = malloc(sizeof(node_t));
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  
  if (l->head == NULL){
    l->head = new_node;
    list_size++;
    return;
  }
  
  current_node = l->head;
  while (current_node->next != NULL){
    current_node = current_node->next;
  }
   current_node->next = new_node;
   list_size++;
   return; 
}

void list_add_to_front(list_t *l, elem value) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  node_t *current_node = malloc(sizeof(node_t));
  
  if (l->head == NULL){
    l->head = new_node;
    list_size++;
    return;
  }
  
  new_node->next = l->head;
  l->head = new_node;
  list_size++;
  return;
}

// Adds a node at specified index. Does nothing if index out of bounds.
void list_add_at_index(list_t *l, elem value, int index) {
  node_t *new_node = malloc(sizeof(node_t));
  new_node->value = value;
  
  if (l->head == NULL){
    l->head = new_node;
    return;
  }
  
  if (index < 0){
    printf("Specified index is out of bounds. The list was not modified.\n");
    return;
  }
  
  if (index == 0){
    list_add_to_front(l, value);
    return;
  }
  
  if (index >= list_size){
    printf("Specified index is out of bounds. The list was not modified.\n");
    return;
  }
  
  int current_index = 0;
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  while (current_node != NULL){
    if (current_index == index - 1){
      node_t *original_next = malloc(sizeof(node_t));
      original_next = current_node->next;
      current_node->next = new_node;
      new_node->next = original_next;
      return;
    }
    current_node = current_node->next;
    current_index++;
  }
}

elem list_remove_from_back(list_t *l) {
  if (l->head == NULL){
    printf("Cannot remove from an empty list.\n");
    return;
  }
  
  int current_index = 0;
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  while (current_node != NULL){
    if (current_index == list_size - 1){
      node_t *original_next = malloc(sizeof(node_t));
      original_next = current_node->next;
      current_node->next = NULL;
      list_size--;
      return original_next->value;
    }
    current_node = current_node->next;
    current_index++;
  }
}
  
elem list_remove_from_front(list_t *l) { 
  if (l->head == NULL){
    printf("Cannot remove from an empty list.\n");
    return;
  }
  
  node_t *original_head = malloc(sizeof(node_t));
  original_head = l->head;
  l->head = l->head->next;
  list_size--;
  return original_head->value;

}

// Removes a node at specified index. Does nothing if index out of bounds. 
elem list_remove_at_index(list_t *l, int index) {
  if (l->head == NULL){
    printf("Cannot remove from an empty list.\n");
    return;
  }
  
  if (index < 0){
    printf("Specified index is out of bounds. The list was not modified.\n");
    return;
  }
  
  if (index == 0){
    return list_remove_from_front(l);
  }
  
  if (index >= list_size){
    printf("Specified index is out of bounds. The list was not modified.\n");
    return;
  }
  
  int current_index = 0;
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  while (current_node != NULL){
    if (current_index == index - 1){
      node_t *original_next = malloc(sizeof(node_t));
      original_next = current_node->next;
      current_node->next = current_node->next->next;
      list_size--;
      return original_next->value;
    }
    current_node = current_node->next;
    current_index++;
  }
  
}

bool list_is_in(list_t *l, elem value) {
  if (l->head == NULL){
    printf("Cannot search an empty list.\n");
    return false;
  }
  
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  
  while (current_node != NULL){
    if (current_node->value == value){
      return true;
    }
    current_node = current_node->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) {
  if (l->head == NULL){
    printf("Cannot search an empty list.\n");
    return -1;
  }
  
  if (index < 0){
    printf("Specified index is out of bounds. Nothing is returned.\n");
    return -1;
  }
  
  if (index == 0){
    return l->head->value;
  }
  
  if (index >= list_size){
    printf("Specified index is out of bounds. Nothing is returned.\n");
    return -1;
  }
  
  int current_index = 0;
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  
  while (current_node != NULL){
    if (current_index == index){
      return current_node->value;
    }
    current_node = current_node->next;
    current_index++;
  }
  
}

int list_get_index_of(list_t *l, elem value) {
  if (l->head == NULL){
    printf("Cannot search an empty list.\n");
    return -1;
  }
  
  int current_index = 0;
  node_t *current_node = malloc(sizeof(node_t));
  current_node = l->head;
  
  while (current_node != NULL){
    if (current_node->value == value){
      return current_index;
    }
    current_node = current_node->next;
    current_index++;
  }
  
  printf("Element not found in list.\n");
  return -1;
}