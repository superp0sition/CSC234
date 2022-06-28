///////////////////////////////////////////////////////////////////////
//
// Class: Student                                          
//                                                                   
// Description:
//    Store a student's information       
//
//    List of data members
//      first
//		last
//		ssn
//		tests
//		average
//    List of member functions
//      get_first
//		get_last
//		get_ssn
//		get_scores
//		get_average
//		to_string
//		add_score                                     
// 
///////////////////////////////////////////////////////////////////////

#include "Student.h"

/*Student::Student(string _first, string _last, string _ssn, float t1, float t2, float t3, float t4) {
	first = _first;
	last = _last;
	ssn = _ssn;
	tests = { t1, t2, t3, t4 };
}*/ // unused original constructor

Student::Student(string s) // constructor
{
	// originally tried using getline with the delimiter ' ', but values are not single-space seperated.

	regex e("\\s+"); // create an expression to remove all spaces in a string and use that to seperate data
	regex_token_iterator<string::iterator> i(s.begin(), s.end(), e, -1); // iterate over string using the regex
	regex_token_iterator<string::iterator> end; // signify end
	last = *i++; // first info is the last name
	first = *i++; // second is the first name
	ssn = *i++; // next is the ssn
	while (i != end) // keep adding as many scores as it finds
		add_score(stof(*i++)); // convert the string to float
	float avg = 0;
	for (float s : tests)
		avg += s / tests.size(); // calculate the average of all scores
	average = avg; // store it
}

///////////////////////////////////////////////////////////////////////
//
// Function: get_first                                          
//                                                                   
// Description:
//    Returns the first name of a student
// 
// Returns:  
//    (string)first: first name of the student               
//                                            
///////////////////////////////////////////////////////////////////////


string Student::get_first() 
{
	return first;
}

///////////////////////////////////////////////////////////////////////
//
// Function: get_last                                          
//                                                                   
// Description:
//    Returns the last name of a student
// 
// Returns:  
//    (string)last: last name of the student               
//                                            
///////////////////////////////////////////////////////////////////////

string Student::get_last() 
{
	return last;
}

///////////////////////////////////////////////////////////////////////
//
// Function: get_ssn                                          
//                                                                   
// Description:
//    Returns the ssn of a student
// 
// Returns:  
//    (string)ssn: ssn of the student               
//                                            
///////////////////////////////////////////////////////////////////////

string Student::get_ssn() 
{
	return ssn;
}

///////////////////////////////////////////////////////////////////////
//
// Function: get_scores                                          
//                                                                   
// Description:
//    Returns the vector storing the test scores of a student
// 
// Returns:  
//    (vector<float>)tests: test scores of the student              
//                                            
///////////////////////////////////////////////////////////////////////

vector<float> Student::get_scores() 
{
	return tests;
}

///////////////////////////////////////////////////////////////////////
//
// Function: get_first                                          
//                                                                   
// Description:
//    Returns the average of all scores for a student
// 
// Returns:  
//    (float)average: average score of the student               
//                                            
///////////////////////////////////////////////////////////////////////

float Student::get_average() 
{
	return average;
}

///////////////////////////////////////////////////////////////////////
//
// Function: to_string                                         
//                                                                   
// Description:
//    Returns a string to display information of all student data
// 
// Returns:  
//    (string)s: string containing information              
//                                            
///////////////////////////////////////////////////////////////////////

void Student::to_string()
{
	string s = "";
	s += printf("%-15s|%-15s|%-15s|", last.c_str(), first.c_str(), ssn.c_str()); // printf expect C style strings, gave me trouble at first since I haven't done this stuff in a while
	for (auto i = tests.begin(); i != tests.end(); ++i) {
		s += printf("%8.1f|", *i);
	}	
	s += printf("%9.1f\n", average);
	//return s;
}
