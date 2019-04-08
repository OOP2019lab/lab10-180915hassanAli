#include <iostream>
#include"course.h"
#include "student.h"

int main(){
	student S1("S1", "Anum", "11-1351");
	student S2("S2", "Sara", "12-6462");
	student S3("S3", "Sana", "11-4531");
	student S4("S4", "Zara", "12-4342");
	student S5("S5", "Hira", "11-5940");

	course C1("OOP", "CS102");
	course C2("PF", "CS101");
	course C3("AI", "CS365");

	std::cout<<"task 2"<<std::endl<<std::endl;

	C1.AddStudent_task2(&S5);
	S5.addCourse(&C3);
	C1.AddStudent_task2(&S5);
	std::cout<<S5;
	std::cout<<C1;
	std::cout<<C3;

	S5.dropCourse(&C1);
	S4.dropCourse(&C3);


	system("pause");


}