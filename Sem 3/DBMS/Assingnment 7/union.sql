USE shop;

SELECT firstname, lastname , credit FROM store 
UNION
SELECT orderid, orderdate , quantity FROM order_details;