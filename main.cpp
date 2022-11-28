#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{

	int val;
	struct cell* next;

}CELL;

void create(CELL* lead,int val);
void index(CELL* lead);

int main()
{

	int val;
	CELL lead;
	lead.next = nullptr;

	while (true)
	{

		scanf_s("%d", &val);

		create(&lead, val);

		index(&lead);

	}

	return 0;


}

void create(CELL* lead, int val)
{
	CELL* newCell;

	newCell = (CELL*)malloc(sizeof(CELL));

	newCell->val = val;
	newCell->next = nullptr;

	while (lead->next != nullptr)
	{

		lead = lead->next;

	}

	if (newCell != nullptr)
	{
		lead->next = newCell;
	}
}

void index(CELL* lead)
{

	while (lead->next != nullptr)
	{

		lead = lead->next;

		printf("%d\n", lead->val);

	}

}
