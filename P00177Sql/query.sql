CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
  RETURN QUERY (
    -- Write your PostgreSQL query statement below.
    SELECT A.Salary as Salary FROM (
    SELECT (DENSE_RANK() OVER (ORDER BY Employee.salary DESC))::INT as idx, Employee.Salary FROM Employee) A
    WHERE A.idx = N LIMIT 1
  );
END;
$$ LANGUAGE plpgsql;
