/*
 * linked_list.c
 *
 *  Created on: ??ş/??ş/????
 *      Author: ÚÇáã ÇáßãÈíæÊÑ
 */

#include"linked_list.h"
struct Sstudent*gp_friststudent=NULL;
void add_student(void)
{
	struct Sstudent*p_newstudent;
	struct Sstudent*p_laststudent;
	//check if list is empty
	if(gp_friststudent)//list is not empty
	{
		//init the pointer with the frist student
		p_laststudent=gp_friststudent;
		//loop until i reach the last node
		while(p_laststudent->p_Nextstudent)
		{
			p_laststudent=p_laststudent->p_Nextstudent;
		}
		//while terminates when i reach the last node
		//create new record
		p_newstudent=(struct Sstudent*)malloc(sizeof(struct Sstudent));
		p_laststudent->p_Nextstudent=p_newstudent;
	}
	else//list is empty
	{
		//create the frist record
		p_newstudent=(struct Sstudent*)malloc(sizeof(struct Sstudent));
		gp_friststudent=p_newstudent;
	}
	//fill the new record
	DPRINTF("enter the student id\n");
	scanf("%d",&p_newstudent->student.id);
	DPRINTF("enter the student name\n");
	gets(p_newstudent->student.name);
	DPRINTF("enter the student height\n");
	scanf("%f",&p_newstudent->student.height);
	p_newstudent->p_Nextstudent=NULL;
}
int delete_student(void)
{
	int selected_id;
	DPRINTF("enter the id of the student you want to delete");
	scanf("%d",&selected_id);
	struct Sstudent*p_previousstudent=NULL;
	struct Sstudent*p_selectedstudent=gp_friststudent;
	//check if list is empty
	if(gp_friststudent)
	{
		//check if the id is exist or not
		while(p_selectedstudent)
		{
			if(p_selectedstudent->student.id==selected_id)
			{
				if(p_previousstudent)
				{
					p_previousstudent->p_Nextstudent=p_selectedstudent->p_Nextstudent;
				}
				else//the selected  is the frist
				{
					gp_friststudent=gp_friststudent->p_Nextstudent;
				}
				free(p_selectedstudent);
				return 1;
			}
			p_previousstudent=p_selectedstudent;
			p_selectedstudent=p_selectedstudent->p_Nextstudent;

		}
		DPRINTF("the id you choose is not exist");
		return 0;
	}
	else
	{
		DPRINTF("list is empty");
	}
}
void view_all(void)
{
	int count=0;
	struct Sstudent*p_currentstudent;
	p_currentstudent=gp_friststudent;
	if(gp_friststudent)
	{
		while(p_currentstudent)
		{
			DPRINTF("student number %d\n",count+1);
			DPRINTF("id=%d\n",p_currentstudent->student.id);
			DPRINTF("Name=%s\n",p_currentstudent->student.name);
			DPRINTF("height=%f\n",p_currentstudent->student.height);
			p_currentstudent=p_currentstudent->p_Nextstudent;
			count++;
		}
	}
	else
	{
		DPRINTF("list is empty\n");
	}
}
void delete_all(void)
{
	struct Sstudent*p_currentstudent;
	struct Sstudent*p_temp;
	p_currentstudent=gp_friststudent;
	if(gp_friststudent)
	{
		while(p_currentstudent)
		{
			p_temp=p_currentstudent;
			p_currentstudent=p_currentstudent->p_Nextstudent;
			free(p_temp);
		}
		gp_friststudent=NULL;
	}
	else
	{
		DPRINTF("list is empty\n");
	}
}
int Get_nth(int index)
{
	struct Sstudent*p_specficnode=gp_friststudent;
	int count=0;
	if(index==count&&p_specficnode==NULL)
	{
		printf("index is not exist");
		return 0;
	}
	while(index!=count)
	{
		count++;
		p_specficnode=p_specficnode->p_Nextstudent;
		if(p_specficnode==NULL&&index!=NULL)
		{
			printf("index is not exist\n");
			return 0;
		}
	}
	if(index==count)
	{
		DPRINTF("student number %d\n",count+1);
		DPRINTF("id=%d\n",p_specficnode->student.id);
		DPRINTF("Name=%s\n",p_specficnode->student.name);
		DPRINTF("height=%.2f\n",p_specficnode->student.height);
		return 1;
	}
}
int Get_length(void)
{
	int count=0;
	struct Sstudent *p_currentstudent=gp_friststudent;
	while(p_currentstudent)
	{
		count++;
		p_currentstudent=p_currentstudent->p_Nextstudent;
	}
	printf("length=%d nodes",count);
	return count;
}

