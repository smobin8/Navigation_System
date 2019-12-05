#include "CRoute.h"
#include "CPOI.h"

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CROUTE.CPP
* Author          :Mohammad Shahid Mobin
* Description     :Route class is defining Route by entering all the interested waypoints and point of interest as well as
* 					getting distance between two location using calculate distance function used in CWaypoint
*
*
****************************************************************************/


//System Include Files


//Own Include Files

//Method Implementations


//Parameterized constructor taking maxWp and MaxPoi as argument
CRoute::CRoute(unsigned int maxWp,unsigned int maxPoi)
{
	m_pPoiDatabase=NULL;
	m_maxWp=maxWp;
	m_maxPoi=maxPoi;
	m_nextPoi=0;
	m_nextWp=0;
	m_pPoi=new CPOI*[m_maxPoi];
	m_pWaypoint=new CWaypoint[m_maxWp];
	//

}

//copy constructor
CRoute::CRoute(const CRoute &origin)
{
	this->m_maxWp=origin.m_maxWp;
	this->m_maxPoi=origin.m_maxPoi;
	this->m_nextPoi=origin.m_nextPoi;
	this->m_nextWp=origin.m_nextWp;
	this->m_pWaypoint=origin.m_pWaypoint;
	this->m_pPoi=origin.m_pPoi;
	this->m_pPoiDatabase=origin.m_pPoiDatabase;


}

//destructor
CRoute::~CRoute()
{
	delete []m_pWaypoint;
	delete []m_pPoi;
//delete command for short array
}

//connectToPoiDatabase taking input address of database and connecting to it
void CRoute::connectToPoiDatabase(CPoiDatabase *pPoiDB)
{
	m_pPoiDatabase=pPoiDB;
	//cout<<" address of DB is: "<<m_pPoiDatabase<<endl;

}

//it is taking waypoint address as argument and adding to the route.
void CRoute::addWaypoint(const CWaypoint &wp)
{
	if(m_nextWp<m_maxWp)
	{
		m_pWaypoint[m_nextWp]=wp;
	//	cout<<" Added "<<m_pWaypoint[m_nextWp].getName()<< " at latitude "<<m_pWaypoint[m_nextWp].getLatitude()<< " at longitude "<<m_pWaypoint[m_nextWp].getLongitude()<<endl;
		m_nextWp++;
	}
}

//it is taking poi name as argument and adding to the route.
void CRoute::addPoi(string namePoi)

{
	if(m_pPoiDatabase !=NULL)
	{

		if(m_nextPoi<m_maxPoi)
		{

			if(m_pPoiDatabase->getPointerToPoi(namePoi)==NULL)
			{
				cout<<"ERROR: Could not find POI Something not in the pool "<<endl;
			}
			else
			{
				m_pPoi[m_nextPoi]=m_pPoiDatabase->getPointerToPoi(namePoi);

				//cout<<" Added "<<m_pPoi[m_nextPoi]->getName()<< " at latitude "<<m_pPoi[m_nextPoi]->getLatitude()<< " at longitude "<<m_pPoi[m_nextPoi]->getLongitude()<<endl;
				m_nextPoi++;
			}

		}
		else
		{
			cout<<"you are extending number of Poi's in a route"<<endl;
		}
	}
	else
	{
		cout<<"Database is empty"<<endl;
	}
}

/*
 * getDistanceNextPoi is taking  address of Waypoint and Poi and calculating the distance between them as well sorting the
 * value and returning the Poi which is at nearest distance as well printing the sorted array.
 */
double CRoute::getDistanceNextPoi(const CWaypoint &wp,CPOI &poi)
{

	//cout<<"distance calculating"<<endl;
	double distanceCalculated[10]={0},shortest_distance=100000;
	for(unsigned int i=0;i<m_nextPoi;i++)
	{
		distanceCalculated[i]=m_pPoi[i]->calculateDistance(wp);


		if(distanceCalculated[i]<=shortest_distance){
			shortest_distance=distanceCalculated[i];

		}
	}
	return shortest_distance;
}

/*
 * print function for printing the value
 */
void CRoute::print()
{
	cout<<" Our Route has "<<m_nextWp<<" Waypoints "<<endl;
	for(unsigned int i=0;i<m_nextWp;i++)
	{
	    m_pWaypoint[i].print(2);
	}

	unsigned int j = m_nextPoi;
	m_nextPoi = 0;
	cout<<j<<" Pois is included in our route"<<endl;
		for(m_nextPoi=0;m_nextPoi<j;m_nextPoi++){

			m_pPoi[m_nextPoi]->print();

		}




}
