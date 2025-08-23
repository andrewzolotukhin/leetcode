# Write your MySQL query statement below

select
    id,
    if(sum(case month when 'Jan' then 1 else 0 end) = 0, null, sum(case month when 'Jan' then revenue else 0 end)) Jan_Revenue,
    if(sum(case month when 'Feb' then 1 else 0 end) = 0, null, sum(case month when 'Feb' then revenue else 0 end)) Feb_Revenue,
    if(sum(case month when 'Mar' then 1 else 0 end) = 0, null, sum(case month when 'Mar' then revenue else 0 end)) Mar_Revenue,
    if(sum(case month when 'Apr' then 1 else 0 end) = 0, null, sum(case month when 'Apr' then revenue else 0 end)) Apr_Revenue,
    if(sum(case month when 'May' then 1 else 0 end) = 0, null, sum(case month when 'May' then revenue else 0 end)) May_Revenue,
    if(sum(case month when 'Jun' then 1 else 0 end) = 0, null, sum(case month when 'Jun' then revenue else 0 end)) Jun_Revenue,
    if(sum(case month when 'Jul' then 1 else 0 end) = 0, null, sum(case month when 'Jul' then revenue else 0 end)) Jul_Revenue,
    if(sum(case month when 'Aug' then 1 else 0 end) = 0, null, sum(case month when 'Aug' then revenue else 0 end)) Aug_Revenue,
    if(sum(case month when 'Sep' then 1 else 0 end) = 0, null, sum(case month when 'Sep' then revenue else 0 end)) Sep_Revenue,
    if(sum(case month when 'Oct' then 1 else 0 end) = 0, null, sum(case month when 'Oct' then revenue else 0 end)) Oct_Revenue,
    if(sum(case month when 'Nov' then 1 else 0 end) = 0, null, sum(case month when 'Nov' then revenue else 0 end)) Nov_Revenue,
    if(sum(case month when 'Dec' then 1 else 0 end) = 0, null, sum(case month when 'Dec' then revenue else 0 end)) Dec_Revenue
from
    Department
group by id 
