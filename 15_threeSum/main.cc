#include <iostream>
#include <vector>
#include <map>

using namespace std;

void matchingNums(const map<int, int>& num_map, vector<vector<int>>& res)
{
    auto it1 = num_map.begin();
    while (it1 != num_map.end() && it1->first <= 0) {
        map<int, int> temp(it1, num_map.end());
        temp[it1->first]--;
        for (auto it2 = temp.lower_bound(it1->first); it2 != temp.end(); it2++) {
            if (temp[it2->first] == 0) {
                continue;
            }
            temp[it2->first]--;
            int tar = 0 - (it1->first + it2->first);
            if (temp.find(tar) != temp.end() && temp[tar] > 0) {
                res.push_back({it1->first, it2->first, tar});
                temp[tar] = 0;
            }
        }
        it1++;
    }
}

vector<vector<int>> threeSum(vector<int>& nums)
{
    map<int, int> num_map;
    for (auto it = nums.begin(); it != nums.end(); it++) {
        if (num_map.find(*it) == num_map.end()) {
            num_map[*it] = 1;
        } else {
            num_map[*it]++;
        }
    }
    vector<vector<int>> res;
    matchingNums(num_map, res);
    return res;
}

void printVectorOfVectors(const vector<vector<int>>& vv) {
    for (const auto& row : vv) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    vector<int> nums = {-2,0,0,2,2};
    vector<vector<int>> res = threeSum(nums);
    printVectorOfVectors(res);
    return -1;
}