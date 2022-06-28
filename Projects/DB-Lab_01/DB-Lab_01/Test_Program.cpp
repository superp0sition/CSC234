///////////////////////////////////////////////////////////////////////
//                                                                     
// Filename: Test_Program.cpp
// Date: January 12, 2022
// Programmer: David Badcoe             
//
// Description:
//    Displays several values from students.txt to user along
//    along with a few extra calculated values.
/////////////////////////////////////////////////////////////////////////


#include "Classroom.h"

int main()
{
    Classroom c;
    c.to_sting(); // output class information (simply contains student information)
    printf("\nThe number of students in the class is:\t%d\nThe average grade of all students is:\t%.1f\n", c.get_class_size(),c.get_avg_grade()); // formatted output containing calculated values
}
