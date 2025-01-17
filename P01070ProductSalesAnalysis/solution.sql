-- Write your PostgreSQL query statement below

with
first_years as(
select distinct on(product_id) product_id, year FROM Sales ORDER BY product_id, year)
select 
  Sales.product_id as product_id,
  Sales.year as first_year,
  quantity as quantity,
  price as price
FROM Sales
WHERE (product_id, year) in (select product_id, year from first_years);
