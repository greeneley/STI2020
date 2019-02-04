int p;
int q;

input(p);
input(q);
while(p != q)
  {
    if(p>q)
      p = p - q;
    else
      q = q - p;
  }
print(p);
