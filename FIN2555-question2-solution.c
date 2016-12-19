// TYPE_NODEPTR == TYPE_NODE*

int CopyAVLTree(TYPE_NODEPTR T1,TYPE_NODEPTR *T2){
    
    // Note: T2 is pointer point to TYPE_NODEPTR 

    if(!T1){
        //if(T1 == NULL)
        return 0;
    }

    (*T2) = NewNode(T1 -> Info);

    CopyAVLTree(T1 -> Left, &((*T2) -> Left));
    CopyAVLTree(T1 -> Right, &((*T2) -> Right));

    // & ( (*T2) -> Left ) == address of (*T2) -> Left
    // "&(*T2)->Left" has same meaning because "->" has higher order than &

    if((*T2) -> Left){
        (*T2) -> Left -> Parent = (*T2);
    }

    if((*T2) -> Right){
        (*T2) -> Right -> Parent = (*T2);
    }

    /*  Use these is better
        
        if(CopyAVLTree(T1 -> Left, (*T2) -> Left))

    */

    return 1;

}
