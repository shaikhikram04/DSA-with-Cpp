#include <iostream>
#include <vector>
using namespace std;

long long mostPoints(vector<vector<int>> &questions) {
    long long maxPonts = 0;
    for (int i = 0; i < questions.size(); i++) {
        long long totalPoints = questions[i][0];
        int unable = questions[i][1];
        int skip = 0;
        for (int j = i + 1 + unable; j < questions.size(); j++){
            if (skip == 0) {
                totalPoints += questions[j][0];
                skip = questions[j][1];
            } else {
                skip--;
            }
        }
        if (maxPonts < totalPoints)
            maxPonts = totalPoints;
    }
    return maxPonts;
}