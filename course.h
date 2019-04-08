#pragma once

#include <string>
#include <iostream>
#include "student.h"

class student;

class course{
	friend student;
	
public:
	course(std::string,std::string);
	~course();
	course& operator=(const course&);
	friend std::ostream& operator<<(std::ostream&, const course&);

	std::string getName(){return course_name;};
	void AddStudent_task2(student *);

private:
	std::string course_name;
	std::string course_number;

	student ** students;
	int studentCount;

	void AddStudent(student *);
	void dropStudent(student *);
};