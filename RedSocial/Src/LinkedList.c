#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Heathers/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* nd = NULL;
    if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this))
    {
        nd = this->pFirstNode;
        if (nodeIndex>0)
        {
            while(nodeIndex>0)
            {
                nd=nd->pNextNode;
                nodeIndex--;
            }
        }
    }
    return nd;
}

static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int isError = -1;
    Node* nd = NULL;
    Node* auxnd;
    if (this!=NULL&&nodeIndex>=0)
    {
        nd = (Node*) malloc(sizeof(Node));
        if (nd!=NULL)
        {
            nd->pElement=pElement;
            if(ll_len(this)>=1)
            {
                auxnd = getNode(this,nodeIndex);
            }
            nd->pNextNode=auxnd;
            if (nodeIndex==0)
            {
                this->pFirstNode=nd;
            }
            else
            {
                auxnd=getNode(this,--nodeIndex);
                auxnd->pNextNode=nd;
            }
            this->size++;
            isError=0;
        }
    }
    return isError;
}

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* newLL;
    newLL = (LinkedList*) malloc(sizeof(LinkedList));
    if (newLL!=NULL)
    {
        newLL->size=0;
        newLL->pFirstNode=NULL;
    }
    return newLL;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int len = -1;
    if (this!=NULL)
    {
        len = this->size;
    }
    return len;
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int isError = -1;
    isError = addNode(this,ll_len(this),pElement);
    return isError;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        auxNode = getNode(this,index);
        if(auxNode!=NULL)
        {
            returnAux = auxNode->pElement;
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int isError = -1;
    Node* auxNode;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        auxNode = getNode(this,index);
        if(auxNode!=NULL)
        {
            auxNode->pElement=pElement;
            isError=0;
        }
    }
    return isError;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int isError = -1;
    Node* node;
    Node* auxNode;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        node = getNode(this,index);
        if(index==0)
        {
            auxNode=getNode(this,++index);
            this->pFirstNode=auxNode;
        }
        else
        {
            auxNode=getNode(this,--index);
            auxNode->pNextNode=node->pNextNode;
        }
        free(node);
        this->size--;
        isError=0;
    }
    return isError;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int isError = -1;
    if(this!=NULL)
    {
        while(ll_len(this))
        {
            ll_remove(this,0);
        }
        isError=0;
    }
    return isError;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int isError = -1;
    if(this!=NULL)
    {
        ll_clear(this);
        free(this);
        isError=0;
    }
    return isError;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1,len;
    Node* auxNode;
    if(this!=NULL)
    {
        len=ll_len(this);
        while(len>=0)
        {
            auxNode=getNode(this,len);
            if(auxNode!=NULL)
            {
                if(auxNode->pElement==pElement)
                {
                    returnAux=len;
                    break;
                }
            }
            len--;
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
        if(this->size>0)
            returnAux=0;
        else
            returnAux=1;
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    return addNode(this,index,pElement);
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this!=NULL && index>=0 && index<ll_len(this))
    {
        returnAux=ll_get(this,index);
        if(ll_remove(this,index)==-1)
        {
            returnAux = NULL;
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int isReturn = -1;
    if(this!=NULL)
    {
        isReturn=0;
        if(ll_indexOf(this,pElement)>= 0)
        {
            isReturn=1;
        }
    }
    return isReturn;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int isReturn = -1;
    void* element;
    if(this!=NULL&&this2!=NULL)
    {
        isReturn=1;
        for(int len=ll_len(this2)-1; len>=0; len--)
        {
            element=ll_get(this2,len);
            if(ll_contains(this,element)==0)
            {
                isReturn=0;
                break;
            }
        }
    }
    return isReturn;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* element;
    if(!(this==NULL||from<0||from>ll_len(this)||from>=to||to>ll_len(this)))
    {
        cloneArray = ll_newLinkedList();
        while(from<=to)
        {
            element=ll_get(this,from);
            if(ll_add(cloneArray,element)==-1)
            {
                cloneArray=NULL;
                break;
            }
            from++;
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if (this!=NULL)
    {
        cloneArray=ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int isError =-1,len;
    void* aux;
    if(this!=NULL&&pFunc!=NULL&&order>=0&&order<=1)
    {
        len=ll_len(this);
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(pFunc(ll_get(this,i),ll_get(this,j))>0&&order==1)
                {
                    aux=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,aux);
                }
                else if(pFunc(ll_get(this,i),ll_get(this,j))<0&&order==0)
                {
                    aux=ll_get(this,i);
                    ll_set(this,i,ll_get(this,j));
                    ll_set(this,j,aux);
                }
            }
        }
        isError=0;
    }
    return isError;

}

LinkedList* ll_fillter(LinkedList* this, int (*pFunc)(void* ,void*), void* excluded)
{
    LinkedList* clonedList = NULL;//ll_clone(this);
    void* checking;
    if(this!=NULL)
    {
        clonedList = ll_clone(this);
        for(int len = ll_len(this); len>=0; len--)
        {
            checking = ll_get(clonedList, len);
            if(pFunc(checking,excluded)!=0)
            {
                ll_remove(clonedList,len);
            }
        }
    }
    return clonedList;
}

int ll_sortDouble(LinkedList* this, int (*upperPrio)(void* ,void*), int (*lowerPrio)(void* ,void*), int order)
{
    int isError = 1;
    int lenght;
    int aux;
    void* auxElement;
    lenght = ll_len(this);
    if(this!=NULL)
    {
        aux=ll_sort(this,upperPrio,order);
        if(aux==0)
        {
            for(int i = 0; i<lenght; i++)
            {
                for(int j = i+1; j<lenght; j++)
                {
                    if(upperPrio(ll_get(this,i),ll_get(this,j))==0&&lowerPrio(ll_get(this,i),ll_get(this,j))>0&&order==1)
                    {
                        auxElement=ll_get(this,i);
                        ll_set(this,i,ll_get(this,j));
                        ll_set(this,j,auxElement);
                    }
                    else if(upperPrio(ll_get(this,i),ll_get(this,j))==0&&lowerPrio(ll_get(this,i),ll_get(this,j))>0&&order==0)
                    {
                        auxElement=ll_get(this,i);
                        ll_set(this,i,ll_get(this,j));
                        ll_set(this,j,auxElement);
                    }
                }
            }
            isError=0;
        }
    }
    return isError;
}

LinkedList* ll_map (LinkedList* this, void*(*pFunc) (void* element))
{
    int lenght;
    int aux;
    LinkedList* resultList = NULL;
    void* element;
    void* auxElement;
    resultList = ll_newLinkedList();
    lenght = ll_len(this);
    if(this!=NULL&&(*pFunc)!=NULL&&resultList!=NULL)
    {
        for(int i = 1; i<lenght; i++)
        {
            element = ll_get(this,i);
            if(element!=NULL)
            {
                auxElement=pFunc(element);
                if(auxElement!=NULL)
                {
                    aux = ll_add(resultList,auxElement);
                    if (aux==-1)
                    {
                        resultList = NULL;
                        break;
                    }
                }

            }
        }
    }
    return resultList;
}
