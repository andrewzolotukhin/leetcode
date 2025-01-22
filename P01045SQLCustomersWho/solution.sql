-- Write your PostgreSQL query statement below
select customer_id from (select customer_id, count(distinct product_key) as c from Customer group by customer_id) where c = (select count(distinct product_key) from Product)
