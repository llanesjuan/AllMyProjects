// car_dataBase_tree.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "carType.h"
//#include"binarySearchTree.h"
#include"carBinaryTree.h"
using namespace std;

void createCarTree(ifstream& infile, carBinaryTree& carTree);
void displayMenu();
void entManualData(carBinaryTree& carTree);
void createArchive(carBinaryTree& carTree,string make,int count);
void swapp(char &a, char &b);
void permutation(string str, int start, int end, carBinaryTree& cartree, int count,int& numNodes);

int main()
{
	int count;
	string make;
	string id;
	string addStart;
	carBinaryTree carTree;
	int choice;
	char ch;
	string model;
	ifstream infile;
	string newAddress;
	char newAdd;
	cout << "Do you want to input a new address of system file: enter y or n?\n";
	cin.get(newAdd);
	cin.get(ch);
	if (newAdd == 'y') {
		cout << "Enter new address\n";
		getline(cin, addStart);
		addStart = addStart.c_str();
		//carTree.setSaveAddress(addStart);
		//infile.open(addStart.c_str());
	}
	else {
		//open the input file
		//infile.open("C:\\Users\\juan\\Desktop\\carDat.txt");
		addStart = "C:\\Users\\juan\\Desktop\\carDat.txt";
	}
	infile.open(addStart);
	if (!infile)
	{
		cout << "The input file does not exist. "
			<< "The program terminates!!!" << endl;
		return 1;
	}
	//create the car list
	carTree.setSaveAddress(addStart);
	createCarTree(infile, carTree);
	infile.close();
	displayMenu();
	cout << "Enter your choice: ";
	cin >> choice; //get the request

	cin.get(ch);
	cout << endl;
	//process the requests
	while (choice <= 8)
	{
		switch (choice)
		{
		case 1://                    To check whether the store carries a particular car
			carTree.genSearch();
			break;
		case 2:     //To check out a car
			cout << "enter make\n";//cout << "Select one of the following:" << endl;	
			getline(cin, make);
			cout << "Enter ID\n";
			getline(cin, id);
			cout << endl;
			carTree.carCheckOut(make, id);	
			carTree.saveCarTree();
			break;
		case 3://To check in a car
			cout << "Enter the model: ";
			getline(cin, make);
			cout << "Enter ID\n";
			getline(cin, id);
			cout << endl;
			cout << endl;
			carTree.carCheckIn(make, id);
			carTree.saveCarTree();
			break;		
		case 4://To print only the make of all the cars
			carTree.carPrintMake();
			break;
		case 5://To print a list of all the cars
			if (carTree.isEmpty()) {
				cout << "No entries \n";
				break;
			}				
			carTree.inorderTraversal();
			break;
		case 6://To introduce data manually
			entManualData(carTree);
			carTree.saveCarTree();
			break;
		case 7://To create an archive of 100 000 items

			cout << "Enter make\n";
			getline(cin, make);
			cout << "Enter amount of element\n";
			cin >> count;
			cout << endl;
			createArchive(carTree,make,count);
			cout << "Do you want to input a new address of stest file: enter y or n?\n";
			cin.get(newAdd);
			cin.get(ch);
			if (newAdd == 'y') {
				cout << "Enter new address\n";
				getline(cin, addStart);
				addStart = addStart.c_str();
			}
			else 
				addStart = "C:\\Users\\juan\\Desktop\\carTestDat.txt";
			carTree.setSaveAddressTest(addStart);
			carTree.saveCarTreeTest();
			break;
		default:
			cout << "Invalid selection." << endl;
		}//end switch
		displayMenu(); //display menu
		cout << "Enter your choice: ";
		cin >> choice; //get the next request
		cin.get(ch);
		cout << endl;
	}//end while
	return 0;
}

