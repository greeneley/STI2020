.data
var1 DWORD 10000000h
var2 DWORD 10000000h
.code
mov eax,var1;
add eax,var2;
add eax,0FFFFFFFFh;
add eax,1;
sub eax,1;