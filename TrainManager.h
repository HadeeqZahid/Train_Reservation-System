#pragma once
#include "LinkedList.h"
#include "Train.h"

class TrainManager{
	LinkList<Train> trains;
	
	public:
		void loadFromFile(){
			trains.loadFromFile("Train.dat");
		}
		void saveToFile() {
			trains.saveToFile("Train.dat");
		} 
		
		void addTrain(int id,string name,string src,string dest) {
			if(trains.find(to_string(id)) != NULL) {
				cout << "\n\t\t\t\t\t\tTrain ID already exists!\n";
            	return;
			}
			trains.insert(Train(id,name,src,dest));
			cout << "\n\t\t\t\t\t\tTrain added successfully!\n";
		}
		
		void updateTrain(int id,string newName,string src,string dest) {
			Train* ptr = trains.find(to_string(id));
			if(ptr == NULL) {
				cout << "\n\t\t\t\t\t\tError: Train ID not found!\n";
            	return;
			}
			ptr->updateTrainName(newName,src,dest);
			cout << "\n\t\t\t\t\t\tTrain updated successfully!\n";
		}
		
		void deleteTrain(int id) {
	        if (trains.remove(to_string(id))) {
	            cout << "\n\t\t\t\t\t\tTrain deleted successfully!\n";
	        } else {
	            cout << "\n\t\t\t\t\t\tError: Train ID not found!\n";
	        }
	    }
	    
	    void displayAllTrains() {
	        cout << "\n\t\t\t\t\t\tTrain List:\n";
	        trains.displayAll();
	    }

	    void displayTrain(int id) {
	        Train* ptr = trains.find(to_string(id));
	        if (ptr != NULL) {
	            ptr->display();
	        } else {
	            cout << "\n\t\t\t\t\t\tError: Train ID not found!\n";
	        }
	    }

	    bool isValidTrain(int tid) {
	        return trains.find(to_string(tid)) != NULL;
	    }
};