#include <stddef.h>
#include <stdio.h>

typedef struct list {
  int val;
  struct list *next;
} list_t;

// Makes a list with the first element `first_value`, and the second element `first_value + 1`
list_t make_two_elt_list(int starting_value) {
  list_t list_node_2 = {starting_value + 1, NULL};

  list_t list_node_1 = {starting_value, &list_node_2};

  return list_node_1;
}

int main() {
  list_t my_list = make_two_elt_list(1);
  printf("First list element: %d\n", my_list.val);
  printf("Second list element: %d\n", my_list.next->val);
}
