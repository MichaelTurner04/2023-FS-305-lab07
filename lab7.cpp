// Programmer: Michael Turner
// Student ID: 18229090
// Section: 305
// Date: 10/4/23
// File: lab7.cpp 

#include <iostream>
#include <ctime>
using namespace std;
int getNumberOfStudents();
void getStudentData(int students, double &avg, double &score, double &max, double &min, string &name, string &minName, string &maxName, int &passed, int &failed);
void displayStatistics(double avg, double score, double max, double min, string name, string minName, string maxName, int passed, int failed);
void getUserName(string &userName);
void getUserId(string &pass);
int calculateASCIISum(string &pass, int &sumASCII);
void greetUser(string &userName, int &sumASCII);
int exitProgram(string userName);
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
	string pass;
	char ch;
	string userName;
	int sumASCII = 0;
	getUserName(userName);
	getUserId(pass);
	calculateASCIISum(pass, sumASCII);
	greetUser(userName, sumASCII);
	if (sumASCII >= 150){
		char choice;
		do{
			cout << "\n1. Calculate student statistics \n2. Display statistics \n3. Exit"<<endl;
			cout << "Enter your choice: ";
			cin >> choice;
			switch(choice){
			case '1':
				students = getNumberOfStudents();
				getStudentData(students, avg, score, max, min, name, minName, maxName, passed, failed);
				break;
			case '2':
				displayStatistics(avg, score, max, min, name, minName, maxName, failed, passed);
				break;
			case '3':
				break;
			default:
				cout << "invalid input" <<endl;
			}
		}while(choice != '3');

	}else if(sumASCII < 150){
		char choice;
		do{
			cout << "\nMenu 1: Under construction \nMenu 2: Exit program" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			switch(choice){
				case '1':
					cout << "This feature is under construction"<< endl;
					break;
				case '2':
					break;
				default:
					cout << "Invalid input" << endl;
				}
		}while(choice != '2');
	}
	exitProgram(userName);

}
int getNumberOfStudents(){
	int students;
	cout << "Enter the number of students (1 - 100): ";
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
		cout << "Enter name of student " << i << ": ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter score of student " << name << ": ";
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
void getUserName(string &userName){
	cout << "Enter your name: ";
	cin >> userName;

}
void getUserId(string &pass){
	do{ //do while loop for input validation
	cout << "Enter your 5-character ID:";
	cin >> pass;
	if(pass.size() != 5){ //getting an input of 5 characters
		cout <<"Invalid input. Please enter 5 characters ";
		cin >> pass;
		}
	}while(pass.size() != 5);
}
int calculateASCIISum(string &pass, int &sumASCII){
	for(int i=0; i <3 ; i++) { //for loop for each character inserted
		int asciiValue = int(pass[i]);
		sumASCII += asciiValue;
		}
	return sumASCII;

}
void greetUser(string &userName,int &sumASCII){
	if(sumASCII >= 150){
	cout << "welcome teacher " << userName << endl;
	}
	else{
	cout << "welcome student " << userName << endl;
	}
	time_t now = time(0);
	char* dt = ctime(&now);
	cout << "you logged in at "<< dt <<endl;
}
int exitProgram(string userName){
	cout << "Goodbye " << userName <<endl;
	return 0;
}
