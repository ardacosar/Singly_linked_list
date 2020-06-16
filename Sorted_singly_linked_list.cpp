
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct node {
	int data;
    node* next;
};

node* firstNode(node* r, int x)
{
	r = new node;
	r->data = x;
	r->next = NULL;
	return r;
}

void showList(node* r)
{
	while (r != NULL)
	{
		cout << r->data << " ";
		r = r->next;
	}
}
node* addNode(node* r, int x)
{
	if (r == NULL)
	{
		r = firstNode(r, x);
	}
	else
	{
		node* tmp;
		tmp = r;

		while (tmp->next != NULL && tmp->next->data < x) // Finding location
		{tmp = tmp->next;}

		
		if (tmp == r && x < r->data) // Add to head
		{
			tmp = new node;
			tmp->data = x;
			tmp->next = r;			
			r = tmp;		
		}
		else if (tmp->next == NULL) // Add to last 
		{
			tmp->next = new node;
			tmp->next->data = x;
			tmp->next->next = NULL;
		}
		else // Add to middle
		{
			node* tmp2;
			tmp2 = new node;

			tmp2->data = x;
			tmp2->next = tmp->next;
			tmp->next = tmp2;

			tmp2 = NULL;
			delete tmp2;		
		}
		tmp = NULL;
		delete tmp;
	}
	return r;
}

int main()
{
	srand(time(NULL));

	node* root;
	root = NULL;

	for (int i = 0; i < 100; i++)
	{
		root = addNode(root, rand()%  500 + 100);
	}
	showList(root);
}

