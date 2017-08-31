create database leetcode177;
use leetcode177;
create table Employee(Id int,Salary int);
insert into Employee values(1,100);
insert into Employee values(2,200);
insert into Employee values(3,300);
select * from Employee;
drop function if exists getNthHighestSalary; 
delimiter $$
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  declare num int;
  set num=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct Salary from Employee order by Salary desc limit num,1
  );
END$$
delimiter ;
select getnthhighestsalary(2);