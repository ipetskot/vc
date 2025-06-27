#include <stdlib.h>
#include <stdio.h>

typedef struct ListType
{
	int value;

	struct ListType* next;
} ListType;


ListType** SplitListToParts(ListType* head, int partCount)
{
	int length = 0;
	ListType* current = head;

	while (current)
	{
		length++;
		current = current->next;
	}

	int partSize	= length / partCount;
	int extra		= length % partCount;

	ListType** result = (ListType**)malloc(sizeof(ListType*) * partCount);
	current = head;

	for (int i = 0; i < partCount; i++)
	{
		result[i] = current;
		int currentPartSize = partSize + (i < extra ? 1 : 0);

		for (int j = 0; j < currentPartSize - 1 && current; j++)
		{
			current = current->next;
		}

		if (current)
		{
			ListType* next = current->next;
			current->next = NULL;
			current = next;
		}
	}

	return result;
}

ListType* CreateList(int value)
{
	ListType* list = (ListType*)malloc(sizeof(ListType));
	list->value = value;
	list->next	= NULL;

	return list;
}

void PrintList(ListType* head)
{
	while (head)
	{
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

void main()
{
	system("cls");

	const int partCount = 3; // Это N из задачи

	ListType* head		= CreateList(1);
	ListType* current	= head;

	// Создание списка
	for (int i = 2; i < 10; i++)
	{
		current->next = CreateList(i);
		current = current->next;
	}

	// Список делитнся на N частей
	ListType** parts = SplitListToParts(head, partCount);

	// Показываем преподу результат
	for (int i = 0; i < partCount; i++)
	{
		printf("%d : ", i + 1);
		PrintList(parts[i]);
	}

	// Память
	for (int i = 0; i < partCount; i++)
	{
		while (current)
		{
			ListType* tmp = current;
			current = current->next;
			free(tmp);
		}
	}

	free(parts);
}
