-- Write your PostgreSQL query statement below

with q1 as (
select user_id, rank() over (order by count(*) desc) as rc 
from MovieRating group by 1),
p1 as (
select Users.name as results from q1
join Users on q1.user_id = Users.user_id
where rc = 1
order by Users.name asc limit 1),
q2 as (
    select movie_id, rank() over (order by avg(rating) desc) as rc
    from MovieRating 
    where cast(date_trunc('month', created_at) as date) = '2020-02-01'
    group by 1
),
p2 as (select Movies.title as results from q2
join Movies on q2.movie_id = Movies.movie_id
where rc = 1
order by Movies.title asc limit 1
 )
select * from p1 union all select * from p2;
