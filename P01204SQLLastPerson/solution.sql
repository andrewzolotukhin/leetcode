-- Write your PostgreSQL query statement below
with q as (
select 
    SUM(weight) OVER (order by turn ROWS BETWEEN UNBOUNDED PRECEDING AND CURRENT ROW) as acc,
    person_name
from
    Queue
order by turn asc)
select person_name from q where acc <= 1000 order by acc desc limit 1; 
