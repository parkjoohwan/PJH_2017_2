--select * from dbo.Trisides(10,300);

--select * from dbo.FN('kim yong gyu,byengshin');

--select * from sys.objects;

--select * from sys.parameters;

--select * from sys.tables;

--select * from sys.columns;

--select * from sys.objects where type = 'TF' or type = 'FN';

use CSE_DEPT;
go

create function A2T2()
returns table as
return
	select name, object_id, type, type_desc
	from sys.objects 
	where type = 'TF' or type = 'FN';

--select name, object_id, type, type_desc from sys.objects where type = 'TF' or type = 'FN';
--select * from dbo.A2T2()