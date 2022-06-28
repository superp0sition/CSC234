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


#include "Classroom.h"

Classroom::Classroom() : Classroom("students.txt") { }

Classroom::Classroom(string dir) {
    ifstream data;
    data.open(dir);
    if (data.is_open()) {
        //class_size = 0;
        string student;
        while (getline(data, student)) {
            add_student(student);
            /*class_size++;
            istringstream unformatted(student);
            Student* temp = new Student[class_size];
            memcpy(temp, students, (class_size - 1) * sizeof(Student));
            students = temp;
            (&students+1)[-1] = new Student(unformatted);*/ // this is what was written prior to abandoning it in favor of vectors
        }
        data.close();
        class_size = students.size();
    }
    else {
        cout << "File could not be opened!" << endl;
        class_size = 0;
    }
        
}

///////////////////////////////////////////////////////////////////////
//
// Function: get_class_size                                          
//                                                                   
// Description:
//    Get the number of the students in the class
//           
// Returns:  
//    class_size: class data value of number of students in the class                
//                                            
///////////////////////////////////////////////////////////////////////

size_t Classroom::get_class_size()
{
    return class_size;
}

///////////////////////////////////////////////////////////////////////
//
// Function: get_avg_grade                                          
//                                                                   
// Description:
//    Returns the average grade over all students          
//                                                       
// Returns:  
//    avg: average of all tests                
//                                            
///////////////////////////////////////////////////////////////////////

float Classroom::get_avg_grade()
{
    float avg = 0;
    for (auto s : students)
        avg += s.get_average() / class_size; // potentially could have rounding errors
    return avg;
}

///////////////////////////////////////////////////////////////////////
//
// Function: add_student                                          
//                                                                   
// Description:
//    Adds a student to the class and increments the size of the class
//
// Parameters:  
//    s: student object to be added, public because students 
//       may need to be added later                                      
//                                            
///////////////////////////////////////////////////////////////////////

void Classroom::add_student(Student s) {
    students.push_back(s);
    class_size++;
}

///////////////////////////////////////////////////////////////////////
//
// Function: get_students                                          
//                                                                   
// Description:
//    Returns the vector containing all students in the class         
//                                                       
// Returns:  
//    students: vector containing the students               
//                                            
///////////////////////////////////////////////////////////////////////

vector<Student> Classroom::get_students()
{
    return students;
}

///////////////////////////////////////////////////////////////////////
//
// Function: to_sting                                          
//                                                                   
// Description:
//    Prints a header for information, iterates over every student's to_string                   
//                                            
///////////////////////////////////////////////////////////////////////

void Classroom::to_sting()
{
    //////////////////
    // Table header //
    //////////////////
    int numTests = students[0].get_scores().size(); // get the number of tests of first student, others should be the same size. Not great practice since I should check elsewhere, but that data is unnecessary
    printf("%-15s %-15s %-15s", "Last", "First", "SSN"); // printf expect C style strings, gave me trouble at first since I haven't done this stuff in a while
    string test = "Test ";
    for (auto i = 0; i < numTests; ++i) 
    {
        test.push_back(49 + i); // append, then later remove the test number
        printf("%8s ", test.c_str());
        test.pop_back();
    }
        
    printf("%9s\n", "Average");

    printf("%s\n", string(16*3 + 9 * (numTests + 1) , '_').c_str()); // spaces are hardcoded because adding the returned strings from printf didn't work for me

    ////////////////
    // Table data //
    ////////////////
    for (auto s = students.begin(); s != students.end(); ++s)
        s->to_string();
}
