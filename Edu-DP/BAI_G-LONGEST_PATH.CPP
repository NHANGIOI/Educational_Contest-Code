//Nhận xét 1  : là độ thị có hướng ko chu trình (vì có chu trình thì kq là vô cực)
//Nhận xét 2 : có thể duyệt trong O(n) bằng đệ quy có nhớ
// Thuật chuẩn :
/*
dùng qhd duyệt hết M cạnh (ko check (ko có chu trình và để duyệt hết cạnh))
gọi dp[u] là đg đi dài nhất khi xuất phát từ đỉnh u
thì dp[u] += dp[v]
kq BT là *max_element(dp,dp + n);
*/