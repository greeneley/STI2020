.386
.model flat
.data
Xval DWORD 25450546	
Yval DWORD 12545874
Zval DWORD 13154645
Rval DWORD ?
var1 DWORD 25656655
var2 DWORD 889787987
var3 DWORD 878787878
;segment 2
.data 
var4 DWORD ?
.code ; declaration du segment du code
main proc
; operation Rval=-Xval+(Yval-Zval)
mov eax,Xval;
neg eax
add eax,Yval;
sub eax,Zval;
mov Rval,eax;
;;;;;;;;;;;;;;;;;;;;;;;;
; operation var4=(var1+var2)*var3
mov eax,var1;
add eax,var2;
mul var3
; solution 1
mov var4,eax ; vi phep tinh nhan nay dua ra ket qua 64bit nhung regist chi ghi dc 32 bits ; vi the no se chia ket qua thanh 2 phan luu vao eax va edx
mov [var4+4],edx;  dich chuyen var4 len 32bit <=> var4+4 de luu tiep gia tri ket qua vao 
; solution 2
; lea esi,var5  stockage sur une variable 64 bits
; mov [esi],eax
; mov [esi+4],edx

; operation var4=(var1*-5)\(var2%var3)
mov eax,var2
mov ecx,var3
div ecx
mov ebx,eax
mov eax,var1
mov edx,5
mul edx
div ebx
mov var4,eax
neg var4
main endp
end;