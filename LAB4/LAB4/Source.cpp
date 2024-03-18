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
	printf("яохянй хмхжхюкхгхпнбюм!\n");
}

void checkVoid(struct list list) {
	if (list.current == 0) printf("яохянй осяр\n");
	else printf("яохянй ме осяр\n");
}

void print(struct list list) {
	struct node* currptr;
	if (list.current == 0) {
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	//ОПЪЛНЕ МЮОПЮБКЕМХЕ
	printf("опълне мюопюбкемхе: ");
	for (currptr = list.first; currptr != NULL; currptr = currptr->next) {
		if (currptr == list.current) {
			printf(">%c<", currptr->value);
			continue;
		}
		printf("%c", currptr->value);
	}
	printf("\n");
	//ПЕБЕПЯ
	printf("напюрмне мюопюбкемхе: ");
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
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	else list->current = list->first;
	print(*list);
}

void setLast(struct list* list) {
	if (list->current == 0) {
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	else list->current = list->last;
	print(*list);
}

void setToLeft(struct list* list) {
	if (list->current == 0) {
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	else {
		if (list->current == list->first) printf("оепедбхмсрэ пс бкебн мебнглнфмн. опхвхмю: пс б мювюке кхярю\n");
		else list->current = list->current->prev;
	}
	print(*list);
}

void setToRight(struct list* list) {
	if (list->current == 0) {
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	else {
		if (list->current == list->last) printf("оепедбхмсрэ пс бопюбн мебнглнфмн. опхвхмю: пс б йнмже кхярю\n");
		else list->current = list->current->next;
	}
	print(*list);
}

void checkFirst(struct list list) {
	if (list.current == 0) {
		printf("ньхайю! кхяр осяр.\n");
	}
	else {
		if (list.current == list.first) printf("пс == мювюкн яохяйю.\n");
		else printf("пс != мювюкн яохяйю.\n");
		print(list);
	}
}

void checkLast(struct list list) {
	if (list.current == 0) {
		printf("ньхайю! кхяр осяр.\n");
	}
	else {
		if (list.current == list.last) printf("пс == йнмеж яохяйю.\n");
		else printf("пс != йнмеж яохяйю.\n");
		print(list);
	}
}

void printToRight(struct list list) {
	if (list.current == 0) {//ЕЯКХ КХЯР ОСЯР
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	else {
		if (list.current == list.last) printf("пс б йнмже кхярю. щкелемр пс: %c\n", list.current->value);
		else printf("щкелемр гю пс: %c\n", list.current->next->value);
	}
	print(list);
}

void printToLeft(struct list list) {
	if (list.current == 0) {//ЕЯКХ КХЯР ОСЯР
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	else {
		if (list.current == list.first) printf("пс б мювюке кхярю. щкелемр пс: %c\n", list.current->value);
		else printf("щкелемр дн пс: %c\n", list.current->prev->value);
	}
	print(list);
}

void takeLeft(struct list* list) {
	if (list->current == 0) {//ЕЯКХ КХЯР ОСЯР
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	else {
		if (list->current != list->first) { //ЕЯКХ пс МЕ Б МЮВЮКЕ
			tElem = list->current->prev->value;
			if (list->current->prev == list->first) { // ЕЯКХ пс БН БРНПНИ ЪВЕИЙЕ
				list->first = list->current;
				free(list->current->prev);
				list->current->prev = NULL;
			}
			else {
				list->current->prev = list->current->prev->prev;
				free(list->current->prev->next);
				list->current->prev->next = list->current;
			}
			printf("бгърши щкелемр: %c\n", tElem);
		}
		else {
			tElem = list->current->value;
			if (list->first == list->last) { //ЕЯКХ КХЯР Я НДМХЛ ЩКЕЛЕМРНЛ
				free(list->current);
				list->current = 0;
				list->first = 0;
				list->last = 0;
				printf("кхяр ярюк осяршл. бгърши щкелемр: %c\n", tElem);
				return;
			}
			//ЕЯКХ пс Б МЮВЮКЕ
			else printf("пс б мювюке кхярю, бгърэ щкелемр мебнглнфмн.\n");
		}
	}
	print(*list);
}

void takeRight(struct list* list) {
	if (list->current == 0) {//ЕЯКХ КХЯР ОСЯР
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	else {
		if (list->current != list->last) { //ЕЯКХ пс МЕ Б ЙНМЖЕ
			tElem = list->current->next->value;
			if (list->current->next == list->last) { // ЕЯКХ пс Б ОПЕДОНЯКЕДМЕИ ЪВЕИЙЕ
				list->last = list->current;
				free(list->current->next);
				list->current->next = NULL;
			}
			else {
				list->current->next = list->current->next->next;
				free(list->current->next->prev);
				list->current->next->prev = list->current;
			}
			printf("бгърши щкелемр: %c\n", tElem);
		}
		else {
			tElem = list->current->value;
			if (list->first == list->last) { //ЕЯКХ КХЯР Я НДМХЛ ЩКЕЛЕМРНЛ
				free(list->current);
				list->current = 0;
				list->first = 0;
				list->last = 0;
				printf("кхяр ярюк осяршл. бгърши щкелемр %c\n", tElem);
				return;
			}
			//ЕЯКХ пс Б ЙНМЖЕ
			else printf("пс б йнмже кхярю, бгърэ щкелемр мебнглнфмн. \n");
		}
	}
	print(*list);
}

void changeLeft(struct list* list, char elem) {
	if (list->current == list->first) printf("пс б мювюке кхярю. гмювемхе пс хглемхкняэ: %c\n", list->current->value = elem);
	else list->current->prev->value = elem;
	print(*list);
}

void changeRight(struct list* list, char elem) {
	if (list->current == list->last) printf("пс б йнмже кхярю. гмювемхе пс хглемхкняэ: %c\n", list->current->value = elem);
	else list->current->next->value = elem;
	print(*list);
}

void delToLeft(struct list* list) {
	if (list->current == 0) {//ЕЯКХ КХЯР ОСЯР
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	else {
		if (list->current != list->first) { //ЕЯКХ пс МЕ Б ЙНМЖЕ
			if (list->current->prev == list->first) { // ЕЯКХ пс Б ОПЕДОНЯКЕДМЕИ ЪВЕИЙЕ
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
			if (list->first == list->last) { //ЕЯКХ КХЯР Я НДМХЛ ЩКЕЛЕМРНЛ
				free(list->current);
				list->current = 0;
				list->first = 0;
				list->last = 0;
				printf("кхяр ярюк осяршл.\n");
				return;
			}
			//ЕЯКХ пс Б МЮВЮКЕ
			else printf("пс б мювюке кхярю, сдюкемхе мебнглнфмн. \n\n");
		}
	}
	print(*list);
}

void delToRight(struct list* list) {
	if (list->current == 0) {//ЕЯКХ КХЯР ОСЯР
		printf("ньхайю! кхяр осяр.\n");
		return;
	}
	else {
		if (list->current != list->last) { //ЕЯКХ пс МЕ Б ЙНМЖЕ
			if (list->current->next == list->last) { // ЕЯКХ пс Б ОПЕДОНЯКЕДМЕИ ЪВЕИЙЕ
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
			if (list->first == list->last) { //ЕЯКХ КХЯР Я НДМХЛ ЩКЕЛЕМРНЛ
				free(list->current);
				list->current = 0;
				list->first = 0;
				list->last = 0;
				printf("кхяр ярюк осяршл.\n");
				return;
			}
			//ЕЯКХ пс Б ЙНМЖЕ
			else printf("пс б йнмже кхярю, сдюкемхе мебнглнфмн. \n\n");
		}
	}
	print(*list);
}

//4 яксвюъ: 1) йнцдю кхяр осяр 2) йнцдю пс ме йпюимхи 3.1) йнцдю пс б мювюке 3.2) йнцдю пс б йнмже
void addToLeft(struct list* list, char elem) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = elem;
	if (list->current == 0) { //ЕЯКХ КХЯР ОСЯР
		newNode->next = 0;
		newNode->prev = 0;
		list->first = list->last = list->current = newNode;
	}
	else {
		if (list->current != list->first) { //ЕЯКХ пс МЕ Б МЮВЮКЕ
			newNode->prev = list->current->prev;
			newNode->next = list->current;
			list->current->prev->next = newNode;
			list->current->prev = newNode;
		}
		else { //ЕЯКХ пс Б МЮВЮКЕ
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
	if (list->current == 0) { //ЕЯКХ КХЯР ОСЯР
		newNode->next = 0;
		newNode->prev = 0;
		list->first = list->last = list->current = newNode;
	}
	else {
		if (list->current != list->last) { //ЕЯКХ пс МЕ Б ЙНМЖЕ
			newNode->prev = list->current;
			newNode->next = list->current->next;
			list->current->next->prev = newNode;
			list->current->next = newNode;
		}
		else { //ЕЯКХ пс Б ЙНМЖЕ
			newNode->prev = list->current;
			newNode->next = NULL;
			list->current->next = newNode;
			list->last = newNode;
		}
	}
	print(*list);
}

void clearList(struct list* list) {
	if (list->current == 0) {//ЕЯКХ КХЯР ОСЯР
		printf("ньхайю! кхяр сфе осяр.\n");
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
	printf("нвхярйю опнькю сяоеьмн \n");
}

void deleteList(struct list* list) {
	if (list->current == 0 || (list->current == list->first && list->current == list->last)) {
		free(list->current);
		flag = false;
		printf("пюанрю ян яохяйнл гюйнмвемю.\n");
		return;
	}
	for (list->current = list->first->next; list->current != list->last; list->current = list->current->next) free(list->current->prev);
	free(list->current);
	flag = false;
	printf("пюанрю ян яохяйнл гюйнмвемю.\n");
}

void menu() {
	printf("лемч:\n");
	printf("1) мювюрэ пюанрс\n"); // DONE
	printf("2) ядекюрэ яохянй осяршл\n"); // DONE
	printf("3) опнбепйю мю осярнрс\n"); // DONE
	printf("4) сярюмнбйю пс б мювюкн яохяйю\n"); // DONE
	printf("5) сярюмнбйю пс б йнмеж яохяйю\n"); // DONE
	printf("6) опнбепйю: пс == мювюкн яохяйю \n"); // DONE
	printf("7) опнбепйю: пс == йнмеж яохяйю\n"); // DONE
	printf("8) оепедбхмсрэ пс бопюбн\n"); // DONE
	printf("9) оепедбхмсрэ пс бкебн\n"); // DONE
	printf("10) онйюгюрэ гмювемхе щкелемрю дн пс\n"); // DONE
	printf("11) онйюгюрэ гмювемхе щкелемрю гю пс\n"); // DONE
	printf("12) сдюкхрэ щкелемрю дн пс\n"); // DONE
	printf("13) сдюкхрэ щкелемрю гю пс\n"); // DONE
	printf("14) бгърэ щкелемр дн пс\n");
	printf("15) бгърэ щкелемр гю пс\n");
	printf("16) хглемхрэ гмювемхе щкелемрю дн пс\n");
	printf("17) хглемхрэ гмювемхе щкелемрю гю пс\n");
	printf("18) днаюбхрэ щкелемр дн пс\n"); // DONE. ядекюи опнбепйс мю дкхмс ббндю
	printf("19) днаюбхрэ щкелемр гю пс\n"); // DONE
	printf("20) пюяоевюрюрэ яохянй\n"); // DONE
	printf("21) гюйнмвхрэ пюанрс ян яохяйнл\n"); // вюярхвмн цнрнбн
	printf("22) гюйнмвхрэ пюанрс я опнцпюллни\n"); // DONE
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
		if (checkNum(choice)) {
			clear;
			printf("ббедх мнпл йнлюмдс, онфюксиярю\n");
			continue;
		}
		ch = atoi(choice);
		clear;
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
			if (flag) setLast(&list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 6:
			if (flag) checkFirst(list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 7:
			if (flag) checkLast(list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 8:
			if (flag) setToRight(&list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 9:
			if (flag) setToLeft(&list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 10:
			if (flag) printToLeft(list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 11:
			if (flag) printToRight(list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 12:
			if (flag) delToLeft(&list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 13:
			if (flag) delToRight(&list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 14:
			if (flag) takeLeft(&list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 15:
			if (flag) takeRight(&list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 16:
			if (flag) {
				if (list.current == 0) {//ЕЯКХ КХЯР ОСЯР
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
					changeLeft(&list, c);
				}
			}
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 17:
			if (flag) {
				if (list.current == 0) {//ЕЯКХ КХЯР ОСЯР
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
		case 18:
			if (flag) {
				while (1) {
					printf("ббедхре яхлбнк: ");
					gets_s(choice);
					clear;
					if (strlen(choice) == 1) break;
					else printf("ббнд опебшьюер дкхмс. онфюксиярю ббедхре рнкэйн ндхм яхлбнк!!!\n");
				}
				c = choice[0];
				addToLeft(&list, c);
			}
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 19:
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
		case 20:
			if (flag) print(list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 21:
			if (flag) deleteList(&list);
			else printf("бшонкмхрэ йнлюмдс мебнглнфмн. кхяр ме хмхжхюкхгхпнбюм.\n");
			break;
		case 22:
			printf("бгърши щкелемр: %c\n", tElem);
			printf("гюбепьемхе опнцпюллш");
			return 0;
		default:
			printf("рюйни йнлюмдш ме ясыеярбсер. онфюксиярю, ббедхре йнлюмдс ямнбю.\n");
		}
	}
}