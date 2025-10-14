# Write your MySQL query statement below

with s as (
    select user_id, 
    min(case when event_type = 'start' then event_date else null end) as "start_date",
    max(event_date) as "last_event",
    max(monthly_amount) as "max_revenue",
    sum(event_type = 'downgrade') as "downgrade_count"
    from subscription_events
    group by user_id
)
select ss.user_id, se.plan_name as "current_plan", se.monthly_amount as "current_monthly_amount", ss.max_revenue as "max_historical_amount", datediff(ss.last_event, ss.start_date) as "days_as_subscriber"
from s ss join subscription_events se on ss.user_id = se.user_id and ss.last_event = se.event_date
where se.event_type <> 'cancel' and ss.downgrade_count > 0 and se.monthly_amount * 2 < ss.max_revenue and datediff(ss.last_event, ss.start_date) > 60 order by datediff(ss.last_event, ss.start_date) desc, ss.user_id asc;
