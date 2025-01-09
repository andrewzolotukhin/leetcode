# Write your MySQL query statement below

SELECT 
    Register.contest_id as contest_id,
    round(count(DISTINCT user_id)/(select count(*)/100 from Users),2) as percentage
FROM
    Register
GROUP BY contest_id
order by percentage desc, contest_id asc
