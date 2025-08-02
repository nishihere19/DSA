#include<iostream>
using namespace std;

void play(vector<vector<string>>& ans, vector<string>& board, int n, int i){
    if(i==n){
        ans.push_back(board);
    }
    for(int j=0;j<n;j++){
        bool flag = 0;
        for(int k=0;k<i;k++){
            if(board[k][j]=='Q') flag = 1;
        }
        if(flag==0){
            int k = i-1;
            int l = j-1;
            while(k>=0&&l>=0&&flag==0){
                if(board[k][l]=='Q') flag = 1;
                k--;
                l--;
            }
        }
        if(flag==0){
            int k = i-1;
            int l = j+1;
            while(k>=0&&l<n&&flag==0){
                if(board[k][l]=='Q') flag = 1;
                k--;
                l++;
            }
        }
        if(flag==0){
            board[i][j]='Q';
            play(ans,board,n,i+1);
            board[i][j]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    string row = "";
    for(int i=0; i<n;i++){
        row+=".";
    }
    vector<string> board;
    vector<vector<string>> ans;
    for(int i=0; i<n;i++){
        board.push_back(row);
    }
    play(ans,board,n,0);
    return ans;
}

int main() {
    int n;
    cout << "Enter Size Of Chess Board: ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    cout << "\nTotal Solutions: " << solutions.size() << "\n";

    for (int i = 0; i < solutions.size(); i++) {
        cout << "Solution " << i + 1 << ":\n";
        for (const string& row : solutions[i]) {
            cout << row << "\n";
        }
        cout << "\n";
    }

    return 0;
}



    
