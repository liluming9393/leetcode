create database leetcode197;
use leetcode197;
create table Weather(Id int,Date date,Temperature int);
insert into Weather values(1,'2015-01-01',10);
insert into Weather values(2,'2015-01-02',25);
insert into Weather values(3,'2015-01-03',20);
insert into Weather values(4,'2015-01-04',30);
select * from Weather;
select Id from Weather w where Temperature > (select Temperature from Weather where Date=subdate(w.Date,1));
drop table Weather;