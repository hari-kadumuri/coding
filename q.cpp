#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b) {
	return (a>b?b:a);
}

int getNodePower(int x) {
	bool flag[x+1];
	for(int i=0;i<x+1;i++)
		flag[i] = false;
	int i = 2;
	while(i<x) {
		if(flag[i]==true)
			i++;
		else {
			int s = i*i;
			for(int j = 0; s+j < x+1; j += i)
				flag[s+j] = true;
			i++;
		}
	}
	int prod = 1;
	for(int i=2;i<x+1;i++)
		if(flag[i]==false && x%i==0)
			prod *= i;
	return prod;
}

int getComponentPower(vector<int> &nodes, vector<int>& connectList, int idx) {
	int keyComponent = connectList[idx], sum = 0;
	for(int i=0;i<connectList.size();i++) {
		if(connectList[i]==keyComponent)
			sum += getNodePower(nodes[i]);
	}
	return sum;
}

void executeQuery1(vector<int> &nodes, int** queries, vector<vector<int>> connectTable, vector<int>& connectList, int Q, int idx) {
	nodes.push_back(queries[idx][1]);
	vector<int> tempvector;
	tempvector.push_back(connectTable.size()-1);
	connectTable.push_back(tempvector);
	connectList.push_back(connectTable.size()-1);
}

void executeQuery2(vector<int> &nodes, int** queries, vector<vector<int>>& connectTable, vector<int>& connectList, int Q, int idx) {
	int node1 = queries[idx][1], node2 = queries[idx][2];
	int component1 = min(connectList[node1], connectList[node2]);
	int component2 = max(connectList[node1], connectList[node2]);
	if(component1==component2)
		return;
	for(int i=0;i<connectTable[component2].size();i++)
		connectTable[component1].push_back(connectTable[component2][i]);
	connectTable.erase(connectTable.begin()+component2);
	for(int i=0;i<connectList.size();i++) {
		if(connectList[i]==component1 || connectList[i]==component2)
			connectList[i] = component1;
	}
}

void executeQuery3(vector<int> &nodes, int** queries, vector<vector<int>>& connectTable, vector<int> & connectList, int Q, int idx) {
	int count = 0, nodeVal = nodes[idx];
	int keyComponentPower = getNodePower(nodeVal);
	for(int i=0;i<connectTable.size();i++) {
		int ithPower = getComponentPower(nodes, connectList, connectTable[i][0]);
		if(ithPower>keyComponentPower)
			count++;
	}
	cout<<count<<endl;
}

void executeQuery(vector<int>& nodes, int** queries, vector<vector<int>>& connectTable, vector<int>& connectList, int Q, int idx) {
	switch(queries[idx][0]) {
		case 1:
			executeQuery1(nodes, queries, connectTable, connectList, Q, idx);
			break;
		case 2:
			executeQuery2(nodes, queries, connectTable, connectList, Q, idx);
			break;
		case 3:
			executeQuery3(nodes, queries, connectTable, connectList, Q, idx);
			break;
	}
}

int main(int argc, char const *argv[])
{
	int N, Q, i;
	scanf("%d%d", &N, &Q);
	vector<int> nodes, connectList;
	vector<vector<int>> connectTable;
	int** queries = new int*[Q];
	for(i=0;i<Q;i++)
		queries[i] = new int[3];
	for(i=0;i<N;i++) {
		int temp;
		vector<int> tmpvector;
		scanf("%d", &temp);
		nodes.push_back(temp);
		tmpvector.push_back(i);
		connectList.push_back(i);
		connectTable.push_back(tmpvector);
	}
	for(i=0;i<Q;i++) {
		scanf("%d", &queries[i][0]);
		switch(queries[i][0]) {
			case 1:
				scanf("%d", &queries[i][1]);
				break;
			case 2:
				scanf("%d%d", &queries[i][1], &queries[i][2]);
				break;
			case 3:
				scanf("%d", &queries[i][1]);
				break;
		}
	}
	for(i=0;i<Q;i++)
		executeQuery(nodes, queries, connectTable, connectList, Q, i);
	return 0;
}