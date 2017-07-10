#include <stdio.h>
#include <stdlib.h>

typedef struct CELL {
	int value;		// int �ȊO���g�������ꍇ�͌^��ύX���邱��
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
	// LinkedList�̍쐬
	LinkedList *list = createLinkedList();

	// �f��������������list��7������
	addToLinkedList(list, 2);
	addToLinkedList(list, 3);
	addToLinkedList(list, 5);
	addToLinkedList(list, 7);
	addToLinkedList(list, 11);
	addToLinkedList(list, 13);
	addToLinkedList(list, 17);

	// list�̑S�v�f��\������
	int size = sizeOfLinkedList(list);	// list�Ɋ܂܂�Ă���v�f��
	for (int i = 0; i < size; i++) {
		int data = getFromLinkedList(list, i);
		printf("%d�Ԗڂ̗v�f��%d\n", i, data);
	}

	// list�̐擪�v�f��7��폜����
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);
	removeFromLinkedList(list, 0);

	// list�̃T�C�Y��\������(0�ɂȂ��Ă���͂�)
	size = sizeOfLinkedList(list);
	printf("�폜��̗v�f����%d\n", size);

	// �Ō�̓�����������Ă�������
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
		// �ŏ��ɗv�f��ǉ�����ꍇ
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
		// �擪�̗v�f���폜����ꍇ
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