# Write your MySQL query statement below

select machine_id, ROUND(avg(time), 3) as processing_time from (
    select machine_id, process_id, (sum(case when activity_type = 'start' then 0 else timestamp end) - sum(case when activity_type = 'end' then 0 else timestamp end)) as time from Activity group by machine_id, process_id) as act
    group by machine_id
