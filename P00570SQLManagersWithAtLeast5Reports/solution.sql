/* Write your T-SQL query statement below */

SELECT [Employee].[name] as [name]
FROM (
SELECT 
    [managerId]
FROM
    [Employee]
WHERE
    [managerId] IS NOT NULL
GROUP BY [managerId]
HAVING count(*) > 4) [a]
JOIN [Employee] ON [a].[managerId] = [Employee].id;
