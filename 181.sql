create database leetcode181;
use leetcode181;
create table Employee(Id int,Name varchar(20),Salary int,ManagerId int);
insert into Employee values(1,'Joe',70000,3);
insert into Employee values(2,'Henry',80000,4);
insert into Employee values(3,'Sam',60000,null);
insert into Employee values(4,'Max',90000,null);
select * from Employee;
select Name Employee from Employee e where Salary>(select Salary from Employee t where e.ManagerId=t.Id);