node* sort_merge(node* up, node* down);

void split_list(struct node* start_list, struct node** front, struct node** back) {}

void merge_sort(struct node** head) {
	struct node* temp = *head;
	node* up;
	node* down;

	if (empty() == true) {
		cout << "List is empty!" << endl;
		return;
	}

	split_list(temp, up, down);
	merge_sort(&up);
	merge_sort(&down);
	*head = sort_merge(up, down);
}

void sort_merge(node* up, node* down) {
	node* output = NULL;

	if (up == NULL) return(up);
	else if (down == NULL) return(down);

	if (up->key <= down->key) {
		output = up;
		output->next = sort_merge(up->next, down);
	}
	else if (down->key <= up->key) {
		output = down;
		output->next = sort_merge(up, down->next);
	}

	return (output);
}

void split_list(node* start_list, node** front, node* back) {
	node* one_node;
	node* two_node;

	while (two_node != NULL) {
		two_node = two_node->next;

		if (two_node != NULL) {
			one_node = one_node->next;
			two_node = two_node->next;
		}
	}

	*front = start_list;
	*back = one_node->next;
	one_node->next = NULL;
}
