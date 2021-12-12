#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"
#include "ex6.h"
#include "Utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define COUNT 8
#define SIZE 40
#define LEFT 1
#define MID 2
#define RIGHT 3
#define BFS_PRINT 1
#define SUPERSPREADER_PRINT 2
#define LEN 50
#define SPACES 3
void selectNextOpt(struct node* root);
void printMenu(struct node* root);
void operationChooser(struct node* root);
struct node* createTrinAri(struct node* root);
void newFamilyMember(struct node* root);
struct node* search(struct node* root, int ID);
void opt3Menu(struct node* root);
void newLeaf(struct node* root);
struct node* isParent(struct node* root, int ID);
void bidud(struct node* root);
void preOrderPrint(struct node* root);
void leftOrderPrint(struct node* root);
void printBFS(struct node* root, int opt);
void superSpreader(struct node* root);
int vaccinateTrinAri(struct node* root);
void destroyTrinAriTree(struct node* root);
int leafPos(struct node* parent, int ID);
void opt0(struct node* root);
void opt1(struct node* root);
void opt2(struct node* root);
void opt3(struct node* root);
void opt4(struct node* root);
void opt5(struct node* root);
void opt6(struct node* root);
void NULL_maker(struct node* new_leaf);
void leafCpy(struct node* new_leaf, char name1[LEN], int ID);
void printMenuFor3(struct node* root);
/***********************************************************************************
* Name: Or Spiegel
* ID: 318720067
* Group: 1
* Assignment: ex6
***********************************************************************************/
void print2DUtil(struct node* root, int space)
{
	// Base case 
	if (root == NULL)
		return;

	// Increase distance between levels 
	space += COUNT;

	// Process right child first 
	print2DUtil(root->right, space);
	for (int i = COUNT; i < space; i++)
		printf(" ");
	printf("%s %d\n", root->name, root->id);
	// Process middle child 
	print2DUtil(root->middle, space);
	printf("\n");
	// Process left child 
	print2DUtil(root->left, space);
}
/***********************************************************************************
* Function name: printMenu
* Input: struct node* root
* Output: void
* Function Operation: the function printd the menu to the user, and than calls the
*					choosing function, the wiil let the user to chose an option.
***********************************************************************************/
void printMenu(struct node* root)
{
	printf("Please select an operation:\n\t0. Exit.\n\t1. Create family.\n\t2. Add family member.\n\t3. Print Family-Tree.\n\t4. Bidud.\n\t5. Superspreader.\n\t6. Vaccine.\n\t7. Print the menu.\n");
	operationChooser(root);
}

/***********************************************************************************
* Function name: operationChooser
* Input: struct node* root
* Output: void
* Function Operation: the function lets the user to insert an opt input,
*					that is a decimal number in rgane 0-7.
					with correlation That function calls the suitable functions.
***********************************************************************************/
void operationChooser(struct node* root)
{
	char opt[100] = { 0 };
	scanf(" %[^\n]", opt);
	if (strlen(opt) != 1) {
		printf("Error: unrecognized operation\n");
	}
	if (strcmp(opt, "0") == 0) {
		opt0(root);
	}
	else if (strcmp(opt, "1") == 0)	{
		opt1(root);
	}
	else if (strcmp(opt, "2") == 0)	{
		opt2(root);
	}
	else if (strcmp(opt, "3") == 0)	{
		opt3(root);
	}
	else if (strcmp(opt, "4") == 0)	{
		opt4(root);
	}
	else if (strcmp(opt, "5") == 0)	{
		opt5(root);
	}
	else if (strcmp(opt, "6") == 0)	{
		opt6(root);
	}
	else if (strcmp(opt, "7") == 0)	{
		printMenu(root);
	}
	else {
		printf("Error: unrecognized operation.\n");
		selectNextOpt(root);
	}
	return;
}

/***********************************************************************************
* Function name: opt0
* Input: struct node* root
* Output: void
* Function Operation: the function calss the suitable fuctions to "0" operation
						that is the exit operation. It calls the freeing function
						and than ends the program.
***********************************************************************************/
void opt0(struct node* root)
{
	destroyTrinAriTree(root);
	exit(0);
}

