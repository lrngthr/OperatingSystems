// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t *list_alloc() {
   list_t *new_list = (list_t *)malloc(sizeof(list_t));
    if (new_list == NULL) {
        // Handle memory allocation failure
        exit(1);
    }
    new_list->head = NULL;
    return new_list;
 }
void list_free(list_t *l) {
  node_t *current = l->head;
  node_t *next;
  while (current != NULL) {
      next = current->next;
      free(current);
      current = next;
  }
  l->head = NULL;
}

void list_print(list_t *l) {
   if (l == NULL || l->head == NULL) {
        printf("Empty List\n");
        return;
    }

    node_t *current = l->head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

char * listToString(list_t *l) {
  char* buf = (char *) malloc(sizeof(char) * 1024);
  char tbuf[20];

	node_t* curr = l->head;
  while (curr != NULL) {
    sprintf(tbuf, "%d->", curr->value);
    curr = curr->next;
    strcat(buf, tbuf);
  }
  strcat(buf, "NULL");
  return buf;
}

int list_length(list_t *l) {
  if (l == NULL) {
        return 0;
    }

    int length = 0;
    node_t *current = l->head;
    while (current != NULL) {
        length++;
        current = current->next;
    }

    return length; }

void list_add_to_back(list_t *l, elem value) {
  if (l == NULL) {
        return;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        exit(1); // Handle memory allocation failure
    }
    new_node->value = value;
    new_node->next = NULL;

    if (l->head == NULL) {
        l->head = new_node;
    } else {
        node_t *current = l->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}
void list_add_to_front(list_t *l, elem value) {
  if (l == NULL) {
        return;
    }

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        exit(1); // Handle memory allocation failure
    }
    new_node->value = value;
    new_node->next = l->head;
    l->head = new_node;
}
void list_add_at_index(list_t *l, elem value, int index) {
  if (l == NULL || index < 0) {
        return;
    }

    if (index == 0) {
        list_add_to_front(l, value);
    } else {
        node_t *new_node = (node_t *)malloc(sizeof(node_t));
        if (new_node == NULL) {
            exit(1); // Handle memory allocation failure
        }
        new_node->value = value;
        new_node->next = NULL;

        node_t *current = l->head;
        int i = 0;
        while (current != NULL && i < index - 1) {
            current = current->next;
            i++;
        }

        if (current != NULL) {
            new_node->next = current->next;
            current->next = new_node;
        }
    }
}

elem list_remove_from_back(list_t *l) {
  if (l == NULL || l->head == NULL) {
        return -1; // List is empty
    }

    if (l->head->next == NULL) {
        // Only one element in the list
        elem value = l->head->value;
        free(l->head);
        l->head = NULL;
        return value;
    }

    node_t *current = l->head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    elem value = current->next->value;
    free(current->next);
    current->next = NULL;
    return value;
}
elem list_remove_from_front(list_t *l) {
  if (l == NULL || l->head == NULL) {
        return -1; // List is empty
    }

    node_t *temp = l->head;
    l->head = l->head->next;
    elem value = temp->value;
    free(temp);
    return value;
 }

elem list_remove_at_index(list_t *l, int index) { 
   if (l == NULL || l->head == NULL || index < 0) {
        return -1; // List is empty or index is invalid
    }

    if (index > list_length(l)) { return -1;}

    if (index == 0) {
        return list_remove_from_front(l);
    }

    node_t *current = l->head;
    int i = 0;
    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }
    if (current == NULL || current->next == NULL) {
        return -1; // Index out of range
    }

    node_t *temp = current->next; //70
    elem value = temp->value; // 70
    current->next = temp->next;
    free(temp);
    return value;
 }

bool list_is_in(list_t *l, elem value) { 
  node_t *current = l->head;
    
	while (current != NULL) {
		if (current->value == value) {
			return true;
		}
		current = current->next;
	}
	
	return false;
}
elem list_get_elem_at(list_t *l, int index) { 
  if (l == NULL || l->head == NULL || index < 0) {
        return -1; // List is empty or index is invalid
    }

    node_t *current = l->head;
    int i = 0;
    while (current != NULL && i < index) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        return -1; // Index out of range
    }

    return current->value;
 }
int list_get_index_of(list_t *l, elem value) {
  if (l == NULL || l->head == NULL) {
        return -1; // List is empty
    }

    node_t *current = l->head;
    int index = 0;
    
    while (current != NULL) {
        if (current->value == value) {
            return index; // Element found, return its index
        }
        current = current->next;
        index++;
    }

    return -1; // Element not found
 }

