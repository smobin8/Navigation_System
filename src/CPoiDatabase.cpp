#include "CPoiDatabase.h"
#include "CPOI.h"
#include "string"
#include <iostream>
using namespace std;
const int CAPACITY=10;
//CPOI m_CPOI[10];

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPOIDATABASE.CPP
* Author          :Mohammad Shahid Mobin
* Description     :CPoiDatabase is inheriting CPOI class. in this addpoi and getpointer is defined
*
*
****************************************************************************/


//System Include Files


//Own Include Files

//Method Implementations


//constructor
CPoiDatabase::CPoiDatabase()
{
	 m_noPoi=0;

}

//addPoi is taking parameter of POIS and adding to if the require condition is met.
void CPoiDatabase::addPoi(t_poi type,string name,string description,double latitude,double longitude)
{
	CPOI xyz(type,name,description,latitude,longitude);
	if(m_noPoi<10)
	{
			m_POI[m_noPoi]=xyz;
			m_noPoi++;
	}
	else
	{

		cout<<"maximum length of POI should be less than or equal to 10";
	}
}

//getPointerToPoi is taking input as name and after searching it is returning the CPOI pointer
CPOI* CPoiDatabase::getPointerToPoi(string name)
{
	CPOI *ptr = m_POI;
	for(int i=0;i<m_noPoi;i++)
	{
	if(ptr->getName()==name)
	{

		return ptr;
	}
	else
	{
		++ptr;
	}
	}
	return NULL;
}
