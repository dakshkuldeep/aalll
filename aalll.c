#include <stdio.h>
#include <stdlib.h>
#include "aalll.h"

void ll_display(node *head_node) {
    while(head_node != NULL) {
        printf("%d -> ", head_node->value);
        head_node = head_node->nextnode;
    }
    printf("NULL\n");
}

node *insert_at_head(node *head_node, int value) {
    node *new_node = (node*)calloc(1, sizeof(node));
    if(new_node == NULL) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;

    if(head_node != NULL)
        new_node->nextnode = head_node;

    return new_node;
}

node *insert_at_tail(node *head_node, int value) {
    node *new_node = (node*)calloc(1, sizeof(node));
    if(new_node == NULL) {
        printf("Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;

    node *current_node = head_node;
    if(head_node == NULL)
        return new_node;
    else {
        while(current_node->nextnode != NULL) current_node = current_node->nextnode;
        current_node->nextnode = new_node;
        return head_node;
    }
}

node *delete_at_head(node *head_node) {
    if(head_node == NULL) 
        return NULL;
    else {
        node *new_head = head_node->nextnode;
        free(head_node);
        return new_head;        
    }
}

node *delete_at_end(node *head_node) {
    if(head_node == NULL)
        return NULL;
    else if(head_node->nextnode == NULL) {
        free(head_node);
        return NULL;
    } else {
        node *current_node = head_node;
        while(current_node->nextnode->nextnode != NULL) current_node = current_node->nextnode;
        free(current_node->nextnode);
        current_node->nextnode = NULL;
        return head_node;
    }
}

int ll_length(node *head_node) {
    int count = 0;
    while(head_node != NULL) {
        count++;
        head_node = head_node->nextnode;
    }
    return count;

    /*to find length recursively:
    if(head_node == NULL) return 0;
    else return 1 + ll_length(head_node->nextnode);
    */
}

int ll_search(node *head_node, int search_value) {
	while(head_node != NULL) {
		if(head_node->value == search_value) return 1;
		head_node = head_node->nextnode;
	}
	return 0;

	/*to find length recursively:
    if(head_node == NULL) return 0;
    else if(head_node->value == search_value) return 1;
    else return ll_search(head_node->nextnode, search_value);
    */
}

int ll_count(node *head_node, int search_value) {
	int count = 0;
    while(head_node != NULL) {
    	if(head_node->value == search_value) count++;
		head_node = head_node->nextnode;
    }
    return count;

    /*to find length recursively:
    if(head_node == NULL) return 0;
    else if(head_node->value == search_value)
    	return 1 + ll_count(head_node->nextnode, search_value);
    else return ll_count(head_node->nextnode, search_value);
	*/
}

void ll_replace(node *head_node, int search_value, int replace_value, int scope) {
	/*scope:
		x > 0: replace all
		0: replace first occurance
	*/
	if(scope) {
		while(head_node != NULL) {
			if(head_node->value == search_value) head_node->value = replace_value;
			head_node = head_node->nextnode;
		}
	} else {
		while(head_node != NULL) {
			if(head_node->value == search_value) {
				head_node->value = replace_value;
				break;
			}
			head_node = head_node->nextnode;
		}
	}
}

node *delete_first_match(node *head_node, int search_value, int *delete_status) {
	if(head_node == NULL) {
		*delete_status = 0;
		return NULL;
	} else if(head_node->value == search_value) {
		node *new_head = head_node->nextnode;
		free(head_node);
		*delete_status = 1;
		return new_head;
	}

	node *current_node = head_node->nextnode;
	node *previous_node = head_node;
	while(current_node != NULL) {
		if(current_node->value == search_value) {
			previous_node->nextnode = current_node->nextnode;
			free(current_node);
			*delete_status = 1;
			return head_node;
		}
		previous_node = current_node;
		current_node = current_node->nextnode;
	}

	*delete_status = 0;
	return head_node;	
}

node *delete_all_match(node *head_node, int search_value, int *delete_status) {
	*delete_status = 0;
	if(head_node == NULL) 
		return head_node;
		
	node *node_dump, *new_head;
	while(head_node->value == search_value) {
		node_dump = head_node;
		head_node = head_node->nextnode;
		free(node_dump);
		*delete_status = *delete_status + 1;
		if(head_node == NULL) return NULL;
	}
	new_head = head_node;

	while(head_node->nextnode != NULL) {
		if(head_node->nextnode->value == search_value) {
			node_dump = head_node->nextnode;
			head_node->nextnode = head_node->nextnode->nextnode;
			free(node_dump);
			*delete_status = *delete_status + 1;
		} else head_node = head_node->nextnode;
	}
	return new_head;
}

node *ll_append(node *ll1, node *ll2) {
	if(ll1 == NULL) return ll2;

	while(ll1->nextnode != NULL) ll1 = ll1->nextnode;
	ll1->nextnode = ll2;
	return ll1;
}

node *ll_reverse(node *head_node) {
	if(head_node == NULL) return NULL;
	if(head_node->nextnode == NULL) return head_node;

	node *temp, *step_node = head_node->nextnode;
	head_node->nextnode = NULL;
	
	while(step_node != NULL) {
		temp = step_node->nextnode;
		step_node->nextnode = head_node;
		head_node = step_node;
		step_node = temp;
	}
	return head_node;
}

void ll_sort(node *head_node) {
	if(head_node == NULL || head_node->nextnode == NULL) return;

	node *step_node = head_node->nextnode;
	int temp;
	while(head_node != NULL) {
		step_node = head_node->nextnode;
		while(step_node != NULL) {
			if(head_node->value > step_node->value) {
				temp = head_node->value;
				head_node->value = step_node->value;
				step_node->value = temp;
			}
			step_node = step_node->nextnode;
		}
		head_node = head_node->nextnode;
	}	
}

node *ll_clear(node *head_node) {
	if(head_node != NULL) {
		ll_clear(head_node->nextnode);
		free(head_node);
	}
	return NULL;	
}
