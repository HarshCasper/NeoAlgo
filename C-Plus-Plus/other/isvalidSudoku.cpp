class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map <char, vector<pair<int, int>>> v;
        
        for (int i = 0; i < board.size(); i++) {
            
            for (int j = 0; j < board[i].size(); j++) {
                char value = board[i][j];
                if (!(value >= '1' && value <= '9')) {
                    continue;
                }
                if (v.find(value) != v.end()) {
                    vector<pair<int, int>> vec = v[value];
                    for (int idx = 0; idx < vec.size(); idx++) {
                        int x, y;
                        x = vec[idx].first;
                        y = vec[idx].second;
                        int sec_i, sec_j, sec_x, sec_y;
                        sec_i = i / 3;
                        sec_j = j / 3;
                        sec_x = x / 3;
                        sec_y = y / 3;
                        if (x == i || y == j) {
                            return false;
                        } else if ((sec_i == sec_x && sec_j == sec_y) && 
                                   (abs(i - x) <= 2 && abs(j - y) <= 2)) {
                            return false;
                        }
                    }
                    v[value].push_back(make_pair(i, j));
                } else {
                    vector<pair<int, int>> r;
                    r.push_back(make_pair(i, j));
                    v[value] = r;
                }
            }
        }
        
        return true;
    }
};