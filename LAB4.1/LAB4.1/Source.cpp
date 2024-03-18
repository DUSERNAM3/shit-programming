#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define clear system("cls");

bool flag = false;

struct node {
	struct node* next;
	char value;
};

struct list {
	struct node* current;
	struct node* first;
};

char tElem;

int checkNum(char chck[100]) {
	int i, length;
	length = strlen(chck);
	for (i = 0; i < length; i++) {
		if (!(isdigit(chck[i])))
			return 1;
	}
	return 0;
}

void init(struct list* list) {
	list->current = 0;
	list->first = 0;
	flag = true;
	printf("������ ���������������!\n");
}

void print(struct list list) {
	struct node* currptr;
	if (list.current == 0) {
		printf("������! ���� ����.\n");
		return;
	}
	printf("����������� ������: ");
	for (currptr = list.first; currptr != NULL; currptr = currptr->next) {
		if (currptr == list.current) {
			printf(">%c<", currptr->value);
			continue;
		}
		printf("%c", currptr->value);
	}
	printf("\n");
}

void checkVoid(struct list list) {
	if (list.current == 0) printf("������ ����\n");
	else {
		printf("������ �� ����\n");
		print(list);
	}
}

void delToRight(struct list* list) {
	struct node* delNode;
	if (list->current->next != NULL) { //���� �� �� � �����
		if (list->current->next->next == NULL) { // ���� �� � ������������� ������
			free(list->current->next->next);
			list->current->next = NULL;
		}
		else {
			delNode = list->current->next->next;
			free(list->current->next);
			list->current->next = delNode;
		}
	}
	else {
		if (list->first->next == NULL) { //���� ���� � ����� ���������
			free(list->current);
			list->current = 0;
			list->first = 0;
			printf("���� ���� ������.\n");
			return;
		}
		//���� �� � �����
		else printf("�� � ����� �����, �������� ����������.\n");
	}
}

void clearList(struct list* list) {
	if (list->current == 0) {//���� ���� ����
		printf("������! ���� ��� ����.\n");
		return;
	}
	else {
		while (list->first != NULL && list->current != 0) {
			list->current = list->first;
			delToRight(list);
		}
		free(list->current);
	}
	list->current = list->first = 0;
	printf("������� ������ ������� \n");
}

void setFirst(struct list* list) {
	if (list->current == 0) {
		printf("������! ���� ����.\n");
		return;
	}
	else list->current = list->first;
	print(*list);
}

void checkLast(struct list list) {
	if (list.current == 0) {
		printf("������! ���� ����.\n");
	}
	else {
		if (list.current->next == NULL) printf("�� == ����� ������.\n");
		else printf("�� != ����� ������.\n");
		print(list);
	}
}

void setToRight(struct list* list) {
	if (list->current == 0) {
		printf("������! ���� ����.\n");
		return;
	}
	else {
		if (list->current->next == NULL) printf("����������� �� ������ ����������. �������: �� � ����� �����\n");
		else list->current = list->current->next;
	}
	print(*list);
}

void printToRight(struct list list) {
	if (list.current == 0) {//���� ���� ����
		printf("������! ���� ����.\n");
		return;
	}
	else {
		if (list.current->next == NULL) printf("�� � ����� �����. ������� ��: %c\n", list.current->value);
		else printf("������� �� ��: %c\n", list.current->next->value);
	}
	print(list);
}

void takeRight(struct list* list) {
	struct node* delNode;
	if (list->current == 0) {//���� ���� ����
		printf("������! ���� ����.\n");
		return;
	}
	else {
		if (list->current->next != NULL) { //���� �� �� � �����
			tElem = list->current->next->value;
			if (list->current->next->next == NULL) { // ���� �� � ������������� ������
				free(list->current->next->next);
				list->current->next = NULL;
			}
			else {
				delNode = list->current->next->next;
				free(list->current->next);
				list->current->next = delNode;
			}
			printf("������ �������: %c\n", tElem);
		}
		else {
			if (list->first->next == NULL) { //���� ���� � ����� ���������
				tElem = list->current->value;
				free(list->current);
				list->current = 0;
				list->first = 0;
				printf("���� ���� ������.\n");
				return;
			}
			//���� �� � �����
			else printf("�� � ����� �����, ����� ������� ����������.\n");
		}
	}

}

