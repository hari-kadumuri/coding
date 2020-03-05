// Theatre problem asked in udaan 2019 placement test
// It involves implementating reservation of seats and getting available seats in a row, adding a new screen and getting suggestions seats

// The following are the commands to be given as input to check the complete functionalities of the this program
// 7
// add_screen1_12_10_4_5_9
// reserve_screen1_2_5_6_7
// get-unreserved-seats_screen1_2
// suggest_screen1_3_3_5
// suggest_screen1_3_2_7
// suggest_screen1_3_2_3
// suggest_screen1_3_2_1
#include <bits/stdc++.h>
using namespace std;

struct Seat {
	int seatno;
	bool isaisle = false;
	bool isbooked = false;
};

struct Screen {
	string name;
	int numrows;
	int seatsperrow;
	vector<int> aisleSeatsList;
	vector<vector<Seat>> seats;
};

vector<Screen> Screens;

bool isAisle(int seatno, vector<int> list) {
	for(int i=0;i<list.size();i++) {
		if(seatno==list[i]) return true;
	}
	return false;
}

string addScreen(string exp) {
	string scname;
	int i=0;
	while(exp[i]!='_' && i<exp.size())
		i++;
	i++;
	if(i>=exp.size())
		return "failure";
	while(exp[i]!='_' && i<exp.size()) {
		scname.push_back(exp[i]);
		i++;
	}
	i++;
	if(i>=exp.size())
		return "failure";
	int numrows = 0;
	while(exp[i]!='_' && i<exp.size()) {
		numrows = numrows*10+exp[i]-'0';
		i++;
	}
	i++;
	if(i>=exp.size())
		return "failure";
	int seatsperrow = 0;
	while(exp[i]!='_' && i<exp.size()) {
		seatsperrow = seatsperrow*10+exp[i]-'0';
		i++;
	}
	i++;
	if(i>=exp.size())
		return "failure";
	Screen screen;
	screen.name = scname;
	screen.numrows = numrows;
	screen.seatsperrow = seatsperrow;
	vector<int> aisleSeatsList;
	int val = 0;
	while(i<exp.size()) {
		if(exp[i]!='_') {
			val = val*10+exp[i]-'0';
		}
		else {
			aisleSeatsList.push_back(val);
			val = 0;
		}
		i++;
	}
	aisleSeatsList.push_back(val);
	screen.aisleSeatsList = aisleSeatsList;
	for(int i=0;i<numrows;i++) {
		vector<Seat> row;
		for(int j=0;j<seatsperrow;j++) {
			Seat newseat;
			newseat.seatno = j+1;
			if(isAisle(j+1, aisleSeatsList))
				newseat.isaisle = true;
			row.push_back(newseat);
		}
		(screen.seats).push_back(row);
	}
	Screens.push_back(screen);
	return "success";
}

string reserveSeats(string exp) {
	string scname;
	int i=0;
	while(exp[i]!='_' && i<exp.size())
		i++;
	i++;
	if(i>=exp.size())
		return "failure";
	while(exp[i]!='_' && i<exp.size()) {
		scname.push_back(exp[i]);
		i++;
	}
	i++;
	if(i>=exp.size())
		return "failure";
	int row = 0;
	while(exp[i]!='_' && i<exp.size()) {
		row = row*10+exp[i]-'0';
		i++;
	}
	i++;
	if(i>=exp.size())
		return "failure";
	vector<int> seatsList;
	int val = 0;
	while(i<exp.size()) {
		if(exp[i]!='_') {
			val = val*10+exp[i]-'0';
		}
		else {
			seatsList.push_back(val);
			val = 0;
		}
		i++;
	}
	seatsList.push_back(val);
	// cout<<"scname = "<<scname<<endl;
	// cout<<"row = "<<row<<endl;
	// cout<<"seats requested: ";
	for(int i=0;i<seatsList.size();i++) {
		cout<<seatsList[i]<<" ";
	}
	int idx;
	for(idx = 0;idx<Screens.size();idx++) {
		if(Screens[i].name.compare(scname))
			break;
	}
	cout<<endl;
	if(idx==Screens.size()) return "failure";
	for(int i=0;i<seatsList.size();i++)
		if((Screens[idx].seats)[row-1][seatsList[i]-1].isbooked) return "failure";
	for(int i=0;i<seatsList.size();i++)
		(Screens[idx].seats)[row-1][seatsList[i]-1].isbooked = true;
	return "success";
}

