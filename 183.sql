create database leetcode183;
use leetcode183;
create table Customers(Id int,Name varchar(20));
insert into Customers values(1,'Joe');
insert into Customers values(2,'Henry');
insert into Customers values(3,'Sam');
insert into Customers values(4,'Max');
select * from Customers;
create table Orders(Id int,CustomerId int);
insert into Orders values(1,3);
insert into Orders values(2,1);
select Name Customers from Customers where Id not in (select CustomerId from Orders); 