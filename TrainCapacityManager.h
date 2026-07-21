#include "TrainClassManager.h"
#include "TrainManager.h"
#include "TrainCapacity.h"

class TrainCapacityManager{
	LinkList<TrainCapacity> trainCapacities;
	public:
		void loadFromFile() {
			trainCapacities.loadFromFile("TrainCapacity.dat");
		}
		
		void saveToFile() {
			trainCapacities.saveToFile("TranCapacity.dat");
		}
		
		void addTrainCapacity(int cid,int tid,  int seats, int rate, TrainClassManager& classManager, TrainManager& trainManager) {
			if (!classManager.isValidTrainClass(cid)) {
	            cout << "\n\n\t\t\t\t\t\tClass Id " << cid << " is not Present! Try Again." << endl;
	            return;
	        }

	        if (!trainManager.isValidTrain(tid)) {
	            cout << "\n\n\t\t\t\t\t\tTrain Id " << tid << " is not Present! Try Again." << endl;
	            return;
	        }
	        
	        string key = to_string(cid)+ "_" + to_string(tid);
	        
	        if(trainCapacities.find(key) != NULL) {
	        	cout << "\n\n\t\t\t\t\t\tCombination Already Exists! Try again!" << endl;
	            return;
			}
			
			trainCapacities.insert(TrainCapacity(cid,tid,seats,rate));
			cout << "\n\n\t\t\t\t\t\tTrain Capacity added Successfully!" << endl;
		}
		
		void updateTrainCapacity(int cid,int tid,int seats,int rate) {	
			string key = to_string(cid) + "_" + to_string(tid);
			TrainCapacity* capacity = trainCapacities.find(key);
			if(capacity != NULL) {
				capacity->updateCapacity(seats,rate);
				cout << "\n\n\t\t\t\t\t\tTrain Capacity updated successfully!" << endl;
			} else {
				 cout << "\n\n\t\t\t\t\t\tTrain-Class Combination Not found!" << endl;
			}
		}
		
		void deleteTrainCapacity(int cid,int tid) {
			string key = to_string(cid) + "_" + to_string(tid);
	        if(trainCapacities.remove(key)) {
	            cout << "\n\n\t\t\t\t\t\tTrain Capacity deleted successfully!" << endl;
	        } else {
	            cout << "\n\n\t\t\t\t\t\tTrain-Class Combination Not found!" << endl;
	        }
		}
		
		void displayAllTrainCapacities() {
			cout << "\n\t\t\tTrain Capacities:\n";
			trainCapacities.displayAll();
		}
		
		void displayTrainCapacity(int cid,int tid) {
			string key = to_string(cid) + "_" + to_string(tid);
	        TrainCapacity* capacity = trainCapacities.find(key);
	        if (capacity != NULL) {
	            capacity->display();
	        } else {
	            cout << "\n\n\t\t\t\t\t\tTrain-Class Combination Not found!" << endl;
	        }
		}
		
		bool isValidCombination(int cid,int tid) {
			string key = to_string(cid) + "_" + to_string(tid);
			return trainCapacities.find(key) != NULL;
		}
		
		int getTotalSeatsValue(int cid,int tid) {
			string key = to_string(cid) + "_" + to_string(tid);
			TrainCapacity* capacity = trainCapacities.find(key);
			return capacity->getTotalSeats();
		}
		bool classPresentInCapacity(int cid) {
			Node<TrainCapacity>* temp = trainCapacities.getHead();
			while(temp != NULL) {
				if(temp->data.getCid() == cid) {
					return true;
				}
				temp = temp->next;
			}
			return false;
		}
		
		bool trainPresentInCapacity(int tid) {
			Node<TrainCapacity>* temp = trainCapacities.getHead();
			while(temp != NULL) {
				if(temp->data.getTid() == tid) {
					return true;
				}
				temp = temp->next;
			}
			return false;
		}
};