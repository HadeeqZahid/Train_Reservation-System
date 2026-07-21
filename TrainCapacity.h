#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class TrainCapacity {
	int cid;
	int tid;
	int totalSeats;
	int rate;
	
	public:
		TrainCapacity() {
			cid = 0;
			tid = 0;
			totalSeats = 0;
			rate = 0;
		}
		TrainCapacity(int cid,int tid,int ts,int r) {
			this->cid = cid;
			this->tid = tid;
			totalSeats = ts;
			rate = r;
		}
		
		int getCid() {
			return cid;
		}
		
		int  getTid() {
			return tid;
		} 
		
		int getTotalSeats() {
			return totalSeats;
		}
		
		int getRate() {
			return rate;
		}
		
		void updateCapacity(int seats,int ticketRate) {
			totalSeats = seats;
			rate = ticketRate;
		}
		
		void display () {
			cout<<"\n\n\t\t\t\t\t\tTrain Class ID = "<<cid<<", Train ID = "<<tid<<"\n\n\t\t\t\t\t\tTotal Seats = "<<totalSeats<<", Ticket Rate = "<<rate<<endl;

		}
		
		void writeToFile(ofstream& out) {
			out.write(reinterpret_cast<const char*>(&cid),sizeof(cid));
			out.write(reinterpret_cast<const char*>(&tid),sizeof(tid));
			out.write(reinterpret_cast<const char*>(&totalSeats),sizeof(totalSeats));
			out.write(reinterpret_cast<const char*>(&rate),sizeof(rate));
		}
		
		bool readFromFile(ifstream& in) {
			if (!in.read(reinterpret_cast<char*>(&cid), sizeof(cid))){
	            return false;
			}
			if (!in.read(reinterpret_cast<char*>(&tid), sizeof(tid))){
	            return false;
			}
			if (!in.read(reinterpret_cast<char*>(&totalSeats), sizeof(totalSeats))){
	            return false;
			}
			if (!in.read(reinterpret_cast<char*>(&rate), sizeof(rate))){
	            return false;
			}
			
			return true;
		}
		
		string getKey() const {
			return to_string(cid) + "_" + to_string(tid);
		}
		bool operator<(TrainCapacity& other) {
        	return tid < other.tid;
    	}

};