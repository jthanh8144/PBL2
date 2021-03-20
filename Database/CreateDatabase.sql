--create database DALT
--go

use DALT
go

create table ThongTinNhanVien
(
	MaNV char(10) primary key,
	HoTen char(45),
	NgaySinh date,
	GioiTinh char(5),
	SDT char(15),
	ChucVu char(15),
	DiaChi varchar(50)
)
go

insert dbo.ThongTinNhanVien values
('001', 'Vo Van Thanh', '20011101', 'Nam', '0782378407', 'Quan li', 'Dien Ban, Quang Nam'),
('002', 'Nguyen Duy Thinh', '20010130', 'Nam', '0334487232', 'Quan li', 'Hue'),
('003', 'Do Nhat Anh', '20001209', 'Nam', '0832179782', 'Ki thuat vien', 'Da Nang'),
('004', 'Phan Van Binh', '20010907', 'Nam', '0974521457', 'Ki thuat vien', 'Hue'),
('005', 'Le Hoang Ngoc Han', '20010608', 'Nu', '0918817826', 'Tu van vien', 'Da Nang'),
('006', 'Bui Viet Huy Hoang', '20010606', 'Nam', '0785134080', 'Nhan vien kho', 'Quang Nam'),
('007', 'Nguyen Thai Loc', '20010409', 'Nam', '0905421172', 'Nhan vien kho', 'Da Nang'),
('008', 'Tran Thi Phuong', '20010722', 'Nu', '0336615425', 'Tu van vien', 'Quang Nam'),
('009', 'Le Thanh Quy', '20011014', 'Nam', '0384933379', 'Thu ngan', 'Quang Nam'),
('010', 'Nguyen Huy Tuong', '20010101', 'Nam', '0965223769', 'FE', 'Quang Nam'),
('011', 'Ho Van Vy', '20010501', 'Nu', '0961882993', 'FE', 'Hue'),
('012', 'Le Thanh Long', '19980909', 'Nam', '0796823436', 'Thu ngan', 'Da Nang'),
('053', 'NTNB', '20010305', 'Nu', '0000000000', 'Sell', 'Quang Nam')
/*------------------------------------------------------------------------------------------------------*/
create table ThongTinKhachHang
(
	MaKH char(10) primary key,
	TenKH char(45),
	SDT char(15),
	DiaChi varchar(50)
)
go

insert dbo.ThongTinKhachHang values 
('001', 'Vo Van Thanh', '0782378407', '8 Ha Van Tinh, Da Nang'),
('002', 'Nguyen Duy Thinh', '0334487232', 'Hue')
/*------------------------------------------------------------------------------------------------------*/

create table ThongTinSanPham
(
	MaModel char(5) primary key,
	Hang char(10),
	TenSP char(20) not null,
	XuatXu char(20),
	NSX date
)
go

insert dbo.ThongTinSanPham values 
('AC1', 'Acer', 'Nitro 5', 'China', '20200604'),
('AC2', 'Acer', 'Swift 3', 'China', '20200615'),
('AC3', 'Acer', 'Predator Helios 300', 'China', '20200804'),
('AP1', 'Apple', 'Macbook Pro', 'USA', '20200505'),
('AP2', 'Apple', 'Macbook Air', 'USA', '20191212'),
('AS1', 'Asus', 'Strix G531', 'Taiwan', '20191101'),
('AS2', 'Asus', 'Tuf Fx505', 'Taiwan', '20190305'),
('AS3', 'Asus', 'Vivobook S15', 'Taiwan', '20200101'),
('D1', 'Dell', 'Alienware M15', 'USA', '20200101'),
('D2', 'Dell', 'Gaming G3', 'USA', '20190606'),
('D3', 'Dell', 'XPS 15', 'USA', '20200303'),
('H1', 'HP', 'Omen 15 2020', 'China', '20200102'),
('H2', 'HP', 'Pavilion 15 2020', 'China', '20200202'),
('H3', 'HP', 'EliteBook 840', 'China', '20200404'),
('L1', 'Lenovo', 'Legion Y540', 'China', '20200921'),
('L2', 'Lenovo', 'ThinkPad E14', 'China', '20200921'),
('L3', 'Lenovo', 'Ideapad S145', 'China', '20200921'),
('M1', 'MSI', 'GF63', 'China', '20201120'),
('M2', 'MSI', 'Bravo 15', 'China', '20201020'),
('M3', 'MSI', 'Modern 14', 'China', '20200308')
/*------------------------------------------------------------------------------------------------------*/
create table CauHinhChiTiet
(
	MaSP char(5) primary key,
	MaModel char(5) not null foreign key references dbo.ThongTinSanPham (MaModel),
	ManHinh char(10),
	CPU char(20),
	GPU char(45),
	RAM char(10),
	LuuTru char(20),
	[Pin(Wh)] int,
	[KhoiLuong(Kg)] float,
	Gia int,
)
go

