// Programmer: Michael Turner
// Student ID: 18229090
// Section: 305
// Date: 10/4/23
// File: lab6-1.cpp 

#include <iostream>
using namespace std;
int getNumberOfStudents();
void getStudentData(int students, double &avg, double &score, double &max, double &min, string &name, string &minName, string &maxName, int &passed, int &failed);
void displayStatistics(double avg, double score, double max, double min, string name, string minName, string maxName, int passed, int failed);
int main(){
	int students;
	string name;
	double score;
	double sum;
	double avg;
	int passed = 0;
	int failed = 0;
	double min = 100;
	double max = 0;
	string maxName;
	string minName;
	char again;
	do{
	students = getNumberOfStudents();
	getStudentData(students, avg, score, max, min, name, minName, maxName, passed, failed);
	displayStatistics(avg, score, max, min,name, minName, maxName, failed, passed);
	cout << "would you like to rerun the program? (y/n) ";
	cin >> again;
	}while (again == 'y' || again == 'Y');
	return 0;

}
int getNumberOfStudents(){
	int students;
	cout << "Enter the number of students ";
	cin >> students;
	while(students < 0 || students > 100){// getting a valid input
		cout << "Invalid range. Please enter range 0-100:" << endl;
		cin >> students;
		}
	return students;
}
void getStudentData(int students, double &avg, double &score, double &max, double &min, string &name,string &minName, string &maxName, int &passed, int &failed){
	double sum;
	for(int i = students; i > 0; i--){//for loop to get information about each student
		cout << "Enter name of student " << i << endl;
		cin.ignore();
		getline(cin, name);
		cout << "Enter score of student " << name << ":";
		cin >> score;
		while(score <0 || score > 100){ //entering a valid score
			cout << "Invalid range. Please enter range 0-100:" << endl;
			cin>> score;
			}
		if(score > max){//getting max value
			max = score;
			maxName = name;
		}
		if (score < min){//getting min value
			min = score;
			minName = name; 
			}
		sum += score; //gathering sum for later use in avg
		cout << name <<": " << score << endl;
		if(score > 60){
			passed++;
			}
		else{
			failed++;
			}
		avg = sum / students; //Equation for avg
		}
}
void displayStatistics(double avg, double score, double max, double min, string name, string minName, string maxName, int passed, int failed ){
	cout << "Class Statistics:\n" << "Max:" << max <<" (student: " << maxName <<")\n" << "Min: " << min << " (student: " << minName << ")"<< endl;
	cout << "Average Score: " << avg<< endl;
	cout << "Number of students failed: " << failed << endl;
	cout << "Number of students passed: " << passed << endl;
}
