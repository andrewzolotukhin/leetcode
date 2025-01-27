with q1 as (
    select distinct on (product_id) product_id, change_date, new_price from Products
    where change_date <= '2019-08-16'
    order by product_id, change_date desc
),
q2 as (select distinct product_id from Products)
select 
    q2.product_id as product_id, 
    COALESCE(q1.new_price, 10) as price 
from q2 LEFT JOIN q1 on q2.product_id = q1.product_id;
