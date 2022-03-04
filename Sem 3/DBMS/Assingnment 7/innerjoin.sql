USE shop;

SELECT * FROM store 
INNER JOIN order_details ON store.customerID = order_details.customerID;

SELECT 
	store.firstname,
	store.credit,
    order_details.quantity,
    order_details.orderdate 
FROM order_details
INNER JOIN store ON order_details.customerID=store.customerID ;