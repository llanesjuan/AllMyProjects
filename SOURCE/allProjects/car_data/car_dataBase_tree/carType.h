#pragma once
//************************************************************
// Author: Juan Alberto LLanes
//
// class carType
// This class specifies the members of car.
//************************************************************
#ifndef H_carType
#define H_carType
#include <iostream>
#include <string>
using namespace std;


class carType
{
	friend ostream& operator<< (ostream&, const carType&);
public:
	void setCarInfo(string make,string id,string model,string year, string engine,string door,string drive,string fuelType,string trim,string trans,string condition,	string price,int setInStock);
	//Function to set the details of a car.
	//The member variables are set according to the
	//parameters.
	//Postcondition: carMake = make; carModel = model;
	// carYear = year; carEngine = engine; 
	// carDoor = door;carDrive = drive;carFuelType = fuelType;carTrim = trim;carTrans = trans;carCondition = condition;carPrice = price;
	// copiesInStock = setInStock;	
	void checkOut();
	//Function to rent a car.
	//Postcondition: The number of copies in stock is
	// decremented by one.
	void checkIn();
	//Function to check in a car.
	//Postcondition: The number of copies in stock is
	// incremented by one.
	void printMake() const;
	//Function to print the title of a car.
	void printInfo() const;
	//Function to print the details of a car.
	//Postcondition: The make of the car, model,
	// year, and so on are displayed
	// on the screen.
	bool checkTitle(string title);
	//Function to check whether there is 
	//make of the car in dataBase
	//Postcondition: Returns the value true if there is
	// false otherwise.
	void updateInStock(int num);
	//Function to increment the number of copies in stock by
	//adding the value of the parameter num.
	//Postcondition: copiesInStock = copiesInStock + num;
	void setCopiesInStock(int num);
	//Function to set the number of copies in stock.
	//Postcondition: copiesInStock = num;	
	carType(string carMake = "",string carId="", string carModel = "",
		string carYear = "", string carEngine = "", string carDoor = "", string carDrive = "",
		string fuelType = "", string carTrim = "",string carTrans = "",string carCondition = "", string carPrice = "", int setInStock = 0);
	//constructor
	//The member variables are set according to the
	//incoming parameters. If no values are specified, the
	//default values are assigned.
	//Postcondition: carMake = make; carModel = model;
	// carYear = year; carEngine = engine; 
	// carDoor = door;carDrive = drive;carFueltype = fuelType;carTrim = trim;carTrans = trans;carCondition = condition;carPrice = price;
	// copiesInStock = setInStock;
	//Overload the relational operators.
	bool operator==(const carType&) const;
	bool operator!=(const carType&) const;
	bool operator<(const carType&) const;
	bool operator<=(const carType&) const;
	bool operator>(const carType&) const;
	bool operator>=(const carType&) const;
	string getMake() const;
	//Postcondition: The make of the car is returned.
	//Function to return the make of the car.
	//int getNoOfCopiesInStock() const;
	//Function to check the number of copies in stock.
	//Postcondition: The value of copiesInStock is returned.
	string getId();
	string getMake();
	string getModel();
	string getYear();
	string getEngine();
	string getDoor();
	string getDrive();
	string getFuel();
	string getTrim();
	string getTrans();
	string getCond();
	string getPrice();
	int getInStock();
private:
	string carId;
	string carMake; //variable to store brandname
	string carModel; //variable to store the amodel
	string carYear; //variable to store the year
	string carEngine; //variable to store how many cylinders
	string carDoor; //variable to store amount of doors
	string carDrive; //variable to store front or rear drive
	string carFuelType;// variable to store gas or diesel
	string carTrim; //variable to store trin classification
	string carTrans;//variable to store type of transmission
	string carCondition;//variable to store condition of car
	string carPrice; //variable to store the price
	int carInStock;
};
#endif