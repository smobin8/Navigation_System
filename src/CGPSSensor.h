/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CGPSSENSOR.H
* Author          :Mohammad Shahid Mobin
* Description     :This class is taking Current Location and returning it to CWaypoint in this prototypes is defined
*
*
****************************************************************************/

#ifndef CGPSSENSOR_H
#define CGPSSENSOR_H
#include "CWaypoint.h"
class CGPSSensor {
public:

    CGPSSensor();

    CWaypoint getCurrentPosition();
};
/********************
**  CLASS END
*********************/
#endif /* CGPSSENSOR_H */
