CREATE DATABASE Students;
USE Students;
CREATE TABLE student (
ID INT NOT NULL PRIMARY KEY,
Student_Name VARCHAR(30),
DOB DATE,
Mobile_Number MEDIUMINT(11),
City TEXT(10),
Branch_Code CHAR(3),
Graduation_Year YEAR,
Coder_0or1 BOOL
);
INSERT INTO student
VALUES (1 , 'Student1', '1999-01-01', 1234554, 'XYZ', 'BR', 2021 , 1);
INSERT INTO student
VALUES (2 ,'Student2', '1999-02-01', 123454, 'ABC', 'RB', 2022 , 0);
INSERT INTO student
VALUES (5 ,'Student5', '1999-05-01', 1234454, 'PQR', 'BD', 2024 , 1);
SELECT * FROM student;