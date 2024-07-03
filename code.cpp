#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& pages, int n, int m, int curr_min) {
    int studentsRequired = 1, curr_sum = 0;

    for (int i = 0; i < n; ++i) {
        if (pages[i] > curr_min) return false;
        if (curr_sum + pages[i] > curr_min) {
            studentsRequired++;
            curr_sum = pages[i];
            if (studentsRequired > m) return false;
        } else {
            curr_sum += pages[i];
        }
    }
    return true;
}

int findPages(vector<int>& pages, int n, int m) {
    if (n < m) return -1;
    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);
    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(pages, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    /* 
    int n, m;
    cin >> n >> m;
    vector<int> pages(n);
    for(int i=0; i<n; i++) cin >> a[i];
    */
    vector<int> pages = {12, 34, 67, 90};
    int m = 2;
    int n = pages.size();
    cout << "Minimum number of pages: " << findPages(pages, n, m) << endl;
    return 0;
}