int nodes_length(struct Sstudent *p_length)
{
	if(p_length)
	{
		return 1+ nodes_length(p_length->p_Nextstudent);
	}
	else
	{
		return 0;
	}
}
int Get_nth_from_end(int index)
{
	struct Sstudent *main_ptr=gp_friststudent;
	struct Sstudent *ref_ptr=gp_friststudent;
	int count=0;
	int length=nodes_length(gp_friststudent);
	//check if list is empty
	if(length==0)
	{
		printf("list is empty\n");
		return 0;
	}
	//check if there is enough nodes to get the specfic node
	if(index>length)
	{
		printf("index is not exist\n");
		return 0;
	}
	//loop until i get the last node
	while(ref_ptr)
	{
		ref_ptr=ref_ptr->p_Nextstudent;
		count++;
		//loop after i get the difference between 2 pointers unil i get the last node
		printf("count=%d\n",count);
		while(count==index&&ref_ptr!=NULL)
		{
			ref_ptr=ref_ptr->p_Nextstudent;
			main_ptr=main_ptr->p_Nextstudent;
		}
	}
	DPRINTF("student number %d\n",count);
	DPRINTF("id=%d\n",main_ptr->student.id);
	DPRINTF("Name=%s\n",main_ptr->student.name);
	DPRINTF("height=%.2f\n",main_ptr->student.height);
}
int find_middle(void)
{
	int count=0;
	int length=nodes_length(gp_friststudent);
	struct Sstudent *slow_ptr=gp_friststudent;
	struct Sstudent *fast_ptr=gp_friststudent;
	struct Sstudent *middle_ptr=gp_friststudent;
	//check if list is empty
	if(length==0)
	{
		printf("list is empty\n");
		return 0;
	}
	while(fast_ptr->p_Nextstudent)
	{
		fast_ptr=fast_ptr->p_Nextstudent->p_Nextstudent;
		slow_ptr=slow_ptr->p_Nextstudent;
		count++;
		if(count==length/2)
			break;
		middle_ptr=middle_ptr->p_Nextstudent;

	}
	if(length%2!=0)
	{
		DPRINTF("student number %d\n",count+1);
		DPRINTF("id=%d\n",slow_ptr->student.id);
		DPRINTF("Name=%s\n",slow_ptr->student.name);
		DPRINTF("height=%.2f\n",slow_ptr->student.height);
	}
	else
	{
		DPRINTF("student number %d\n",count);
		DPRINTF("id=%d\n",middle_ptr->student.id);
		DPRINTF("Name=%s\n",middle_ptr->student.name);
		DPRINTF("height=%.2f\n",middle_ptr->student.height);
		DPRINTF("student number %d\n",count+1);
		DPRINTF("id=%d\n",slow_ptr->student.id);
		DPRINTF("Name=%s\n",slow_ptr->student.name);
		DPRINTF("height=%.2f\n",slow_ptr->student.height);

	}

}

void reverse_linkedlist(void)
{
struct Sstudent *temp1=NULL;
struct Sstudent *temp2=NULL;
struct Sstudent *head=gp_friststudent;
while(head)
{
	temp2=head->p_Nextstudent;
	head->p_Nextstudent=temp1;
	temp1=head;
	head=temp2;
}
head=temp1;
gp_friststudent=head;
}
