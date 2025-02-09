select
    product_name, units as unit
from
    Products
join (
select 
    Products.product_id, 
    sum(unit) as units
from
    Products
join Orders on Orders.product_id = Products.product_id
where Orders.order_date >= '2020-02-01' and Orders.order_date < '2020-03-01'
group by Products.product_id
having sum(unit) >= 100) ne
on Products.product_id = ne.product_id
