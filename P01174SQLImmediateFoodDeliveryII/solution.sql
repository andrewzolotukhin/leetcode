-- Write your PostgreSQL query statement below

WITH 
 first_orders as (select DISTINCT ON (customer_id) customer_id, delivery_id from Delivery order by customer_id, order_date),
 s_orders as (
  select 
    round(sum(CASE WHEN order_date = customer_pref_delivery_date THEN 1.0 ELSE 0 END)/count(*)*100, 2) as immediate_percentage  
  from 
    Delivery 
  where 
    delivery_id in (select delivery_id from first_orders)
  )
SELECT 
  * 
from 
  s_orders;
