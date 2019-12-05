#include "CNavigationSystem.h"
#include "CRoute.h"
#include <iostream>
#include <string>
using namespace std;

/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CNAVIGATIONSYSTEM.CPP
* Author          :Mohammad Shahid Mobin
* Description     :Navigation system is the front block of navigation system in this all the requirement of user is implemented
*
*
*
****************************************************************************/


//System Include Files


//Own Include Files

//Method Implementations

//Constructor
CNavigationSystem::CNavigationSystem()
{
	m_route.connectToPoiDatabase(&m_PoiDatabase);
}

//run function will call all the other method from it
void CNavigationSystem::run()
{

	enterRoute();
	printRoute();
	printDistanceCurPosNextPoi();

}


//enter Route will take all the input like adding all the pois and waypoint and current location.
void CNavigationSystem::enterRoute()
{
		CWaypoint Amsterdam("Amsterdam",52.3680,4.9036);
		CWaypoint Darmstadt("Darmsdadt",49.8728,8.6512);
		CWaypoint Berlin("Berlin",52.5166,13.40);
		CWaypoint Tokio("Tokio",35.6895,139.6917);
		CPOI PIZZA_HUT(RESTAURANT,"PIZZA_HUT","BEST PIZZA IN WORLD",69.46,39.00);
		CPOI HDA(UNIVERSITY,"HDA"," UNI IN GERMANY",20.46,56.00);
		CPOI SHELLGAS(GASSTATION,"SHELL_GAS","BEST FUEL WILL GET",9.46,18.00);
		CPOI TUD(UNIVERSITY,"TUD"," TECHNICAL UNI IN GERMANY",56.46,48.00);
		CPOI Brandenburg_Gate(TOURISTIC,"BrandenburgGate","18th-century neoclassical monument in Berlin",39.46,17.00);
		CPOI CologneCathedral(TOURISTIC,"CologneCathedral","Catholic cathedral in Cologne North Rhine-Westphalia",54.46,35.00);
		CPOI LahorePalace(RESTAURANT,"LahorePalace","FAMOUS PAKISTANI RESTAURANT",45.46,45.00);
		CPOI PUREGAS(GASSTATION,"PUREGAS","Famous for its quality",79.46,78.00);
		CPOI DelhiDarbar(RESTAURANT,"DelhiDarbar","world best restaurant",69.39,4.00);
		CPOI Mc1Donald(RESTAURANT,"McDonald","Famous for Burger",79.39,60.00);


		m_PoiDatabase.addPoi(RESTAURANT,"PIZZA_HUT","BEST PIZZA IN WORLD",69.46,39.00);
		m_PoiDatabase.addPoi(UNIVERSITY,"HDA"," UNI IN GERMANY",20.46,56.00);
		m_PoiDatabase.addPoi(GASSTATION,"SHELL_GAS","BEST FUEL WILL GET",9.46,18.00);
		m_PoiDatabase.addPoi(UNIVERSITY,"TUD"," TECHNICAL UNI IN GERMANY",56.46,48.00);
		m_PoiDatabase.addPoi(TOURISTIC,"BrandenburgGate","18th-century neoclassical monument in Berlin",39.46,17.00);
		m_PoiDatabase.addPoi(TOURISTIC,"CologneCathedral","Catholic cathedral in Cologne North Rhine-Westphalia",54.46,35.00);
		m_PoiDatabase.addPoi(RESTAURANT,"LahorePalace","FAMOUS PAKISTANI RESTAURANT",45.46,45.00);
		m_PoiDatabase.addPoi(GASSTATION,"PUREGAS","Famous for its quality",79.46,78.00);
		m_PoiDatabase.addPoi(RESTAURANT,"DelhiDarbar","world best restaurant",69.39,4.00);
		m_PoiDatabase.addPoi(RESTAURANT,"McDonald","Famous for Burger",79.39,60.00);




		//"Adding WayPoints";

		m_route.addWaypoint(Berlin);
		m_route.addWaypoint(Tokio);

		//"Adding Point Of Interest";

		m_route.addPoi("HDA");
		m_route.addPoi("Wrong_Value");
		m_route.addPoi("TUD");
		m_route.addPoi("CologneCathedral");

}


//printing all the waypoint and POis added to the route
void CNavigationSystem::printRoute()
{
	m_route.print();
}


//function for printing distance from current location and finding nearest poi.
void CNavigationSystem::printDistanceCurPosNextPoi()
{

	CPOI DelhiDarbar;
	CWaypoint enteredCWaypoint=m_GPSSensor.getCurrentPosition();
	double x=m_route.getDistanceNextPoi(enteredCWaypoint,DelhiDarbar);
	cout<<"shortest POI is at distance "<<x<<"km"<<endl;
}

