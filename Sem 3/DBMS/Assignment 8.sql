CREATE DATABASE Departments;

BACKUP DATABASE databasename
TO DISK = 'filepath';


CREATE TABLE Employee(
	EmpNo INT NOT NULL UNIQUE AUTO_INCREMENT,
	DeptID VARCHAR(5)  UNIQUE NOT NULL,
	UID VARCHAR(10) PRIMARY KEY ,
	Name VARCHAR(35),
	Department VARCHAR(35) UNIQUE,
	Age INT CHECK ( Age > 18  AND Age < 40 ),
	Working_Hours INT DEFAULT '15'
); 

INSERT INTO Employee (DeptID, UID, Name, Department, Age, Working_Hours) VALUES("PR159", "PRO2021", "Kelsey Mclean" ,"PRODUCTION", 23, 23);

INSERT INTO Employee (DeptID, UID, Name, Department, Age, Working_Hours) VALUES("R75", "RES2018", "Elaina Brady", "RESEARCH", 26, 30);

INSERT INTO Employee (DeptID, UID, Name, Department, Age, Working_Hours) VALUES("PU42", "PUR2021", "Kaiya Schaefer", "PURCHASING" , 22, 35);

INSERT INTO Employee (DeptID, UID, Name, Department, Age, Working_Hours) VALUES("MA48", "MAR2015", "Alisson Harmon", "MARKETING" , 32, 32);

INSERT INTO Employee (DeptID, UID, Name, Department, Age, Working_Hours) VALUES("HR415", "HRM2017", "Kaylyn Payne", "HUMAN RESOURCE MANAGEMENT", 36, 38);

INSERT INTO Employee (DeptID, UID, Name, Department, Age, Working_Hours) VALUES("AF147", "AAF2021", "Keaton Wright", "ACCOUNTING AND FINANCE", 21, 37 );


SELECT * FROM Employee;


CREATE TABLE Employee_Scores(
	TeamID VARCHAR(10) PRIMARY KEY ,
	UID VARCHAR(10),
	Score VARCHAR(5) NOT NULL,
FOREIGN KEY (UID) REFERENCES Employee(UID));


INSERT INTO Employee_Scores (TeamID, UID, Score) VALUES("R75", "RES2018", "862");

INSERT INTO Employee_Scores (TeamID, UID, Score) VALUES("PU42", "PUR2021", "654");

INSERT INTO Employee_Scores (TeamID, UID, Score) VALUES("HRM415", "HRM2017", "915");

INSERT INTO Employee_Scores (TeamID, UID, Score) VALUES("AF147", "AAF2021", "531");

SELECT * FROM Employee_Scores;
 
CREATE INDEX SkillScore ON Employee_Scores(TeamID, Score);




ALTER TABLE Employee_Scores MODIFY COLUMN Score INT;
ALTER TABLE Employee_Scores ADD City VARCHAR(20) DEFAULT 'JALANDHAR';

SELECT * FROM Employee_Scores;



DROP TABLE Employee_Scores;


DROP DATABASE Departments;