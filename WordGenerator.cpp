// the following program generates all the meaningful words with given characters (without repetetion).
// conditions like a particular character a particular position can also be given. The code will generate the words according
// to that
#include <bits/stdc++.h>
using namespace std;

// node for dictionary
struct node {
	char val = '-';
	bool flag = false;
	node* next[26] = {NULL};
};

// variable to store root of the trie generated from dictionary
node* root;

// function that generates trie from list of words
node* constructTrie(vector<string>& dict) {
	node* root = new node;
	root->flag = true;
	int dictsize = dict.size();
	for(int i=0;i<dictsize;i++) {
		node* p = root;
		for(int j=0;j<dict[i].size();j++) {
			if(!(p->next)[dict[i][j]-'a']) {
				(p->next)[dict[i][j]-'a'] = new node;
				(p->next)[dict[i][j]-'a']->val = dict[i][j];
			}
			if(j==dict[i].size()-1) (p->next)[dict[i][j]-'a']->flag = true;
			p = (p->next)[dict[i][j]-'a'];
		}
	}
	return root;
}

// function that takes a word, root of the trie and the index. It returns if the suffix of word starting with that index exists in the trie
bool traverseTrie(string str, node* root, int i) {
	// cout<<i<<": "<<endl;
	if(i>=str.size()) return true;
	if(!(root->next)[str[i]-'a']) return false;
	// cout<<"comparing "<<str[i]<<" and "<<(root->next)[str[i]-'a']->val<<endl;
	if(i==str.size()-1) return (root->next)[str[i]-'a']->flag;
	return traverseTrie(str, (root->next)[str[i]-'a'], i+1);
}

// function to delete trie from the heap memory
void deleteTrie(node* root) {
	if(!root) return;
	for(int i=0;i<26;i++)
		deleteTrie((root->next)[i]);
	delete root;
}

// function that takes a word and root of the trie. It returns if that word exists in the trie
bool ifexists(string buf) {
	return traverseTrie(buf, root, 0);
}

// uitility recursive function that generates words with input characters and checks if they exist in the dictionary
void modPrintPossiblities(char input[], int n, vector<pair<char, int>>& conditions, bool visited[], string buf, int idx) {
	if(idx==buf.size()) {
		if(ifexists(buf))
			cout<<buf<<endl;
		return;
	}
	if(buf[idx]=='-') {
		for(int i=0;i<n;i++) {
			if(!visited[i]) {
				buf[idx] = input[i];
				visited[i] = true;
				modPrintPossiblities(input, n, conditions, visited, buf, idx+1);
				visited[i] = false;
			}
		}
	}
	else
		modPrintPossiblities(input, n, conditions, visited, buf, idx+1);
}

// function that returns the index of a character in a character array
int findPos(char input[], char c, int n) {
	for(int i=0;i<n;i++)
		if(input[i]==c) return i;
	return -1;
}

// uitility function that generates words with input characters and checks if they exist in the dictionary
void printPossibilities(char input[], int n, int size, vector<pair<char, int>>& conditions) {
	vector<string> allwords;
	// yet to be done
	string buf;
	for(int i=0;i<size;i++)
		buf.push_back('-');
	bool visited[n] = {false};
	for(int i=0, j=0;i<n && conditions.size()>0;i++) {
		if(i==conditions[j].second-1) {
			buf[i] = conditions[j].first;
			j++;
			visited[findPos(input, buf[i], n)] = true;
		}
	}
	modPrintPossiblities(input, n, conditions, visited, buf, 0);
}

int main(int argc, char const *argv[])
{
	cout<<"\nConstructing Dictionary from all English words..."<<endl;
	vector<string> dict;
	string buff;
	// reading from a file
	ifstream MyReadFile("Total_Words.txt");
	string tmpword;
	while (getline(MyReadFile, buff))
		dict.push_back(buff);
	MyReadFile.close();
	
	root = constructTrie(dict);
	cout<<"Dictionary is created :-)"<<endl;
	
	while(1) {
		int n;
		cout<<"\nenter number of characters (enter non positive value to abort):";
		cin>>n;
		if(n<=0)
			break;
		cout<<n<<endl;
		char input[n];
		cout<<"enter characters:\n";
		for(int i=0;i<n;i++)
			cin>>input[i];
		while(1) {
			int size;
			cout<<"enter size of the word needs to be generated (enter non-positive to abort): ";
			cin>>size;
			if(size<=0) break;
			vector<pair<char, int>> conditions;
			cout<<"enter conditions (character followed by position counting from 1, enter - to run possibilities)"<<endl;
			while(1) {
				char c;
				int pos;
				cin>>c;
				if(c=='-')
					break;
				cin>>pos;
				conditions.push_back(make_pair(c, pos));
			}
			printPossibilities(input, n, size, conditions);
		}
	}
	cout<<"\ndeleting dictionary..."<<endl;
	deleteTrie(root);
	cout<<"dictionary deleted. GoodBye :-)\n"<<endl;
	return 0;
}