-- Write your PostgreSQL query statement below

with
pr as (select employee_id, department_id from Employee where primary_flag = 'Y')
select * from pr union all 
select distinct on (employee_id, department_id) employee_id, department_id from Employee where (employee_id) not in (select employee_id from pr) order by employee_id, department_id
