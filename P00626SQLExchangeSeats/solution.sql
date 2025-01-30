with q as (
    select id, student, LAG(student, -1) OVER (order by id) as nextStudent, LAG(student, 1) OVER (order by id) as prevStudent from Seat order by id
),
q2 as (select id, case when mod(id, 2) = 1 then COALESCE(nextStudent, student) else COALESCE(prevStudent, student) end as student from q)
select * from q2;
