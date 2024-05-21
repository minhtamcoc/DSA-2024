#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    string S;
    int K;
    cin >> S >> K;

    // Đếm số lần xuất hiện của mỗi ký tự
    map<char, int> freq;
    for (char c : S) {
        freq[c]++;
    }

    // Sắp xếp các ký tự theo số lần xuất hiện tăng dần
    vector<pair<char, int>> sortedFreq(freq.begin(), freq.end());
    sort(sortedFreq.begin(), sortedFreq.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
    });

    // Loại bỏ K ký tự có số lần xuất hiện ít nhất
    int removed = 0;
    for (const auto& p : sortedFreq) {
        if (removed + p.second <= K) {
            removed += p.second;
            freq.erase(p.first);
        } else {
            break;
        }
    }

    // Tính giá trị mới của xâu S sau khi loại bỏ K ký tự
    int minValue = 0;
    for (const auto& p : freq) {
        minValue += p.second * p.second;
    }

    cout << minValue << endl;

    return 0;
}
