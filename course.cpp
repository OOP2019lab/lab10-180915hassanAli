#include "course.h"

course::course(std::string name,std::string no):course_name(name),course_number(no){
	students=new student*[4];
	studentCount=0;
}

course::~course(){
	delete[] students;
}

course& course::operator=(const course& c){
	course_name=c.course_name;
	course_number=c.course_number;

	studentCount=c.studentCount;
	for (int i=0;i<studentCount;++i){
		students[i]=c.students[i];
	}

	return *this;
}

void course::AddStudent(student * stu)
{
	if (studentCount<4){
		bool unique=1;
		for (int c=0;c<studentCount;++c){
			if (stu==students[c]) unique =0;
		}

		if (unique==1){
			students[studentCount]=stu;
			++studentCount;
		}
		else{
			std::cout<<"student already enrolled";
		}
	}
	else{
		std::cout<<"course has 4 student";
	}
}

std::ostream& operator<<(std::ostream& is, const course& c){
	std::cout<<"course name: "<<c.course_name<<std::endl;
	std::cout<<"course number: "<<c.course_number<<std::endl;

	std::cout<<"students: "<<std::endl;
	for (int i=0;i<c.studentCount;++i){
		std::cout<<c.students[i]->getname()<<"	";
	}

	return is;
}

void course::AddStudent_task2(student * stu){
	if (studentCount<4){
		bool unique=1;
		for (int c=0;c<studentCount;++c){
			if (stu==students[c]) unique =0;
		}

		if (unique==1){
			students[studentCount]=stu;
			++studentCount;
			stu->addCourse(this,0);
		}
		else{
			std::cout<<"student already enrolled";
		}
	}
	else{
		std::cout<<"course has 4 student";
	}
}

void course::dropStudent(student * stu){
	for (int i=0;i<studentCount;++i){
		if (stu==students[i]){
			students[i]=nullptr;
			--studentCount;
		}
	}
}