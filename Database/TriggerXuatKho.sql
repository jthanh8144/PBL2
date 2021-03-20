use DALT
go

create trigger trg_XuatKho
on XuatKho
for insert
as
begin
	declare @MaSP char(5)
	declare @SoLuongXuat int
	declare @SoLuongKho int
	select @MaSP = MaSP, @SoLuongXuat = SoLuong from inserted
	select @SoLuongKho = SoLuong from Kho where MaSP = @MaSP
	if @SoLuongXuat > @SoLuongKho or @SoLuongXuat < 0
		rollback transaction
	else
		update Kho
		set SoLuong = SoLuong - @SoLuongXuat
		where MaSP = @MaSP
end