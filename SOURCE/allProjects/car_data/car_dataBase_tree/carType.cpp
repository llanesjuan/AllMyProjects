#include"carType.h"
using namespace std;
#include<string>


void carType::setCarInfo(string make,string id, string model, string year, string engine, 
	string door, string drive, string fuelType, string trim, string trans, 
	string condition, string price, int setInStock)
{
	carMake = make;
	carId = id;
	carModel = model;
	carYear = year;
	carEngine = engine;
	carDoor = door;
	carDrive = drive;
	carFuelType = fuelType;
	carTrim = trim;
	carTrans = trans;
	carCondition = condition;
	carPrice = price;
	carInStock = setInStock;
}
void carType::checkOut()
{
	//if (getNoOfCopiesInStock() > 0)
	if(getInStock()>0)
		carInStock--;
	else
		cout << "Currently out of stock" << endl;
}
void carType::checkIn()
{
	carInStock++;
}
//int carType::getNoOfCopiesInStock() const
//{
//	return carInStock;
//}
void carType::printMake() const
{
	cout << "car Make: " << carMake << endl;
}
void carType::printInfo() const
{
	cout << "car Make: " << carMake << endl;
	cout << "Car id: " << carId << endl;
	cout << "Model: " << carModel << " Year: " << carYear << endl;
	cout << "Engine: " << carEngine<< endl;
	cout << "Doors: " << carDoor << endl;
	cout << "Drive: " << carDrive << endl;
	cout << "Fuel: " << carFuelType << endl;
	cout << "Trim: " << carTrim<<"Transmission: "<<carTrans<<"Condition: "<<carCondition<<"Price: "<<carPrice << endl;
	cout << "Copies in stock: " << carInStock
		<< endl;
}
bool carType::checkTitle(string make)
{
	bool findTitle = true;
	for (int i = 0; i < carMake.length(); i++) {
		if (tolower(carMake[i]) != tolower(make[i])) {
			findTitle = false;
			break;
		}
	}
	return findTitle;
	//return(tolower(dvdTitle) == tolower(title));
}
void carType::updateInStock(int num)
{
	carInStock += num;
}
void carType::setCopiesInStock(int num)
{
	carInStock = num;
}
string carType::getMake() const
{
	return carMake;
}
carType::carType(string carMake,string carId,string carModel,string carYear,
	string carEngine,string carDoor,string carDrive,string carFuelType,
	string carTrim,string carTrans,string carCondition,string carPrice,
int carInStock)
{
	setCarInfo(carMake,carId, carModel, carYear,carEngine, carDoor, carDrive, carFuelType, carTrim,carTrans, carCondition,  carPrice,carInStock );
	
}


bool carType::operator==(const carType& other) const
{
	return (carMake == other.carMake);
}
bool carType::operator!=(const carType& other) const
{
	return (carMake != other.carMake);
}
bool carType::operator <(const carType& right) const
{
	return (carMake < right.carMake);
}
bool carType::operator <=(const carType& right) const
{
	return (carMake <= right.carMake);
}
bool carType::operator >(const carType& right) const
{
	return (carMake > right.carMake);
}
bool carType::operator >=(const carType& right) const
{
	return (carMake >= right.carMake);
}



ostream& operator<< (ostream& osObject, const carType& car)
{
	osObject <<"Make: "<< car.carMake << endl;
	osObject << "Id: "<<car.carId << endl;
	osObject << "Model: "<<car.carModel<< endl;
	osObject << "Year: "<<car.carYear << endl;
	osObject << "Engine: "<<car.carEngine << endl;
	osObject << "Door: "<<car.carDoor << endl;
	osObject << "Drive: "<<car.carDrive<< endl;
	osObject << "Fuel_Type: "<<car.carFuelType << endl;
	osObject << "Trim: "<<car.carTrim << endl;
	osObject << "Transmission: "<<car.carTrans << endl;
	osObject << "Condition: "<<car.carCondition << endl;
	osObject << "Price: "<<car.carPrice << endl;
	osObject << "In_Stock: "<<to_string(car.carInStock) << endl;
	return osObject;
}
string carType::getMake() {
	return carMake;
}
string carType::getId() {
	return carId;
}
string carType::getModel() {
	return carModel;
}
string carType::getYear() {
	return carYear;
}
string carType::getEngine() {
	return carEngine;
}
string carType::getDoor() {
	return carDoor;
}
string carType::getDrive() {
	return carDrive;
}
string carType::getFuel() {
	return carFuelType;
}
string carType::getTrim() {
	return carTrim;
}
string carType::getTrans() {
	return carTrans;
}
string carType::getCond() {
	return carCondition;
}
string carType::getPrice() {
	return carPrice;
}
int carType::getInStock() {
	return carInStock;
}