select usid as id, sum(num) as num
from (select
  requester_id as usid,
  count(*) as num
from RequestAccepted
group by 1
union all
select
  accepter_id as usid,
  count(*) as num
from RequestAccepted
group by 1) t
group by 1 order by num desc limit 1
