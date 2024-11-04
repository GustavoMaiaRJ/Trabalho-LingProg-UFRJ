// Desafio 905. Sort Array by Parity link: https://leetcode.com/problems/sort-array-by-parity/?envType=problem-list-v2&envId=sorting

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            // avança o ponteiro esquerdo se o elemento é par
            if (nums[left] % 2 == 0) {
                left++;
            }
            // retrocede o ponteiro direito se o elemento é ímpar
            else if (nums[right] % 2 == 1) {
                right--;
            }
            // troca elementos ímpar no início com par no final
            else {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        
        return nums;
    }
};
