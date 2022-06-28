///////////////////////////////////////////////////////////////////////
//
// Class: Classroom                                          
//                                                                   
// Description:
//    Store students of a classroom and calculate basic values       
//
//    List of data members
//      students
//      class_size
//    List of member functions
//      get_class_size
//      get_avg_grade
//      add_student
//      get_students
//      to_string                                       
// 
///////////////////////////////////////////////////////////////////////

#include <fstream>
#include "Student.h"
using namespace std;

class Classroom {
	public:
		Classroom();
		Classroom(string _dir);
		size_t get_class_size();
		float get_avg_grade();
		void add_student(Student _student);
		vector<Student> get_students();
		void to_sting();

	private:
		vector<Student> students;	// Originally was planning to use primitive arrays, but soon ended 
									// up using vectors because I didn't want to debug compilation errors 
									// because size starts with zero, also I'm a bit rusty in c++.
									// Student* students;
		size_t class_size; // kept to verify number students in a class
};