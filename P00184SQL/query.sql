-- Write your PostgreSQL query statement below
with
 highest as (
    select departmentId, max(salary) as maxS from Employee group by departmentId
 )
 select 
    Department.name as department,
    Employee.name as Employee,
    Employee.salary as Salary
from
    Employee
join Department on Department.id = Employee.departmentId
where (Employee.departmentId, Employee.salary) in (select * from highest);
