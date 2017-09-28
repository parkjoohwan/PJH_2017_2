use CSE_DEPT
go


if object_id('Trisides') is not null
drop function Trisides
go

create function Trisides(@srange int, @erange int)
returns @triTable table (s1 int, s2 int, s3 int)  
as
begin
declare @s1 as int;
declare @s2 as int;
declare @s3 as int;

	set @s1 = @srange;
	while(@s1<=@erange)
	begin
		set @s2=@srange;
		while(@s2<=@erange)
		begin
			set @s3=@srange;
			while(@s3<=@erange)
			begin
				if (power(@s1,2)+power(@s2,2)=power(@s3,2) )
					insert into @triTable values(@s1,@s2,@s3);
			set @s3=@s3+1;
			end
		set @s2=@s2+1;
		end
		set @s1=@s1+1;
	end;
	return;
end