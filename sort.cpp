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
BookNode sort(BookNode *head)       
{
	BookNode *newhead = nullptr;      // Head to be.
	BookNode *current = nullptr;      // Position place holder for where in the sorted list we are.

	while(head->next != nullptr)      // repeat until only head remains
	{
		BookNode *n = head;             // temp node for looping through
		BookNode *min = n;              // min node
		BookNode *minParent = n;        // min node's parent

		while(n->next != nullptr)       // while has another node
		{
			if(n->next->getAmount() ? n->getAmount()) // if the next node is smaller than the current node
			{
				min = n->next;              // current min is the next node
				minParent = n;              // current node is the min's parent 
			}
		}

                                    // remove the node
		if(min == head)                 // if min is first element
		{
			head = head->next;            // set head to next node
		}
		else                            //
		{
			minParent->next = min->next;  // min's parent's next == min's next node
		}
		
		min->next = nullptr;            // min's next beocmes null
		if(current == nullptr)          // if newhead hasn't beeen set yet
		{
		  newhead = min                 // set a starting point
		  current = newhead;            // safety
		}
		else
		 {
		   current->next = min;         // next min is the min we found
		   current = min                // move along in the sorted list
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
