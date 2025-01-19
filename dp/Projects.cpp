#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
int main() {
	/*
	We create a custom variable project that stores that starting date, end date
	and the reward for each project.
	(1) We sort the projects in ascending order of their end dates.
	(2) We copy the ending dates in the vector lastEndDate
	(3) We go over each project, and then find the index of the last project end date 
		which comes before the starting date for the project. Then we have two opitons -
		to ignore the current project or to choose it (in which case we add its reward 
		to the maximum money that could have been obtained by doing previous projects).
	*/
    	struct project {
		int startDate = 0;
		int endDate = 0;
		int reward = 0;
	};
 
	int n; cin >> n;
	vector <project> projects (n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> projects[i].startDate >> projects[i].endDate >> projects[i].reward;
	}
	
	// (1)
	sort(projects.begin() + 1, projects.end(), [](const project &p1, const project &p2) {
		return p1.endDate < p2.endDate;
	});
 
	// (2)
	vector <int> lastEndDate (n + 1);
	for (int i = 1; i <= n; i++) {
		lastEndDate[i] = projects[i].endDate;
	}
 
	// (3)
	vector <ll> maxMoney (n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int j = distance(lastEndDate.begin(), lower_bound(lastEndDate.begin(), lastEndDate.end(), projects[i].startDate)) - 1;
		maxMoney[i] = max(maxMoney[i - 1], maxMoney[j] + projects[i].reward);
	}
 
	cout << maxMoney[n] << "\n";
 
    return 0;
}