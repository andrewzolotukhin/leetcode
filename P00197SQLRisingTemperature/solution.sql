# Write your MySQL query statement below

select Weather.id from Weather join Weather w2 on Weather.recordDate = w2.recordDate + INTERVAL 1 DAY and Weather.temperature > w2.temperature