void createCarTree(ifstream& infile, carBinaryTree& carTree)
{
	string id;
	string line;
	string make;
	string model;
	string year;
	string engine;
	string door;
	string drive;
	string fuelType;
	string trim;
	string trans;
	string condition;
	string price;
	int inStock;
	string cha = ":";
	string inStockSt;
	carType newCar;
	getline(infile, make);
	while (infile) {
		if (make == "") {
			cout << "File is empty\n";
			break;
		}
		make = make.substr(make.find(cha) + 2, 200);
		getline(infile, id);
		id = id.substr(id.find(cha) + 2, 200);
		getline(infile, model);
		model = model.substr((model.find(cha) + 2), 200);
		getline(infile, year);
		year= year.substr((year.find(cha) + 2), 200);
		getline(infile, engine);
		engine = engine.substr(engine.find(cha) + 2, 200);
		getline(infile, door);
		door = door.substr((door.find(cha) + 2), 200);
		getline(infile, drive);
		drive = drive.substr((drive.find(cha) + 2), 200);
		getline(infile, fuelType);
		fuelType = fuelType.substr((fuelType.find(cha) + 2), 200);
		getline(infile, trim);
		trim = trim.substr(trim.find(cha) + 2, 200);
		getline(infile, trans);
		trans = trans.substr(trans.find(cha) + 2, 200);
		getline(infile, condition);
		condition = condition.substr(condition.find(cha) + 2, 200);
		getline(infile, price);
		price = price.substr(price.find(cha) + 2, 200);
		getline(infile, inStockSt);
		inStockSt = inStockSt.substr((inStockSt.find(cha) + 2), 200);
		inStock = stoi(inStockSt);
		newCar.setCarInfo(make,id, model, year, engine, door, drive, fuelType, trim, trans, condition, price,inStock); 
		carTree.insert(newCar);
		getline(infile, line);
		getline(infile, make);
		if (make == "")
			break;
	}//end while
}//end createcarTree
void entManualData(carBinaryTree& carTree) {
	string id;
	string make;
	string model;
	string year;
	string engine;
	string door;
	string drive;
	string fuelType;
	string trim;
	string trans;
	string condition;
	string price;
	int inStock;
	string cha = ":";
	string inStockSt;
	carType newCar;
	cout << "Enter Make\n";
	getline(cin, make);
	cout << "Enter id\n";
	getline(cin, id);
	cout << "Enter Model\n";
	getline(cin, model);
	cout << "enter Year\n";
	getline(cin, year);
	cout << "Enter engine\n";
	getline(cin, engine);
	cout << "Enter number of doors\n";
	getline(cin, door);
	cout << "Enter type of Drive\n";
	getline(cin, drive);
	cout << "Enter Fuel type\n";
	getline(cin, fuelType);
	cout << "enter Trim\n";
	getline(cin, trim);
	cout << "Enter type of Transmission\n";
	getline(cin, trans);
	cout << "Enter condition\n";
	getline(cin, condition);
	cout << "Enter quantity of items of this car in existence\n";
	getline(cin, inStockSt);
	inStock = stoi(inStockSt);
	newCar.setCarInfo(make,id, model, year, engine, door, drive, fuelType, trim, trans, condition, price, inStock);
	carTree.insert(newCar);
	//carTree.savecarTree();
}
void displayMenu()
{
	cout << "Select one of the following:" << endl;
	cout << "1: To check whether the store carries a "
		<< "particular car." << endl;
	cout << "2: To check out a car." << endl;
	cout << "3: To check in a car." << endl;
	cout << "4: To print only the make of all the cars."
		<< endl;
	cout << "5: To print a list of all the cars." << endl;
	cout << "6: To save the archive." << endl;
	cout << "6: To introduce data manually\n";
	cout << "7: To create an archive of 100 000 items\n";
	cout << ">=8: To exit" << endl;
}//end displayMenu
void createArchive(carBinaryTree& carTree,string make,int count) {
	int start = 0, numNodes = 0;
	carTree.destroyTree();
	permutation(make, start,make.length()-1, carTree, count,numNodes);
	cout << "Number of cars =  " << numNodes << endl;
}
void swapp(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}
void permutation(string str, int start, int end, carBinaryTree& carTree, int count,int& numNodes) {
	string id;
	string make;
	string model;
	string year;
	string engine;
	string door;
	string drive;
	string fuelType;
	string trim;
	string trans;
	string condition;
	string price;
	int inStock = 1;
	carType newCar;

	int i;
	if (start == end) {
		if (numNodes <= count) {
			numNodes++;
			make = str;
			newCar.setCarInfo(make,id, model, year, engine, door, drive, fuelType, trim, trans, condition, price, inStock);
			carTree.insert(newCar);
		}
	}
	else
	{
		for (i = start; i <= end; i++)
		{
			swapp(str[start], str[i]);
			permutation(str, start + 1, end, carTree, count,numNodes);
			swapp(str[start], str[i]);
		}
	}
}