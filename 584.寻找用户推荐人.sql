--
-- @lc app=leetcode.cn id=584 lang=mysql
--
-- [584] 寻找用户推荐人
--

-- @lc code=start
-- # Write your MySQL query statement below
select name from customer where referee_id != '2'
-- @lc code=end

