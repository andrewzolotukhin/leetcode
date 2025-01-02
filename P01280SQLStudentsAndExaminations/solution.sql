/* Write your T-SQL query statement below */

SELECT 
    [Students].[student_id] as [student_id],
    [Students].[student_name] as [student_name],
    [Subjects].[subject_name] as [subject_name],
    sum(CASE ISNULL([Examinations].[subject_name], '') WHEN '' THEN 0 ELSE 1 END) AS [attended_exams]
FROM [Students]
CROSS JOIN [Subjects]
LEFT JOIN [Examinations] ON [Examinations].[student_id] = [Students].[student_id] AND [Subjects].[subject_name] = [Examinations].[subject_name]
GROUP BY [Students].[student_id], [Students].[student_name], [Subjects].[subject_name]
ORDER BY [Students].[student_id], [Subjects].[subject_name]
