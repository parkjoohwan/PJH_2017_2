
create function FN(@str varchar(max))
returns
@names table(name varchar(25))
as
begin

	declare @ln as int;
	set @ln=len(@str);

	while( charindex(',', @str) > 0 )
	begin
	insert into @names values(substring(@str, 1, charindex(',',@str) - 1 ));
	set @str = substring(@str, charindex(',', @str) + 1, @ln);
	end;
	insert into @names values(@str);

	return;
end;