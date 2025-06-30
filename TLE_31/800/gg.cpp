#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void max_strong_teams(int t, vector<pair<pair<int, int>, vector<int>>> &test_cases) {
    vector<int> results;

    for (auto &test_case : test_cases) {
        int n = test_case.first.first;
        int x = test_case.first.second;
        vector<int> &skills = test_case.second;

        sort(skills.rbegin(), skills.rend()); // Sort in descending order
        int team_count = 0, team_size = 0;

        for (int skill : skills) {
            team_size++;

            // If current team meets the required strength
            if (skill * team_size >= x) {
                team_count++;
                team_size = 0; // Reset team size for next team
            }
        }

        results.push_back(team_count);
    }

    for (int result : results) {
        cout << result << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    vector<pair<pair<int, int>, vector<int>>> test_cases;

    for (int i = 0; i < t; i++) {
        int n, x;
        cin >> n >> x;
        vector<int> skills(n);
        for (int j = 0; j < n; j++) {
            cin >> skills[j];
        }
        test_cases.push_back({{n, x}, skills});
    }

    max_strong_teams(t, test_cases);

    return 0;
}