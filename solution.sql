-- Write your PostgreSQL query statement below

with q as (
    select 
        CASE 
            WHEN 
                income < 20000 THEN 'Low Salary'
            WHEN
                income >=20000 AND income <= 50000 THEN 'Average Salary'
            ELSE 'High Salary'
        END as category
    from
        Accounts 
), c as ( select category
    from (
    values ('Low Salary'), ('Average Salary'), ('High Salary')
) s(category)
),
q2 as (select c.category as category, q.category as c2 from c left join q on q.category = c.category)
select category, sum(CASE WHEN q2.c2 IS NULL THEN 0 ELSE 1 END) as accounts_count from q2 group by 1; 
