-- Write your PostgreSQL query statement below

with q1 as (
select 
    LAG(num, 1) OVER (ORDER BY id) as p1,
    LAG(num, 2) OVER (ORDER BY id) as p2,
    id, num from Logs),
q2 as (select * from q1  where p1 = p2 AND p1 = num)
select distinct num as "ConsecutiveNums" from q2;