insert dbo.CauHinhChiTiet values
('AC1A', 'AC1', '15.6" FHD', 'i5 9300H', 'GTX 1650/ Intel UHD Graphics 630', '8GB DDR4', '512GB SSD', 55, 2.3, 19990000),
('AC1B', 'AC1', '15.6" FHD', 'i7 9750H', 'GTX 1650/ Intel UHD Graphics 630', '8GB DDR4', '512GB SSD', 55, 2.3, 23990000),
('AC1C', 'AC1', '15.6" FHD', 'i7 9750H', 'GTX 1660Ti/ Intel UHD Graphics 630', '8GB DDR4', '512GB SSD', 55, 2.3, 27990000),
('AC2A', 'AC2', '14" FHD', 'i3 8145U', 'Intel UHD Graphics 620', '4GB DDR4', '256GB SSD', 45, 1.5, 11990000),
('AC2B', 'AC2', '14" FHD', 'i5 8250U', 'Intel UHD Graphics 620', '4GB DDR4', '1TB HDD', 45, 1.5, 15907000),
('AC2C', 'AC2', '15.6" FHD', 'i5 8250U', 'Intel UHD Graphics 620', '8GB DDR4', '256GB SSD', 48, 1.7, 18890000),
('AC3A', 'AC3', '15.6" FHD', 'i7 9750H', 'GTX 1660Ti/ Intel UHD Graphics 630', '8GB DDR4', '512GB SSD',58, 2.3, 34490000),
('AC3B', 'AC3', '15.6" FHD', 'i7 9750H', 'RTX 2060/ Intel UHD Graphics 630', '16GB DDR4', '256GB SSD', 59, 2.4, 41990000),
('AP1A', 'AP1', '16" ', 'i7', 'AMD Radeon Pro 5300M/ Intel UHD Graphics 630', '16GB', '512GB SSD', 100, 2, 58190000),
('AP1B', 'AP1', '13.3" ', 'i5', 'Intel HD Graphics', '16GB', '256GB SSD', '', 1.4, 44390000),
('AP2A', 'AP2', '13.3" ', 'i3', 'Intel Iris Plus Graphics', '8GB', '256GB SSD', '', 1.3, 26590000),
('AP2B', 'AP2', '13.3" ', 'i5', 'Intel Iris Plus Graphics', '8GB', '512GB SSD', '', 1.3, 33490000),
('AS1A', 'AS1', '15.6" FHD', 'i5 9300H', 'GTX 1650/ Intel UHD Graphics 630', '8GB DDR4', '512GB SSD', 66, 2.4, 19290000),
('AS1B', 'AS1', '15.6" FHD', 'i7 9750H', 'GTX 1650/ Intel UHD Graphics 630', '8GB DDR4', '512GB SSD', 66, 2.4, 22990000),
('AS1C', 'AS1', '15.6" FHD', 'i7 9750H', 'RTX 2060/ Intel UHD Graphics 630', '8GB DDR4', '512GB SSD', 66, 2.4, 24990000),
('AS2A', 'AS2', '15.6" FHD', 'AMD Ryzen 5 3500H', 'GTX 1050/ Intel UHD Graphics 630', '8GB DDR4', '1TB HDD', 48, 2.2, 14290000),
('AS2B', 'AS2', '15.6" FHD', 'i5 9300H', 'GTX 1650/ Intel UHD Graphics 630', '8GB DDR4', '512GB SSD', 48, 2.2, 17990000),
('AS2C', 'AS2', '15.6" FHD', 'AMD Ryzen 7 3750H', 'GTX 1650/ Intel UHD Graphics 630', '8GB DDR4', '512GB SSD', 48, 2.2, 18490000),
('AS3A', 'AS3', '15.6" FHD', 'i5 8265U', 'Intel UHD Graphics 620', '4GB DDR4', '1TB HDD', 42, 1.8, 14890000),
('AS3B', 'AS3', '15.6" FHD', 'i5 8250U', 'NVIDIA MX150/ Intel UHD Graphics 620', '4GB DDR4', '1TB HDD', 42, 1.8, 16390000),
('D1', 'D1', '15.6" FHD', 'i7 9750H', 'RTX 2060/ Intel UHD Graphics 630', '8GB DDR4', '1TB SSHD', 60, 2.16, 41900000),
('D2A', 'D2', '15.6" FHD', 'i5 9300H', 'GTX 1650/ Intel UHD Graphics 630', '8GB DDR4', '512GB SDD', 51, 2.3, 22690000),
('D2B', 'D2', '15.6" FHD', 'i7 9750H', 'GTX 1660Ti/ Intel UHD Graphics 630', '8GB DDR4', '512GB SDD', 51, 2.3, 25690000),
('D3', 'D3', '15.6" FHD', 'i5 10300H', 'Intel UHD Graphics 630', '8GB DDR4', '256GB SDD', 86, 2, 37990000),
('H1', 'H1', '15.6" FHD', 'i7 10750H', 'RTX 2060/ Intel UHD Graphics 630', '16GB DDR4', '512GB SSD', 71, 2.46, 39990000),
('H2A', 'H2', '15.6" FHD', 'i5 1035G1', 'Intel UHD Graphics', '4GB DDR4', '256GB SSD', 41, 1.7, 14000000),
('H2B', 'H2', '15.6" FHD', 'i5 1035G1', 'Intel UHD Graphics', '8GB DDR4', '512GB SSD', 41, 1.7, 16000000),
('H3', 'H3', '14" FHD', 'i5 4200U', 'Intel HD Graphics 4400', '4GB DDR4', '120GB SSD', 40, 1.58, 6700000),
('L1A', 'L1', '15.6" FHD', 'i5 9300H', 'GTX 1650/ Intel UHD Graphics 630', '8GB DDR4', '128GB SSD', 52, 2.3, 18900000),
('L1B', 'L1', '15.6" FHD', 'i7 9750H', 'GTX 1650/ Intel UHD Graphics 630', '8GB DDR4', '128GB SSD + 1TB HDD', 52, 2.3, 22450000),
('L2', 'L2', '14" FHD', 'i5 10210U', 'Intel UHD Graphics', '4GB DDR4', '256GB SSD', 45, 1.7, 16090000),
('L3A', 'L3', '14" FHD', 'AMD Ryzen 3 3200U', 'AMD Radeon Vega 3 Graphics', '4GB DDR4', '256GB SSD', 30, 1.6, 9450000),
('L3B', 'L3', '15.6" FHD', 'i5 1035G1', 'Intel UHD Graphics', '4GB DDR4', '256GB SSD', 35, 1.8, 12990000),
('M1A', 'M1', '15.6" FHD', 'i5 9300H', 'GTX 1650/ Intel UHD Graphics 630', '8GB DDR4', '512GB SSD', 51, 1.9, 12990000),
('M1B', 'M1', '15.6" FHD', 'i7 10750H', 'GTX 1650/ Intel UHD Graphics 630', '8GB DDR4', '512GB SSD', 51, 1.9, 25990000),
('M2', 'M2', '15.6" FHD', 'AMD Ryzen 5 4600H', 'AMD Radeon RX 5300M', '8GB DDR4', '256GB SSD', 51, 2, 17790000),
('M3A', 'M3', '14" FHD', 'i5 10210U', 'Intel UHD Graphics', '8GB DDR4', '256GB SSD', 50, 1.2, 18090000),
('M3B', 'M3', '14" FHD', 'i7 10510U', 'NVIDIA MX330/ Intel UHD Graphics', '8GB DDR4', '512GB SSD', 50, 1.2, 23490000)
/*------------------------------------------------------------------------------------------------------*/
create table Account
(
	ID char(10) foreign key references dbo.ThongTinNhanVien (MaNV),
	Pass varchar(20)
)
go

