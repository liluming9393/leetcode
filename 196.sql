create database leetcode196;
use leetcode196;
create table Person(Id int primary key,Email varchar(40));
insert into Person values(1,'john@example.com');
insert into Person values(2,'bob@example.com');
insert into Person values(3,'john@example.com');
select * from Person;
delete from Person where Id in (select Id from(select a.Id from Person a inner join Person b on a.Email=b.Email && a.Id>b.Id) temp);
drop table Person;