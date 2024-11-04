// Desafio 75. Sort Colors link: https://leetcode.com/problems/sort-colors/description/?envType=problem-list-v2&envId=sorting

#include <vector>
using namespace std;

class Solucao {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                // troca o 0 para a posição do low
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // apenas avança o ponteiro mid
                mid++;
            } else {
                // troca o 2 para a posição do high
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