insert dbo.Account values
('001', 'tB538144'),
('002', '456'),
('003', '123'),
('004', '123'),
('005', '123'),
('006', '123'),
('007', '123'),
('008', '123'),
('009', '123'),
('010', '123'),
('011', '123'),
('012', '123'),
('053', '000')
/*------------------------------------------------------------------------------------------------------*/
create table Kho
(
	MaSP char(5) foreign key references dbo.CauHinhChiTiet (MaSP),
	SoLuong int
)

insert dbo.Kho
values ('AC1A', 30),
	   ('AC1B', 30),
	   ('AC1C', 20),
	   ('AC2A', 30),
	   ('AC2B', 30),
	   ('AC2C', 30),
	   ('AC3A', 10),
	   ('AC3B', 10),
	   ('AP1A', 10),
	   ('AP1B', 10),
	   ('AP2A', 10),
	   ('AP2B', 10),
	   ('AS1A', 30),
	   ('AS1B', 30),
	   ('AS1C', 30),
	   ('AS2A', 30),
	   ('AS2B', 30),
	   ('AS2C', 30),
	   ('AS3A', 30),
	   ('AS3B', 30),
	   ('D1', 5),
	   ('D2A', 30),
	   ('D2B', 30),
	   ('D3', 10),
	   ('H1', 10),
	   ('H2A', 30),
	   ('H2B', 10),
	   ('H3', 30),
	   ('L1A', 30),
	   ('L1B', 30),
	   ('L2', 30),
	   ('L3A', 30),
	   ('L3B', 30),
	   ('M1A', 30),
	   ('M1B', 30),
	   ('M2', 30),
	   ('M3A', 30),
	   ('M3B', 30)
