#include "CPOI.h"
#include <iostream>
using namespace std;


/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPOI.CPP
* Author          :Mohammad Shahid Mobin
* Description     :CPOI class is for entertaining Point of Interest. it is taking input from user and setting that value of
* 					of different poi.
*
*
****************************************************************************/


//System Include Files


//Own Include Files

//Method Implementations





/*
 * CPOI Constructor  taking arguments and initializing all the values. it also uses set function of CWaypoint class for setting its value.
 */
CPOI::CPOI(t_poi type_call,string name_call,string description_call,double latitude_call,double longitude_call)
{
	set(name_call,latitude_call,longitude_call);
	m_type=type_call;
	m_description=description_call;
}


/*
 * getAllDataByRefernce: this function is taking input as thgere reference value. and setting the value.
 */
void CPOI::getAllDataByRefernce(string &name,double &latitude,double &longitude,t_poi &type,string &description)
{
	name = getName();
	latitude =getLatitude();
	longitude = getLongitude();
	type = m_type;
	description = m_description;
}


/*
 * print function is local class for CPOI it is also using getter function of CWaypointb for printing its value.
 */
void CPOI::print()
{
	CWaypoint::print(1);
	switch(m_type)
	{
	   case 1 :
	      cout<<"RESTAURANT"<<endl;
	      break;
	   case 2  :
		   cout<<"TOURISTIC"<<endl;
	      break;
	   case 3 :
	      cout<<"GASSTATION"<<endl;
	      break;
	   case 4  :
		   cout<<"UNIVERSITY"<<endl;
	      break;
	   default:
		  cout<<"invalid type"<<endl;
	}
	cout<<m_description<<endl;
}
