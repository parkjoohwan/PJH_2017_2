use CSE_DEPT
go

create function myFirstFun(@p1 int, @p2 int) returns int
as
begin
return @p1+@p2;
end