/***********************************************************************************
* Function name: opt1
* Input: struct node* root
* Output: void
* Function Operation: the function calls the suitable fuctions to "1" operation,
*					that is the function that creates a new root.
***********************************************************************************/
void opt1(struct node* root)
{
	/*if theres already a root, we can't add a new one!*/
	if (root != NULL) {
		printf("The family has already been created\n");
		selectNextOpt(root);
	}
	root = createTrinAri(root);
	selectNextOpt(root);
}

/***********************************************************************************
* Function name: opt2
* Input: struct node* root
* Output: void
* Function Operation: the function calls the suitable fuctions to "2" operation,
*					that is the function that creates a new family member.
***********************************************************************************/
void opt2(struct node* root)
{
	/*
	if there's no root, the user need to create one first
	else-> ill call a new family member cration function
	*/
	if (root == NULL) {
		printf("Please create the family first\n");
		selectNextOpt(root);
		return;
	}
	newFamilyMember(root);
	selectNextOpt(root);
}

/***********************************************************************************
* Function name: opt3
* Input: struct node* root
* Output: void
* Function Operation: the function calls the suitable fuctions to "3" operation,
*					that is the function that prints the "mini-Prints" menu
***********************************************************************************/
void opt3(struct node* root)
{
	opt3Menu(root);
	selectNextOpt(root);
}

/***********************************************************************************
* Function name: opt4
* Input: struct node* root
* Output: void
* Function Operation: the function calls the suitable fuctions to "4" operation,
*					that is the function that calls members to get in BIDUDU.
***********************************************************************************/
void opt4(struct node* root)
{
	/*
	if there's no root, the user need to create one first
	else-> ill call the bidud function
	*/
	if (root == NULL) {
		printf("Please create the family first\n");
		selectNextOpt(root);
		return;
	}
	bidud(root);
	selectNextOpt(root);
}

/***********************************************************************************
* Function name: opt5
* Input: struct node* root
* Output: void
* Function Operation: the function calls the suitable fuctions to "5" operation,
*					that is the function that calls a superspreader to stay home.
***********************************************************************************/
void opt5(struct node* root)
{
	/*
	if there's no root, the user need to create one first
	else-> ill call my superspreader function
	*/
	if (root == NULL) {
		printf("Please create the family first\n");
		selectNextOpt(root);
		return;
	}
	superSpreader(root);
	selectNextOpt(root);
}

/***********************************************************************************
* Function name: opt6
* Input: struct node* root
* Output: void
* Function Operation: the function calls the suitable fuctions to "6" operation,
*					that is the function that vaccinatesmam member.
***********************************************************************************/
void opt6(struct node* root)
{
	/*
	if there's no root, the user need to create one first
	else-> ill call my vaccinate function
	*/
	if (root == NULL) {
		printf("Please create the family first\n");
		selectNextOpt(root);
		return;
	}
	if (vaccinateTrinAri(root) == 1) {
		root = NULL;
	}
	selectNextOpt(root);
}

/***********************************************************************************
* Function name: selectNextOpt
* Input: struct node* root
* Output: void
* Function Operation: the function calls the operationChooser function,
					that lets the user to chose an option.
***********************************************************************************/
void selectNextOpt(struct node* root)
{
	printf("Select the next operation (insert 7 for the entire menu):\n");
	operationChooser(root);
	return;
}

/***********************************************************************************
* Function name: createTrinAri
* Input: struct node* root
* Output: struct node* 
* Function Operation: the function crates a new family head/root.
*					it allocates an memory to the family head member, and
*					places his data at his address.
***********************************************************************************/
struct node* createTrinAri(struct node* root)
{
	char name1[LEN] = { 0 };
	//initiation of the id variable
	int ID;
	//initiation of a new pointer that soon to point on the root, and allocation
	struct node* ptr = (struct node*)malloc(sizeof(struct node));

	/*if the allocation falied*/
	if (ptr == NULL){
		printf("Malloc falied!\n");
		free(ptr);
		exit(1);
	}
	printf("enter name\n");
	scanf(" %[^\n]", &name1);
	printf("enter ID\n");
	scanf("%d", &ID);
	strcpy(ptr->name, name1);
	//placement of the ID value on the struct
	ptr->id = ID;
	// Initialize left, equal and right children of the root iv'e insert as NULL 
	ptr->left = NULL;
	ptr->middle = NULL;
	ptr->right = NULL;
	printf("Hello %s, ID: %d\n", ptr->name, ptr->id);
	return ptr;
}

