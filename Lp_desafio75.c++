#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                // Troca o 0 para a posição do 'low'
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // Apenas avança o ponteiro 'mid'
                mid++;
            } else {
                // Troca o 2 para a posição do 'high'
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};