#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define clear system("cls");

bool flag = false;

struct node {
	struct node* prev;
	struct node* next;
	char value;
};

struct list {
	struct node* current;
	struct node* first;
	struct node* last;
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
	list->last = 0;
	flag = true;
	printf("������ ���������������!\n");
}

void checkVoid(struct list list) {
	if (list.current == 0) printf("������ ����\n");
	else printf("������ �� ����\n");
}

void print(struct list list) {
	struct node* currptr;
	if (list.current == 0) {
		printf("������! ���� ����.\n");
		return;
	}
	//������ �����������
	printf("������ �����������: ");
	for (currptr = list.first; currptr != NULL; currptr = currptr->next) {
		if (currptr == list.current) {
			printf(">%c<", currptr->value);
			continue;
		}
		printf("%c", currptr->value);
	}
	printf("\n");
	//������
	printf("�������� �����������: ");
	for (currptr = list.last; currptr != NULL; currptr = currptr->prev) {
		if (currptr == list.current) {
			printf(">%c<", currptr->value);
			continue;
		}
		printf("%c", currptr->value);
	}
	printf("\n");
}

void setFirst(struct list* list) {
	if (list->current == 0) {
		printf("������! ���� ����.\n");
		return;
	}
	else list->current = list->first;
	print(*list);
}

void setLast(struct list* list) {
	if (list->current == 0) {
		printf("������! ���� ����.\n");
		return;
	}
	else list->current = list->last;
	print(*list);
}

void setToLeft(struct list* list) {
	if (list->current == 0) {
		printf("������! ���� ����.\n");
		return;
	}
	else {
		if (list->current == list->first) printf("����������� �� ����� ����������. �������: �� � ������ �����\n");
		else list->current = list->current->prev;
	}
	print(*list);
}

void setToRight(struct list* list) {
	if (list->current == 0) {
		printf("������! ���� ����.\n");
		return;
	}
	else {
		if (list->current == list->last) printf("����������� �� ������ ����������. �������: �� � ����� �����\n");
		else list->current = list->current->next;
	}
	print(*list);
}

void checkFirst(struct list list) {
	if (list.current == 0) {
		printf("������! ���� ����.\n");
	}
	else {
		if (list.current == list.first) printf("�� == ������ ������.\n");
		else printf("�� != ������ ������.\n");
		print(list);
	}
}

void checkLast(struct list list) {
	if (list.current == 0) {
		printf("������! ���� ����.\n");
	}
	else {
		if (list.current == list.last) printf("�� == ����� ������.\n");
		else printf("�� != ����� ������.\n");
		print(list);
	}
}

void printToRight(struct list list) {
	if (list.current == 0) {//���� ���� ����
		printf("������! ���� ����.\n");
		return;
	}
	else {
		if (list.current == list.last) printf("�� � ����� �����. ������� ��: %c\n", list.current->value);
		else printf("������� �� ��: %c\n", list.current->next->value);
	}
	print(list);
}

void printToLeft(struct list list) {
	if (list.current == 0) {//���� ���� ����
		printf("������! ���� ����.\n");
		return;
	}
	else {
		if (list.current == list.first) printf("�� � ������ �����. ������� ��: %c\n", list.current->value);
		else printf("������� �� ��: %c\n", list.current->prev->value);
	}
	print(list);
}

void takeLeft(struct list* list) {
	if (list->current == 0) {//���� ���� ����
		printf("������! ���� ����.\n");
		return;
	}
	else {
		if (list->current != list->first) { //���� �� �� � ������
			tElem = list->current->prev->value;
			if (list->current->prev == list->first) { // ���� �� �� ������ ������
				list->first = list->current;
				free(list->current->prev);
				list->current->prev = NULL;
			}
			else {
				list->current->prev = list->current->prev->prev;
				free(list->current->prev->next);
				list->current->prev->next = list->current;
			}
			printf("������ �������: %c\n", tElem);
		}
		else {
			tElem = list->current->value;
			if (list->first == list->last) { //���� ���� � ����� ���������
				free(list->current);
				list->current = 0;
				list->first = 0;
				list->last = 0;
				printf("���� ���� ������. ������ �������: %c\n", tElem);
				return;
			}
			//���� �� � ������
			else printf("�� � ������ �����, ����� ������� ����������.\n");
		}
	}
	print(*list);
}