/***********************************************************************************
* Function name: newFamilyMember
* Input: struct node* root
* Output: void
* Function Operation: the function crates a new family member.
*					it asks for ID from the user, and if the id is exist on TrinAri,
*					and if all the child positions of the parent isnt full, it will 
*					call an allocation function to tha new leaf.
***********************************************************************************/
void newFamilyMember(struct node* root)
{
	//initiation of a new pointer to NULL
	struct node* parent = NULL;
	//initiation of a integer variabale to the ID value of the parent
	int ID_input;
	printf("Enter the ID of the person who wants to make an appointment?\n");
	scanf("%i", &ID_input);
	//initiation of a new pointer to keep the desired parent address
	struct node* parent_adress = search(root, ID_input);

	/*
	if the address that the "search" function return = NULL, 
	there is no ID like the input
	*/
	if (parent_adress == NULL) {
		printf("There is no ID %d\n", ID_input);
	}

	/*else, if all of the leafs (children) of the parent are full:*/
	else if (parent_adress->left != NULL && parent_adress->middle != NULL && parent_adress->right != NULL) {
		printf("%s ID: %d can't meet more than 3 members!\n", parent_adress->name, parent_adress->id);
		return;
	}

	/*
	At the best case, ill call the "newLeaf" function to 
	allocate a new family member!
	*/
	else {
		parent = parent_adress;
		newLeaf(parent);
	}
}

/***********************************************************************************
* Function name: opt3Menu
* Input: struct node* root
* Output: void
* Function Operation: The function prints the mini- Menu first, than, in correlation
*					with the user input, it calls the desired operation suitable
*					sub-functions.
***********************************************************************************/
void opt3Menu(struct node* root)
{	
	char opt[LEN];
	printf("Please select an operation:\n\t0. Return to the main menu.\n\t1. Print Trin-Ari family.\n\t"
		"2. Print Pre-order.\n\t3. Print Left-order.\n\t4. Print BFS.\n");
	scanf(" %[^\n]", opt);

	/*if the user chose 0 option*/
	if (strcmp(opt, "0") == 0) {
		if (root == NULL) {
			printMenuFor3(root);
			return;
		}
		printMenu(root);
	}

	/*if the user chose 1 option*/
	else if (strcmp(opt, "1") == 0) {
		if (root == NULL) {
			printMenuFor3(root);
			return;
		}
		print2DUtil(root, SPACES);
		printMenuFor3(root);
	}

	/*if the user chose 2 option*/
	else if (strcmp(opt, "2") == 0)	{
		if (root == NULL) {
			printMenuFor3(root);
			return;
		}
		preOrderPrint(root);
		printMenuFor3(root);
	}

	/*if the user chose 3 option*/
	else if (strcmp(opt, "3") == 0)	{
		if (root == NULL) {
			printMenuFor3(root);
			return;
		}
		leftOrderPrint(root);
		printMenuFor3(root);
	}

	/*if the user chose 4 option*/
	else if (strcmp(opt, "4") == 0)	{
		if (root == NULL) {
			printMenuFor3(root);
			return;
		}
		printBFS(root,BFS_PRINT);
		printMenuFor3(root);
	}

	/*if the user didnt chose a valid option*/
	else if (strcmp(opt, "0") != 0 && strcmp(opt, "1") != 0 && strcmp(opt, "2") != 0 && strcmp(opt, "3") != 0 && strcmp(opt, "4") != 0)	{
		printf("Error: unrecognized operation.\n");
		opt3Menu(root);
	}
	return;
}

/***********************************************************************************
* Function name: printMenuFor3
* Input: struct node* root
* Output: void
* Function Operation: the function prints the menu and than lets the user to chhose
*					the option he wants to
***********************************************************************************/
void printMenuFor3(struct node* root)
{
	printMenu(root);
	operationChooser(root);
}
/***********************************************************************************
* Function name: preOrderPrint
* Input: struct node* root
* Output: void
* Function Operation: the function prints all of the TrinAri members
*					by pre order print. If the root id NULL, it will end 
*					the function and print nothing.
***********************************************************************************/
void preOrderPrint(struct node* root)
{
	/*Base case*/
	if (root == NULL)
		return;

	/*Process right child first*/
	printf("%s ID: %d\n", root->name, root->id);
	preOrderPrint(root->left);

	/*Process middle child*/
	preOrderPrint(root->middle);

	/*Process left child */
	preOrderPrint(root->right);
}

