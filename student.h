#pragma once

#include <string>
#include <iostream>

#include "course.h"

class course;

class student{
public:
	student(std::string,std::string,std::string);
	~student();

	friend std::ostream& operator<<(std::ostream& is, const student& stu);
	student& operator=(const student&);

	void addCourse(course *);
	void addCourse(course *,int);
	void dropCourse(course *);

	std::string getname(){return name;}

private:
	std::string username;
	std::string name;
	std::string roll_number;

	course ** courses;
	int CourseCount;
};