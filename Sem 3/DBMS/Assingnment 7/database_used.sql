CREATE DATABASE shop;

USE shop;

CREATE TABLE store(
customerID int ,
firstname varchar(20),
lastname  varchar(30),
credit int 

);

CREATE TABLE order_details(
customerID int ,
orderID varchar(25) ,
orderdate date,
quantity int
);


INSERT INTO store VALUES(2000,"Carine","Schmitt",750);
INSERT INTO store VALUES(3000,"Helen","Bennett",751);
INSERT INTO store VALUES(4000,"Annette","Roulet",752);
INSERT INTO store VALUES(6000,"Renate","Messner",753);
INSERT INTO store VALUES(8000,"Paolo","Accorti",754);
INSERT INTO store VALUES(10000,"Daniel","Silva",755);
INSERT INTO store VALUES(11000,"Giovanni","Rovelli",756);
INSERT INTO store VALUES(12000,"Adrian","Huxley",757);



INSERT INTO order_details VALUES(2000 ,"O78945",'2020-10-06',8 );
INSERT INTO order_details VALUES(4000 ,"O78945",'2020-04-16',66 );
INSERT INTO order_details VALUES(6000 ,"O78945",'2020-12-09',45 );
INSERT INTO order_details VALUES(10000 ,"O78945",'2020-03-28',19 );
INSERT INTO order_details VALUES(23000 ,"O78945",'2020-06-13',12 );
