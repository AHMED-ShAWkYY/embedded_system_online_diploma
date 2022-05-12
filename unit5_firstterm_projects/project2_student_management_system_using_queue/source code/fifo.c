//@ahmed shawki

#include"fifo.h"
FIFO_status FIFO_init(FIFO_buf_t*FIFO_P,element_type *P_buf,unsigned int length)
{
	//check if buffer is valid
	if(P_buf== NULL)
		return FIFO_null;
	FIFO_P->FIFO_base=P_buf;
	FIFO_P->FIFO_head=P_buf;
	FIFO_P->FIFO_tail=P_buf;
	FIFO_P->FIFO_length=length;
	FIFO_P->FIFO_count=0;
	return FIFO_no_error;
}
FIFO_status Get_data_from_file(FIFO_buf_t*FIFO_P)
{
	char f_name[50];
	char l_name[50];
	int roll_num,cid[5],x,file_count=0;
	float GPA;
	int line =0;
	if(!FIFO_P->FIFO_base||!FIFO_P->FIFO_head||!FIFO_P->FIFO_tail)
	{
		DPRINTF("fifo is not exist\n");
		return FIFO_null;
	}
	if(FIFO_P->FIFO_count==FIFO_P->FIFO_length)
	{
		DPRINTF("ERROR:- fifo is full\n");
		return FIFO_full;
	}
	FILE *p_file = fopen("file.txt","r");
	if(p_file==NULL)
	{

		DPRINTF("[ERROR] File not found \n");
		return FIFO_error;
	}


	// reading from file

	while( fscanf(p_file,"%d %s %s %f %d %d %d %d %d [^\n]", &roll_num, f_name,l_name,&GPA,&cid[0],&cid[1],&cid[2],&cid[3],&cid[4])!=EOF)
	{
		if(FIFO_P->FIFO_count==FIFO_P->FIFO_length)
		{   DPRINTF("----------------------------\n");
		DPRINTF("[ERROR] fifo is full\n");

		return FIFO_full;
		}
		if(check_dubicated_rollnumber(FIFO_P,roll_num)==0)
		{
			DPRINTF("[ERROR] IN line %d : Roll Number is already taken before \n",line);
			line++;
			continue; // to skip this student
		}
		FIFO_P->FIFO_head->roll=roll_num;
		FIFO_P->FIFO_head->GPA=GPA;
		strcpy(FIFO_P->FIFO_head->fristname,f_name);
		strcpy(FIFO_P->FIFO_head->secondname,l_name);
		for(x=0;x<5;x++)
		{
			FIFO_P->FIFO_head->cid[x]=cid[x];
		}
		FIFO_P->FIFO_head++;
		FIFO_P->FIFO_count++;
		line++;
		file_count++;
		DPRINTF("[INFO] Roll Number %d saved successfully \n",line);

	}
	DPRINTF("\nEnd of file.\n");
	fclose(p_file);
	DPRINTF("************************\n");
	DPRINTF("[INFO]the total number of students are %d\n",FIFO_P->FIFO_count);
	DPRINTF("[INFO]you can add up to %d students\n",FIFO_P->FIFO_length);
	DPRINTF("[INFO]you can add %d more students\n",FIFO_P->FIFO_length-FIFO_P->FIFO_count);
	return FIFO_no_error;
}

