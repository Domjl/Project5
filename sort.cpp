/**
 * Purpose: sort.. that I believe based on my understanding of c++ will work.
 * with comments.. :D
 * 
 * @param *head pass in the current head of the list
 * @return returns the new head of the list.
 * 
 * @author Dominic :P
 * @version 0.5 4/22/16
 */
BookNode sortBooks(BookNode *head)       
{
	BookNode *newhead = nullptr;      // Head to be.
	BookNode *current = nullptr;      // Position place holder for where in the sorted list we are.

	while(head->next != nullptr)      // repeat until only head remains
	{
		BookNode *n = head;             // temp node for looping through
		BookNode *max = n;              // max node
		BookNode *maxParent = n;        // max node's parent

		while(n->next != nullptr)       // while has another node
		{
			if(n->next->getAmount() > n->getAmount()) // if the next node is larger than the current node
			{
				max = n->next;              // current max is the next node
				maxParent = n;              // current node is the max's parent 
			}
		}

                // remove the node - Delink the node from the link and relink the remaining list
		if(max == head)                 // if max is first element
		{
			head = head->next;            // set head to next node
		}
		else                            //
		{
			maxParent->next = max->next;  // max's parent's next == max's next node
		}
		max->next = nullptr;            // max's next beocmes null
		
		//Append the cut node to the new list.
		if(current == nullptr)          // if newhead hasn't beeen set yet
		{
		  newhead = max;                 // set a starting point
		  current = newhead;            // safety
		}
		else
		 {
		   current->next = max;         // next max is the max we found
		   current = max;                // move along in the sorted list
		 }
	}

	current->next = head;             // add the remaining value;
	
	return newhead;                   // return the new list
}


//==========================================
//
//See Psuedo and planning bellow
//
//==========================================
//find min
//addNewNode to new list
//
//conditions
//first will be the new head
//current -> next = next min
//==========================================
while(n.hasnext())
{
	if(n->next->value < n->value)
	{
		min = n-> next;
	}
}

if(n==head)
{
	head = n.next;
	n.next = null;
}
else{
n.parent = n.next;
n.next = nullptr;

}

if(top==null)
{
	top = n;
	current = top;
}
else
{
	current -> next = n;
}

//repeat until original head = null
//return new head

//======================================================================
//
//SEE BELLOW FOR UGLYNESS
//======================================================================
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
void blah
