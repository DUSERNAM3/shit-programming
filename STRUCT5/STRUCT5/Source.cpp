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
	printf("����: ");
	printArray(array, size);
	int count = 0;
	for (int i = 1;i < size;i++) {
		printf("*\n");
		for (int j = i;j > 0 && array[j - 1] > array[j];j--) {// ���� j>0 � ������� j-1 > j, x-������ int
			count++;
			swap = array[j];
			array[j] = array[j - 1];
			array[j - 1] = swap;
			printf("�������� %d: ", count);
			printArray(array, size);
		}
	}
	if (count == 0) printf("������ ��� ������������. ���������� �� �������������.\n");
}

void sortShaker(int array[], int size)
{
	printf("����: ");
	printArray(array, size);
	int left = 0, right = size - 1; // ����� � ������ ������� ����������� ������� �������
	int flag = 1;  // ���� ������� �����������
	// ���������� ����� ���� ����� ������� �� �������� � ������
	// � ���� � ������� ������� �����������
	while ((left < right) && flag != 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)  //��������� ����� �������
		{
			if (array[i] > array[i + 1]) // ���� ��������� ������� ������ ��������,
			{             // ������ �� �������
				int t = array[i];
				array[i] = array[i + 1];
				array[i + 1] = t;
				flag = 1;      // ����������� � ���� ����� ����
			}
		}
		if (flag) printArray(array, size);
		right--; // �������� ������ ������� �� ���������� �������
		for (int i = right; i > left; i--)  //��������� ������ ������
		{
			if (array[i - 1] > array[i]) // ���� ���������� ������� ������ ��������,
			{            // ������ �� �������
				int t = array[i];
				array[i] = array[i - 1];
				array[i - 1] = t;
				flag = 1;    // ����������� � ���� ����� ����
			}
		}
		left++; // �������� ����� ������� �� ��������� �������
		if (flag) printArray(array, size);
	}
}

void sortShell(int* array, int size) {
	int i, j, k, buffer, step = 4;

	for (step; step > 0; step /= 2) { // ���� 4, 2, 1
		for (j = 0; j < step; j++) { // ��������� �������
			for (i = j; i < size; i += step) { // ���������� ���������
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
	printf("	����:\n");
	printf("1) ���� ���������\n");
	printf("2) ���� ��������\n");
	printf("3) ���� �����\n");
	printf("4) ������� ������ � �������� ���������\n");
	printf("5) ��������� ���������\n");
}

int main() {
	setlocale(LC_ALL, "ru");
	int choice;
	int array[] = { 6,5,3,1,8,7,2,4 };
	int n = sizeof(array) / sizeof(array[0]);
	while (1) {
		menu();
		printf("�������� �������� ��������: ");
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
			printf("����: ");
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
			printf("������\n");
			printArray(array, n);
			break;
		case 5:
			return 0;
		default:
			printf("������������ �������\n");
		}
	}
}
