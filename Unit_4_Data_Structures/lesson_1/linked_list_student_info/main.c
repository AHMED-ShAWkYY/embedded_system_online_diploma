/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ÚÇáã ÇáßãÈíæÊÑ
 */

#include"linked_list.h"
extern struct Sstudent*gp_friststudent;

void main()
{
	int Case;
	int node_index,length;
	while(1)
	{
		DPRINTF("choose one of following options\n");
		DPRINTF("1: add student\n");
		DPRINTF("2: delete student\n");
		DPRINTF("3: view all students\n");
		DPRINTF("4: delete all  students\n");
		DPRINTF("5: get the data of a specific node\n");
		DPRINTF("6: get the length of linked list(iteratine fn)\n");
		DPRINTF("7: get the length of linked list(recursive fn)\n");
		DPRINTF("8: get the data of a specific node from the end\n");
		DPRINTF("9: get the data of a middle node\n");
		DPRINTF("10: reverse a linked list\n");
		scanf("%d",&Case);
		switch(Case)
		{
		case 1:
			add_student();
			break;
		case 2:
			delete_student();
			break;
		case 3:
			view_all();
			break;
		case 4:
			delete_all();
			break;
		case 5:
			DPRINTF("enter the index of the node\n");
			scanf("%d",&node_index);
			fflush(stdin);
			Get_nth(node_index);
			break;
		case 6:
			Get_length();
			break;
		case 7:
			length=nodes_length(gp_friststudent);
			DPRINTF("length=%d nodes\n",length);
			break;
		case 8:
			DPRINTF("enter the index of the node from the end\n");
			scanf("%d",&node_index);
			fflush(stdin);
			Get_nth_from_end(node_index);
			break;
		case 9:
			find_middle();
			break;
		case 10:
			reverse_linkedlist();
			break;
		default:
			DPRINTF("WRONG OPTIONS");
			break;
		}
	}
}
