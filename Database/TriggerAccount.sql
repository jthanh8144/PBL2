use DALT
go

create trigger trg_Account
on ThongTinNhanVien
for insert
as
begin
	declare @ID char(10)
	select @ID = MaNV from inserted
	insert Account values (@ID, '1')
end