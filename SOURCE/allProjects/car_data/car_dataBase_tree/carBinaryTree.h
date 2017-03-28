#pragma once
#include <iostream>
#include <string>
#include"binaryTreeType.h"
#include "binarySearchTree.h"
#include<fstream>
#include "carType.h"
#include<vector>
using namespace std;
class carBinaryTree :public bSearchTreeType<carType>
{
public:
	bool carSearch(string title)const;
	//Function to search the list to see whether a particular
	//title, specified by the parameter title, is in stock.
	//Postcondition: Returns true if the title is found,
	// false otherwise.
	bool isCarAvailable(string title)const;
	//Function to determine whether at least one copy of a
	//particular car is in stock.
	//Postcondition: Returns true if at least one copy is in
	// stock, false otherwise.
	void carCheckOut(string title,string id);
	//Function to check out a car, that is, rent a car.
	//Postcondition: copiesInStock is decremented by 1.
	void carCheckIn(string make,string id);
	//Function to check in a car returned by a customer.
	//Postcondition: copiesInStock is incremented by 1.
	bool carCheckMake(string title)const;
	//Function to determine whether a particular car is in
	//stock.
	//Postcondition: Returns true if the car is in stock,
	// false otherwise.
	void carUpdateInStock(string title, int num);
	//Function to update the number of copies of a car by
	//adding the value of the parameter num. The parameter title
	//specifies the name of the car for which the number of
	//copies is to be updated.
	//Postcondition: copiesInStock = copiesInStock + num
	void carSetCarInStock(string title, int num);
	//Function to reset the number of copies of a car. The
	//parameter title specifies the name of the car for which
	//the number of copies is to be reset; the parameter num
	//specifies the number of copies.
	//Postcondition: copiesInStock = num
	void carPrintMake();
	//Function to print the titles of all the cars in stock.
	void saveCarTree() ;
	void saveCarTreeTest();
	void savePreorder(binaryTreeNode<carType>* p, ofstream&);
	void setSaveAddress(string addInput);
	void setSaveAddressTest(string addInput);
	void carBinaryTree::genSearch();
	void genSearchRec(binaryTreeNode<carType>* current, int& count, string make, string model, string year, string engine, string door, string drive, string fuelType, string trim, string trans, string condition, string price);
private:
	void searchCarList(string title, bool& found, binaryTreeNode<carType>* &current)const;
	//Function to search the car list for a particular car,
	//specified by the parameter title.
	//Postcondition: If the car is found, the parameter found
	// is set to true, false otherwise. The parameter current
	// points to the node containing the car.
	void inorderMake(binaryTreeNode<carType> *p);
	//Function to print the titles of all the cars in stock.
	void searchCarListId(string make,string id, bool& found, binaryTreeNode<carType>* &current)const;
	string saveAddress;
	string saveAddressTest;
};