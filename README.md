# Assignment

#Algorithm Insertion

<b>Input:</b>  data, the data to be inserted and header, the pointer to the header node
<b>Output:</b> bag with new data inserted.
<b>Data Structure:</b> Linked list representation of multiset.

    1. ptr=header
    2. while(ptr→link!=NULL) //traverse till the last node
        1. ptr=ptr→link
        2. if(ptr→data=data) // checking if a copy of the data already exist
            1. go to step 10
        3. endif
    3. new=GETNODE(NODE)// Creating a new node
    4. new→data=data// entering data
    5. new→count=1//setting count as 1
    6. new→link=NULL
    7. ptr→link=new// inserting the node at the last position
    8. go to 11
    9. ptr→count=ptr→count+1
    10. Stop