/***********************************************************************************
* Function name: leftOrderPrint
* Input: struct node* root
* Output: void
* Function Operation: the function prints all of the TrinAri members
*					by left order print. If the root id NULL, it will end
*					the function and print nothing.
***********************************************************************************/
void leftOrderPrint(struct node* root)
{
	/*
	if thr head of the family isnt NULL, 
	ill recursively print the family members by left order print
	*/
	if (root == NULL) {
		return;
	}
	leftOrderPrint(root->left);
	printf("%s ID: %d\n", root->name, root->id);
	leftOrderPrint(root->middle);
	leftOrderPrint(root->right);
}

/***********************************************************************************
* Function name: search
* Input: struct node* root, int ID
* Output: struct node*
* Function Operation: the function gets an ID, and looking for it
*					holder's address, recursively, If the root is NULL,
*					the function will return NULL, if the function will
*					not fint the ID holder, it will return NULL. else,
					the function return the ID holder's address.
***********************************************************************************/
struct node* search(struct node* root, int ID)
{
	struct node* node = NULL;
	/* Base Cases: root is null or ID is present at root*/
	if (root == NULL) {
		return NULL;
	}
	else if (ID == root->id) {
		return root;
	}

	/*else, Ill search recursively the address of the desired ID holder*/
	else if (root->id != ID) {
		node = search(root->left, ID);

		/*if the search function didnt returned a NULL ptr*/
		if (node != NULL) {
			return node;
		}
		node = search(root->middle, ID);

		/*if the search function didnt returned a NULL ptr*/
		if (node != NULL) {
			return node;
		}
		node = search(root->right, ID);

		/*if the search function didnt returned a NULL ptr*/
		if (node != NULL) {
			return node;
		}
	}
	if (node == NULL) {
		//printf("%d do not exists in BST.\n", ID);
		return NULL;
	}
	return node;
}

/***********************************************************************************
* Function name: newLeaf
* Input: struct node* root
* Output: void
* Function Operation: the function firstly takes an input of an id from the user.
*					than it searches the pointer to that id->if the pointer is null, 
*					that is an original ID num. else, that id is taken.
*					the function allocates a memory for that new leaf.
*					than it checks if theres any placr fot accomodation for the leaf
*					if theres a place at left-> the func put the pointer at left.
*					if not-> the func put the pointer at the middle leaf, if the
*					middle leaf is also full, ,it puts the pointer at the right leaf. 
*					if all the positions are full, it will print that the parent
*					cant meet more than 3 members.
***********************************************************************************/
void newLeaf(struct node* parent)
{
	//initialization of the name input to be al long as 50 chars
	char name1[LEN] = { 0 };
	//initialization of the id integer
	int ID;
	printf("enter name\n");
	scanf(" %[^\n]", &name1);
	printf("enter ID\n");
	scanf("%d", &ID);
	//initialization of the ptr to point on the ID holder address
	struct node* ptr = search(parent, ID);

	/*if theres already an id like the input*/
	if (ptr != NULL) {
		printf("ID %d belongs to %s\n", ID, ptr->name);
		newLeaf(parent);
		return;
	}
	//initialization of 2 pointers, and allocaion of "new_leaf" pointer
	struct node* new_leaf = (struct node*)malloc(sizeof(struct node));
	struct node* p = new_leaf;

	//if the malloc has failed
	if (new_leaf == NULL) {
		printf("Malloc falied!\n");
		free(new_leaf);
		exit(1);
	}	
	//ill make the cuurent leaf subtrees null
	NULL_maker(new_leaf);

	/*if theres a space on the left leaf*/
	if (parent->left == NULL) {
		parent->left = new_leaf;
		leafCpy(new_leaf, name1, ID);
	}

	/*else, if theres a space on the middle leaf*/
	else if (parent->middle == NULL) {
		parent->middle = new_leaf;
		leafCpy(new_leaf, name1, ID);

	}

	/*else, if theres a space on the right leaf*/
	else if (parent->right == NULL)	{
		parent->right = new_leaf;
		leafCpy(new_leaf, name1, ID);
	}

	/*else, ther no place to anymore meetings*/
	else {
		printf("%s ID: %d can't meet more than 3 members!\n", parent->name, parent->id);
		return;
	}
}

