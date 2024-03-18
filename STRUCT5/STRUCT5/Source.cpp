#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#define clear system("cls")

int swap;

void printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

void sortByIns(int array[], int size) {
	printf("БЫЛО: ");
	printArray(array, size);
	int count = 0;
	for (int i = 1;i < size;i++) {
		printf("*\n");
		for (int j = i;j > 0 && array[j - 1] > array[j];j--) {// пока j>0 и элемент j-1 > j, x-массив int
			count++;
			swap = array[j];
			array[j] = array[j - 1];
			array[j - 1] = swap;
			printf("ИТЕРАЦИЯ %d: ", count);
			printArray(array, size);
		}
	}
	if (count == 0) printf("МАССИВ УЖЕ ОТСОРТИРОВАН. СОРТИРОВКА НЕ ОСУЩЕСТВИЛАСЬ.\n");
}

void sortShaker(int array[], int size)
{
	printf("БЫЛО: ");
	printArray(array, size);
	int left = 0, right = size - 1; // левая и правая границы сортируемой области массива
	int flag = 1;  // флаг наличия перемещений
	// Выполнение цикла пока левая граница не сомкнётся с правой
	// и пока в массиве имеются перемещения
	while ((left < right) && flag != 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //двигаемся слева направо
		{
			if (array[i] > array[i + 1]) // если следующий элемент меньше текущего,
			{             // меняем их местами
				int t = array[i];
				array[i] = array[i + 1];
				array[i + 1] = t;
				flag = 1;      // перемещения в этом цикле были
			}
		}
		if (flag) printArray(array, size);
		right--; // сдвигаем правую границу на предыдущий элемент
		for (int i = right; i > left; i--)  //двигаемся справа налево
		{
			if (array[i - 1] > array[i]) // если предыдущий элемент больше текущего,
			{            // меняем их местами
				int t = array[i];
				array[i] = array[i - 1];
				array[i - 1] = t;
				flag = 1;    // перемещения в этом цикле были
			}
		}
		left++; // сдвигаем левую границу на следующий элемент
		if (flag) printArray(array, size);
	}
}

void sortShell(int* array, int size) {
	int i, j, k, buffer, step = 4;

	for (step; step > 0; step /= 2) { // Шаги 4, 2, 1
		for (j = 0; j < step; j++) { // Начальная позиция
			for (i = j; i < size; i += step) { // Сортировка вставками
				k = j;
				buffer = array[i];
				while (k <= i) {
					if (array[k] > buffer) {
						array[i] = array[k];
						array[k] = buffer;
						buffer = array[i];
					}
					k += step;
				}
			}
		}
		printArray(array, size);
	}
}

void menu() {
	printf("	МЕНЮ:\n");
	printf("1) СОРТ ВСТАВКАМИ\n");
	printf("2) СОРТ ШЕЙКЕРОМ\n");
	printf("3) СОРТ ШЕЛЛА\n");
	printf("4) ВЕРНУТЬ МАССИВ В ИСХОДНОЕ СОСТОЯНИЕ\n");
	printf("5) ЗАВЕРШИТЬ ПРОГРАММУ\n");
}

int main() {
	setlocale(LC_ALL, "ru");
	int choice;
	int array[] = { 6,5,3,1,8,7,2,4 };
	int n = sizeof(array) / sizeof(array[0]);
	while (1) {
		menu();
		printf("ВЫБЕРИТЕ ЖЕЛАЕМОЕ ДЕЙСТВИЕ: ");
		scanf_s("%d", &choice);
		clear;
		switch (choice) {
		case 1:
			sortByIns(array, n);
			break;
		case 2:
			sortShaker(array, n);
			break;
		case 3:
			printf("БЫЛО: ");
			printArray(array, n);
			sortShell(array, n);
			break;
		case 4:
			array[0] = 6;
			array[1] = 5;
			array[2] = 3;
			array[3] = 1;
			array[4] = 8;
			array[5] = 7;
			array[6] = 2;
			array[7] = 4;
			printf("ГОТОВО\n");
			printArray(array, n);
			break;
		case 5:
			return 0;
		default:
			printf("НЕПРАВИЛЬНАЯ КОМАНДА\n");
		}
	}
}
