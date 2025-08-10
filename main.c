#include <stdio.h>
#include "aalll.h"

int main() {
    printf("running main function\n");
    node *head_node = NULL;
    head_node = insert_at_tail(head_node, 1);
    head_node = insert_at_tail(head_node, 2);
    head_node = insert_at_tail(head_node, 3);
    head_node = insert_at_tail(head_node, 4);
    head_node = insert_at_tail(head_node, 5);
    head_node = insert_at_tail(head_node, 6);
    head_node = insert_at_tail(head_node, 7);
    head_node = insert_at_tail(head_node, 8);    
    ll_display(head_node);
   	head_node = ll_reverse(head_node);
	ll_display(head_node);
    head_node = ll_clear(head_node);
    ll_display(head_node);
    return 0;
}