/***********************************************************************************
* Function name: NULL_maker
* Input: struct node* root
* Output: void
* Function Operation: the function gets a leaf poiner, and makes his offspring NULL
***********************************************************************************/
void NULL_maker(struct node* new_leaf)
{
	new_leaf->left = NULL;
	new_leaf->middle = NULL;
	new_leaf->right = NULL;
}

/***********************************************************************************
* Function name: leafCpy
* Input: struct node* new_leaf, char name1[LEN], int ID
* Output: void
* Function Operation: the function takes a pointer to a leaf, a name string, and an 
*					id number, and copy that name and ID to the right place 
					on the struct.
***********************************************************************************/
void leafCpy(struct node* new_leaf, char name1[LEN], int ID)
{
	strcpy(new_leaf->name, name1);
	new_leaf->id = ID;
	printf("Hello %s, ID: %d\n", new_leaf->name, new_leaf->id);
}

/***********************************************************************************
* Function name: bidud
* Input: struct node* root
* Output: void
* Function Operation: the function will scan the ID,
					fintd the pointer to that specific suspect ID,
*					and will search his parent, and his subTrees, 
*					snd for the suspect, for the suspect parent and for the suspect
*					subtrees it will print to stay home. 
***********************************************************************************/
void bidud(struct node* root)
{
	printf("Enter the ID of the suspected member\n");
	//initiation of int variable, thal soon to hold the ID value
	int ID;
	scanf("%d", &ID);
	//points on the location of the ID
	struct node* ptr = search(root, ID);
	//temporary pointer
	struct node* tmp = NULL;

	/*if theres no ID like that*/
	if (ptr == NULL) {
		printf("ID %d does not exist\n", ID);
		return;
	}

	/*if the ptr points on the head of the family (the root), ill send to BIdud all of his meeting members*/
	if (ptr == root) {
		printf("#StayHome! %s %d\n", ptr->name, ptr->id);

		/*if the left leaf isn't null, ill send him to Bidud*/
		if (root->left != NULL)	{
			printf("#StayHome! %s %d\n", ptr->left->name, ptr->left->id);
		}

		/*if the middle leaf isn't null, ill send him to Bidud*/
		if (root->middle != NULL) {
			printf("#StayHome! %s %d\n", ptr->middle->name, ptr->middle->id);
		}

		/*if the right leaf isn't null, ill send him to Bidud*/
		if (root->right != NULL) {
			printf("#StayHome! %s %d\n", ptr->right->name, ptr->right->id);
		}
	}

	/*
	if the location ptr points on the last one of the list, 
	ill sent the specific person to Bidud and also his parent
	*/
	else if (ptr->left == NULL && ptr->middle == NULL && ptr->right == NULL) {
		//ptr will hold the parent address
		tmp = isParent(root, ID);
		printf("#StayHome! %s %d\n", tmp->name, tmp->id);
		printf("#StayHome! %s %d\n", ptr->name, ptr->id);
	}

	/*
	Else; ill sent the specific person to Bidud, also his parent, and also his meeting members
	*/
	else {
		//tmp will hold the parent address
		tmp = isParent(root, ID);
		printf("#StayHome! %s %d\n", tmp->name, tmp->id);
		printf("#StayHome! %s %d\n", ptr->name, ptr->id);

		/*if there is an left member, ill send him home!*/
		if (ptr->left != NULL) {
			printf("#StayHome! %s %d\n", ptr->left->name, ptr->left->id);
		}

		/*if there is an middle member, ill send him home!*/
		if (ptr->middle != NULL) {
			printf("#StayHome! %s %d\n", ptr->middle->name, ptr->middle->id);
		}

		/*if there is an right member, ill send him home!*/
		if (ptr->right != NULL)	{
			printf("#StayHome! %s %d\n", ptr->right->name, ptr->right->id);
		}
	}
	return;
}

/***********************************************************************************
* Function name: isParent
* Input: struct node* root, int ID
* Output: struct node* parent
* Function Operation: the function will get an ID,
*					and will search his parent. it will return at the end the
*					ID holder parent's address.
***********************************************************************************/
struct node* isParent(struct node* root, int ID)
{
	struct node* node = NULL;
	/* Base Cases: root is null or ID is present at root */
	if (root == NULL) {
		return NULL;
	}

