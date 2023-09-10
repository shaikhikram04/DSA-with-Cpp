// https://www.codingninjas.com/studio/problems/common-elements-present-in-all-rows-of-a-matrix_1118111?topList=love-babbar-dsa-sheet-problems

#include <unordered_map>
#include <vector>
using namespace std;

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    unordered_map<int, int> heap;

    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            int ele = mat[i][j];
            if (heap[ele] == i) {
                heap[ele] = i+1;
            }
        }
    }

    vector<int> ans;
    int row = mat.size();

    for (auto i : heap) {
        if (i.second == row) {
            ans.push_back(i.first);
        }
    }

    return ans;
}
