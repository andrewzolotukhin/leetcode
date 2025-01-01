/* Write your T-SQL query statement below */

SELECT 
    [Employee].[name] as [name],
    [Bonus].[bonus] as [bonus] 
FROM
    [Employee]
LEFT JOIN [Bonus] ON [Employee].[empId] = [Bonus].[empId]
WHERE ISNULL([Bonus].[bonus], 0) < 1000;
