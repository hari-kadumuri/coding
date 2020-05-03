#include <bits/stdc++.h>
using namespace std;

long computePeriods(vector<int> arr, int k) {
	vector<pair<int, pair<int, int>>> periods;
	bool flag = (arr[1]-arr[0]>=0?true:false);
	int start = (flag?0:-1), end = -1, sum = (flag?arr[0]:0);
	for(int i=1;i<arr.size();i++) {
		if(arr[i]-arr[i-1]>0) {
			if(!flag) {
				flag = true;
				start = i-1;
				sum = arr[i-1];
			}
			sum += arr[i];
		}
		else {
			if(flag) {
				flag = false;
				end = i;
				periods.push_back(make_pair(start, make_pair(end, sum)));
				sum = 0;
				start = -1;
			}
		}
		// cout<<i<<" -> "<<sum<<" "<<flag<<" "<<start<<" "<<end<<endl;
	}
	if(flag) {
		periods.push_back(make_pair(start, make_pair(arr.size()-1, sum)));
	}
	// cout<<"--------------------------------"<<endl;
	// for(auto x: periods) {
	// 	cout<<x.first<<" "<<(x.second).first<<" "<<(x.second).second<<endl;
	// }
	int ret = -1;;
	for(int i=0;i<periods.size();i++) {
		int sum = periods[i].second.second, max = -1;
		for(int j=i+1;j<periods.size();j++) {
			max = -1;
			if(periods[i].second.first-1+k<periods[j].first)
				if(max<periods[j].second.second)
					max = periods[j].second.second;
		}
		if(ret<sum+max)
			ret = sum+max;
		cout<<ret<<" "<<sum<<" "<<max<<endl;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(1);
	arr.push_back(2);
	cout<<computePeriods(arr, 0)<<endl;
	return 0;
}