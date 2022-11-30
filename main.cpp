#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{

	int val;
	struct cell* prev;
	struct cell* next;

}CELL;

void create(CELL* currenCell, int val);
void index(CELL* endCell);
CELL* getInsertListAddress(CELL* endCELL, int iterator);

int main()
{

	int itetator;
	int inputValue;
	CELL* insertcell;

	CELL lead;
	lead.next = nullptr;

	while (true)
	{

		printf("“ü—Íahooooooooooooo\n");
		scanf_s("%d", &itetator);
		printf("‘}“ü‚·‚é’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢\n");
		scanf_s("%d", &inputValue);

		insertcell = getInsertListAddress(&lead, itetator);

		create(&lead, inputValue);

		index(&lead);

	}

	return 0;


}

void create(CELL* currenCell, int val)
{
	CELL* newCell;

	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = val;
	newCell->prev = currenCell;
	newCell->next = currenCell->next;

	if (currenCell->next)
	{
		CELL* nextCell = currenCell->next;
		nextCell->prev = newCell;
	}

	currenCell->next = newCell;
}

void index(CELL* endCell)
{
	int no = 1;
	while (endCell->next != nullptr)
	{

		endCell = endCell->next;

		printf("%d", no);
		printf("%p", endCell->prev);
		printf("%5d", endCell->val);
		printf("(%p)", endCell);
		printf("%p\n", endCell->next);

		no++;
	}

}

CELL* getInsertListAddress(CELL* endCELL, int iterator)
{

	for (int i = 0; i < iterator; i++)
	{
		if (endCELL->next)
		{
			endCELL = endCELL->next;
		}
		else
		{
			break;
		}

	}

	return endCELL;

}
