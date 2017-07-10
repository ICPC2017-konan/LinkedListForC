#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
	int value;		// int ˆÈŠO‚ğg‚¢‚½‚¢ê‡‚ÍŒ^‚ğ•ÏX‚·‚é‚±‚Æ
	struct CELL *next = NULL;
} Cell;

typedef struct LINKED_LIST {
	int size;
	Cell *head = NULL;
} LinkedList;

LinkedList *createLinkedList();
int sizeOfLinkedList(LinkedList *list);
int getFromLinkedList(LinkedList *list, int index);
void addToLinkedList(LinkedList *list, int value);
void removeFromLinkedList(LinkedList *list, int index);
int containedByLinkedList(LinkedList *list, int value);

int main() {
	// LinkedList‚Ìì¬
	LinkedList *list = createLinkedList();

	// ‘f”‚ğ¬‚³‚¢‡‚Élist‚É7‚Â‰Á‚¦‚é
	addToLinkedList(list, 2);
	addToLinkedList(list, 3);
	addToLinkedList(list, 5);
	addToLinkedList(list, 7);
	addToLinkedList(list, 11);
	addToLinkedList(list, 13);
	addToLinkedList(list, 17);

	// list‚Ì‘S—v‘f‚ğ•\¦‚·‚é
	int size = sizeOfLinkedList(list);	// list‚ÉŠÜ‚Ü‚ê‚Ä‚¢‚é—v‘f”
	for (int i = 0; i < size; i++) {
		int data = getFromLinkedList(list, i);
		printf("%d”Ô–Ú‚Ì—v‘f‚Í%d\n", i, data);
	}

	// list‚Ìæ“ª—v‘f‚ğ7‰ñíœ‚·‚é
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);

	// list‚ÌƒTƒCƒY‚ğ•\¦‚·‚é(0ŒÂ‚É‚È‚Á‚Ä‚¢‚é‚Í‚¸)
	size = sizeOfLinkedList(list);
	printf("íœŒã‚Ì—v‘f”‚Í%d\n", size);

	// ÅŒã‚Íƒƒ‚ƒŠ‰ğ•ú‚µ‚Ä‚¨‚­‚±‚Æ
	free(list);

	getchar();
}

LinkedList *createLinkedList() {
	LinkedList * newList = (LinkedList *)malloc(sizeof(LinkedList));
	newList->size = 0;
	newList->head = NULL;
	return newList;
}

int sizeOfLinkedList(LinkedList *list) {
	return list->size;
}

int getFromLinkedList(LinkedList *list, int index) {
	Cell *p;
	for (p = list->head; p != NULL; p = p->next) {
		if (index == 0) {
			return p->value;
		}
		index--;
	}
	return -1;
}

void addToLinkedList(LinkedList *list, int value) {
	Cell *p;
	if (list->head == NULL) {
		// Å‰‚É—v‘f‚ğ’Ç‰Á‚·‚éê‡
		list->head = (Cell *)malloc(sizeof(Cell));
		list->head->value = value;
		list->head->next = NULL;
		list->size++;
		return;
	}
	for (p = list->head; p->next != NULL; p = p->next);
	p->next = (Cell *)malloc(sizeof(Cell));
	p->next->value = value;
	p->next->next = NULL;
	list->size++;
}

void removeFromLinkedList(LinkedList *list, int index) {
	Cell *tmp;
	if (index == 0) {
		// æ“ª‚Ì—v‘f‚ğíœ‚·‚éê‡
		tmp = list->head;
		list->head = list->head->next;
		free(tmp);
		list->size--;
		return;
	}
	Cell *p;
	for (p = list->head; p != NULL; p = p->next) {
		if (index == 1) {
			tmp = p->next;
			p->next = p->next->next;
			free(tmp);
			list->size--;
			return;
		}
		index--;
	}
}

int containedByLinkedList(LinkedList *list, int value) {
	Cell *p;
	for (p = list->head; p != NULL; p = p->next) {
		if (p->value == value) {
			return 1;
		}
	}
	return 0;
}