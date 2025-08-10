typedef struct ll_node {
    int value;
    struct ll_node *nextnode;
} node;

void ll_display(node *head_node);
node *insert_at_tail(node *head_node, int value);
node *insert_at_head(node *head_node, int value);
node *delete_at_head(node *head_node);
node *delete_at_end(node *head_node);
int ll_length(node *head_node);
int ll_search(node *head_node, int search_value);
int ll_count(node *head_node, int search_value);
void ll_replace(node *head_node, int search_value, int replace_value, int scope);
node *delete_first_match(node *head_node, int search_value, int *delete_status);
node *delete_all_match(node *head_node, int search_value, int *delete_status);
node *ll_append(node *ll1, node *ll2);
node *ll_reverse(node *head_node);
void ll_sort(node *head_node);
node *ll_clear(node *head_node);
