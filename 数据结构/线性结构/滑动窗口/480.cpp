/*未完成*/
/*480. 滑动窗口中位数

中位数是有序序列最中间的那个数。如果序列的大小是偶数，则没有最中间的数；此时中位数是最中间的两个数的平均数。

例如：

    [2,3,4]，中位数是 3
    [2,3]，中位数是 (2 + 3) / 2 = 2.5

给你一个数组 nums，有一个大小为 k 的窗口从最左端滑动到最右端。窗口中有 k 个数，每次窗口向右移动 1 位。你的任务是找出每次窗口移动后得到的新窗口中元素的中位数，并输出由它们组成的数组。

 

示例：

给出 nums = [1,3,-1,-3,5,3,6,7]，以及 k = 3。

窗口位置                      中位数
---------------               -----
[1  3  -1] -3  5  3  6  7       1
 1 [3  -1  -3] 5  3  6  7      -1
 1  3 [-1  -3  5] 3  6  7      -1
 1  3  -1 [-3  5  3] 6  7       3
 1  3  -1  -3 [5  3  6] 7       5
 1  3  -1  -3  5 [3  6  7]      6

 因此，返回该滑动窗口的中位数数组 [1,-1,-1,3,5,6]。

 

提示：

    你可以假设 k 始终有效，即：k 始终小于输入的非空数组的元素个数。
    与真实值误差在 10 ^ -5 以内的答案将被视作正确答案。

*/
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ret;
        vector<int>::iterator beginOfWindow = nums.begin();
        vector<int>::iterator endOfWindow = nums.begin();
        multiset<int> window;
        multiset<int>::iterator leftOfMidWindow;
        multiset<int>::iterator rightOfMidWindow;
        multiset<int>::iterator tempSetIterator;
        int findMid = 0;
        double midValue = 0;

        while(endOfWindow!=nums.begin()+k){
            window.insert(*endOfWindow);
            endOfWindow++;
        }
        while(endOfWindow!=nums.end()){
            if(k%1==0){
                findMid = 1;
                leftOfMidWindow = window.begin();
                while(findMid<(k>>1)){
                    leftOfMidWindow++;                    
                }
                rightOfMidWindow = leftOfMidWindow;
                rightOfMidWindow++;
                midValue = *leftOfMidWindow + *rightOfMidWindow;
                midValue /= 2;
                ret.push_back(midValue);
            }else{
                findMid = 0;
                leftOfMidWindow = window.begin();
                while(findMid<(k>>)){
                    leftOfMidWindow++;                    
                }
                midValue = *leftOfMidWindow;
                midValue /= 2;
                ret.push_back(midValue);
            }
            tempSetIterator = window.find(*beginOfWindow);
            window.erase(tempSetIterator);
            window.insert(*endOfWindow);
            beginOfWindow++;
            endOfWindow++;
        }
        return ret;
    }
};