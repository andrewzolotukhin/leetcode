# Write your MySQL query statement below

select
 DATE_FORMAT(trans_date,'%Y-%m') as month,
 country,
 sum(1) as trans_count,
 sum(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) as approved_count,
 sum(amount) as trans_total_amount,
 sum(CASE WHEN state = 'approved' THEN amount ELSE 0 END) as approved_total_amount
from
 Transactions
group by
 month,
 country

