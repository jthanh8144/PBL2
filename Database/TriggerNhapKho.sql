use DALT
go

create trigger trg_NhapKho
on NhapKho
for insert
as
begin
	declare @MaSP char(5)
	declare @SoLuongNhap int
	declare @SoLuongKho int
	select @MaSP = MaSP, @SoLuongNhap = SoLuong from inserted
	if @SoLuongNhap < 0 
		rollback transaction
	else
		update Kho
		set SoLuong = SoLuong + @SoLuongNhap
		where MaSP = @MaSP
end