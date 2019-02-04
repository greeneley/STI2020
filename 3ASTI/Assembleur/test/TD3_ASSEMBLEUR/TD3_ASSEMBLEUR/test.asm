.386
.model flat
.data
table word 10h,20h,30h
.code 
main proc
lea esi, table
mov al, [esi]
mov al, [esi+2]
mov al, [esi+4]
main endp
end