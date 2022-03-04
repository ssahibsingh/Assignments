USE shop;

SELECT 
	store.firstname,
    store.credit,
    order_details.quantity,
    order_details.orderdate
FROM order_details
RIGHT JOIN store ON order_details.customerID=store.customerID ;

SELECT
	store.firstname,
    store.credit,
    order_details.quantity,
    order_details.orderdate
FROM store
RIGHT JOIN order_details ON store.customerID=order_details.customerID ;