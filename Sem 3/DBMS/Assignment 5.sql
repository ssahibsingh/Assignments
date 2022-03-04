
-- UPDATE 
UPDATE employees 
SET lastName = 'JOSEPH' 
WHERE employeeNumber = 1143;

SELECT * FROM employees;

-- DELETE
DELETE FROM payments 
WHERE customerNumber IN (103, 141) AND AMOUNT < 5000;
SELECT *  FROM payments LIMIT 10;

-- LIMIT
SELECT * FROM employees 
LIMIT 5;

-- MIN and MAX
SELECT MAX(amount) , MIN(amount) FROM payments;

-- COUNT, SUM, AVG
SELECT 
	SUM(amount) AS "Total Amount",
    COUNT(customerNumber) AS "Total Customers",
    AVG(amount) AS "Average Amount Per Customer" 
FROM payments;

-- LIKE
SELECT firstName, lastName FROM employees WHERE firstName LIKE 's%';
SELECT firstName, lastName FROM employees WHERE firstName LIKE '%e';
SELECT firstName, lastName FROM employees WHERE firstName LIKE 's_%';
SELECT firstName, lastName FROM employees WHERE firstName LIKE '% %';

