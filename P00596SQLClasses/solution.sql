-- Write your PostgreSQL query statement below

select class from (
select class,
count(student) as cnt
from Courses group by class) a where a.cnt >= 5;
