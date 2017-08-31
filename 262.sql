create database leetcode262;
use leetcode262;
create table Trips(Id int,Client_Id int,Driver_Id int,City_Id int,Status varchar(20),Request_at date);
desc Trips;
insert into Trips values(1,1,10,1,'completed','2013-10-01');
insert into Trips values(2,2,11,1,'cancelled_by_driver','2013-10-01');
insert into Trips values(3,3,12,6,'completed','2013-10-01');
insert into Trips values(4,4,13,6,'cancelled_by_client','2013-10-01');
insert into Trips values(5,1,10,1,'completed','2013-10-02');
insert into Trips values(6,2,11,6,'completed','2013-10-02');
insert into Trips values(7,3,12,6,'completed','2013-10-02');
insert into Trips values(8,2,12,12,'completed','2013-10-03');
insert into Trips values(9,3,10,12,'completed','2013-10-03');
insert into Trips values(10,4,13,12,'cancelled_by_driver','2013-10-03');
insert into Trips values(11,1,10,1,'completed','2013-10-04');
select * from Trips;
create table Users(Users_Id int,Banned varchar(3),Role varchar(10));
desc Users;
insert into Users values(1,'NO','client');
insert into Users values(2,'Yes','client');
insert into Users values(3,'NO','client');
insert into Users values(4,'NO','client');
insert into Users values(10,'NO','driver');
insert into Users values(11,'NO','driver');
insert into Users values(12,'NO','driver');
insert into Users values(13,'NO','driver');
select * from Users;
drop table Trips;

select temp2.Request_at Day,round(ifnull(temp1.cancelled_count,0)/temp2.total_count,2) AS 'Cancellation Rate' from
(select Request_at,count(*) cancelled_count from Trips inner join Users on(Trips.Client_Id=Users.Users_Id && Users.Banned='No' && Trips.Status!='completed') group by Request_at order by Request_at asc) temp1
right join 
(select Request_at,count(*) total_count from Trips inner join Users on(Trips.Client_Id=Users.Users_Id && Users.Banned='No' && Trips.Request_at<='2013-10-03' && Trips.Request_at>='2013-10-01') group by Request_at order by Request_at asc) temp2
on (temp1.Request_at=temp2.Request_at );

