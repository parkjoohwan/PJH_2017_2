use CSE_DEPT
go

if OBJECT_ID('uspDeleteFaculty','P') is not null
drop procedure uspDeleteFaculty;

go

create procedure uspDeleteFaculty
	@FID varchar(50)

	as
	begin
	declare @cnt int;
	select @cnt = count( * )
		from dbo.Faculty
		where Faculty_id = @FID

		if @cnt < 1
		raiserror('Recode does not exist.....', 11, 1);
		else
		  delete from dbo.Faculty
					where faculty_id = @FID;

	END
