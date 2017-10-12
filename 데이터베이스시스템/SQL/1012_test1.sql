use CSE_DEPT
go

if OBJECT_ID('uspAddFaculty','P') is not null
drop procedure uspAdFaculty;

go

create procedure uspAddFaculty
	@FID varchar(50),
	@Fname varchar(50),
	@Foffice varchar(50),
	@Fphone varchar(50),
	@Fcollege varchar(50),
	@Ftitle varchar(50),
	@Femail varchar(50)

	as
	begin
	insert into dbo.Faculty( faculty_id, faculty_name, office, phone, college, title, email )
					values( @FID, @Fname, @Foffice, @Fphone, @Fcollege, @Ftitle, @Femail );

	END