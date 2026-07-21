#include "Reservation.h"
#include "TrainCapacityManager.h"
#include "LinkedList.h"
bool isDigit(char c) {
	if(c >= '0' && c <= '9') {
		return true;   
	}
	return false;
}
bool isValidCNIC(string& cnic) {
	if(cnic.length() != 13) {
		return false;
	}
	for(char c:cnic) {
		if(!isDigit(c)) {
			return false;
		}
	}
	return true;
}
bool isValidPassengerName(string& name) {
	if(name.empty() ) {
		return false;
	}
	for(char c:name ) {
		if(!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') && (c != ' ')) {
			return false;
		}
	}
	return true;
}
bool isValidDate(string& date) {
	if(date.length() != 10 || date[2] != '/' || date[5] != '/') {
		return false;
	}
	if(	!(isDigit(date[0])) || !(isDigit(date[1])) || 
		!(isDigit(date[3])) || !(isDigit(date[4])) ||
		!(isDigit(date[6])) || !(isDigit(date[7])) ||
		!(isDigit(date[8])) || !(isDigit(date[9])) ) {
		
		return false;
	}
	
	int day = (date[0] - '0')* 10 + (date[1]-'0');
	int month = (date[3] - '0') * 10 + (date[4] - '0');
	int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');  
	
	if(month < 1 || month > 12 || day < 1 || day > 31 ) {
		return false;
	}
	
	return true;
}

class ReservationManager{
	LinkList<Reservation> reservations;
	public:
		void loadFromFile() {
			reservations.loadFromFile("reservation.dat");
		}	
		void saveToFile() {
			reservations.saveToFile("reservation.dat");
		}
		
		int totalSeatsReserved(int cid,int tid,string date)  {
			int count;
			Node<Reservation>* temp = reservations.getHead();
			while(temp != NULL) {
				if(temp->data.getCid() == cid && temp->data.getTid() == tid && temp->data.getDate() == date) {
					count++;
				}
				temp = temp->next;
			}
			return count;
		}
		int totalSeatsAvailable(int cid,int tid,string date,TrainCapacityManager& capacityManager) {
			int totalSeats = capacityManager.getTotalSeatsValue(cid,tid);
			int reserved = totalSeatsReserved(cid,tid,date);
			return max(0,totalSeats - reserved);
		}
		
		void addReservation(int cid,int tid,string date,string cnic,string name,TrainCapacityManager& capacityManager) {
			int availableSeats = totalSeatsAvailable(cid,tid,date,capacityManager);
			if(availableSeats <= 0) {
				cout<<"\n\n\t\t\t\t\t\tNo seats available for this Train class on thr given date."<<endl;
				return;
			}
			int ticketNo = 1;
			Node<Reservation>* temp = reservations.getHead();
			while(temp != NULL) {
				if(temp->data.getCid() == cid && temp->data.getTid() == tid && temp->data.getDate() == date) {
					ticketNo = max(ticketNo,temp->data.getTicketNo() + 1);
				}
				temp = temp->next;
			}
			
			reservations.insert(Reservation(cid,tid,ticketNo,date,cnic,name));
			cout<<"\n\n\t\t\t\t\t\tReservation Successfully! "<<endl;
			cout<<"\n\n\t\t\t\t\t\tYour Ticket Number = "<<ticketNo<<endl;
		}
		
		void updateReservation(int cid,int tid,int ticketNo,string date,string newCNIC,string newName) {
			string key = to_string(cid) + "_" + to_string(tid) + "_" + to_string(ticketNo) + "_" + date;
			Reservation* r = reservations.find(key);
			if(r != NULL) {
				r->updateReservation(newCNIC,newName);
				cout<<"\n\n\t\t\t\t\t\tReservation Updated Successfully!"<<endl;
				return;
			} else {
				cout<<"\n\n\t\t\t\t\t\tNo Reservation Found with ticket No "<<ticketNo<<" On "<<date<<endl;
			}
		}
		
		void deleteReservation(int cid,int tid,int ticketNo,string date) {
			string key = to_string(cid) + "_" + to_string(tid) + "_" + to_string(ticketNo) + "_" + date;
			if(reservations.remove(key)) {
				cout<<"\n\n\t\t\t\t\t\tReservation for Ticket No "<<ticketNo<<" on "<<date<<" has been canceled!" << endl;
				return;
			} else {
				cout<<"\n\n\t\t\t\t\t\tNo Reservation Found with ticket No "<<ticketNo<<" On "<<date<<endl;
			}
		}
		
		void displayAllReservations() {
			cout << "\n\n\t\t\t\t\t\tAll Reservations:\n";
			reservations.displayAll();
		}
		
		void displayReservation(int cid,int tid,int ticketNo,string date) {
			string key = to_string(cid) + "_" + to_string(tid) + "_" + to_string(ticketNo) + "_" + date;
			Reservation* r = reservations.find(key);
			if(r != NULL) {
				r->display();
				return;
			} else {
				cout<<"\n\n\t\t\t\t\t\tNo Reservation Found with ticket No "<<ticketNo<<" On "<<date<<endl;
			}
		}
		
		bool capacityPresentInReservation(int cid,int tid) {
			Node<Reservation>* temp = reservations.getHead();
			while(temp != NULL) {
				if(temp->data.getCid() == cid && temp->data.getTid() == tid) {
					return true;
				}
				temp = temp->next;
			}
			return false;
		}
};