WITH c AS (
  SELECT num, COUNT(*) AS cnt
  FROM MyNumbers
  GROUP BY num
)
SELECT *
FROM (
  SELECT CASE 
           WHEN c.cnt <> 1 THEN NULL 
           ELSE c.num 
         END AS num
  FROM c
  ORDER BY c.cnt asc, c.num DESC
)
WHERE ROWNUM = 1;

