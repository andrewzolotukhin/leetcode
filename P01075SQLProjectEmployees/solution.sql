# Write your MySQL query statement below

select 
    Project.project_id as project_id,
    ROUND(avg(CAST(Employee.experience_years as DECIMAL(10, 6))), 2) as average_years
from
    Project
join Employee on Employee.employee_id = Project.employee_id
group by Project.project_id
order by project_id
