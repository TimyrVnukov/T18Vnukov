#include <iostream>
#include <iterator>
#include <list>
using namespace std;
#include "CarTaxi.h"
void showlist(list<CarTaxi> myList)
{
	list<CarTaxi>::iterator it;
	for (it = myList.begin(); it != myList.end(); ++it){
		it->showInfo();
	}
	cout << '\n';
}
void addItemIn(list<CarTaxi> myList, string beforeId, CarTaxi newCar) {
	list<CarTaxi>::iterator it;
	list<CarTaxi> tmp;
	for (it = myList.begin(); it != myList.end(); ++it) {
		if (it->getId() == beforeId) {
			tmp.push_back(newCar);
			newCar.showInfo();
		}
		tmp.push_back(*it);
		it->showInfo();
	}
	myList = tmp;
	
}
void delItem(list<CarTaxi> myList, string id)
{
	list<CarTaxi>::iterator it;
	for (it = myList.begin(); it != myList.end(); ++it) {
		if (it->getId() == id) {
			myList.erase(it);
			break;
		}
	}
}
void goTaxi(list<CarTaxi> myList, string id) {
	list<CarTaxi>::iterator it;
	for (it = myList.begin(); it != myList.end(); ++it) {
		if (it->getId() == id) {
			it->setIsFree(false);
			break;
		}
	}
}
void backTaxi(list<CarTaxi> myList, string id) {
	list<CarTaxi>::iterator it;
	for (it = myList.begin(); it != myList.end(); ++it) {
		if (it->getId() == id) {
			it->setIsFree(true);
			break;
		}
	}
}
void showInfobyType(list<CarTaxi> myList, bool isFree) {
	list<CarTaxi>::iterator it;
	for (it = myList.begin(); it != myList.end(); ++it) {
		if (it->getIsFree() == isFree) {
			it->showInfo();
		}
	}
	cout << '\n';
}
int main() {
	setlocale(0, "UKR");
	list<CarTaxi> Taxi;

	Taxi.push_back(CarTaxi("HF83WN", "mark1", "Name1", true));
	Taxi.push_back(CarTaxi("4WTMMW", "mark2", "Name2", true));
	Taxi.push_back(CarTaxi("76GBT4", "mark3", "Name3", false));
	Taxi.push_back(CarTaxi("M98JT5", "mark4", "Name4", true));
	auto it = Taxi.begin();
	//listt.erase(it);

	string id, beforeId, mark, name;
	bool isFree;
	int menu, seconMenu;
	do
	{
		cout << "1: вывод всех такси" << endl;
		cout << "2: добавление такси в начало списка" << endl;
		cout << "3: добавление такси перед определенным такси" << endl;
		cout << "4: удаление выбранного такси" << endl;
		cout << "5: при выезде каждого такси вводится номер такси, и программа устанавливает значение признака «такси на вызове»" << endl;
		cout << "6: при освобождении такси вводится номер такси, и программа устанавливает значение признака «такси свободное»" << endl;
		cout << "7: по запросу выдаются сведения о свободных такси, или о такси, находящихся на выезде" << endl;
		cin >> menu;
		system("CLS");
		switch (menu)
		{
		case 1:
			it = Taxi.begin();
			showlist(Taxi);
			break;
		case 2:
			cout << "id: "; cin >> id;
			cout << "mark: "; cin >> mark;
			cout << "name: "; cin >> name;
			cout << "isFree: "; cin >> isFree;
			Taxi.push_front(CarTaxi(id, mark, name, isFree));
			break;
		case 3:
			cout << "~~~New car~~~" << endl;
			cout << "id: "; cin >> id;
			cout << "mark: "; cin >> mark;
			cout << "name: "; cin >> name;
			cout << "isFree: "; cin >> isFree;
			cout << "~~~Before car~~~" << endl;
			cout << "id: "; cin >> beforeId;
			addItemIn(Taxi, beforeId, CarTaxi(id, mark, name, isFree));
			break;
		case 4:
			cout << "id: "; cin >> id;
			delItem(Taxi, id);
			break;
		case 5:
			cout << "id: "; cin >> id;
			goTaxi(Taxi, id);
			break;
		case 6:
			cout << "id: "; cin >> id;
			backTaxi(Taxi, id);
			break;
		case 7:
			cout << "0: wait" << endl;
			cout << "1: free" << endl;
			cin >> seconMenu;
			switch (seconMenu)
			{
			case 0:
				showInfobyType(Taxi, false);
				break;
			case 1:
				showInfobyType(Taxi, true);
				break;
			default:
				break;
			}
		default:
			break;
		}
	} while (menu);
}