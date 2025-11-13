-- Write your PostgreSQL query statement below

WITH 
ranks as (
select employee_id, review_date, rating, RANK() OVER (PARTITION BY employee_id order by review_date DESC) as rowNum, LAG(rating, -1, 0) OVER (PARTITION BY employee_id order by review_date DESC) as prev_rating,
LAG(rating, -2, 0) OVER (PARTITION BY employee_id order by review_date DESC) as prev_prev_rating from performance_reviews
order by employee_id, review_date desc),
lasts as (select employee_id, review_date, rating, rowNum, prev_rating, prev_prev_rating from 
ranks where rowNum = 1 and rating > prev_rating and prev_rating > prev_prev_rating and prev_prev_rating <> 0),
joined as (select lasts.employee_id, name, (rating-prev_prev_rating) as improvement_score from lasts
join employees on lasts.employee_id = employees.employee_id order by improvement_score desc, name asc)
select * from joined;
