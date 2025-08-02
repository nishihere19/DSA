#include<iostream>
using namespace std;

void play(vector<vector<string>>& ans, vector<string>& board, int n, int i, vector<bool>col, vector<bool>diag1, vector<bool>diag2){
    if(i==n){
        ans.push_back(board);
    }
    for(int j=0;j<n;j++){
        if(col[j] || diag1[i+j] || diag2[i-j+n-1]) continue;
        board[i][j]='Q';
        col[j] = diag1[i+j] = diag2[i-j+n-1] = true;
        play(ans,board,n,i+1, col, diag1, diag2);
        board[i][j]='.';
        col[j] = diag1[i+j] = diag2[i-j+n-1] = false;
    }
}

int solveNQueens(int n) {
    string row = "";
    for(int i=0; i<n;i++){
        row+=".";
    }
    vector<string> board;
    vector<vector<string>> ans;
    vector<bool>col(n,false), diag1(2*n-1,false), diag2(2*n-1,false);
    for(int i=0; i<n;i++){
        board.push_back(row);
    }
    play(ans,board,n,0, col, diag1, diag2);
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



    
