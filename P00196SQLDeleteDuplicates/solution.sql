-- Write your PostgreSQL query statement below

delete from Person where (email, id) not in (select DISTINCT on (email) email, id from Person order by email, id asc)
