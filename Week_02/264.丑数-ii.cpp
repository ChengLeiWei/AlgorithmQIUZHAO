/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 *
 * https://leetcode-cn.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (53.01%)
 * Likes:    338
 * Dislikes: 0
 * Total Accepted:    30.1K
 * Total Submissions: 56.5K
 * Testcase Example:  '10'
 *
 * 编写一个程序，找出第 n 个丑数。
 * 
 * 丑数就是质因数只包含 2, 3, 5 的正整数。
 * 
 * 示例:
 * 
 * 输入: n = 10
 * 输出: 12
 * 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
 * 
 * 说明:  
 * 
 * 
 * 1 是丑数。
 * n 不超过1690。
 * 
 * 
 */

// @lc code=start
class Solution {
    private:
        int uglyNumber[3] = {2, 3, 5};

    public:
        int nthUglyNumber(int n){
            priority_queue<long> pq;
            pq.push(1L);
            int count = 0;
            while (! pq.empty()) {
                long cut = pq.pop();

                if (++count >= n) {
                    return cut;
                }

                for (int num : uglyNumber) {
                    if (! pq.count(num * cut)) {
                        pq.push(num * cut);
                    }
                }
            }
            return -1;
        }
};
// @lc code=end

