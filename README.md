# Assignment

# Algorithm Insertion

<b>Input:</b>  data, the data to be inserted and header, the pointer to the header node
<b>Output:</b> bag with new data inserted.
<b>Data Structure:</b> Linked list representation of multiset.

    1. ptr=header
    2. while(ptr→link!=NULL) //traverse till the last node
        2.1 ptr=ptr→link
        2.2 if(ptr→data=data) // checking if a copy of the data already exist
            1. go to step 10
        2.3 endif
    3. endwhile
    4. new=GETNODE(NODE)// Creating a new node
    5. new→data=data// entering data
    6. new→count=1//setting count as 1
    7. new→link=NULL
    7. ptr→link=new// inserting the node at the last position
    9. go to 11
    10. ptr→count=ptr→count+1
    11. Stop

# Algorithm Deletion

<b>Input:</b> data, the item to be deleted, header, the pointer to the header node.
<b>Output:</b> bag with data deleted.
<b>Data Structure:</b> Linked list representation of multiset

    1. flag=0
    2. ptr=header
    3. if(ptr=NULL)
            3.1 print “The Bag is empty”
    4. else
        4.1. while(ptr→link!=NULL)
            4.1.1. ptr1=ptr
            4.1.2. ptr=ptr→link
            4.1.3. if(ptr→data=data)
                4.1.3.1. flag=1
                4.1.3.2. go to 4.1.5.1
            4.1.4. endif
            4.1.5. if(flag=0)
                4.1.4.1. print “ data is not present in bag”
            4.1.6. else
                4.1.6.1. ptr→count=ptr→count-1
                4.1.6.2. if(ptr→count=0)
                    1. ptr1=ptr→link
                4.1.6.3. endif
            4.1.7. endif
        4.2. endwhile
    5. endif
    6. stop
    
#Algorithm Deletion

<b>Input:</b>  header, the pointer to the header node.
<b>Output:</b> display the multiset
<b>Data Structure:</b> Linked list representation of multiset

    1. ptr=header→link
    2. if(ptr=NULL)
            1.1 print “The bag is empty”
    3. else
        3.1. while(ptr!=NULL)
            3.1.1. print “count,ptr→data”
        3.2. endwhile
    4. endif
    5. stop

       
