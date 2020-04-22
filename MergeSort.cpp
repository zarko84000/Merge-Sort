#include <iostream> 



void Merge(int *T,int a, int b , int m)
{
   
    int MergeTable[b] ; 
    int Iterator_i = a , Iterator_j = m+1 ,Indice =a; 
  
    while (Iterator_i <= m && Iterator_j  <= b)
    {
        if( T[Iterator_i] <= T[Iterator_j] )
        {
            MergeTable[Indice] = T[Iterator_i] ;
            
            Iterator_i++ ; 
        }
        else
        {
            MergeTable[Indice] = T[Iterator_j] ;
            Iterator_j++ ; 
        }
        Indice++ ; 
    }

    for( int i = Iterator_i ; Iterator_i < m ; i++ )
    {
        MergeTable[Indice] = T[i] ;
        Indice++ ;
    }

    for( int j = Iterator_j ; j < b ; j++ )
    {
        MergeTable[Indice] = T[j] ;
        Indice++ ;
    }
    
    for( int j = a ; j < Indice ; j++ )
    {
        
        T[j] = MergeTable[j] ; 
    }
}

void RecursiveMergeSort(int *T,int a,int b)
{
    if(a<b)
    {
        int m= (a+b)/2 ; 
        RecursiveMergeSort(T,a,m);
        RecursiveMergeSort(T,m+1,b);
        Merge(T,a,b,m) ; 
    }
}

void Display(int *T , int b)
{
    for(int i=0 ; i < b ; i++)
    {
        std::cout << T[i] << " "  ; 
    }
    std::cout << "\n" << "------------------------------------" << std::endl ; 
}

void MergeSort(int *T,int Size)
{
    std::cout << "Before MergeSort : " << std::endl ; 
    Display(T,Size) ; 
    RecursiveMergeSort(T,0,Size-1) ;
    std::cout << "After MergeSort : " << std::endl ; 
    Display(T,Size) ; 
}

int main()
{
    int T[8] = {1,2,1,4,1,6,8,9} ; 
    MergeSort(T,8);
    

    return 0 ; 
}
