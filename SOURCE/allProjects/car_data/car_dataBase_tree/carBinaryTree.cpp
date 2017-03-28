#include"carBinaryTree.h"
#include"binarySearchTree.h"
#include"binaryTreeType.h"
#include"carType.h"
#include<string>
#include<fstream>
#include<vector>
using namespace std;


void carBinaryTree::genSearch() {
	int count = 0;
	string make;
	string id;
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
	//int inStock;
	cout << "Enter Make\n";
	getline(cin, make);
	cout << "enter id\n";
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
	int countCar = 0;
	binaryTreeNode<carType>* current = root;
	if (current == NULL) {
		cout << " No cars in archive\n";
		return ;
	}
	genSearchRec(current, count, make, model, year, engine, door, drive, fuelType, trim, trans, condition, price);
	cout << "Number of car encounterd; " << count << endl;
	
}
void carBinaryTree::genSearchRec(binaryTreeNode<carType>* current,int& count,string make, string model, string year, string engine, 
	string door, string drive, string fuelType, string trim, string trans, string condition, string price) {
	if(current){
		if ((current->info.getMake() == make || make == "") && (current->info.getModel() == model || model == "") && 
			(current->info.getYear() == year || year == "") &&(current->info.getEngine()==engine||engine=="") &&
			(current->info.getDoor()==door||door=="")&&(current->info.getDrive()==drive||drive=="")&&(current->info.getFuel()==fuelType||fuelType=="")&&
			(current->info.getTrim() == trim || trim == "") && (current->info.getTrans() == trans || trans == "") && 
			(current->info.getCond() == condition || condition == "") && (current->info.getPrice() == price || price == "")) {
			count+=current->info.getInStock();
			cout << current->info;
		}
		genSearchRec(current->llink,count, make, model, year, engine, door, drive, fuelType, trim, trans, condition, price);
		genSearchRec(current->rlink,count, make, model, year, engine, door, drive, fuelType, trim, trans, condition, price);
	}
}
void carBinaryTree::searchCarList(string make, bool& found, binaryTreeNode<carType>* &current)const
{
	found = false;
	current = root;
	if (current == NULL) //the tree is empty
		cout << "Cannot search an empty tree. " << endl;
	else
	{
		found = false; //set found to false
		while (!found && current != NULL) //search the tree
			if(current->info.getMake()==make)
				found = true;
			else if (current->info.getMake() > make)
				current = current->llink;
			else
				current = current->rlink;
	} //end else
}
void carBinaryTree::searchCarListId(string make,string id, bool& found, binaryTreeNode<carType>* &current)const
{
	found = false;
	current = root;
	if (current == NULL) //the tree is empty
		cout << "Cannot search an empty tree. " << endl;
	else
	{
		found = false; //set found to false
		while (!found && current != NULL) //search the tree
			if (current->info.getId() == id)
				found = true;
			else if (current->info.getMake() > make)
				current = current->llink;
			else
				current = current->rlink;
	} //end else
}
void carBinaryTree::inorderMake(binaryTreeNode<carType> *p)
{
	if (p != NULL)
	{
		inorderMake(p->llink);
		p->info.printMake();
		inorderMake(p->rlink);
	}
}
void carBinaryTree::carPrintMake()
{
	inorderMake(root);
}
bool carBinaryTree::isCarAvailable(string title) const
{
	bool found;
	binaryTreeNode<carType> *location;
	searchCarList(title, found, location);
	if (found)
		found = (location->info.getInStock() > 0);
	else
		found = false;
	return found;
}

void carBinaryTree::carCheckIn(string make,string id)
{
	bool found = false;
	binaryTreeNode<carType> *location;
	searchCarListId(make,id, found, location);
	if (found)
		location->info.checkIn();
	else
		cout << "The store does not carry " << make
		<< endl;
}
void carBinaryTree::carCheckOut(string make,string id)
{
	bool found = false;
	binaryTreeNode<carType> *location;
	searchCarListId(make,id, found, location);
	if (found)
		location->info.checkOut();
	else
		cout << "The store does not carry " << make
		<< endl;
}

bool carBinaryTree::carCheckMake(string make) const
{
	bool found = false;
	binaryTreeNode<carType> *location;
	searchCarList(make, found, location); //search the list
	return found;
}
void carBinaryTree::carUpdateInStock(string make, int num)
{
	bool found = false;
	binaryTreeNode<carType> *location;
	searchCarList(make, found, location); //search the list
	if (found)
		location->info.updateInStock(num);
	else
		cout << "The store does not carry " << make
		<< endl;
}
void carBinaryTree::carSetCarInStock(string make, int num)
{
	bool found = false;
	binaryTreeNode<carType> *location;
	searchCarList(make, found, location);
	if (found)
		location->info.setCopiesInStock(num);
	else
		cout << "The store does not carry " << make
		<< endl;
}
bool carBinaryTree::carSearch(string make) const
{
	bool found = false;
	binaryTreeNode<carType> *location;
	searchCarList(make, found, location);
	return found;	
}
void carBinaryTree::saveCarTree() {
	binaryTreeNode<carType>* current = root;
	ofstream outfile;
	outfile.open(saveAddress);
	savePreorder(current,outfile);
	outfile.close();
	}
void carBinaryTree::saveCarTreeTest() {
	binaryTreeNode<carType>* current = root;
	ofstream outfile;
	outfile.open(saveAddressTest);
	savePreorder(current, outfile);
	outfile.close();
}
	void carBinaryTree::savePreorder( binaryTreeNode<carType>* p,ofstream& outfile)
	{
	if (p != NULL)	{
		outfile << p->info << endl;
		savePreorder(p->llink,outfile);
		savePreorder(p->rlink,outfile);
		}
}
	void carBinaryTree::setSaveAddress(string addInput) {
		saveAddress = addInput;
	}
	void carBinaryTree::setSaveAddressTest(string addInput) {
		saveAddressTest = addInput;
	}


