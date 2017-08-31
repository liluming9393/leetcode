create database leetcode185;
use leetcode185;
create table Employee(Id int,Name varchar(20),Salary int,DepartmentId int);
insert into Employee values(1,'Joe',70000,1);
insert into Employee values(2,'Henry',80000,2);
insert into Employee values(3,'Sam',60000,2);
insert into Employee values(4,'Max',90000,1);
insert into Employee values(5,'Janet',69000,1);
insert into Employee values(6,'Randy',85000,1);
insert into Employee values(7,'Frank',90000,1);
select * from Employee;
create table Department(Id int,Name varchar(20));
insert into Department values(1,'IT');
insert into Department values(2,'Sales');
select * from Department;
select * from Employee inner join Department on Employee.DepartmentId=Department.Id order by Department.Id,Salary desc;
select distinct Salary,DepartmentId from Employee;

select Department.Name Department,temp.Name Employee,temp.Salary Salary from Department inner join (
select e.Id Id,min(e.Name) Name,min(e.Salary) Salary,count(*) Rank,min(e.DepartmentId) DepartmentId from Employee e,(select distinct Salary,DepartmentId from Employee) s where (e.Salary<=s.Salary && e.DepartmentId=s.DepartmentId) group by e.Id order by min(e.DepartmentId), min(e.Salary) desc) temp
on (Department.Id=temp.DepartmentId) where temp.rank<=3 order by Department, Salary desc;