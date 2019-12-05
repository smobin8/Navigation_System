/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPOI.H
* Author          :MOhammad Shahid Mobin
* Description     :CPOI class is for entertaining Point of Interest. it is taking input from user and setting that value of
* 					of different poi. in header file it is defining all the prototypes
*
*
****************************************************************************/

#ifndef CPOI_H
#define CPOI_H
#include "CWaypoint.h"
#include <iostream>
#include <string>
using namespace std;
enum t_poi{Default,RESTAURANT, TOURISTIC, GASSTATION, UNIVERSITY};
class CPOI : public CWaypoint {
private:


	t_poi m_type;
	string m_description;
public:
	//CPOI();
	CPOI(t_poi type=Default,string name="NO_Name",string description="No_Description",double latitude=0.00,double longitude=0.00);
	void print();

    void getAllDataByRefernce(string &name,double &latitude,double &longitude,t_poi &type,string &description);



};
/********************
**  CLASS END
*********************/
#endif /* CPOI_H */