void changeRight(struct list* list, char elem) {
	if (list->current->next == NULL) printf("�� � ����� �����. �������� �� ����������: %c\n", list->current->value = elem);
	else printf("�������� �������� �� �� ���������� �� %c\n", list->current->next->value = elem);
	print(*list);
}

void addToRight(struct list* list, char elem) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = elem;
	if (list->current == 0) { //���� ���� ����
		newNode->next = 0;
		list->first = list->current = newNode;
	}
	else {
		if (list->current->next != NULL) { //���� �� �� � �����
			newNode->next = list->current->next;
			list->current->next = newNode;
		}
		else { //���� �� � �����
			newNode->next = NULL;
			list->current->next = newNode;
		}
	}
	print(*list);
}

void deleteList(struct list* list) {
	while (list->first != NULL && list->current != 0) {
		list->current = list->first;
		delToRight(list);
	}
	free(list->current);
	flag = false;
	printf("������ �� ������� ���������.\n");
}

void menu() {
	printf("����:\n");
	printf("1) ������ ������ �� �������\n"); // DONE
	printf("2) ���������� ������\n"); 
	printf("3) ��������� �� NULL\n");
	printf("4) ���������� �� � ������ ������\n");
	printf("5) ��������� �� �� ����� ������\n"); // DONE
	printf("6) �������� �� ������ �� �������\n"); // DONE
	printf("7) �������� �������� �������� �� ��\n"); // DONE
	printf("8) ������� ������� �� ��\n"); // DONE
	printf("9) ����� ������� �� ��\n"); // DONE
	printf("10) �������� �������� �������� �� ��\n"); // DONE
	printf("11) �������� ������� �� ��\n"); // DONE
	printf("12) ����������� ������\n"); // DONE
	printf("13) ��������� ������ �� �������\n"); // DONE
	printf("14) ��������� ������ ���������\n"); // DONE
	printf("������� �������: ");
}

int main() {
	setlocale(LC_ALL, "ru");
	char choice[100];
	char c;
	int ch;
	struct list list;
	while (1) {
		menu();
		gets_s(choice);
		clear;
		if (checkNum(choice)) {
			printf("����� ���� �������, ���������� \n");
			continue;
		}
		ch = atoi(choice);
		switch (ch) {
		case 1:
			if (!flag) init(&list);
			else printf("��������� ������� ����������. ���� ��� ���������������.\n");
			break;
		case 2:
			if (flag) clearList(&list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 3:
			if (flag) checkVoid(list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 4:
			if (flag) setFirst(&list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 5:
			if (flag) checkLast(list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 6:
			if (flag) setToRight(&list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 7:
			if (flag) printToRight(list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 8:
			if (list.current == 0) {//���� ���� ����
				printf("������! ���� ����.\n");
				continue;
			}
			else{
				if (flag) delToRight(&list);
				else printf("��������� ������� ����������. ���� �� ���������������.\n");
				print(list);
				break;
			}
		case 9:
			if (flag) takeRight(&list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 10:
			if (flag) {
				if (list.current == 0) {
					printf("������! ���� ����.\n");
					continue;
				}
				else {
					while (1) {
						printf("������� ������: ");
						gets_s(choice);
						clear;
						if (strlen(choice) == 1) break;
						else printf("���� ��������� �����. ���������� ������� ������ ���� ������!!!\n");
					}
					c = choice[0];
					changeRight(&list, c);
				}
			}
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 11:
			if (flag) {
				while (1) {
					printf("������� ������: ");
					gets_s(choice);
					clear;
					if (strlen(choice) == 1) break;
					else printf("���� ��������� �����. ���������� ������� ������ ���� ������!!!\n");
				}
				c = choice[0];
				addToRight(&list, c);
			}
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 12:
			if (flag) print(list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 13:
			if (flag) deleteList(&list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 14:
			printf("������ �������: %c\n", tElem);
			printf("���������� ���������");
			return 0;
		default:
			printf("����� ������� �� ����������. ����������, ������� ������� �����.\n");
		}
	}
}