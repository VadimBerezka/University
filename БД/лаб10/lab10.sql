--1
use UNIVER;
exec sp_helpindex 'AUDITORIUM_TYPE'

CREATE table #EX
	(
	TKEY int, 
	TF varchar(10)
	);
  set nocount on;           
  declare @i int = 0;
  while   @i < 1000
  begin
       INSERT #EX(TKEY, TF) values(floor(30000*RAND()), 'вадим');
       set @i = @i + 1; 
  end;
  SELECT * FROM #EX
  SELECT * FROM #EX WHERE TKEY BETWEEN 600 AND 700 order by TKEY;
  --drop table #EX

  checkpoint;
  DBCC DROPCLEANBUFFERS;
  CREATE clustered index #EX_CL on #EX(TKEY);
  drop index #EX_CL on #EX;

  --2
  CREATE table #EX2
	(  
	TKEY int, 
	CC int identity(1, 1),
	TF varchar(100)
	);

  set nocount on;           
  declare @i2 int = 0;
  while   @i2 < 10000
  begin
       INSERT #EX2(TKEY, TF) values(floor(30000*RAND()), replicate('строка ', 10));
        set @i2 = @i2 + 1; 
  end;

	--drop table #EX2
	SELECT count(*)[количество строк] from #EX2;


	CREATE index #EX2_NONCLU on #EX2(TKEY, CC)
	drop index #EX2_NONCLU on #EX2;
	SELECT * from  #EX2 where  TKEY = 1500 and  CC < 4500;  
	select * from #EX2
	--3
	CREATE table #EX3
	(  
	TKEY int, 
	CC int identity(1, 1),
	TF varchar(100)
	);

  set nocount on;           
  declare @i3 int = 0;
  while   @i3 < 10000
  begin
       INSERT #EX3(TKEY, TF) values(floor(30000*RAND()), replicate('строка ', 10));
        set @i3 = @i3 + 1; 
  end;


  CREATE  index #EX3_TKEY_X on #EX3(TKEY) INCLUDE (CC)
  drop index #EX3_TKEY_X on #EX3;
  SELECT CC from #EX3 where TKEY>15000 
  SELECT TKEY from #EX3 where CC>15000 
  select * from #EX3
  --drop table #EX3

  --4
	CREATE table #EX4
	(  
	TKEY int, 
	CC int identity(1, 1),
	TF varchar(100)
	);

  set nocount on;           
  declare @i4 int = 0;
  while   @i4 < 10000
  begin
       INSERT #EX4(TKEY, TF) values(floor(30000*RAND()), replicate('строка ', 10));
        set @i4 = @i4 + 1; 
  end;
    select * from #EX4
	  --drop table #EX4

SELECT TKEY from  #EX4 where TKEY between 5000 and 19999; 
SELECT TKEY from  #EX4 where TKEY>15000 and  TKEY < 20000  
SELECT TKEY from  #EX4 where TKEY=17000

CREATE  index #EX4_WHERE on #EX4(TKEY) where (TKEY>=15000 and TKEY < 20000);  
drop index #EX4_WHERE on #EX4;

--5
CREATE   index #EX4_TKEY ON #EX4(TKEY); 
SELECT name [Индекс], avg_fragmentation_in_percent [Фрагментация (%)]
FROM sys.dm_db_index_physical_stats(DB_ID(N'TEMPDB'), 
OBJECT_ID(N'#EX4'), NULL, NULL, NULL) ss  JOIN sys.indexes ii on ss.object_id = ii.object_id and ss.index_id = ii.index_id  WHERE name is not null;
INSERT top(10000) #EX4(TKEY, TF) select TKEY, TF from #EX4;

ALTER index #EX4_TKEY on #EX4 reorganize;

ALTER index #EX4_TKEY on #EX4 rebuild with (online = off);

--6
DROP index #EX4_TKEY on #EX4;
    CREATE index #EX4_TKEY on #EX4(TKEY)
	with (fillfactor = 65);
    INSERT top(50)percent INTO #EX4(TKEY, TF) 
    SELECT TKEY, TF  FROM #EX4;
SELECT name [Индекс], avg_fragmentation_in_percent [Фрагментация (%)]
FROM sys.dm_db_index_physical_stats(DB_ID(N'TEMPDB'),    
OBJECT_ID(N'#EX4'), NULL, NULL, NULL) ss  JOIN sys.indexes ii 
ON ss.object_id = ii.object_id and ss.index_id = ii.index_id  WHERE name is not null;
select * from #EX4
drop table #EX4

