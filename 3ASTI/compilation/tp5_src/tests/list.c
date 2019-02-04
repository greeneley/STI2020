typedef struct {
  int element;
  list_t* next;
} list_t;


void main()
{
  list_t* list;
  list_t* current;
  int i;

  //Build the list [0; 1; 2]
  list = malloc(sizeof(list_t));
  current = list;
  for(i=0; i<3; i++)
    {
      (*current).element = i;
      (*current).next = malloc(sizeof(list_t));
      current = (*current).next;
    }

  current = list;
  for(i=0; i<3; i++)
    {
      print_int((*current).element);
      current = (*current).next;
    }
}
