use CSE_DEPT;
go

declare @i as int, @name varchar(50), @dob date;
declare @a as time;

set @i = 10;
set @name = 'Tariq';
set @dob = '2000/10/10';
set @a = '16:20';

print @i;
print @name;
print @dob;
print @a;

end 

go 

declare @t table ( id int, nam varchar(20), dob date );

insert into @t values(1011, 'Tariq', '2000/10/10');
insert into @t values(1012, 'abdul Hamid', '2010/10/10');
insert into @t values(1013, 'M Tariq', '2003/10/10');

select * from @t;
go
