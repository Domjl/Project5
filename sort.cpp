//Full Recursive Sort **HEAVY USAGE**
//NOPE, don't like it... 
BookNode recursiveSort(BookNode *n)
{
  if(n->next == null)
  {
    return n;
  }
  else if(n.get___() > recursiveSort(n->next))
  {
    swapUp(n);
  }
} 

swapUp(BookNode *n)
{
  BookNode s = n->next;
  
}

//Insertion Sort 
//Assumed to be already sorted.
