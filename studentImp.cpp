#include "student.h"

student::student(std::string username,std::string name,std::string roll_number):username(username),name(name), roll_number(roll_number){
	courses=new course*[2];
	CourseCount=0;
}

student::~student(){
	delete[] courses;
}

std::ostream& operator<<(std::ostream& is, const student& stu){
	std::cout<<"username: "<<stu.username<<std::endl;
	std::cout<<"name: "<<stu.name<<std::endl;
	std::cout<<"roll no: "<<stu.roll_number<<std::endl;

	std::cout<<"courses enrolled:"<<std::endl;
	for (int c=0;c<stu.CourseCount;++c){
		std::cout<<stu.courses[c]->getName()<<"	";
	}

	return is;
}

student& student::operator=(const student& stu){
	username.clear();
	username=stu.username;

	name.clear();
	name=stu.name;

	roll_number.clear();
	roll_number=stu.roll_number;

	CourseCount=stu.CourseCount;
	for (int i=0;i<CourseCount;++i){
		courses[i]=stu.courses[i];
	}

	return *this;
}

void student::addCourse(course * cors)
{
	if (CourseCount<2){
		bool unique=1;
		for (int c=0;c<CourseCount;++c){
			if (courses[c]==cors) unique=0;
		}

		if (unique==1){
			courses[CourseCount]=cors;
			++CourseCount;
			cors->AddStudent(this);
		}
		else{
			std::cout<<"course already present";
		}
	}
	else{
		std::cout<<"student has 2 courses";
	}
}

void student::addCourse(course * cors, int dum)
{
	if (CourseCount<2){
		bool unique=1;
		for (int c=0;c<CourseCount;++c){
			if (courses[c]==cors) unique=0;
		}

		if (unique==1){
			courses[CourseCount]=cors;
			++CourseCount;
		}
		else{
			std::cout<<"course already present";
		}
	}
	else{
		std::cout<<"student has 2 courses";
	}
}

void student::dropCourse(course * c){
	for (int i=0;i<CourseCount;++i){
		if (c==courses[i]){
			c->dropStudent(this);
			c=nullptr;
			--CourseCount;

			return;
		}
	}
	std::cout<<"cannot be dropped";
}