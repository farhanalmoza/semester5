#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node node;

void addFront(node **head);
void addMiddle(node **head);
void addEnd(node **head);
void deleteFront(node **head);
void deleteMiddle(node **head);
void deleteEnd(node **head);
void sumAll(node *head);
void traverse(node *head);

int main()
{
	char selectMenu;
	node *head;
	
	do{
		system("cls");
		printf("LINKED LIST DEMO - CODE SKELETON : \n\n");
		printf("1. add data << in the beginning of the list >>\n");
		printf("2. add data << in the middle of the list >>\n");
		printf("3. add data << in the end of the list >>\n");
		printf("4. delete data << in the beginning of the list >>\n");
		printf("5. delete data << in the middle of the list >>\n");
		printf("6. delete data << in the end of the list >>\n");
		printf("7. sum all data in the list \n");
		printf("8. show all data <<node traversal>>\n\n");
		printf("ENTER YOUR OPTION (PRESS 'q' FOR QUIT) : ");
		fflush(stdin);
		scanf("%c", &selectMenu);
		if (selectMenu == '1')
			addFront(&head);
		else if (selectMenu == '2')
			addMiddle(&head);
		else if (selectMenu == '3')
			addEnd(&head);
		else if (selectMenu == '4')
			deleteFront(&head);
		else if (selectMenu == '5')
			deleteMiddle(&head);
		else if (selectMenu == '6')
			deleteEnd(&head);
		else if (selectMenu == '7')
			sumAll(head);
		else if (selectMenu == '8'){
			traverse(head);
			// getch();
		}
	}while (selectMenu != 'q');
}

void addFront(node **head){
	int data_number;
	node *pNew;
	node* pTail = malloc(sizeof(node));
	
	system("cls");
	fflush(stdin);
	
	printf("Enter Data : "); fflush(stdin); 
	scanf("%d", &data_number);
	
	pNew = (node *)malloc(sizeof(node));
	if (pNew != NULL){
		pNew->data = data_number;
		pNew->next = *head;
		pTail->next = pNew;
		*head = pNew;
	}
	else{
		printf("NOT ENOUGH MEMORY");
		getch();
	}
}

void addMiddle(node **head){
	int data_number;
	node *pNew;
	node* pTail = malloc(sizeof(node));
	
	system("cls");
	fflush(stdin);
	
	printf("Enter Data : "); fflush(stdin); 
	scanf("%d", &data_number);
	
	pNew = (node *)malloc(sizeof(node));
	if (pNew != NULL){
		pNew->data = data_number;
		pNew->next = *head;
		pTail->next = pNew;
		*head = pNew;
	}
	else{
		printf("NOT ENOUGH MEMORY");
		getch();
	}
}

void addEnd(node **head){
	int data_number;
	node *pNew;
	node* pTail = malloc(sizeof(node));
	
	system("cls");
	fflush(stdin);
	
	printf("Enter Data : "); fflush(stdin); 
	scanf("%d", &data_number);
	
	pNew = (node *)malloc(sizeof(node));
	if (pNew != NULL){
		pNew->data = data_number;
		pNew->next = *head;
		pTail->next = pNew;
		*head = pNew;
	}
	else{
		printf("NOT ENOUGH MEMORY");
		getch();
	}
}

void deleteFront(node **head){
	node *pDel;
	
	system("cls");
	
	if (*head != NULL){
		pDel = *head;
		*head = (*head)->next;
		free(pDel);
	}
	else{
		printf("LIST IS EMPTY");
		getch();
	}
}

void deleteMiddle(node **head){
	node *pDel;
	
	system("cls");
	
	if (*head != NULL){
		pDel = *head;
		*head = (*head)->next;
		free(pDel);
	}
	else{
		printf("LIST IS EMPTY");
		getch();
	}
}

void deleteEnd(node **head){
	node *pDel;
	
	system("cls");
	
	if (*head != NULL){
		pDel = *head;
		*head = (*head)->next;
		free(pDel);
	}
	else{
		printf("LIST IS EMPTY");
		getch();
	}
}

// sum all data in circular linked list
void sumAll(node *head){
	int sum = 0;
	node *p;
	
	system("cls");
	
	if (head != NULL){
		p = head;
		do{
			sum += p->data;
			p = p->next;
		}while (p != head);
		printf("SUM OF ALL DATA IN THE LIST : %d", sum);
		getch();
	}
	else{
		printf("LIST IS EMPTY");
		getch();
	}
}

void traverse(node *head){
	node *pTraverse;
	
	system("cls");
	
	if (head != NULL){
		pTraverse = head;
		while (pTraverse != NULL){
			printf("%d ", pTraverse->data);
			pTraverse = pTraverse->next;
		}
		getch();
	}
	else{
		printf("LIST IS EMPTY");
		getch();
	}
}