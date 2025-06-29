#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Activity structure
struct Activity {
    int start, finish;
};

// Comparator function to sort activities by finish time
bool activityCompare(Activity a, Activity b) {
    return a.finish < b.finish;
}

// Function to select maximum number of non-overlapping activities
void activitySelection(vector<Activity> &activities) {
    // Sort activities by their finish time
    sort(activities.begin(), activities.end(), activityCompare);

    cout << "Selected activities:\n";

    // The first activity always gets selected
    int n = activities.size();
    int lastFinishTime = activities[0].finish;
    cout << "(" << activities[0].start << ", " << activities[0].finish << ")\n";

    // Consider the rest of the activities
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinishTime) {
            cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";
            lastFinishTime = activities[i].finish;
        }
    }
}

int main() {
    vector<Activity> activities = {
        {5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}
    };

    activitySelection(activities);

    return 0;
}
