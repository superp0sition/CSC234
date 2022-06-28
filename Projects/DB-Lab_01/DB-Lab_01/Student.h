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

#include <string>
#include <sstream> 
#include <vector>
#include <regex>
#include <iostream> // thought I might need this here, but don't. Kept it to keep the main file slightly shorter
using namespace std;

class Student {
	public:
		Student(string _data);
		string get_first();
		string get_last();
		string get_ssn();
		vector<float> get_scores();
		float get_average();
		void to_string();

	private:
		string first;
		string last;
		string ssn;
		vector<float> tests;
		float average;

		void add_score(float score) {
			tests.push_back(score);
		}
};