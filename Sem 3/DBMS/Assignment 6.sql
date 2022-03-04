-- IN Operator 
SELECT * FROM employees
WHERE officeCode IN (1, 2, 4)
ORDER BY officeCode;

-- BETWEEN Operator 
SELECT * FROM orders
WHERE orderDate BETWEEN '2003-01-01' AND '2003-02-28'
ORDER BY orderDate;

-- ALIASES
SELECT firstName AS First_Name, lastName AS Last_Name 
FROM employees;

-- GROUP BY Statement
SELECT city, COUNT(city) AS 'No. of Offices' FROM classicmodels.offices
GROUP BY city;

-- HAVING Clause
SELECT customerNumber, COUNT(customerNumber) AS 'No. of Transaction' FROM payments
GROUP BY customerNumber
HAVING COUNT(customerNumber) > 3
ORDER BY customerNumber;

-- EXISTS
SELECT * FROM offices
WHERE EXISTS
(SELECT * FROM employees
WHERE officeCode IN (1, 2, 4)
ORDER BY officeCode);


 

