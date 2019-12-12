//Given an array of integers that is already sorted in ascending order, find two numbers such that they add up 
//to a specific target number.

//The function twoSum should return indices of the two numbers such that they add up to the target, where 
//index1 must be less than index2.

//Note:

//Your returned answers (both index1 and index2) are not zero-based.
//You may assume that each input would have exactly one solution and you may not use the same element twice.


// Method 1 Use Hashmap
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> map;
        vector<int> result(2,0);
        for (int i=0; i<numbers.size(); i++){
            auto itr = map.find(target-numbers[i]);
            if(itr!=map.end()){
                result[0] = itr->second+1;
                result[1] = i+1;
                break;
            }
            map[numbers[i]] = i;
        }
        return result;
    }
};

// Method 2 - two pointer
// Time: O(n)  Space: O(1) 
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;
        vector<int> result(2,0);
        while(left<right){
            if(numbers[left]+numbers[right]>target){
                right--;
            }else if(numbers[left]+numbers[right]==target){
                result[0] = left+1;
                result[1] = right+1;
                break;
            }else if(numbers[left]+numbers[right]<target){
                left++;
            }
        }
        return result;
    }
};

