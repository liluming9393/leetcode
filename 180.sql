create database leetcode180;
use leetcode180;
create table Logs(Id int,Num int);
insert into Logs values(1,1);
insert into Logs values(2,1);
insert into Logs values(3,1);
insert into Logs values(4,2);
insert into Logs values(5,1);
insert into Logs values(6,2);
insert into Logs values(7,2);
select * from Logs;
select Num ConsecutiveNums from Logs a where Num=(select Num from Logs where Id=(a.Id+1)) && Num=(select Num from Logs where Id=(a.Id+2)) group by Num;