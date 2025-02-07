with ranks as (
select
    id,
    salary,
    dense_rank() over (order by salary desc) as r
from
    Employee)
select ranks.salary as SecondHighestSalary from (VALUES (2)) as t1(r)
left join ranks on ranks.r = t1.r
limit 1;
