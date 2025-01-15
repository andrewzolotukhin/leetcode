-- Write your PostgreSQL query statement below

WITH
  first_log_in_day as (select DISTINCT ON (player_id) player_id, (event_date + INTERVAL '1 DAY') as next_day from Activity order by player_id, event_date),
  with_activity_next_day as (SELECT player_id FROM 
    Activity WHERE (player_id, event_date) in (select * from first_log_in_day) group by player_id),
res as(
select 
        ((select count(*)::double precision from with_activity_next_day limit 1)/
        (select count(*) from first_log_in_day limit 1)) as fraction)
select round(res.fraction::numeric, 2) as fraction from res;
  
