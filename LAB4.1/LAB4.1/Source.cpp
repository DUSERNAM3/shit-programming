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
	printf("яохянй хмхжхюкхгхпнбюм!\n");
}

void print(struct list list) {
	struct node* currptr;
	if (list.current == 0) {
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	printf("ндмнябъгмши яохянй: ");
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
	if (list.current == 0) printf("яохянй осяр\n");
	else {
		printf("яохянй ме осяр\n");
		print(list);
	}
}

void delToRight(struct list* list) {
	struct node* delNode;
	if (list->current->next != NULL) { //ЕЯКХ пс МЕ Б ЙНМЖЕ
		if (list->current->next->next == NULL) { // ЕЯКХ пс Б ОПЕДОНЯКЕДМЕИ ЪВЕИЙЕ
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
		if (list->first->next == NULL) { //ЕЯКХ КХЯР Я НДМХЛ ЩКЕЛЕМРНЛ
			free(list->current);
			list->current = 0;
			list->first = 0;
			printf("кхяр ярюк осяршл.\n");
			return;
		}
		//ЕЯКХ пс Б ЙНМЖЕ
		else printf("пс б йнмже кхярю, сдюкемхе мебнглнфмн.\n");
	}
}

void clearList(struct list* list) {
	if (list->current == 0) {//ЕЯКХ КХЯР ОСЯР
		printf("ньхайю! кхяр сфе осяр.\n");
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
	printf("нвхярйю опнькю сяоеьмн \n");
}

void setFirst(struct list* list) {
	if (list->current == 0) {
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	else list->current = list->first;
	print(*list);
}

void checkLast(struct list list) {
	if (list.current == 0) {
		printf("ньхайю! кхяр осяр.\n");
	}
	else {
		if (list.current->next == NULL) printf("пс == йнмеж яохяйю.\n");
		else printf("пс != йнмеж яохяйю.\n");
		print(list);
	}
}

void setToRight(struct list* list) {
	if (list->current == 0) {
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	else {
		if (list->current->next == NULL) printf("оепедбхмсрэ пс бопюбн мебнглнфмн. опхвхмю: пс б йнмже кхярю\n");
		else list->current = list->current->next;
	}
	print(*list);
}

void printToRight(struct list list) {
	if (list.current == 0) {//ЕЯКХ КХЯР ОСЯР
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	else {
		if (list.current->next == NULL) printf("пс б йнмже кхярю. щкелемр пс: %c\n", list.current->value);
		else printf("щкелемр гю пс: %c\n", list.current->next->value);
	}
	print(list);
}

void takeRight(struct list* list) {
	struct node* delNode;
	if (list->current == 0) {//ЕЯКХ КХЯР ОСЯР
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	else {
		if (list->current->next != NULL) { //ЕЯКХ пс МЕ Б ЙНМЖЕ
			tElem = list->current->next->value;
			if (list->current->next->next == NULL) { // ЕЯКХ пс Б ОПЕДОНЯКЕДМЕИ ЪВЕИЙЕ
				free(list->current->next->next);
				list->current->next = NULL;
			}
			else {
				delNode = list->current->next->next;
				free(list->current->next);
				list->current->next = delNode;
			}
			printf("бгърши щкелемр: %c\n", tElem);
		}
		else {
			if (list->first->next == NULL) { //ЕЯКХ КХЯР Я НДМХЛ ЩКЕЛЕМРНЛ
				tElem = list->current->value;
				free(list->current);
				list->current = 0;
				list->first = 0;
				printf("кхяр ярюк осяршл.\n");
				return;
			}
			//ЕЯКХ пс Б ЙНМЖЕ
			else printf("пс б йнмже кхярю, бгърэ щкелемр мебнглнфмн.\n");
		}
	}

}

void changeRight(struct list* list, char elem) {
	if (list->current->next == NULL) printf("пс б йнмже кхярю. гмювемхе пс хглемхкняэ: %c\n", list->current->value = elem);
	else printf("гмювемхе щкелемрю гю пс хглемхкняэ мю %c\n", list->current->next->value = elem);
	print(*list);
}

void addToRight(struct list* list, char elem) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = elem;
	if (list->current == 0) { //ЕЯКХ КХЯР ОСЯР
		newNode->next = 0;
		list->first = list->current = newNode;
	}
	else {
		if (list->current->next != NULL) { //ЕЯКХ пс МЕ Б ЙНМЖЕ
			newNode->next = list->current->next;
			list->current->next = newNode;
		}
		else { //ЕЯКХ пс Б ЙНМЖЕ
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
	printf("пюанрю ян яохяйнл гюйнмвемю.\n");
}

void menu() {
	printf("лемч:\n");
	printf("1) мювюрэ пюанрс ян яохяйнл\n"); // DONE
	printf("2) носярньхрэ яохянй\n"); 
	printf("3) опнбепхрэ мю NULL\n");
	printf("4) сярюмнбхрэ пс б мювюкн яохяйю\n");
	printf("5) опнбепхрэ пс мю йнмеж яохяйю\n"); // DONE
	printf("6) ядбхмсрэ пс бопюбн мю щкелемр\n"); // DONE
	printf("7) онйюгюрэ гмювемхе щкелемрю гю пс\n"); // DONE
	printf("8) сдюкхрэ щкелемр гю пс\n"); // DONE
	printf("9) бгърэ щкелемр гю пс\n"); // DONE
	printf("10) хглемхрэ гмювемхе щкелемрю гю пс\n"); // DONE
	printf("11) днаюбхрэ щкелемр гю пс\n"); // DONE
	printf("12) пюяоевюрюрэ яохянй\n"); // DONE
	printf("13) гюйнмвхрэ пюанрс ян яохяйнл\n"); // DONE
	printf("14) гюбепьхрэ пюанрс опнцпюллш\n"); // DONE
	printf("ббедхре йнлюмдс: ");
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
			printf("ббедх мнпл йнлюмдс, онфюксиярю \n");
			continue;
		}
		ch = atoi(choice);
		switch (ch) {
		case 1:
			if (!flag) init(&list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр сфе хмхжхюкхгхпнбюм.\n");
			break;
		case 2:
			if (flag) clearList(&list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 3:
			if (flag) checkVoid(list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 4:
			if (flag) setFirst(&list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 5:
			if (flag) checkLast(list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 6:
			if (flag) setToRight(&list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 7:
			if (flag) printToRight(list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 8:
			if (list.current == 0) {//ЕЯКХ КХЯР ОСЯР
				printf("ньхайю! кхяр осяр.\n");
				continue;
			}
			else{
				if (flag) delToRight(&list);
				else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
				print(list);
				break;
			}
		case 9:
			if (flag) takeRight(&list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 10:
			if (flag) {
				if (list.current == 0) {
					printf("ньхайю! кхяр осяр.\n");
					continue;
				}
				else {
					while (1) {
						printf("ббедхре яхлбнк: ");
						gets_s(choice);
						clear;
						if (strlen(choice) == 1) break;
						else printf("ббнд опебшьюер дкхмс. онфюксиярю ббедхре рнкэйн ндхм яхлбнк!!!\n");
					}
					c = choice[0];
					changeRight(&list, c);
				}
			}
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 11:
			if (flag) {
				while (1) {
					printf("ббедхре яхлбнк: ");
					gets_s(choice);
					clear;
					if (strlen(choice) == 1) break;
					else printf("ббнд опебшьюер дкхмс. онфюксиярю ббедхре рнкэйн ндхм яхлбнк!!!\n");
				}
				c = choice[0];
				addToRight(&list, c);
			}
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 12:
			if (flag) print(list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 13:
			if (flag) deleteList(&list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 14:
			printf("бгърши щкелемр: %c\n", tElem);
			printf("гюбепьемхе опнцпюллш");
			return 0;
		default:
			printf("рюйни йнлюмдш ме ясыеярбсер. онфюксиярю, ббедхре йнлюмдс ямнбю.\n");
		}
	}
}