void takeRight(struct list* list) {
	if (list->current == 0) {//���� ���� ����
		printf("������! ���� ����.\n");
		return;
	}
	else {
		if (list->current != list->last) { //���� �� �� � �����
			tElem = list->current->next->value;
			if (list->current->next == list->last) { // ���� �� � ������������� ������
				list->last = list->current;
				free(list->current->next);
				list->current->next = NULL;
			}
			else {
				list->current->next = list->current->next->next;
				free(list->current->next->prev);
				list->current->next->prev = list->current;
			}
			printf("������ �������: %c\n", tElem);
		}
		else {
			tElem = list->current->value;
			if (list->first == list->last) { //���� ���� � ����� ���������
				free(list->current);
				list->current = 0;
				list->first = 0;
				list->last = 0;
				printf("���� ���� ������. ������ ������� %c\n", tElem);
				return;
			}
			//���� �� � �����
			else printf("�� � ����� �����, ����� ������� ����������. \n");
		}
	}
	print(*list);
}

void changeLeft(struct list* list, char elem) {
	if (list->current == list->first) printf("�� � ������ �����. �������� �� ����������: %c\n", list->current->value = elem);
	else list->current->prev->value = elem;
	print(*list);
}

void changeRight(struct list* list, char elem) {
	if (list->current == list->last) printf("�� � ����� �����. �������� �� ����������: %c\n", list->current->value = elem);
	else list->current->next->value = elem;
	print(*list);
}

void delToLeft(struct list* list) {
	if (list->current == 0) {//���� ���� ����
		printf("������! ���� ����.\n");
		return;
	}
	else {
		if (list->current != list->first) { //���� �� �� � �����
			if (list->current->prev == list->first) { // ���� �� � ������������� ������
				list->first = list->current;
				free(list->current->prev);
				list->current->prev = NULL;
			}
			else {
				list->current->prev = list->current->prev->prev;
				free(list->current->prev->next);
				list->current->prev->next = list->current;
			}
		}
		else {
			if (list->first == list->last) { //���� ���� � ����� ���������
				free(list->current);
				list->current = 0;
				list->first = 0;
				list->last = 0;
				printf("���� ���� ������.\n");
				return;
			}
			//���� �� � ������
			else printf("�� � ������ �����, �������� ����������. \n\n");
		}
	}
	print(*list);
}

void delToRight(struct list* list) {
	if (list->current == 0) {//���� ���� ����
		printf("������! ���� ����.\n");
		return;
	}
	else {
		if (list->current != list->last) { //���� �� �� � �����
			if (list->current->next == list->last) { // ���� �� � ������������� ������
				list->last = list->current;
				free(list->current->next);
				list->current->next = NULL;
			}
			else {
				list->current->next = list->current->next->next;
				free(list->current->next->prev);
				list->current->next->prev = list->current;
			}
		}
		else {
			if (list->first == list->last) { //���� ���� � ����� ���������
				free(list->current);
				list->current = 0;
				list->first = 0;
				list->last = 0;
				printf("���� ���� ������.\n");
				return;
			}
			//���� �� � �����
			else printf("�� � ����� �����, �������� ����������. \n\n");
		}
	}
	print(*list);
}

//4 ������: 1) ����� ���� ���� 2) ����� �� �� ������� 3.1) ����� �� � ������ 3.2) ����� �� � �����
void addToLeft(struct list* list, char elem) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = elem;
	if (list->current == 0) { //���� ���� ����
		newNode->next = 0;
		newNode->prev = 0;
		list->first = list->last = list->current = newNode;
	}
	else {
		if (list->current != list->first) { //���� �� �� � ������
			newNode->prev = list->current->prev;
			newNode->next = list->current;
			list->current->prev->next = newNode;
			list->current->prev = newNode;
		}
		else { //���� �� � ������
			newNode->next = list->current;
			newNode->prev = NULL;
			list->current->prev = newNode;
			list->first = newNode;
		}
	}
	print(*list);
}

