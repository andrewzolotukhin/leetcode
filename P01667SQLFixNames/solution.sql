-- Write your PostgreSQL query statement below

select user_id, UPPER(SUBSTRING(LOWER(name), 1, 1)) || SUBSTRING(LOWER(name), 2) as name from Users order by user_id;
