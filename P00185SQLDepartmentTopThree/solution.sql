with 
us as (
    select distinct departmentId, salary from Employee
),
ds as (
    select departmentId, salary, rank() over (partition by departmentId order by salary desc) as r from us order by departmentId asc, r asc 
)
select 
  Department.name as Department,
  Employee.name as Employee,
  ds.salary as Salary
from ds
join Department on ds.departmentId = Department.id
join Employee on Employee.departmentId = ds.departmentId and Employee.salary = ds.salary
where ds.r <= 3;