FIFO_status add_element_manually(FIFO_buf_t*FIFO_P)
{
	//check if element is valid
	if(!FIFO_P->FIFO_base||!FIFO_P->FIFO_head||!FIFO_P->FIFO_tail)
		return FIFO_null;

	//check if array is full
	if(FIFO_P->FIFO_count==FIFO_P->FIFO_length)
		return FIFO_full;

	DPRINTF("enter the first name \n");
	gets(FIFO_P->FIFO_head->fristname);

	DPRINTF("enter the second name \n");
	gets(FIFO_P->FIFO_head->secondname);

	DPRINTF("enter the id of the student\n");
	scanf("%d",&(FIFO_P->FIFO_head->roll));
	if(check_dubicated_rollnumber(FIFO_P,FIFO_P->FIFO_head->roll)==0)
	{
		DPRINTF("the roll number of the student is dublicated \insert another id \n");
		return FIFO_error;
	}

	DPRINTF("enter the GPA of the student\n");
	scanf("%f",&(FIFO_P->FIFO_head->GPA));

	DPRINTF("enter the course id of each course\n");
	for(int i=0;i<5;i++)
	{
		DPRINTF("Course %d id: ",i+1);
		scanf("%d",&(FIFO_P->FIFO_head->cid[i]));
	}
	FIFO_P->FIFO_head++;
	FIFO_P->FIFO_count++;
	return FIFO_no_error;
	DPRINTF("************************\n");
	DPRINTF("[INFO]the total number of students are %d\n",FIFO_P->FIFO_count);
	DPRINTF("[INFO]you can add up to %d students\n",FIFO_P->FIFO_length);
	DPRINTF("[INFO]you can add %d more students\n",FIFO_P->FIFO_length-FIFO_P->FIFO_count);
}
FIFO_status find_the_Student_by_rollnumber(FIFO_buf_t*FIFO_P)
{
	int rollnum;
	DPRINTF("enter the roll number of the student\n");
	scanf("%d",&rollnum);
	element_type*findstudent=FIFO_P->FIFO_base;


	//check if the id is exist
	int i;
	for(i=0;i<FIFO_P->FIFO_length;i++,findstudent++)
	{
		if((findstudent->roll)==rollnum)
			break;
	}
	if(i==FIFO_P->FIFO_length)
	{
		DPRINTF("ERROR: the roll number %d is not exist\n",rollnum);
		return FIFO_null;
	}
	DPRINTF("the students details are\n");
	DPRINTF("the first name is %s\n",findstudent->fristname);
	DPRINTF("the last name is %s\n",findstudent->secondname);
	DPRINTF("the  GPA is %f\n",findstudent->GPA);
	DPRINTF("the courses id's are \n");
	for(i=0;i<5;i++)
	{
		DPRINTF("the course ID are %d\n",(findstudent->cid[i]));
	}
	return FIFO_no_error;
}
FIFO_status find_the_Student_by_firstname(FIFO_buf_t*FIFO_P)
{
	int test=0;
	//check buf is valid
	if(!FIFO_P->FIFO_base||!FIFO_P->FIFO_head||!FIFO_P->FIFO_tail)
		return FIFO_null;
	char name[20];
	DPRINTF("enter the first name of the student\n");
	gets(name);
	element_type*findstudent=FIFO_P->FIFO_base;

	//check if the id is exist
	int i;
	for(i=0;i<FIFO_P->FIFO_length;i++,findstudent++)
	{
		if(stricmp(name,findstudent->fristname)==0)
		{
			DPRINTF("the students details are\n");
			DPRINTF("the first name is %s\n",findstudent->fristname);
			DPRINTF("the last name is %s\n",findstudent->secondname);
			DPRINTF("the  GPA is %f\n",findstudent->GPA);
			DPRINTF("the courses id's are \n");
			for(i=0;i<5;i++)
			{
				DPRINTF("the course ID are %d\n",(findstudent->cid[i]));
			}
			test++;
		}
	}
	if(test>0)
	{
		DPRINTF("ERROR: this name (%s) is not exist\n",name);
		return FIFO_null;
	}
	DPRINTF("the students details are\n");
	DPRINTF("the first name is %s\n",findstudent->fristname);
	DPRINTF("the last name is %s\n",findstudent->secondname);
	DPRINTF("the  GPA is %f\n",findstudent->GPA);
	DPRINTF("the courses id's are \n");
	for(i=0;i<5;i++)
	{
		DPRINTF("the course ID are %d\n",(findstudent->cid[i]));
	}
	return FIFO_no_error;
}
FIFO_status find_Students_registered_in_same_course(FIFO_buf_t*FIFO_P)
{
	int i,j,selected_id,no_of_students=0;
	//check buf is valid
	if(!FIFO_P->FIFO_base||!FIFO_P->FIFO_head||!FIFO_P->FIFO_tail)
		return FIFO_null;

	DPRINTF("enter the course id \n");
	scanf("%d",&selected_id);
	element_type*findstudent=FIFO_P->FIFO_base;
	for(i=0;i<FIFO_P->FIFO_length;i++,findstudent++)
	{
		for(j=0;j<5;j++)
		{
			if((findstudent->cid[j])==selected_id)
			{
				DPRINTF("the first name is %s\n",findstudent->fristname);
				DPRINTF("the last name is %s\n",findstudent->secondname);
				DPRINTF("the  GPA is %f\n",(findstudent->GPA));
				DPRINTF("the courses id's are \n");
				no_of_students++;
			}
		}
	}
	if(no_of_students==0)
	{
		DPRINTF("ERROR: Course id %d is not exist\n",selected_id);
		return FIFO_null;
	}
	DPRINTF("total number of students enrolled: %d\n",no_of_students);

	return FIFO_no_error;
}

