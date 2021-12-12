#ifndef _EX6_H_
#define _EX6_H_
#define LEN 50


struct node
{
	char name[LEN];
	int id;
	struct node* left;
	struct node* middle;
	struct node* right;
};
void printMenu(struct node* root);

#endif