
#include "fifo.h"
student_t students[50];
int main()
{
	int choice;
	FIFO_buf_t student_information;
	FIFO_init(&student_information,students,50);
	DPRINTF("welcome to the student management system\n");
	while(1)
	{
		DPRINTF("choose the task that you want to perform\n");
		DPRINTF("1. add the students details manually\n");
		DPRINTF("2. add the students details from text file\n");
		DPRINTF("3. find the student details by roll number\n ");
		DPRINTF("4. find the student details by first name\n ");
		DPRINTF("5. find the student details by course ID\n ");
		DPRINTF("6. find the total number of the student\n ");
		DPRINTF("7. delete the student details by roll number\n ");
		DPRINTF("8. update the student details by roll number\n ");
		DPRINTF("9. show all informations\n");
		DPRINTF("10. to exit\n ");
		scanf("%d",&choice);
		switch (choice)
		{
		case 1:
			add_element_manually(&student_information);
			break;
		case 2:
			Get_data_from_file(&student_information);
			break;
		case 3:
			find_the_Student_by_rollnumber(&student_information);
			break;
		case 4:
			find_the_Student_by_firstname(&student_information);
			break;
		case 5:
			find_Students_registered_in_same_course(&student_information);
			break;
		case 6:
			print_number_of_students_in_system(&student_information);
			break;
		case 7:
			delete_a_student(&student_information);
			break;
		case 8:
			update_student(&student_information);
			break;
		case 9:
			display_all_informations(&student_information);
			break;
		case 10:
			exit(1);

		default:
			DPRINTF("wrong choice\n");
			break;
		}
	}
}