void addToRight(struct list* list, char elem) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = elem;
	if (list->current == 0) { //���� ���� ����
		newNode->next = 0;
		newNode->prev = 0;
		list->first = list->last = list->current = newNode;
	}
	else {
		if (list->current != list->last) { //���� �� �� � �����
			newNode->prev = list->current;
			newNode->next = list->current->next;
			list->current->next->prev = newNode;
			list->current->next = newNode;
		}
		else { //���� �� � �����
			newNode->prev = list->current;
			newNode->next = NULL;
			list->current->next = newNode;
			list->last = newNode;
		}
	}
	print(*list);
}

void clearList(struct list* list) {
	if (list->current == 0) {//���� ���� ����
		printf("������! ���� ��� ����.\n");
		return;
	}
	else {
		if (list->current == list->first && list->current == list->last) {
			free(list->current);
			list->current = list->first = list->last = 0;
		}
		else {
			for (list->current = list->last->prev; list->current != list->first; list->current = list->current->prev) free(list->current->next);
			free(list->current);
			list->current = list->first = list->last = 0;
		}
	}
	printf("������� ������ ������� \n");
}

void deleteList(struct list* list) {
	if (list->current == 0 || (list->current == list->first && list->current == list->last)) {
		free(list->current);
		flag = false;
		printf("������ �� ������� ���������.\n");
		return;
	}
	for (list->current = list->first->next; list->current != list->last; list->current = list->current->next) free(list->current->prev);
	free(list->current);
	flag = false;
	printf("������ �� ������� ���������.\n");
}

void menu() {
	printf("����:\n");
	printf("1) ������ ������\n"); // DONE
	printf("2) ������� ������ ������\n"); // DONE
	printf("3) �������� �� �������\n"); // DONE
	printf("4) ��������� �� � ������ ������\n"); // DONE
	printf("5) ��������� �� � ����� ������\n"); // DONE
	printf("6) ��������: �� == ������ ������ \n"); // DONE
	printf("7) ��������: �� == ����� ������\n"); // DONE
	printf("8) ����������� �� ������\n"); // DONE
	printf("9) ����������� �� �����\n"); // DONE
	printf("10) �������� �������� �������� �� ��\n"); // DONE
	printf("11) �������� �������� �������� �� ��\n"); // DONE
	printf("12) ������� �������� �� ��\n"); // DONE
	printf("13) ������� �������� �� ��\n"); // DONE
	printf("14) ����� ������� �� ��\n");
	printf("15) ����� ������� �� ��\n");
	printf("16) �������� �������� �������� �� ��\n");
	printf("17) �������� �������� �������� �� ��\n");
	printf("18) �������� ������� �� ��\n"); // DONE. ������ �������� �� ����� �����
	printf("19) �������� ������� �� ��\n"); // DONE
	printf("20) ����������� ������\n"); // DONE
	printf("21) ��������� ������ �� �������\n"); // �������� ������
	printf("22) ��������� ������ � ����������\n"); // DONE
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
		if (checkNum(choice)) {
			clear;
			printf("����� ���� �������, ����������\n");
			continue;
		}
		ch = atoi(choice);
		clear;
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
			if (flag) setLast(&list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 6:
			if (flag) checkFirst(list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 7:
			if (flag) checkLast(list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 8:
			if (flag) setToRight(&list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 9:
			if (flag) setToLeft(&list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 10:
			if (flag) printToLeft(list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 11:
			if (flag) printToRight(list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 12:
			if (flag) delToLeft(&list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 13:
			if (flag) delToRight(&list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 14:
			if (flag) takeLeft(&list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 15:
			if (flag) takeRight(&list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 16:
			if (flag) {
				if (list.current == 0) {//���� ���� ����
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
					changeLeft(&list, c);
				}
			}
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 17:
			if (flag) {
				if (list.current == 0) {//���� ���� ����
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
		case 18:
			if (flag) {
				while (1) {
					printf("������� ������: ");
					gets_s(choice);
					clear;
					if (strlen(choice) == 1) break;
					else printf("���� ��������� �����. ���������� ������� ������ ���� ������!!!\n");
				}
				c = choice[0];
				addToLeft(&list, c);
			}
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 19:
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
		case 20:
			if (flag) print(list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 21:
			if (flag) deleteList(&list);
			else printf("��������� ������� ����������. ���� �� ���������������.\n");
			break;
		case 22:
			printf("������ �������: %c\n", tElem);
			printf("���������� ���������");
			return 0;
		default:
			printf("����� ������� �� ����������. ����������, ������� ������� �����.\n");
		}
	}
}