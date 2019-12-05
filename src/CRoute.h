/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CROUTE.H
* Author          :Mohammad Shahid Mobin
* Description     :Route class is defining Route by entering all the interested waypoints and point of interest as well as
* 					getting distance between two location using calculate distance function used in CWaypoint
*					defining prototype.
*
*
****************************************************************************/

#ifndef CROUTE_H
#define CROUTE_H
#include <iostream>
#include <string>
#include "CWaypoint.h"
#include "CPoiDatabase.h"
class CPOI;
class CRoute :public CPoiDatabase{
private:
    CWaypoint *m_pWaypoint;
    unsigned int m_maxWp;
   unsigned int m_nextWp;
    unsigned int m_maxPoi;
    unsigned int m_nextPoi;
    CPoiDatabase* m_pPoiDatabase;
    CPOI** m_pPoi;
    double distanceCalculated[10];
public:

   // unsigned int i,j,temp;
   CRoute(unsigned int maxWp=20,unsigned int maxPoi=20);
  CRoute(const CRoute &origin);
    ~CRoute();
    void connectToPoiDatabase(CPoiDatabase *pPoiDB);

    void addWaypoint(const CWaypoint &wp);

   void addPoi(string namePoi);

    double getDistanceNextPoi(const CWaypoint &wp,CPOI &poi);

    void print();






};
/********************
**  CLASS END
*********************/
#endif /* CROUTE_H */
