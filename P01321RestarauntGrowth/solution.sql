-- Write your PostgreSQL query statement below

with 
q0 as (
    select
      visited_on,
      sum(amount) as amount
    from Customer
    group by 1
    order by visited_on
),
q1 as (
select
    visited_on,
    round(avg(amount) over (ORDER BY visited_on ASC ROWS BETWEEN 6 PRECEDING AND CURRENT ROW), 2) as average_amount,
    sum(amount) over (ORDER BY visited_on ASC ROWS BETWEEN 6 PRECEDING AND CURRENT ROW) as amount
from
    q0
order by visited_on),
q2 as (select visited_on from Customer group by 1 order by visited_on OFFSET 6)
SELECT q2.visited_on, q1.amount, q1.average_amount from q2
JOIN q1 on q1.visited_on = q2.visited_on;