FIFO_status print_number_of_students_in_system(FIFO_buf_t*FIFO_P)
{
	DPRINTF("************************\n");
	DPRINTF("[INFO]the total number of students are %d\n",FIFO_P->FIFO_count);
	DPRINTF("[INFO]you can add up to %d students\n",FIFO_P->FIFO_length);
	DPRINTF("[INFO]you can add %d more students\n",FIFO_P->FIFO_length-FIFO_P->FIFO_count);
	return FIFO_no_error;

}
FIFO_status delete_a_student(FIFO_buf_t*FIFO_P)
{

	//check fifo is empty
	if(FIFO_P->FIFO_count==0)
	{
		DPRINTF("system is empty\n");
		return FIFO_empty;
	}
	int i,j,t=0,rollnum;
	DPRINTF("enter the roll number of the student\n");
	scanf("%d",&rollnum);
	element_type*findstudent=FIFO_P->FIFO_base;

	for(i=0;i<FIFO_P->FIFO_count;i++,findstudent++)
	{
		if(findstudent->roll==rollnum)
		{
			for(j=i;j<FIFO_P->FIFO_count;j++)
			{
				strcpy(findstudent->fristname,(findstudent+1)->fristname);
				strcpy(findstudent->secondname,(findstudent+1)->secondname);
				(findstudent->GPA)=((findstudent+1)->GPA);
				(findstudent->roll)=((findstudent+1)->roll);
				for(j=0;j<5;j++)
				{
					(findstudent->cid[j])=((findstudent+1)->cid[j]);
				}
			}
			t++;
		}
	}
	if(t==0)
	{
		DPRINTF("ERROR: the roll number is not exist\n");
		return FIFO_null;
	}

	FIFO_P->FIFO_count--;
	FIFO_P->FIFO_head--;
	DPRINTF("************************\n");
	DPRINTF("[INFO]the total number of students are %d\n",FIFO_P->FIFO_count);
	DPRINTF("[INFO]you can add up to %d students\n",FIFO_P->FIFO_length);
	DPRINTF("[INFO]you can add %d more students\n",FIFO_P->FIFO_length-FIFO_P->FIFO_count);
	return FIFO_no_error;
}

FIFO_status update_student(FIFO_buf_t*FIFO_P)
{
	int rollnum,choice,t=0;
	DPRINTF("enter the roll number to update the entry\n");
	scanf("%d",&rollnum);
	element_type*findstudent=FIFO_P->FIFO_base;


	//check if the id is exist
	int i;
	for(i=0;i<FIFO_P->FIFO_count;i++,findstudent++)
	{
		if((findstudent->roll)==rollnum)
		{
			t++;
			break;
		}
	}
	if(t==0)
	{
		DPRINTF("ERROR: the roll number is not exist\n");
		return FIFO_null;
	}
	DPRINTF("1. firstname\n 2. lastname\n 3. roll no\n 4. GPA\n 5. courses\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		DPRINTF("enter the new frist name\n");
		gets(findstudent->fristname);
		break;
	case 2:
		DPRINTF("enter the new last name\n");
		gets(findstudent->secondname);
		break;
	case 3:
		DPRINTF("enter the new roll num\n");
		scanf("%d",&(findstudent->roll));
		break;
	case 4:
		DPRINTF("enter the new GPA\n");
		scanf("%f",&(findstudent->GPA));
		break;
	case 5:
		DPRINTF("enter the new courses\n");
		for(i=0;i<5;i++)
		{
			scanf("%d",&(findstudent->cid[i]));
		}
		break;
	}
	return FIFO_no_error;
}

FIFO_status display_all_informations(FIFO_buf_t*FIFO_P)
{

	//check if info  is valid
	if(!FIFO_P->FIFO_base||!FIFO_P->FIFO_head||!FIFO_P->FIFO_tail)
		return FIFO_null;

	if(FIFO_P->FIFO_count==0)
	{
		DPRINTF(" fifo is empty\n");
		return FIFO_empty;
	}
	element_type*findstudent=FIFO_P->FIFO_base;


	int i,j;
	for(i=0;i<FIFO_P->FIFO_count;i++,findstudent++)
	{
		DPRINTF(" student number %d details are\n",i+1);
		DPRINTF("the first name is %s\n",findstudent->fristname);
		DPRINTF("the last name is %s\n",findstudent->secondname);
		DPRINTF("the  GPA is %f\n",findstudent->GPA);
		DPRINTF("the courses id's are \n");
		for(j=0;j<5;j++)
		{
			DPRINTF("the course ID are %d\n",findstudent->cid[j]);
		}
		DPRINTF(" count =%d\n",FIFO_P->FIFO_count);
	}
	DPRINTF("************************\n");
	DPRINTF("[INFO]the total number of students are %d\n",FIFO_P->FIFO_count);
	DPRINTF("[INFO]you can add up to %d students\n",FIFO_P->FIFO_length);
	DPRINTF("[INFO]you can add %d more students\n",FIFO_P->FIFO_length-FIFO_P->FIFO_count);
	return FIFO_no_error;
}
int check_dubicated_rollnumber(FIFO_buf_t*FIFO_P,int num)
{
	int i;
	element_type*finddublicate=FIFO_P->FIFO_base;

	for(i=0;i<FIFO_P->FIFO_count;i++,finddublicate++)
	{
		if(finddublicate->roll==num)
			return 0;
	}
	return 1;
}
