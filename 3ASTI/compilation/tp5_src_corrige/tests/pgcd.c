int pgcd(int p, int q)
{
  while(p != q)
    if(p>q)
      p = p - q;
    else
      q = q - p;

  return p;
}


void main()
{
  int result;
  result = pgcd(6,3);
  print_int(result);
}
