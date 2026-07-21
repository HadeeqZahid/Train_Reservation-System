#pragma once
#include "LinkedList.h"
#include "TrainClass.h"

class TrainClassManager{
	LinkList<TrainClass> trainClasses;
	
	public:
		void loadFromFile() {
			trainClasses.loadFromFile("TrainClass.dat");
		}
		
		void saveToFile() {
			trainClasses.saveToFile("TrainClass.dat");
		}
		
		void addTrainClass(int cid,string cname) {
			if(trainClasses.find(to_string(cid)) != NULL) {
				cout << "\n\t\t\tError: Class ID already exists!\n";
            	return;
			}
			trainClasses.insert(TrainClass(cid,cname));
			cout << "\n\t\t\tTrain Class added successfully!\n";
		}
		
		void updateTrainClass(int cid,string newName) {
			TrainClass* ptr = trainClasses.find(to_string(cid));
			if(ptr == NULL) {
				cout << "\n\t\t\tError: Class ID not found!\n";
            	return;
			}
			ptr->update(newName);
			cout << "\n\t\t\tClass name updated successfully!\n";
		}
		
		void deleteTrainClass(int cid) {
			if(trainClasses.remove(to_string(cid))) {
				cout << "\n\t\t\tTrain Class deleted successfully!\n";
        	} else {
        	    cout << "\n\t\t\tError: Class ID not found!\n";
        	}
		}
		
		void displayAllTrainClasses() {
			cout << "\n\t\t\tTrain Classes:\n";
        	trainClasses.displayAll();
		}
		
		void displayTrainClass(int cid) {
			TrainClass* ptr = trainClasses.find(to_string(cid));
			if(ptr != NULL) {
				ptr->display();
			} else {
				cout << "\n\t\t\tError: Class ID not found!\n";
			}	
		}

		bool isValidTrainClass(int cid) {
			return trainClasses.find(to_string(cid)) != NULL;
		}
};