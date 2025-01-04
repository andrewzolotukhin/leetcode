/* Write your T-SQL query statement below */

select
    [Signups].[user_id] as [user_id],
    CONVERT(DECIMAL(10, 2), sum(CASE WHEN [Confirmations].[action] = 'confirmed' THEN 1 ELSE 0 END) / CONVERT(DECIMAL(10,2), count(*))) as [confirmation_rate]
FROM
    [Signups]
LEFT JOIN
    [Confirmations]
ON [Signups].[user_id] = [Confirmations].[user_id]
GROUP BY [Signups].[user_id];

