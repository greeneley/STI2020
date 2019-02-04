typedef struct {
  int element;
  tree_t* left_son;
  tree_t* right_son;
} tree_t;

tree_t* leaf(int element)
{
  tree_t* result;
  result = malloc(sizeof(tree_t));
  (*result).element = element;
  (*result).left_son = 0;
  (*result).right_son = 0;
  return result;
}

void insert(tree_t* tree, int element)
{
  if(element > (*tree).element)
    {
      if((*tree).right_son == 0)
	(*tree).right_son = leaf(element);
      else
	insert((*tree).right_son,element);
    }
  else
    {
      if((*tree).left_son == 0)
	(*tree).left_son = leaf(element);
      else
	insert((*tree).left_son,element);	
    }
}

void print_tree(tree_t* tree)
{
  if(tree != 0)
    {
      print_int((*tree).element);
      print_char('(');
      print_tree((*tree).left_son);
      print_char(',');
      print_tree((*tree).right_son);
      print_char(')');
    }
}

void main()
{
  tree_t* abr;
  abr = leaf(5);
  insert(abr,2);
  insert(abr,7);
  insert(abr,1);
  insert(abr,3);
  print_tree(abr);
  //    5
  //   / \
  //  2   7
  // / \
  //1   3
}