/*------------------------------------------------------------------------------------------------------*/
create table NhapKho
(
	MaSP char(5),
	SoLuong int,
	DonGia int,
	NoiNhap char(15),
	ThoiGianNhap date,
	NhanVienNhap char(10),

	foreign key (MaSP) references dbo.CauHinhChiTiet(MaSP),
	foreign key (NhanVienNhap) references dbo.ThongTinNhanVien(MaNV)
)
go

insert dbo.NhapKho values
('AC1A', 30, 17990000, 'Acer VN Inc', '20200922', '001'),
('AC1B', 30, 21990000, 'Acer VN Inc', '20200922', '001'),
('AC1C', 20, 25990000, 'Acer VN Inc', '20200922', '001'),
('AC2A', 30, 9990000, 'Acer VN Inc', '20200922', '001'),
('AC2B', 30, 13907000, 'Acer VN Inc', '20200922', '001'),
('AC2C', 30, 16890000, 'Acer VN Inc', '20200922', '001'),
('AC3A', 10, 32490000, 'Acer VN Inc', '20200922', '001'),
('AC3B', 10, 39990000, 'Acer VN Inc', '20200922', '001'),
('AP1A', 10, 56190000, 'Apple VN Inc', '20200922', '001'),
('AP1B', 10, 42390000, 'Apple VN Inc', '20200922', '001'),
('AP2A', 10, 24590000, 'Apple VN Inc', '20200922', '001'),
('AP2B', 10, 31490000, 'Apple VN Inc', '20200922', '001'),
('AS1A', 30, 17290000, 'Asus VN Inc', '20200922', '001'),
('AS1B', 30, 20990000, 'Asus VN Inc', '20200922', '001'),
('AS1C', 30, 22990000, 'Asus VN Inc', '20200922', '001'),
('AS2A', 30, 12290000, 'Asus VN Inc', '20200922', '001'),
('AS2B', 30, 15990000, 'Asus VN Inc', '20200922', '001'),
('AS2C', 30, 15490000, 'Asus VN Inc', '20200922', '001'),
('AS3A', 30, 12890000, 'Asus VN Inc', '20200922', '001'),
('AS3B', 30, 14390000, 'Asus VN Inc', '20200922', '001'),
('D1', 5, 39900000, 'Dell VN Inc', '20200922', '001'),
('D2A', 30, 20690000, 'Dell VN Inc', '20200922', '001'),
('D2B', 30, 23690000, 'Dell VN Inc', '20200922', '001'),
('D3', 10, 35990000, 'Dell VN Inc', '20200922', '001'),
('H1', 10, 37990000, 'Hp VN Inc', '20200922', '002'),
('H2A', 30, 12000000, 'Hp VN Inc', '20200922', '002'),
('H2B', 10, 14000000, 'Hp VN Inc', '20200922', '002'),
('H3', 30, 4700000, 'Hp VN Inc', '20200922', '002'),
('L1A', 30, 16900000, 'Lenovo VN Inc', '20200922', '002'),
('L1B', 30, 20450000, 'Lenovo VN Inc', '20200922', '002'),
('L2', 30, 14090000, 'Lenovo VN Inc', '20200922', '002'),
('L3A', 30, 7450000, 'Lenovo VN Inc', '20200922', '002'),
('L3B', 30, 10990000, 'Lenovo VN Inc', '20200922', '002'),
('M1A', 30, 10990000, 'MSI VN Inc', '20200922', '002'),
('M1B', 30, 23990000, 'MSI VN Inc', '20200922', '002'),
('M2', 30, 15790000, 'MSI VN Inc', '20200922', '002'),
('M3A', 30, 16090000, 'MSI VN Inc', '20200922', '002'),
('M3B', 30, 21490000, 'MSI VN Inc', '20200922', '002')
/*------------------------------------------------------------------------------------------------------*/
create table HoaDon
(
	MaHD char(10) primary key,
	MaKH char(10) foreign key references dbo.ThongTinKhachHang (MaKH),
	TongThanhToan int,
	ThoiGianXuat date,
	NhanVienXuat char(10) foreign key references dbo.ThongTinNhanVien (MaNV)
)
go

