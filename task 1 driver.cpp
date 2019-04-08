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

	S1.addCourse(&C1);
	S1.addCourse(&C2);
	S1.addCourse(&C2);
	S1.addCourse(&C3);

	S2.addCourse(&C2);
	S3.addCourse(&C2);
	S4.addCourse(&C2);
	S5.addCourse(&C2);

	std::cout<<S1;
	std::cout<<C1;
	std::cout<<C2;
	system("pause");


}