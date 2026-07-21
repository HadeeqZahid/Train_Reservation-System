#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Reservation{
	int cid;
	int tid;
	int ticketNo;
	string date;
	string CNIC;
	string passengerName;
	public:
		Reservation() {
			cid = tid = ticketNo = 0;
			date = CNIC = passengerName = "";
		}
		Reservation(int cid,int tid,int ticketNo,string date,string CNIC,string name) {
			this->cid = cid;
			this->tid = tid;
			this->ticketNo = ticketNo;
			this->date = date;
			this->CNIC = CNIC;
			this->passengerName = name;
		}
		
		int getCid() {
			return cid;
		}
    	int getTid() {
    		return tid;
		}
    	int getTicketNo(){
    		return ticketNo;
		}
    	string getDate() {
    		return date;
		}
    	string getCNIC() {
    		return CNIC;
		}
    	string getPassengerName() {
    		return passengerName;
		}
		
		void updateReservation(string newCNIC,string newName) {
			CNIC = newCNIC;
			passengerName = newName;
		}
		
		void display() {
			cout<<"\n\n\t\t\t\t\t\tTrain Class ID = "<<cid<<", Train ID = "<<tid<<"\n\n\t\t\t\t\t\tTicket No = "<<ticketNo
			<<", Passenger Name = "<<passengerName<<", CNIC = "<<CNIC<<endl;
		}
		
		void writeToFile(ofstream& out) {
			out.write(reinterpret_cast<const char*>(&cid),sizeof(cid));
			out.write(reinterpret_cast<const char*>(&tid),sizeof(tid));
			out.write(reinterpret_cast<const char*>(&ticketNo),sizeof(ticketNo));
			
			int len = date.size();
			out.write(reinterpret_cast<char*>(&len),sizeof(len));
			out.write(date.c_str(),len);
			
			len = CNIC.size();
			out.write(reinterpret_cast<const char*>(&len),sizeof(len));
			out.write(CNIC.c_str(),len);
			
			len = passengerName.size();
			out.write(reinterpret_cast<const char*>(&len),sizeof(len));
			out.write(passengerName.c_str(),len);
		}
		
		bool readFromFile(ifstream& in) {
			if (!in.read(reinterpret_cast<char*>(&cid), sizeof(cid))){
	            return false;
			}
			if (!in.read(reinterpret_cast<char*>(&tid), sizeof(tid))){
	            return false;
			}
			if (!in.read(reinterpret_cast<char*>(&ticketNo), sizeof(ticketNo))){
	            return false;
			}
			
			int len;
	        char* buffer;

		    in.read(reinterpret_cast<char*>(&len), sizeof(len));
	        buffer = new char[len + 1];
	        in.read(buffer, len);
		    buffer[len] = '\0';
	        date = string(buffer);
	        delete[] buffer;

	        in.read(reinterpret_cast<char*>(&len), sizeof(len));
	        buffer = new char[len + 1];
	        in.read(buffer, len);
	        buffer[len] = '\0';
	        CNIC = string(buffer);
	        delete[] buffer;

	        in.read(reinterpret_cast<char*>(&len), sizeof(len));
	        buffer = new char[len + 1];
	        in.read(buffer, len);
	        buffer[len] = '\0';
	        passengerName = string(buffer);
	        delete[] buffer;

	        return true;
		}
		
		bool operator<(Reservation& other) {
        	return tid < other.tid;
    	}
    	
    	string getKey() {
    		return to_string(cid) + "_" + to_string(tid) + "_" + to_string(ticketNo) + "_" + date;
		}
		
};