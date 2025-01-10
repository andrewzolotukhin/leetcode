# Write your MySQL query statement below

select 
    query_name,
    round(avg(rating/position), 2) as quality,
    round(sum(CASE WHEN rating < 3 THEN 1 ELSE 0 END)/count(*) * 100, 2) poor_query_percentage
from
    Queries
group by query_name;
