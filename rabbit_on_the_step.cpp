#include <iostream>

using namespace std;

/**
 * Recursively calculates the number of ways to reach the nth step
 * @param n Target step number (must be >= 0)
 * @param k Maximum jump length (default 3, must be >= 1)
 * @return Total number of valid jump combinations
 */
int count_jumps(int n, int k = 3) {
    if (n == 0) return 1;  // Base case: already at target
    if (n < 0) return 0;   // Invalid path
    
    int total = 0;
    for (int jump = 1; jump <= k && jump <= n; ++jump) {
        total += count_jumps(n - jump, k);
    }
    return total;
}

int main() {
    int n, k = 3;
    char separator;
    
    cout << "Enter target step and max jump (format: N[,K]): ";
    cin >> n;
    
    if (cin.peek() == ',') {
        cin >> separator >> k;
    }
    
    cout << "Total ways: " << count_jumps(n, k) << endl;
    return 0;
}