void getSeats(string exp) {
	string scname;
	int i=0;
	while(exp[i]!='_' && i<exp.size())
		i++;
	i++;
	if(i>=exp.size()) {
		cout<<1;
		return;
	}
	while(exp[i]!='_' && i<exp.size()) {
		scname.push_back(exp[i]);
		i++;
	}
	i++;
	if(i>=exp.size()) {
		cout<<2;
		return;
	}
	int row = 0;
	while(exp[i]!='_' && i<exp.size()) {
		row = row*10+exp[i]-'0';
		i++;
	}
	i++;
	// cout<<"scname = "<<scname<<endl;
	// cout<<"row = "<<row<<endl;
	int idx;
	for(idx = 0;idx<Screens.size();idx++) {
		if(Screens[i].name.compare(scname))
			break;
	}
	cout<<endl;
	if(idx==Screens.size()) return;
	for(int i=0;i<Screens[idx].seatsperrow;i++)
		((!(Screens[idx].seats)[row-1][i].isbooked)?cout<<i+1<<" ":cout<<"");
	cout<<endl;
}

void suggest(string exp) {
	string scname;
	int i=0;
	while(exp[i]!='_' && i<exp.size())
		i++;
	i++;
	if(i>=exp.size()) {
		cout<<1;
		return;
	}
	while(exp[i]!='_' && i<exp.size()) {
		scname.push_back(exp[i]);
		i++;
	}
	i++;
	if(i>=exp.size()) {
		cout<<2;
		return;
	}
	int numseats = 0;
	while(exp[i]!='_' && i<exp.size()) {
		numseats = numseats*10+exp[i]-'0';
		i++;
	}
	i++;
	if(i>=exp.size()) {
		cout<<3;
		return;
	}
	int row = 0;
	while(exp[i]!='_' && i<exp.size()) {
		row = row*10+exp[i]-'0';
		i++;
	}
	i++;
	if(i>=exp.size()) {
		cout<<4;
		return;
	}
	int seatno = 0;
	while(exp[i]!='_' && i<exp.size()) {
		seatno = seatno*10+exp[i]-'0';
		i++;
	}
	i++;
	// cout<<"scname = "<<scname<<endl;
	// cout<<"numseats = "<<numseats<<endl;
	// cout<<"row = "<<row<<endl;
	// cout<<"seatno = "<<seatno<<endl;
	int idx;
	for(idx = 0;idx<Screens.size();idx++) {
		if(Screens[i].name.compare(scname))
			break;
	}
	if(idx==Screens.size()) return;
	vector<Seat> rowptr = (Screens[idx].seats)[row-1];
	bool flag = true;
	//forward checking
	for(int i=0;i<numseats;i++) {
		if(seatno-1+i>=rowptr.size() || rowptr[seatno-1+i].isbooked || (rowptr[seatno-1+i].isaisle && i<numseats-1)) {
			flag = false;
			break;
		}
	}
	if(flag) {
		for(int i=0;i<numseats;i++)
			cout<<seatno+i<<" ";
		cout<<endl;
		return;
	}
	//backward checking
	else {
		flag = true;
		for(int i=0;i<numseats;i++) {
			if(seatno-1-i<0 || rowptr[seatno-1-i].isbooked || (rowptr[seatno-1-i].isaisle && i<numseats-1)) {
				flag = false;
				break;
			}
		}
		if(flag) {
			for(int i=numseats-1;i>=0;i--)
				cout<<seatno-i<<" ";
			cout<<endl;
			return;
		}
		else
			cout<<"none"<<endl;
	}
}

void evaluate(string exp) {
	switch(exp[0]) {
		case 'a':
			cout<<addScreen(exp)<<endl;
			break;
		case 'r':
			cout<<reserveSeats(exp)<<endl;
			break;
		case 'g':
			getSeats(exp);
			break;
		case 's':
			suggest(exp);
			break;
	}
}

void printScreen(Screen screen) {
	cout<<"Screen name: "<<screen.name<<endl;
	cout<<"numrows: "<<screen.numrows<<endl;
	cout<<"seatsperrow: "<<screen.seatsperrow<<endl;
	cout<<"aisleSeatsList: ";
	for(int i=0;i<screen.aisleSeatsList.size();i++)
		cout<<screen.aisleSeatsList[i]<<" ";
	cout<<endl;
	for(int i=0;i<screen.numrows;i++) {
		for(int j=0;j<screen.seatsperrow;j++)
			cout<<"<"<<(screen.seats)[i][j].seatno<<", "<<(screen.seats)[i][j].isbooked<<", "<<(screen.seats)[i][j].isaisle<<"> ";
		cout<<endl;
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	while(n-->0) {
		string exp;
		cin>>exp;
		cout<<"exp = "<<exp<<endl;
		evaluate(exp);
		cout<<"\nPrinting current state:"<<endl<<endl;
		printScreen(Screens[0]);	
	}
	return 0;
}