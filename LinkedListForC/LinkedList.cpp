#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
	int value;		// int 以外を使いたい場合は型を変更すること
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
	// LinkedListの作成
	LinkedList *list = createLinkedList();

	// 素数を小さい順にlistに7つ加える
	addToLinkedList(list, 2);
	addToLinkedList(list, 3);
	addToLinkedList(list, 5);
	addToLinkedList(list, 7);
	addToLinkedList(list, 11);
	addToLinkedList(list, 13);
	addToLinkedList(list, 17);

	// listの全要素を表示する
	int size = sizeOfLinkedList(list);	// listに含まれている要素数
	for (int i = 0; i < size; i++) {
		int data = getFromLinkedList(list, i);
		printf("%d番目の要素は%d\n", i, data);
	}

	// listの先頭要素を7回削除する
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);

	// listのサイズを表示する(0個になっているはず)
	size = sizeOfLinkedList(list);
	printf("削除後の要素数は%d\n", size);

	// 最後はメモリ解放しておくこと
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
		// 最初に要素を追加する場合
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
		// 先頭の要素を削除する場合
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