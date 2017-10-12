use CSE_DEPT
go

if OBJECT_ID('uspUpdateFaculty','P') is not null
drop procedure uspUpdateFaculty;

go

create procedure uspUpdateFaculty
		@FID varchar(50),
		@Fname varchar(50),
		@Foffice varchar(50),
		@Fphone varchar(50),
		@Fcollege varchar(50),
		@Ftitle varchar(50),
		@Femail varchar(50)
	as
	begin
	declare @cnt int;
	select @cnt = count( * )
		from dbo.Faculty
		where Faculty_id = @FID

		if @cnt < 1
		raiserror('Recode does not exist.....', 11, 1);
		else
		  update dbo.Faculty
		   set faculty_name = @Fname,
				office = @Foffice,
				phone = @Fphone,
				college = @Fcollege,
				title = @Ftitle,
				email = @Femail

				where faculty_id = @FID;
	END
	go
