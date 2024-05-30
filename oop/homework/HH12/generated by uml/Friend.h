/**
 * Project p_representation
 * @author p
 */


#ifndef _FRIEND_H
#define _FRIEND_H

#include "Contact.h"


class Friend: public Contact {
public: 
    char* birth_date;
    char* phone_number;
    char* address;
};

#endif //_FRIEND_H