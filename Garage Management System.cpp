
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class nodeStack
{
	public:
		string plateNum;
		string brand;
		string owner;		
		nodeStack *next;
		
		nodeStack() {
			plateNum = "";
			brand = "";
			owner = "";
		}
		
		nodeStack(string plateNum, string brand, string owner) {
			this->plateNum = plateNum;
			this->brand = brand;
			this->owner = owner;
		}
		
};

class stack
{
	nodeStack *top;
	
	public:
		void createStack() {
			top = NULL;
		}
		
		bool isEmpty() {
			return top == NULL;
		}
		
		void push ();
		void pop ();
		void display();
		void search();
};

void stack::push ()
{
	string newPlateNum, newBrand, newOwner;
	nodeStack *node = new nodeStack;
	
	if (node == NULL)
		cout << "Cannot allocate memory" << endl;
	else
	{
		system("CLS");
		cout << "<<<<<<< Insert Car >>>>>>>" << endl << endl;
		
		// the code to insert new car to the stack. Firstly, ask the 
		//		   user to enter the information of the car which is the plate 
		//		   number, brand/ model and owner's name. 

		cout << "Enter Car Plate Number: ";
		getline(cin, newPlateNum);
		cout << "Enter Car Brand       : ";
		getline(cin, newBrand);
		cout << "Enter Owner Name      : ";
		getline(cin, newOwner);

		node->plateNum = newPlateNum;
		node->brand = newBrand;
		node->owner = newOwner;

		node->next = top;
		top = node;


	}
}

void stack::pop()
{
	nodeStack *delNode;
	
	system("CLS");
	cout << "<<<<<<< Remove Car >>>>>>>" << endl << endl
		 << "Plate Number : " << top->plateNum << endl
	 	 << "Brand/ Model : " << top->brand << endl
	     << "Owner        : " << top->owner << endl << endl;

	cout << "<< Press any key to continue >>";
	cin.get();

	//Task 2 - Write the code to remove the car from the stack 

	delNode = top;
	top = delNode->next;
	delete delNode;
}

void stack::display()
{
	int counter = 1;
	
	nodeStack *currNode; 
	system("CLS");
	cout << "<<<<<<< Display Cars >>>>>>>" << endl << endl;

	//Task 3 - Write the code to display all the cars in the stack 
	

	if(top == NULL){
		cout << "List is Empty" <<endl;
		return;
	}
	currNode = top;
	while(currNode != NULL){
		cout << "Car Plate Number :: " << currNode->plateNum << endl;
		cout << "Car Brand        :: " << currNode->brand << endl;
		cout << "Owner Name       :: " << currNode->owner << endl;
		cout << endl;
		currNode = currNode->next;
	}
	cout << endl;

	//Task 3 end
	
	cout << "<< Press any key to continue >>";
	cin.get();
}

void stack::search()
{
	int choice;
	string input;
	
	nodeStack *currNode; 
	system("CLS");
	
	cout << "<<<<<<< Search Car(s) >>>>>>>" << endl; 

	// The code to search the car in the stack based on brand/  
	//  model 

	if(top == NULL){
		cout << "List is Empty" << endl;
		return;
	}
	cout << "Enter the brand/model that you want to Search :: ";
	getline(cin, input);
	currNode = top;
	while(currNode!= NULL){
		if(currNode->brand == input){
			cout << "The Brand that you search for " << input << " Has Been Founded " << endl;
			cout << "Car Plate Number :: " << currNode->plateNum << endl;
			cout << "Car Brand        :: " << currNode->brand << endl;
			cout << "Owner Name       :: " << currNode->owner << endl;
		}
		currNode = currNode->next;
	}


	cout << "<< Finish searching... Press any key to continue >>";
	cin.get();
}

//To display main menu
void dispMenu()
{
	system("CLS");
	cout << "GARAGE MANAGEMENT SYSTEM" << endl
		 << "\n\t1. Insert car" 
		 << "\n\t2. Remove car" 
		 << "\n\t3. Search car" 
		 << "\n\t4. Display cars" 
		 << "\n\t5. Exit" << endl;		 
}

int main()
{
	stack carRec;
	carRec.createStack();
	int choice;
	
	do
	{
		dispMenu();
		cout << "\nEnter your choice [1-5]: ";
		cin >> choice;
		cin.ignore();
		
		switch(choice)
		{
			case 1: carRec.push();
					break;
			case 2: carRec.pop();
					break;
			case 3: carRec.search();
					break;
			case 4: carRec.display();
					break;
			default: cout << "\nThank you.. see you again.." << endl;
					 return 0;
		}
		
	} while ((choice > 0) && (choice < 5));
	
 	return 0;    
}