	/* if  the left isnt NULL */
	if (root->left != NULL) {

		/*
		if the root left leaf Id id equal to the desired ID,
		ill return the left leaf address
		*/
		if (root->left->id == ID) {
			return root;
		}
	}

	/* if  the middle isnt NULL */
	if (root->middle != NULL) {

		/*
		if the root middle leaf Id id equal to the desired ID, 
		ill return the middle leaf address 
		*/
		if (root->middle->id == ID)	{
			return root;
		}
	}

	/* if  the right isnt NULL */
	if (root->right != NULL) {
		/*
		if the root right leaf Id id equal to the desired ID,
		ill return the right leaf address
		*/
		if (root->right->id == ID) {
			return root;
		}
	}

	/* 
	if  the left isnt NULL-> if his parent node isnt null->
	ill return that node with the address! 
	*/
	else {
		node = isParent(root->left, ID);
		if (node != NULL) {
			return node;
		}
		node = isParent(root->middle, ID);
		if (node != NULL) {
			return node;
		}
		node = isParent(root->right, ID);
		if (node != NULL) {
			return node;
		}
	}
	return node;
}

/***********************************************************************************
* Function name: printBFS
* Input: struct node* root, int opt
* Output: void
* Function Operation: the function will get an opt.
*						if the opt == 1,it will just print by levels 
*						all of the TrinAri members and their data.
*						if the opt input == 2, it will just print by levels 
*						all of the TrinAri members THAT NEET TO GO TO BIDUD
						and their data. That function recursively calls another functions
						that creating a queue, and print the desired words by that
						printing methhod.
***********************************************************************************/
void printBFS(struct node* root, int opt)
{
	//initialization of the queue
	Queue* queue = createQueue();

	/*if theres no family il return*/
	if (root == NULL) {
		return;
	}

	/*if the left offspring of the root is exist*/
	if (root->left != NULL)	{
		enQueue(queue, root->left);
	}

	/*if the middle offspring of the root is exist*/
	if (root->middle != NULL) {
		enQueue(queue, root->middle);
	}

	/*if the right offspring of the root is exist*/
	if (root->right != NULL) {
		enQueue(queue, root->right);
	}

	/*if the option is BFS_PRINT, ill print by bfs order the names*/
	if (opt == BFS_PRINT) {
		printf("%s %d\n", root->name, root->id);
	}

	/*if the option is SUPERSPREADER_PRINT, ill print by bfs order the names with an notation to #StayHome!*/
	if (opt == SUPERSPREADER_PRINT) {
		printf("#StayHome! %s %d\n", root->name, root->id);
	}

	/*while isEmpty isn't NULL*/
	while (!isEmpty(queue)) {
		root = queue->front->data;
		//removing of element from the Queue
		deQueue(queue);

		/*if the left leaf isnt null, ill add his data to my queue*/
		if (root->left != NULL)	{
			enQueue(queue, root->left);
		}

		/*if the middle leaf isnt null, ill add his data to my queue*/
		if (root->middle != NULL) {
			enQueue(queue, root->middle);
		}

		/*if the right leaf isnt null, ill add his data to my queue*/
		if (root->right != NULL) {
			enQueue(queue, root->right);
		}
		
		/*if the function has been called from the printing menu*/
		if (opt == BFS_PRINT) {
			printf("%s %d\n", root->name, root->id);
		}

		/*if the function has been called from the superspreader option*/
		if (opt == SUPERSPREADER_PRINT) {
			printf("#StayHome! %s %d\n", root->name, root->id);
		}
	}
	free(queue);
}

/***********************************************************************************
* Function name: superSpreader
* Input: struct node* root
* Output: void
* Function Operation: the function will get a root. It scans for an ID
*					of suspect fron the user, and than, if that id is realy exist,
*					it calls the BFS print function with the argument of 
					SUPERSPREADER_ PRINT,	that is the option to print all 
					of the suspects by bfs order with "#Stayhome".			
***********************************************************************************/
void superSpreader(struct node* root)
{
	//initiation of int ID variable that soon to hold the ID value
	int ID;
	printf("Enter the ID of the suspected Superspreader\n");
	scanf("%d", &ID);

	//the id_ptr will hold the ID holder address (if theres a one)
	struct node* id_ptr = search(root, ID);

	/*if theres no one who holds that ID*/
	if (id_ptr == NULL)	{
		printf("ID %d does not exist\n", ID);
		return;
	}
	// the parent variable holds the ID holder's parent address
	struct node* parent = isParent(root, ID);

	/*if he have a parent, ill send him first to BIDUD*/
	if (parent != NULL)	{
		printf("#StayHome! %s %d\n", parent->name, parent->id);
	}		
	printBFS(id_ptr,SUPERSPREADER_PRINT);
	return;
}

