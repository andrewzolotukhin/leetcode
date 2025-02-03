with
 dc as (select lat, lon, count(*) as cities from Insurance group by lat, lon),
 dt as (select tiv_2015 as dtiv, count(*) as tivc from Insurance group by tiv_2015),
 q1 as (select 
    * 
from 
    Insurance 
join dc 
    on Insurance.lat = dc.lat and Insurance.lon = dc.lon
join dt
    on Insurance.tiv_2015 = dt.dtiv
)
select round(sum(tiv_2016)::numeric, 2) as tiv_2016 from q1
where q1.tivc > 1 and cities = 1
