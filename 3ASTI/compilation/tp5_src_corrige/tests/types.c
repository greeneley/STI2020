//typedef struct {
//  char[8] element; 
//  list_t* next;
//} list_t;
 
//typedef struct { 
//  char[8] element;  
//  listp_t* next; 
//} listp_t; 

//typedef struct { 
//  char[9] element;  
//  list_t* next; 
//} list2_t;   

typedef struct {
  int[8] element;
  list_t* left_son;
  list_t* right_son;
} list_t;

typedef struct {
  int[8] element;  
  list3_t* left_son; 
  list3_t* right_son; 
} list3_t; 

typedef struct { 
  int[8] element;  
  list3_t* left_son; 
  list3_t* right_son; 
} list2_t; 

typedef struct {
  char[8] element; 
  tree_t* left_son;
  tree_t* right_son;
} tree_t;


typedef struct {
  char[8] nom; 
  char[8] prenom; 
  int age; 
} personne_t;

typedef personne_t[256] personnel_t;

typedef struct {
  int re;
  int im;
} complex_t;

void foo(list_t l)
{}

int main(personnel_t bd)
{
  complex_t[10] tab;
  personne_t personne;
  personnel_t bd_local;
  int x;
  int result;

  //x= search(tab,3,0,9);

  bd[0].nom[0] = 't';
  bd[0].nom[1] = 'i';
  bd[0].nom[2] = 't';
  bd[0].nom[3] = 'i';
  bd[0].nom[4] = 'e';
  bd[0].prenom[0] = 't';
  bd[0].prenom[1] = 'o';
  bd[0].prenom[2] = 't';
  bd[0].prenom[3] = 'o';
  bd[0].prenom[4] = 'e';
  bd[0].age = 25;

  if(bd[0].age >= 18)
    {
      x = 1;
      for(x=0; x<10; x++)
	{
	  x = x+x;
	}
    }
  else
    x = 0;

  while(x != 0)
    {
      x = x - 1;
      if(bd[0].age >= 18)
	{
	  x = 1;
	  for(x=0; x<10; x++)
	    {
	      x = x+x;
	    }
	}
      else
	x = 0;
    }

  

}

int fact(int n)
{
  int tmp;
  tmp = fact(n-1);
  if(n==0)
    return 1;
  else
    return n+tmp;
}

int search(personne_t[10] tab, int e, int debut, int fin)
{
  int m;

  if(debut == fin)
    {
      if(tab[debut] == e)
	return debut;
      else
	return (0-1);
    }

  m = (debut+fin)/2;

  if(tab[m] == e)
    return m;

  if(tab[m] > e)
    return search(tab,e,debut,m);
  else
    return search(tab,e,m,fin);

}
