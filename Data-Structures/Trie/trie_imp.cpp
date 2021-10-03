#include<bits/stdc++.h>
using namespace std;

struct trie{
	struct trie* child[26];
	bool is_end;
	
	trie(){
		memset(child,0,sizeof(child));
		is_end=false;
	}
};

struct trie* root;

void insert(string s){
	struct trie* temp=root;
	for(char c: s){
		if(!temp->child[c-'a'])
			temp->child[c-'a']=new trie;
		temp=temp->child[c-'a'];
	}
	temp->is_end=true;
}

bool check(string s){
	struct trie* temp=root;
	for(char c: s){
		if(!temp->child[c-'a'])
			return false;
		temp=temp->child[c-'a'];
	}
	return temp->is_end;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	root=new trie;	
	int n;
	cout << "Input the number of words in the List" << endl;
	cin >> n;
	string word;
	cout<<"Enter the words"<<endl;
	for(int i=0; i<n; i++){
		cin >> word ;
		insert(word);
	}
	cout << "Enter the number of words you want to check exist in the List" << endl;
	int m;
	cin >> m;
	for(int i=0; i<m; i++){
		cin >> word ;
		if(check(word))
			cout<< "This word exist in the list" <<endl;
		else
			cout<< "This word does not exist in the list"<<endl;
	}
}
