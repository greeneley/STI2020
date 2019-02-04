typedef struct {
  int re;
  int im;
} complex_t;


void print_complex(complex_t complex)
{
  print_int(complex.re);
  print_char('+');
  print_char('i');
  print_int(complex.im);
}

void main()
{
  complex_t complex;

  complex.im = 5;
  complex.re = 6;

  print_complex(complex);
}
