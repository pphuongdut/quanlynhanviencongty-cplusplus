#include "QLNV.cpp"
int main()
{
  QLNV<NhanVien> data; 
  NVBC nv1;
  // NVBC nv2;
  NVBC nv3("1","Phuong",Date(1,1,2018), 1.0, 1000000.0,2.0);
  
  //  data.Insert(nv3,0);
  // cin >> nv1;
  // cout << "Nhap nv 2:" << endl;
  // cin >> nv2;
  // cout << nv1;
  NVHD nv4;
  cin >> nv4;
  NhanVien *a;
  a = &nv4;
  data.Insert(&nv4,0);
  data.InsertLast(&nv4);
    // data.Insert(&nv4,1);
    //   data.Insert(&nv4,1);
    //     data.Insert(&nv4,1);
  data.Xuat();
  cout << " 1";

  // cout << data;
  return 0;
}