insert dbo.HoaDon values
('001', '001', 22990000, '20201002', '002'),
('002', '002', 22690000, '20201002', '001')
/*------------------------------------------------------------------------------------------------------*/
create table XuatKho
(
	MaHD char(10) foreign key references dbo.HoaDon (MaHD),
	MaSP char(5) foreign key references dbo.CauHinhChiTiet (MaSP),
	SoLuong int,
	ThanhTien int
)
go

insert dbo.XuatKho values
('001', 'AS1B', 1, 22990000),
('002', 'D2A', 1, 22690000)
/*
create trigger trg_EditNhapKho
on NhapKho
for update
as
begin
	declare @MaSP char(5)
	declare @SoLuongNhap int
	declare @SoLuongNhapBD int
	select @MaSP = MaSP, @SoLuongNhap = SoLuong from inserted
	select @SoLuongNhapBD = SoLuong from deleted
	update Kho
	set SoLuong = SoLuong - @SoLuongNhapBD + @SoLuongNhap
	where MaSP = @MaSP
end

create trigger trg_EditXuatKho
on XuatKho
for update
as
begin
	declare @MaSP char(5)
	declare @SoLuongXuat int
	declare @SoLuongXuatBD int
	select @MaSP = MaSP, @SoLuongXuat = SoLuong from inserted
	select @SoLuongXuatBD = SoLuong from deleted
	update Kho
	set SoLuong = SoLuong - @SoLuongXuat + @SoLuongXuatBD
	where MaSP = @MaSP
end*/