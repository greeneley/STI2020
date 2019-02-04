.386
.model flat
.data
var1 dword 5,6
.code 
main proc
push [var1]
pop [var1+4]

main endp
end