/***********************************************************************************
* Function name: vaccinateTrinAri
* Input: struct node* root
* Output: int: 1 if the root have been vaccined, and 0 if not
* Function Operation: the function will vaccinate the desired ID holder,
*						that means it will let free the ID holder and also
*						all of his subtrees, Recursively by calling the 
*						destroyTree function.						
***********************************************************************************/
int vaccinateTrinAri(struct node* root)
{
	/*
	initiation of the chils position on the tree to 0,
	nd id variable that soon will get the ID input value
	*/
	int childPos = 0, ID;
	printf("Who got vaccinated (ID)?\n");
	scanf("%d", &ID);
	//initiation of "vaccinated" ptr to the ID holder's address
	struct node* vaccinated = search(root, ID);
	//initiation of "parent" ptr to the ID holder's parent address
	struct node* parent = isParent(root, ID);

	/*if the pointer to the ID holder's ID is null, 
	that means that theres no id like that*/
	if (vaccinated == NULL)	{
		printf("There is no ID %d\n", ID);
		return 0;
	}

	/*if the root is null, also thers no ID like that*/
	if (root == NULL) {
		printf("There is no ID %d\n", ID);
		return 0;
	}

	/*
	if the parent address isn't null,and ill destroy the trinAri.
	ill place the value of the 	"leafPos" on the childPos variable, that 
	determines on which leaf the specific family member is 
	located.
	*/
	if (parent != NULL)	{
		childPos = leafPos(parent, ID);
		destroyTrinAriTree(vaccinated);

		/*if the child is located on the left leaf, ill define it as NULL*/
		if (childPos == LEFT) {
			parent->left = NULL;
		}

		/*if the child is located on the middle leaf, ill define it as NULL*/
		else if (childPos == MID)	{
			parent->middle = NULL;
		}

		/*if the child is located on the right leaf, ill define it as NULL*/
		else if (childPos == RIGHT)	{
			parent->right = NULL;
		}
		return 0;
	}

	/*if the ID holder is the root, ill destroy the trinAri
	and define his leafs by null.
	*/
	else if (parent == NULL) {
		destroyTrinAriTree(vaccinated);
		root->left = NULL;
		root->middle = NULL;
		root->right = NULL;
		return 1;
	}
	return 0;
}

/***********************************************************************************
* Function name: destroyTrinAriTree
* Input: struct node* root
* Output: void
* Function Operation: the function will let free the given pointer
*					and also all of his subTrees, by recursive iteration.
***********************************************************************************/
void destroyTrinAriTree(struct node* root) 
{
	/*if the root is NULL - there's no tree to destroy!*/
	if (root == NULL) {
		return;
	}

	/*recursively destroying of all the tree leafs*/
	destroyTrinAriTree(root->left);
	destroyTrinAriTree(root->middle);
	destroyTrinAriTree(root->right);

	/*freeing every leaf when the root isnt null, and place a NULL value to his pointer*/
	if (root != NULL) {
		printf("%s ID: %d Survived!\n", root->name, root->id);
		free(root);
		root = NULL;
		return;
	}
}

/***********************************************************************************
* Function name: leafPos (for leaf position)
* Input: struct node* parent, int ID
* Output: int
* Function Operation: the function get a pointer to a parent,
*					and an ID. It figures out if the ID's holder is the
*					left, middle or right leaf of that given parent.
* 
***********************************************************************************/
int leafPos(struct node* parent, int ID)
{
	/*if the current pointer points to to the left child of the parent*/
	if (parent->left->id == ID)	{
		return LEFT;
	}

	/*if the current pointer points to to the middle child of the parent*/
	else if (parent->middle->id == ID) {
		return MID;
	}

	/*if the current pointer points to to the right child of the parent*/
	else if (parent->right->id == ID) {
		return RIGHT;
	}
	return 0;
}