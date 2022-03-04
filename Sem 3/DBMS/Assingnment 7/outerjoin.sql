

USE shop;

SELECT 
	store.firstname,
	store.credit,
	order_details.quantity,
	order_details.orderdate 
FROM store
LEFT JOIN order_details ON order_details.customerID=store.customerID 
UNION ALL
SELECT 
	store.firstname,
    store.credit,
    order_details.quantity,
	order_details.orderdate 
FROM store
RIGHT JOIN order_details ON order_details.customerID=store.customerID ;