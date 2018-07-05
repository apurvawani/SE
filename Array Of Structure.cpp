/*
Write C/C++ program to store marks scored for first test of subject 'Data Structures and Algorithms' & 'Object Oriented Programming' for N 
students. Compute :  
   I. The average score of class 
   II. Highest score and lowest score of class 
   III. Marks scored by most of the students 
   IV. List of students who were absent for the test 
*/

#include <iostream>
#include<string>
using namespace std;
int n;
struct Student {
	int rollno;
	string name;
	float marks_sub1;
	float marks_sub2;
	bool status;
};
//Reading input
void read(Student *s , int l){
	cout << "Enter student details : " << endl;
	for(int i = 0 ; i < l ; i++) {
		cout << "Enter RollNo, Name & Marks : " << endl;
		cin >> s[i].rollno;
		getline(cin , s[i].name);
		cin >> s[i].marks_sub1;
		cin >> s[i].marks_sub2;
		cout << "Enter 1 if student is present else enter 0. " << endl;
		cin >> s[i].status;
	}
}
int main() {
	cout << "Enter number of students : " << endl;
	cin >> n;
	struct Student s[n];
	read(s, n);
	float total_sub1 = 0 ,total_sub2 = 0 , avg_sub1 = 0 , avg_sub2 = 0;
	//calculate total
	int t = 0;
	for(int i = 0 ; i < n ; i++) {
		if(s[i].status==1) {
			total_sub1 += s[i].marks_sub1;
			total_sub2 += s[i].marks_sub2;
		}
		else {
			t++;
		}
	}
	//calculate avg
	avg_sub1 = total_sub1 /(n-t);
	avg_sub2 = total_sub2 /(n-t);
	cout << "Average score of the class for subject 1: " << avg_sub1 << endl;
	cout << "Average score of the class for subject 2: " << avg_sub2 << endl;
	//max & min score
	float maxScore_sub1 = 0 , maxScore_sub2 = 0 , minScore_sub1 = s[0].marks_sub1 , minScore_sub2 = s[0].marks_sub2;
	for(int i = 0 ; i < n ; i++) {
		if(s[i].marks_sub1 > maxScore_sub1) {
			maxScore_sub1 = s[i].marks_sub1;
		}
		if(s[i].marks_sub1 < minScore_sub1) {
			minScore_sub1 = s[i].marks_sub1;
		}
		if(s[i].marks_sub2 > maxScore_sub2) {
			maxScore_sub2 = s[i].marks_sub2;
		}
		if(s[i].marks_sub2 < minScore_sub2) {
			minScore_sub2 = s[i].marks_sub2;
		}
	}
	cout << "Highest score of class for subject 1 : " << maxScore_sub1 << endl;
	cout << "Lowest score of class for subject 1 : " << minScore_sub1 << endl;
	cout << "Highest score of class for subject 2 : " << maxScore_sub2 << endl;
	cout << "Lowest score of class for subject 2 : " << minScore_sub2 << endl;
	//absent students record
	cout << "Absent students : " << t << endl;
	for(int i = 0 ; i < n ; i++) {
		if(s[i].status==0) {
			cout << "Roll No : " << i+1 << "\tName : " << s[i].name << endl;
		}
	}
	//frequency of marks
	int count_sub1[n] , count_sub2[n];
	for(int i = 0 ; i < n ; i++) {
		int c1 = 0 , c2 = 0;
		for(int j = 0 ; j < n ; j++) {
			if(s[i].marks_sub1==s[j].marks_sub1) {
				c1++;
			}
			if(s[i].marks_sub2==s[j].marks_sub2) {
				c2++;
			}
		}
		count_sub1[i] = c1;
		count_sub2[i] = c2;
	}
	int k1 = 0 , k2 = 0 , maxCount_sub1 = 0 , maxCount_sub2 = 0;
	for(int i = 0 ; i < n ; i++) {
		if(count_sub1[i] > maxCount_sub1) {
			maxCount_sub1 = count_sub1[i];
			k1 = i;
		}
		if(count_sub2[i] > maxCount_sub2) {
			maxCount_sub2 = count_sub2[i];
			k2 = i;
		}
	}
	cout << "Marks scored by most of the students for subject 1 : " << s[k1].marks_sub1 << endl;
	cout << "Marks scored by most of the students for subject 2 : " << s[k2].marks_sub2 << endl;
	return 0;
}
