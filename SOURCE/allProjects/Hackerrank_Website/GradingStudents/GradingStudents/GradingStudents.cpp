// GradingStudents.cpp : Defines the entry point for the console application.
//HackerLand University has the following grading policy :
//Every student receives a  in the inclusive range from 0 to 100
//Any  less than  40 is a failing grade.
//Sam is a professor at the university and likes to round each student's  according to 
//these rules:
//If the difference between the grade and the next multiple of 5 is less than 3, 
//round  up to the next multiple of 5.If the value of  is less than 38, no rounding 
//occurs as the result will still be a failing grade.For example, will be rounded to 
//but  will not be rounded because the rounding would result in a number that is less than .
//Given the initial value of  for each of Sam's  students, write code to automate the 
//rounding process. For each , round it according to the rules above and print the result on a new line.

#include<iostream>
using namespace std;
int grading(int a) {
	if (a > 38 && (a-((a%5)*5+5))>3) {
		return (a % 5) * 5 + 5 ;
	}
	return a;
}

int main()
{
	int n, a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cout<<grading(a)<<endl;
	}

    return 0;
}

