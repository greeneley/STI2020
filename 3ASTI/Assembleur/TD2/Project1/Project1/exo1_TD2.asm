.386
.model flat 
.data ;
pointeur dword ?
pointeur2 dword ?
pointeur3 word ?
.code
main proc ;
mov ax,78;
lea ebx,pointeur;
mov ax,[ebx];
add ax,7659h;
mov pointeur3,ax; il faut choisir une adresse validepar l'OS ne marche pas mov cx,ds:[2000000h]
lea esi,pointeur2
add bx,[esi];
mov [esi+ebp],bx;
sub al,1;
mov [esi+ebp+10],al;
main endp;
end ;