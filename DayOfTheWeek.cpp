#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// using 01/01/2000(saturday) as reference to measure days


struct date {
	int d, m, y;
	date(int d, int m, int y) {
		this->d = d;
		this->m = m;
		this->y = y;
	}
	void operator ++ () {
		this->d+1;
	}
	bool operator > (date d2) {
		if(y>d2.y)
			return true;
		else if(y<d2.y)
			return false;
		else {
			if(m>d2.m)
				return true;
			else if(d2.m>m)
				return false;
			else {
				if(d>d2.d)
					return true;
				else
					return false;
			}
		}
	}
};

date increment(date curr) {
	if(curr.m==12) {
		if(curr.d==31)
			return date(1, 1, curr.y+1);
		return date(curr.d+1, curr.m, curr.y);
	}
	else if(curr.m==2) {
		if(curr.y%4==0) {
			if(curr.d==29)
				return date(1, curr.m+1, curr.y);
			return date(curr.d+1, curr.m, curr.y);
		}
		else {
			if(curr.d==28)
				return date(1, curr.m+1, curr.y);
			return date(curr.d+1, curr.m, curr.y);
		}
	}
	else if(curr.m==1 || curr.m==3 || curr.m==5 || curr.m==7 || curr.m==8 || curr.m==10) {
		if(curr.d==31)
			return date(1, curr.m+1, curr.y);
		return date(curr.d+1, curr.m, curr.y);
	}
	else {
		if(curr.d==30)
			return date(1, curr.m+1, curr.y);
		return date(curr.d+1, curr.m, curr.y);
	}
	return date(0, 0, 0);
}

int getDaysDiff(date post) {
	date pre = date(1, 1, 2000);
	bool flag = false;
	if(pre > post) {
		flag = true;
		date temp = post;
		post = pre;
		pre = temp;
	}
	int count = 0;
	date current = pre;
	while(post > current) {
		count++;
		current = increment(current);
	}
	if(flag) count *= -1;
	return count;
}

string getDay(date dt) {
	int daysDiff = getDaysDiff(dt);
	string day;
	switch(daysDiff%7) {
		case 0:
			day = "Saturday";
			break;
		case 1:
			day = "Sunday";
			break;
		case 2:
			day = "Monday";
			break;
		case 3:
			day = "Tuesday";
			break;
		case 4:
			day = "Wednesday";
			break;
		case 5:
			day = "Thursday";
			break;
		case 6:
			day = "Friday";
			break;
		case -1:
			day = "Friday";
			break;
		case -2:
			day = "Thursday";
			break;
		case -3:
			day = "Wednesday";
			break;
		case -4:
			day = "Tuesday";
			break;
		case -5:
			day = "Monday";
			break;
		case -6:
			day = "Sunday";
			break;
		default:
			day = "invalid date";
			break;
	}
	return day;
}

bool isValid(date dt) {
	if(dt.d<0 || dt.m<0 || dt.m>12 || dt.y<0) return false;
	if(dt.m==1 || dt.m==3 || dt.m==5 || dt.m==7 || dt.m==8 || dt.m==10 || dt.m==12) {
		if(dt.d<31)
			return true;
		else
			return false;
	}
	else {
		if(dt.d<32)
			return true;
		else
			return false;
	}
}

int main(int argc, char const *argv[])
{
	int T, d, m, y;
	cout<<"enter number of testcases: ";
	cin>>T;
	while(T-->0) {
		cout<<"enter date, month and year: ";
		cin>>d>>m>>y;
		date dt = date(d, m, y);
		string day = (isValid(dt)?getDay(dt):"Invalid Date");
		cout<<day<<endl;
	}
	return 0;
}