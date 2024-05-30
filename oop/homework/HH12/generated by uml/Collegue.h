/**
 * Project p_representation
 * @author p
 */


#ifndef _COLLEGUE_H
#define _COLLEGUE_H

#include "Contact.h"


class Collegue: public Contact {
public: 
    char* phone_number;
    char* company_name;
    char* address;
};

#endif //_COLLEGUE_H