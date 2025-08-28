# Write your MySQL query statement below

select
Users.name as name,
sum(amount) as balance 
from
Users
join Transactions on Transactions.account = Users.account
group by Users.name
having balance > 10000;
