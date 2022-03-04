USE classicmodels;

-- * Statement
SELECT * FROM offices;

-- 'Attribute'
SELECT orderNumber, productCode FROM orderdetails LIMIT 6;

-- DISTINCT 
SELECT DISTINCT city , count(city) 
FROM customers 
GROUP BY city LIMIT 10;

SELECT DISTINCT country
FROM customers 
ORDER BY country;

-- WHERE Clause
SELECT checknumber, amount 
FROM payments 
WHERE amount > 80000.00;

-- OR Operations
SELECT orderlinenumber, (quantityordered) "Quantity:" 
FROM orderdetails 
WHERE orderlinenumber = 15 OR orderlineNumber = 14 LIMIT 10;

-- AND Operations
SELECT orderlinenumber, (quantityordered) "Quantity:" 
FROM orderdetails 
WHERE orderlinenumber < 12 AND orderlineNumber > 10 LIMIT 10;

-- NOT Operations
SELECT customerName, city 
FROM customers 
WHERE city NOT IN ('norway' , 'nantes' , 'frankfurt') LIMIT 10;

-- ORDER BY
SELECT * FROM customers 
WHERE country = 'USA' 
ORDER BY CITY DESC LIMIT 10;

-- NULL Values
SELECT ordernumber ,status ,comments 
FROM orders 
WHERE comments IS NOT NULL AND STATUS = 'shipped' LIMIT 10;

SELECT * FROM orders 
WHERE shippeddate IS NULL;